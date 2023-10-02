#include <string.h>
#include <stdint.h>
#include <limits.h>

#define ALIGN      (sizeof(size_t))
#define ONES       ((size_t)-1 / UCHAR_MAX)
#define HIGHS      (ONES * (UCHAR_MAX / 2 + 1))
#define HASZERO(x) ((x)-ONES & ~(x)&HIGHS)

char* strcpy(char* restrict dest, const char* restrict src)
{
#ifdef __GNUC__
    typedef size_t __attribute__((__may_alias__)) word;
    word*       wd;
    const word* ws;

    if ((uintptr_t)src % ALIGN == (uintptr_t)dest % ALIGN)
    {
        for (; (uintptr_t)src % ALIGN; src++, dest++)
        {
            if (!(*dest = *src))
            {
                return dest;
            }
        }

        wd = (word*)dest;
        ws = (const word*)src;

        for (; !HASZERO(*ws); *wd++ = *ws++) {}

        dest = (char*)wd;
        src  = (const char*)ws;
    }
#endif
    for (; (*dest = *src); src++, dest++) {}

    return dest;
}
