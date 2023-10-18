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
