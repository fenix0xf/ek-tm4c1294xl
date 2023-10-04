#include "stdio_impl.h"
#include <string.h>

static size_t string_read(FILE* f, unsigned char* buf, size_t len)
{
    char*  src = (char*)f->cookie;
    size_t k   = len + 256;
    char*  end = (char*)memchr(src, 0, k);
    if (end)
    {
        k = end - src;
    }
    if (k < len)
    {
        len = k;
    }
    memcpy(buf, src, len);
    f->rpos   = (unsigned char*)(src + len);
    f->rend   = (unsigned char*)(src + k);
    f->cookie = src + k;
    return len;
}

int vsscanf(const char* restrict s, const char* restrict fmt, va_list ap)
{
    FILE f = {.buf = (unsigned char*)s, .cookie = (void*)s, .read = string_read, .lock = NULL};
    return vfscanf(&f, fmt, ap);
}
