#ifndef _STDIO_IMPL_H
#define _STDIO_IMPL_H

#include <stdio.h>

#define UNGET    8

#define FLOCK(f) int __need_unlock = (((f)->mutex == NULL) ? 0 : __lockfile((f)))
#define FUNLOCK(f)             \
    do {                       \
        if (__need_unlock)     \
            __unlockfile((f)); \
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
    void*          mutex;
    int            lbf;
    void*          cookie;
    unsigned char* shend;
    off_t          shlim, shcnt;
};

hidden int  __lockfile(FILE*);
hidden void __unlockfile(FILE*);

hidden size_t __stdio_read(FILE*, unsigned char*, size_t);
hidden size_t __stdio_write(FILE*, const unsigned char*, size_t);

hidden int __toread(FILE*);
hidden int __towrite(FILE*);

#if defined(__PIC__) && (100 * __GNUC__ + __GNUC_MINOR__ >= 303)
__attribute__((visibility("protected")))
#endif
int __overflow(FILE *, int), __uflow(FILE *);

hidden size_t __fwritex(const unsigned char*, size_t, FILE*);

#define feof(f)          ((f)->flags & F_EOF)
#define ferror(f)        ((f)->flags & F_ERR)

#define getc_unlocked(f) (((f)->rpos != (f)->rend) ? *(f)->rpos++ : __uflow((f)))

#define putc_unlocked(c, f)                                                                           \
    ((((unsigned char)(c) != (f)->lbf && (f)->wpos != (f)->wend)) ? *(f)->wpos++ = (unsigned char)(c) \
                                                                  : __overflow((f), (unsigned char)(c)))
#endif
