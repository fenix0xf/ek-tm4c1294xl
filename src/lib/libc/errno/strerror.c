#include <errno.h>
#include <stddef.h>
#include <string.h>

#define SUPPORT_STRERROR 0

#if SUPPORT_STRERROR
static const struct errmsgstr_t
{
#define E(n, s) char str##n[sizeof(s)];
#include "__strerror.h"
#undef E
} errmsgstr = {

#define E(n, s) s,
#include "__strerror.h"
#undef E
};

static const unsigned short errmsgidx[] = {
#define E(n, s) [n] = offsetof(struct errmsgstr_t, str##n),
#include "__strerror.h"
#undef E
};
#endif /* SUPPORT_STRERROR */

char* strerror(int e)
{
#if SUPPORT_STRERROR
    const char* s;

    if (e >= sizeof errmsgidx / sizeof *errmsgidx)
    {
        e = 0;
    }

    s = (char*)&errmsgstr + errmsgidx[e];

    return (char*)s;
#else  /* SUPPORT_STRERROR */
    (void)e;

    return "strerror() is not supported";
#endif /* SUPPORT_STRERROR */
}
