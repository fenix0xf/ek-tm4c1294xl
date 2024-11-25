#ifndef _STDIO_IMPL_H
#define _STDIO_IMPL_H

#include <libc.h>
#include <stdio.h>

#define UNGET    8

#define FLOCK(f) int __need_unlock = (__predict_false((f)->lock == NULL) ? 0 : libc_lock((f)->lock))
#define FUNLOCK(f)                         \
    do {                                   \
        if (__predict_true(__need_unlock)) \
        {                                  \
            libc_unlock((f)->lock);        \
        }                                  \
    } while (0)

#define F_PERM 1
#define F_NORD 4
#define F_NOWR 8
#define F_EOF  16
#define F_ERR  32
#define F_SVB  64

struct _IO_FILE
{
    unsigned int   flags;
    unsigned char *rpos, *rend;
    unsigned char *wend, *wpos;
    unsigned char* wbase;
    size_t (*read)(FILE*, unsigned char*, size_t);
    size_t (*write)(FILE*, const unsigned char*, size_t);
    unsigned char* buf;
    size_t         buf_size;
    int            fd;
    int            mode;
    void*          lock;
    int            lbf;
    void*          cookie;
    unsigned char* shend;
    off_t          shlim, shcnt;
};

size_t __stdio_read(FILE*, unsigned char*, size_t);
size_t __stdio_write(FILE*, const unsigned char*, size_t);

int    __toread(FILE*);
int    __towrite(FILE*);
int    __overflow(FILE*, int);
int    __uflow(FILE*);

size_t __fwritex(const unsigned char*, size_t, FILE*);

#define feof(f)          ((f)->flags & F_EOF)
#define ferror(f)        ((f)->flags & F_ERR)

#define getc_unlocked(f) (((f)->rpos != (f)->rend) ? *(f)->rpos++ : __uflow((f)))

#define putc_unlocked(c, f) \
    ((((unsigned char)(c) != (f)->lbf && (f)->wpos != (f)->wend)) ? *(f)->wpos++ = (unsigned char)(c) : __overflow((f), (unsigned char)(c)))
#endif
