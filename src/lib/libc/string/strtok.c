#include <string.h>

#if __STDC_VERSION__ >= 201112L && __STDC_VERSION__ < 202311L
#include <threads.h>
#endif

#if __STDC_VERSION__ >= 201112L
static thread_local char* __tls_p;
#else
static char* __tls_p;
#endif

char* strtok(char* __restrict s, const char* __restrict sep)
{
    char* p = __tls_p;

    if (!s && !(s = p))
    {
        return NULL;
    }

    s += strspn(s, sep);

    if (!*s)
    {
        return p = 0;
    }

    p = s + strcspn(s, sep);

    if (*p)
    {
        *p++ = 0;
    }
    else
    {
        p = 0;
    }

    return s;
}
