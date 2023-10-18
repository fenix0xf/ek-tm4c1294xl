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

#include <stddef.h>
#include <unistd.h>

size_t __stdio_write(FILE* f, const unsigned char* buf, size_t len)
{
    /* Step 1 - Write the file buffer. */
    ptrdiff_t vbuf_len = f->wpos - f->wbase;

    if (vbuf_len > 0)
    {
        unsigned char* vbuf = f->wbase;

        for (;;)
        {
            ssize_t cnt = write(f->fd, vbuf, (size_t)vbuf_len);

            if (cnt == (ssize_t)vbuf_len)
            {
                break;
            }

            if (cnt < 0)
            {
                f->wpos = f->wbase = f->wend  = 0;
                f->flags                     |= F_ERR;
                return 0;
            }

            vbuf     += cnt;
            vbuf_len -= cnt;
        }
    }

    /* Step 2 - Write current buf data. */
    size_t buf_len = len;

    for (;;)
    {
        ssize_t cnt = write(f->fd, buf, buf_len);

        if (cnt == (ssize_t)buf_len)
        {
            break;
        }

        if (cnt < 0)
        {
            f->wpos = f->wbase = f->wend  = 0;
            f->flags                     |= F_ERR;
            return len - buf_len;
        }

        buf     += cnt;
        buf_len -= cnt;
    }

    /* Activate write through the file buffer. */
    f->wpos = f->wbase = f->buf;
    f->wend            = f->buf + f->buf_size;
    return len;
}
