#include <stdlib.h>

void* bsearch(const void* key, const void* base, size_t nel, size_t width, int (*cmp)(const void*, const void*))
{
    void* _try;
    int   sign;
    while (nel > 0)
    {
        _try = (char*)base + width * (nel / 2);
        sign = cmp(key, _try);
        if (sign < 0)
        {
            nel /= 2;
        }
        else if (sign > 0)
        {
            base  = (char*)_try + width;
            nel  -= nel / 2 + 1;
        }
        else
        {
            return _try;
        }
    }
    return NULL;
}
