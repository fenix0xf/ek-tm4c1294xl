/*
 * Copyright (c) 2012, 2013 ARM Ltd
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the company may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ARM LTD ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL ARM LTD BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <libc.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <unistd.h>

#define MALLOC_CHECK_DOUBLE_FREE 1

#ifndef MAX
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#endif

#define ALIGN_PTR(ptr, align)   (((ptr) + (align) - (intptr_t)1) & ~((align) - (intptr_t)1))
#define ALIGN_SIZE(size, align) (((size) + (align) - (size_t)1) & ~((align) - (size_t)1))

/* Alignment of allocated block */
#define MALLOC_ALIGN   (8u)
#define CHUNK_ALIGN    (sizeof(void*))
#define MALLOC_PADDING ((MAX(MALLOC_ALIGN, CHUNK_ALIGN)) - CHUNK_ALIGN)

/* As well as the minimal allocation size to hold a free pointer. */
#define MALLOC_MINSIZE (sizeof(void*))
#define MAX_ALLOC_SIZE (0x80000000u)

struct malloc_chunk
{
    /*          --------------------------------------
     *   chunk->| size                               |
     *          --------------------------------------
     *          | Padding for alignment              |
     *          | This includes padding inserted by  |
     *          | the compiler (to align fields) and |
     *          | explicit padding inserted by this  |
     *          | implementation. If any explicit    |
     *          | padding is being used then the     |
     *          | sizeof (size) bytes at             |
     *          | mem_ptr - CHUNK_OFFSET must be     |
     *          | initialized with the negative      |
     *          | offset to size.                    |
     *          --------------------------------------
     * mem_ptr->| When allocated: data               |
     *          | When freed: pointer to next free   |
     *          | chunk                              |
     *          --------------------------------------
     */

    /* Size of the allocated payload area, including size before CHUNK_OFFSET. */
    ssize_t size;

    /* Since here, the memory is either the next free block, or data load. */
    struct malloc_chunk* next;
};

void* __libc_malloc_lock = NULL;                 /* OS mutex primitive, use libc_set_malloc_lock() to set it. */

static struct malloc_chunk* g_free_list  = NULL; /* List header of free blocks. */
static char*                g_sbrk_start = NULL; /* Starting point of memory allocated from system. */

#define CHUNK_OFFSET ((size_t)(&(((struct malloc_chunk*)0)->next)))

/* Size of smallest possible chunk. A memory piece smaller than this size won't be able to create a chunk. */
#define MALLOC_MINCHUNK (CHUNK_OFFSET + MALLOC_PADDING + MALLOC_MINSIZE)

#define MALLOC_LOCK                        \
    do {                                   \
        if (__libc_malloc_lock)            \
        {                                  \
            libc_lock(__libc_malloc_lock); \
        }                                  \
    } while (0)

#define MALLOC_UNLOCK                        \
    do {                                     \
        if (__libc_malloc_lock)              \
        {                                    \
            libc_unlock(__libc_malloc_lock); \
        }                                    \
    } while (0)

static inline struct malloc_chunk* get_chunk_from_ptr(void* ptr)
{
    /* Assume that there is no explicit padding in the chunk, and that the chunk starts at ptr - CHUNK_OFFSET. */
    struct malloc_chunk* c = (struct malloc_chunk*)((char*)ptr - CHUNK_OFFSET);

    /* c->size being negative indicates that there is explicit padding in the chunk.
     * In which case, c->size is currently the negative offset to the true size. */
    if (c->size < 0)
    {
        c = (struct malloc_chunk*)((char*)c + c->size);
    }

    return c;
}

static size_t get_usable_size(void* ptr)
{
    struct malloc_chunk* c              = (struct malloc_chunk*)((char*)ptr - CHUNK_OFFSET);
    int                  size_or_offset = c->size;

    if (size_or_offset < 0)
    {
        /* Padding is used. Excluding the padding size. */
        c = (struct malloc_chunk*)((char*)c + c->size);
        return c->size - CHUNK_OFFSET + size_or_offset;
    }

    return c->size - CHUNK_OFFSET;
}

/*
 * Use sbrk() to obtain more memory and ensure it is CHUNK_ALIGN aligned.
 * Optimise for the case that it is already aligned - only ask for extra padding after we know we need it.
 */
static void* sbrk_aligned(size_t s)
{
    char *p, *align_p;

    if (g_sbrk_start == NULL)
    {
        g_sbrk_start = sbrk(0);
    }

    p = sbrk(s);

    /* sbrk returns (-1) if fail to allocate */
    if (p == (void*)(-1))
    {
        return p;
    }

    align_p = (char*)ALIGN_PTR((uintptr_t)p, CHUNK_ALIGN);

    if (align_p != p)
    {
        /* p is not aligned, ask for a few more bytes so that we have s bytes reserved from align_p. */
        p = sbrk(align_p - p);

        if (p == (void*)(-1))
        {
            return p;
        }
    }

    return align_p;
}

/* Walk through the free list to find the first match. If fails to find one, call sbrk to allocate a new chunk. */
void* malloc(size_t s)
{
    struct malloc_chunk *p, *r;
    char *               ptr, *align_ptr;
    int                  offset;

    size_t alloc_size;

    alloc_size  = ALIGN_SIZE(s, CHUNK_ALIGN); /* Size of aligned data load. */
    alloc_size += MALLOC_PADDING;             /* Padding. */
    alloc_size += CHUNK_OFFSET;               /* Size of chunk head. */
    alloc_size  = MAX(alloc_size, MALLOC_MINCHUNK);

    if (alloc_size >= MAX_ALLOC_SIZE || alloc_size < s)
    {
        errno = ENOMEM;
        return NULL;
    }

    MALLOC_LOCK;

    p = g_free_list;
    r = p;

    while (r)
    {
        int rem = r->size - alloc_size;

        if (rem >= 0)
        {
            if (rem >= MALLOC_MINCHUNK)
            {
                if (p == r)
                {
                    /* First item in the list, break it into two chunks and return the first one. */
                    r->size           = alloc_size;
                    g_free_list       = (struct malloc_chunk*)((char*)r + alloc_size);
                    g_free_list->size = rem;
                    g_free_list->next = r->next;
                }
                else
                {
                    /* Any other item in the list. Split and return the first one. */
                    r->size       = alloc_size;
                    p->next       = (struct malloc_chunk*)((char*)r + alloc_size);
                    p->next->size = rem;
                    p->next->next = r->next;
                }
            }
            /* Find a chunk that is exactly the size or slightly bigger than requested size, just return this chunk. */
            else if (p == r)
            {
                /* Now it implies p==r==g_free_list. Move the g_free_list to next chunk. */
                g_free_list = r->next;
            }
            else
            {
                /* Normal case. Remove it from g_free_list. */
                p->next = r->next;
            }

            break;
        }

        p = r;
        r = r->next;
    }

    /* Failed to find a appropriate chunk. Ask for more memory. */
    if (r == NULL)
    {
        r = sbrk_aligned(alloc_size);

        /* sbrk returns -1 if fail to allocate. */
        if (r == (void*)(-1))
        {
            /* sbrk didn't have the requested amount. Let's check if the last item in the free list is adjacent to the
             * current heap end (sbrk(0)). In that case, only ask for the difference in size and merge them. */
            p = g_free_list;
            r = p;

            while (r)
            {
                p = r;
                r = r->next;
            }

            if (p != NULL && (char*)p + p->size == (char*)sbrk(0))
            {
                /* The last free item has the heap end as neighbour. Let's ask for a smaller amount and merge. */
                alloc_size -= p->size;

                if (sbrk_aligned(alloc_size) != (void*)(-1))
                {
                    p->size += alloc_size;

                    /* Remove chunk from g_free_list. Since p != NULL there is at least one chunk. */
                    r = g_free_list;

                    if (r->next == NULL)
                    {
                        /* There is only a single chunk, remove it. */
                        g_free_list = NULL;
                    }
                    else
                    {
                        /* Search for the chunk before the one to be removed. */
                        while (p != r->next) { r = r->next; }
                        r->next = NULL;
                    }

                    r = p;
                }
                else
                {
                    errno = ENOMEM;
                    MALLOC_UNLOCK;
                    return NULL;
                }
            }
            else
            {
                errno = ENOMEM;
                MALLOC_UNLOCK;
                return NULL;
            }
        }
        else
        {
            r->size = alloc_size;
        }
    }

    MALLOC_UNLOCK;

    ptr = (char*)r + CHUNK_OFFSET;

    align_ptr = (char*)ALIGN_PTR((uintptr_t)ptr, MALLOC_ALIGN);
    offset    = align_ptr - ptr;

    if (offset)
    {
        /* Initialize sizeof (malloc_chunk.size) bytes at align_ptr - CHUNK_OFFSET with negative offset to the
           size field (at the start of the chunk).

           The negative offset to size from align_ptr - CHUNK_OFFSET is the size of any remaining padding minus
           CHUNK_OFFSET. This is equivalent to the total size of the padding, because the size of any remaining padding
           is the total size of the padding minus CHUNK_OFFSET.

           Note that the size of the padding must be at least CHUNK_OFFSET.
           The rest of the padding is not initialized. */

        *(long*)((char*)r + offset) = -offset;
    }

    assert(align_ptr + s <= (char*)r + alloc_size);
    return align_ptr;
}

/*
 * Maintain a global free chunk single link list, headed by global variable g_free_list.
 * When free, insert the to-be-freed chunk into free list. The place to insert should make sure all chunks are sorted
 * by address from low to high. Then merge with neighbor chunks if adjacent.
 */
void free(void* free_p)
{
    struct malloc_chunk* p_to_free;
    struct malloc_chunk *p, *q;

    if (free_p == NULL)
    {
        return;
    }

    p_to_free = get_chunk_from_ptr(free_p);

    MALLOC_LOCK;

    if (g_free_list == NULL)
    {
        /* Set first free list element. */
        p_to_free->next = g_free_list;
        g_free_list     = p_to_free;
        MALLOC_UNLOCK;
        return;
    }

    if (p_to_free < g_free_list)
    {
        if ((char*)p_to_free + p_to_free->size == (char*)g_free_list)
        {
            /* Chunk to free is just before the first element of free list. */
            p_to_free->size += g_free_list->size;
            p_to_free->next  = g_free_list->next;
        }
        else
        {
            /* Insert before current g_free_list. */
            p_to_free->next = g_free_list;
        }

        g_free_list = p_to_free;
        MALLOC_UNLOCK;
        return;
    }

    q = g_free_list;

    /* Walk through the free list to find the place for insert. */
    do {
        p = q;
        q = q->next;
    } while (q && q <= p_to_free);

    /* Now p <= p_to_free and either q == NULL or q > p_to_free.
     * Try to merge with chunks immediately before/after it. */
    if ((char*)p + p->size == (char*)p_to_free)
    {
        /* Chunk to be freed is adjacent to a free chunk before it. */
        p->size += p_to_free->size;

        /* If the merged chunk is also adjacent to the chunk after it, merge again. */
        if ((char*)p + p->size == (char*)q)
        {
            p->size += q->size;
            p->next  = q->next;
        }
    }
#if MALLOC_CHECK_DOUBLE_FREE
    else if ((char*)p + p->size > (char*)p_to_free)
    {
        /* Report double free fault. */
        errno = ENOMEM;
        MALLOC_UNLOCK;
        return;
    }
#endif
    else if ((char*)p_to_free + p_to_free->size == (char*)q)
    {
        /* Chunk to be freed is adjacent to a free chunk after it. */
        p_to_free->size += q->size;
        p_to_free->next  = q->next;
        p->next          = p_to_free;
    }
    else
    {
        /* Not adjacent to any chunk. Just insert it. Resulting a fragment. */
        p_to_free->next = q;
        p->next         = p_to_free;
    }

    MALLOC_UNLOCK;
}

/* Implement calloc simply by calling malloc and set zero. */
void* calloc(size_t n, size_t elem)
{
    size_t bytes;
    void*  mem;

    if (__builtin_mul_overflow(n, elem, &bytes))
    {
        errno = ENOMEM;
        return NULL;
    }

    mem = malloc(bytes);

    if (mem != NULL)
    {
        memset(mem, 0, bytes);
    }

    return mem;
}

/* Implement realloc by malloc + memcpy. */
void* realloc(void* ptr, size_t size)
{
    void*  mem;
    size_t old_size;

    if (__predict_false(size == 0))
    {
        return NULL;
    }

    if (ptr == NULL)
    {
        return malloc(size);
    }

    old_size = get_usable_size(ptr);

    if (size <= old_size && (old_size >> 1) < size)
    {
        return ptr;
    }

    mem = malloc(size);

    if (__predict_true(mem != NULL))
    {
        if (old_size > size)
        {
            old_size = size;
        }

        memcpy(mem, ptr, old_size);
        free(ptr);
    }

    return mem;
}

/* Allocate memory block aligned at specific boundary.
 * align: required alignment. Must be power of 2. Return NULL if not power of 2.
 * Undefined behavior is bigger than pointer value range.
 * s: required size.
 * Return: allocated memory pointer aligned to align.
 * Algorithm: Malloc a big enough block, padding pointer to aligned address, then truncate and free the tail if too big.
 *            Record the offset of align pointer and original pointer in the padding area.
 */
void* aligned_alloc(size_t align, size_t s)
{
    struct malloc_chunk* chunk_p;
    size_t               size_allocated, offset, ma_size, size_with_padding;
    char *               allocated, *aligned_p;

    /* Return NULL if align isn't power of 2. */
    if ((align & (align - 1)) != 0)
    {
        return NULL;
    }

    align = MAX(align, MALLOC_ALIGN);

    /* Make sure ma_size does not overflow. */
    if (s > __SIZE_MAX__ - CHUNK_ALIGN)
    {
        errno = ENOMEM;
        return NULL;
    }

    ma_size = ALIGN_SIZE(MAX(s, MALLOC_MINSIZE), CHUNK_ALIGN);

    /* Make sure size_with_padding does not overflow. */
    if (ma_size > __SIZE_MAX__ - (align - MALLOC_ALIGN))
    {
        errno = ENOMEM;
        return NULL;
    }

    size_with_padding = ma_size + (align - MALLOC_ALIGN);

    allocated = malloc(size_with_padding);

    if (allocated == NULL)
    {
        return NULL;
    }

    chunk_p   = get_chunk_from_ptr(allocated);
    aligned_p = (char*)ALIGN_PTR((uintptr_t)((char*)chunk_p + CHUNK_OFFSET), (uintptr_t)align);
    offset    = aligned_p - ((char*)chunk_p + CHUNK_OFFSET);

    if (offset)
    {
        if (offset >= MALLOC_MINCHUNK)
        {
            /* Padding is too large, free it. */
            struct malloc_chunk* front_chunk = chunk_p;
            chunk_p                          = (struct malloc_chunk*)((char*)chunk_p + offset);
            chunk_p->size                    = front_chunk->size - offset;
            front_chunk->size                = offset;
            free((char*)front_chunk + CHUNK_OFFSET);
        }
        else
        {
            /* Padding is used. Need to set a jump offset for aligned pointer to get back to chunk head. */
            assert(offset >= sizeof(int));
            *(long*)((char*)chunk_p + offset) = -offset;
        }
    }

    size_allocated = chunk_p->size;

    if ((char*)chunk_p + size_allocated > (aligned_p + ma_size + MALLOC_MINCHUNK))
    {
        /* Allocated much more than what's required for padding, free tail part. */
        struct malloc_chunk* tail_chunk = (struct malloc_chunk*)(aligned_p + ma_size);
        chunk_p->size                   = aligned_p + ma_size - (char*)chunk_p;
        tail_chunk->size                = size_allocated - chunk_p->size;
        free((char*)tail_chunk + CHUNK_OFFSET);
    }

    return aligned_p;
}
