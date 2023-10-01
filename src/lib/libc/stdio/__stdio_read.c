#include "stdio_impl.h"

#include <unistd.h>

/* This function assumes it will never be called with buf == NULL or len == 0. */

size_t __stdio_read(FILE* f, unsigned char* buf, size_t len)
{
    ssize_t cnt  = 0;
    size_t  olen = len - !!f->buf_size; /* Optimization for buffered mode and len == 1. */

    if (olen)
    {
        cnt = read(f->fd, buf, olen);

        if (cnt <= 0)
        {
            f->flags |= cnt ? F_ERR : F_EOF;
            return 0;
        }

        if (!f->buf_size)
        {
            /* No stream buffering, olen == len. Just return cnt. */
            return cnt;
        }

        /* Buffered mode, (olen == len-1). */
        if (cnt < olen)
        {
            /* No more data in the input stream, the second read is not necessary. */
            return cnt;
        }

        /* Buffered mode and (cnt == olen == len-1). Need to try to fill the buffer. */
    }

    /* Buffered mode, (len == 1) or (cnt == len-1). */
    ssize_t cntb = read(f->fd, f->buf, f->buf_size);

    if (cntb <= 0)
    {
        if (cnt)
        {
            /* The second read has failed, return cnt from the first successful read. */
            return cnt;
        }

        /* This was the first reading, do the standard errors processing. */
        f->flags |= cntb ? F_ERR : F_EOF;
        return 0;
    }

    f->rpos      = f->buf;
    f->rend      = f->buf + cntb;
    buf[len - 1] = *f->rpos++;

    return len;
}
