#include <string.h>
#include <stdint.h>
#include <limits.h>

#define ALIGN      (sizeof(size_t))
#define ONES       ((size_t)-1 / UCHAR_MAX)
#define HIGHS      (ONES * (UCHAR_MAX / 2 + 1))
#define HASZERO(x) ((x)-ONES & ~(x)&HIGHS)

char* __stpcpy(char* restrict d, const char* restrict s)
{
#ifdef __GNUC__
    typedef size_t __attribute__((__may_alias__)) word;
    word*       wd;
    const word* ws;
    if ((uintptr_t)s % ALIGN == (uintptr_t)d % ALIGN)
    {
        for (; (uintptr_t)s % ALIGN; s++, d++)
        {
            if (!(*d = *s))
            {
                return d;
            }
        }
        wd = (word*)d;
        ws = (const word*)s;
        for (; !HASZERO(*ws); *wd++ = *ws++) {}

        d = (char*)wd;
        s = (const char*)ws;
    }
#endif
    for (; (*d = *s); s++, d++)
        ;

    return d;
}

weak_alias(__stpcpy, stpcpy);
