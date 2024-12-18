#include <strings.h>
#include <ctype.h>

int strncasecmp(const char* _l, const char* _r, size_t n)
{
    const unsigned char *l = (const unsigned char*)_l, *r = (const unsigned char*)_r;
    if (!n--)
    {
        return 0;
    }
    for (; *l && *r && n && (*l == *r || tolower(*l) == tolower(*r)); l++, r++, n--)
    {
    }
    return tolower(*l) - tolower(*r);
}
