/*

 MIT License

 Copyright © 2023 Alexander Kotikov, alexandr.kotikov@gmail.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

*/

#include "hal_tls.h"

#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include <hal/hal_con.h>
#include <tn.h>

#if HAL_TLS_IS_SUPPORTED

#define TLS_DEBUG             0
#define TLS_PREFIX            "TLS: "

#define HAL_TLS_BITSET(a, b)  HAL_BITSET(a, b, HAL_TLS_BS_SLOT_BIT)
#define HAL_TLS_BITTEST(a, b) HAL_BITTEST(a, b, HAL_TLS_BS_SLOT_BIT)

static size_t               g_tls_items_count;
static struct hal_tls_block g_system_tls_block;

typedef unsigned int word __attribute__((mode(word)));
typedef unsigned int pointer __attribute__((mode(pointer)));

#define POINTER_BIT   (sizeof(pointer) * CHAR_BIT)

#define TLS_VALID_BIT 1
#define TLS_INDEX_BIT (POINTER_BIT - TLS_VALID_BIT)
#define TLS_INDEX_MAX ((pointer) ~(1u << TLS_INDEX_BIT))

static_assert(HAL_TLS_MAX_ITEMS <= TLS_INDEX_MAX, "HAL_TLS_MAX_ITEMS is invalid!");

typedef struct tls_index
{
    pointer val: TLS_INDEX_BIT;
    pointer is_valid: TLS_VALID_BIT;
} tls_index_t;

static_assert(sizeof(tls_index_t) == sizeof(pointer), "Invalid tls_index_t size!");

struct __emutls_object
{
    word size;
    word align;

    union
    {
        pointer     offset;
        void*       ptr;
        tls_index_t idx;
    } loc;

    void* templ;
};

HAL_INLINE bool is_system_ctx(void)
{
    /// if tn_system_is_running() == 1 then tn_curr_run_task is guaranteed not to be NULL.
    return hal_mcu_inside_int() || !tn_system_is_running();
}

HAL_INLINE struct hal_tls_block* get_tls_block(bool system_block)
{
    return HAL_UNLIKELY(system_block) ? &g_system_tls_block : (struct hal_tls_block*)tn_curr_run_task->tls_block;
}

HAL_INLINE bool tls_item_is_valid(struct hal_tls_block* tls_block, struct __emutls_object* obj)
{
    return HAL_TLS_BITTEST(tls_block->bitset, obj->loc.idx.val) != 0;
}

HAL_INLINE void* tls_item_get(struct hal_tls_block* tls_block, struct __emutls_object* obj)
{
    return &tls_block->items[obj->loc.idx.val];
}

HAL_INLINE void* tls_item_copy(struct hal_tls_block* tls_block, struct __emutls_object* obj)
{
    void* ptr = &tls_block->items[obj->loc.idx.val];

    if (HAL_UNLIKELY(obj->templ != NULL))
    {
        memcpy(ptr, obj->templ, obj->size);
    }
    else
    {
        memset(ptr, 0, obj->size);
    }

    HAL_TLS_BITSET(tls_block->bitset, obj->loc.idx.val);

    return ptr;
}

/**
 * @brief Replacement of weak GCC function __emutls_get_address() to intercept access to TLS variables.
 *
 */
void* __emutls_get_address(struct __emutls_object* obj)
{
    bool is_sys_ctx = is_system_ctx();

    struct hal_tls_block* tls_block = get_tls_block(is_sys_ctx);

    if (HAL_UNLIKELY(tls_block == NULL))
    {
        hal_errorf(TLS_PREFIX "%s%s TLS block is not set!",
                   is_sys_ctx ? "System" : "Task ",
                   is_sys_ctx ? "" : tn_curr_run_task->task_name);

        hal_mcu_halt();
    }

    if (HAL_LIKELY(obj->loc.idx.is_valid))
    {
        return tls_item_is_valid(tls_block, obj) ? tls_item_get(tls_block, obj) : tls_item_copy(tls_block, obj);
    }

#if TLS_DEBUG
    hal_printf(TLS_PREFIX "%s%s TLS alloc: size %u, align %u, templ 0x%08X\n",
               is_sys_ctx ? "System" : "Task ",
               is_sys_ctx ? "" : tn_curr_run_task->task_name,
               obj->size,
               obj->align,
               obj->templ);
#endif

    if (HAL_UNLIKELY(obj->size > sizeof(hal_tls_item_t)))
    {
        hal_errorf(TLS_PREFIX "%s%s - TLS item size %u is not supported, max %u bytes!",
                   is_sys_ctx ? "System" : "Task ",
                   is_sys_ctx ? "" : tn_curr_run_task->task_name,
                   obj->size,
                   sizeof(hal_tls_item_t));

        hal_mcu_halt();
    }

    if (HAL_UNLIKELY((obj->align < obj->size) || (obj->align > sizeof(hal_tls_item_t))))
    {
        hal_errorf(TLS_PREFIX "%s%s - TLS item align %u is not supported!",
                   is_sys_ctx ? "System" : "Task ",
                   is_sys_ctx ? "" : tn_curr_run_task->task_name,
                   obj->align);

        hal_mcu_halt();
    }

    if (HAL_UNLIKELY(g_tls_items_count >= HAL_TLS_MAX_ITEMS))
    {
        hal_errorf(TLS_PREFIX "%s%s TLS block overflow, max items count is %u!",
                   is_sys_ctx ? "System" : "Task ",
                   is_sys_ctx ? "" : tn_curr_run_task->task_name,
                   HAL_TLS_MAX_ITEMS);

        hal_mcu_halt();
    }

    hal_cr_sect_enter();

    obj->loc.idx.is_valid = 1;
    obj->loc.idx.val      = g_tls_items_count++ & TLS_INDEX_MAX;

    hal_cr_sect_leave();

    if (tls_item_is_valid(tls_block, obj))
    {
        hal_errorf(TLS_PREFIX "%s%s TLS block is in wrong state!",
                   is_sys_ctx ? "System" : "Task ",
                   is_sys_ctx ? "" : tn_curr_run_task->task_name);

        hal_mcu_halt();
    }

    return tls_item_copy(tls_block, obj);
}

#endif // #if HAL_TLS_IS_SUPPORTED
