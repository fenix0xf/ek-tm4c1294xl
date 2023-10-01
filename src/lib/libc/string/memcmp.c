#include <string.h>

int memcmp(const void* vl, const void* vr, size_t n)
{
    const unsigned char *l = (const unsigned char*)vl, *r = (const unsigned char*)vr;
    for (; n && *l == *r; n--, l++, r++) {}

    return n ? *l - *r : 0;
}
