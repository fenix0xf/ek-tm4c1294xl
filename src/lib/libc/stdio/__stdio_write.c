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
