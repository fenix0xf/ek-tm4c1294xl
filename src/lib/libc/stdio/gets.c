#include "stdio_impl.h"
#include <limits.h>
#include <string.h>

#if __STDC_VERSION__ < 201112L
char* gets(char* s)
{
    size_t i = 0;
    int    c;

    FLOCK(stdin);

    while ((c = getc_unlocked(stdin)) != EOF && c != '\n')
    {
        s[i++] = c;
    }

    s[i] = 0;

    if (c != '\n' && (!feof(stdin) || !i))
    {
        s = 0;
    }

    FUNLOCK(stdin);
    return s;
}
#endif /* __STDC_VERSION__ < 201112L */
