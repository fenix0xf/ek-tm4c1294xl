#include "time_impl.h"
#include <errno.h>

time_t mktime(struct tm* tm)
{
    struct tm _new;
    long      opp;
    long long t = __tm_to_secs(tm);

    __secs_to_zone(t, 1, &_new.tm_isdst, &_new.__tm_gmtoff, &opp, &_new.__tm_zone);

    if (tm->tm_isdst >= 0 && _new.tm_isdst != tm->tm_isdst)
    {
        t -= opp - _new.__tm_gmtoff;
    }

    t -= _new.__tm_gmtoff;
    if ((time_t)t != t)
    {
        goto error;
    }

    __secs_to_zone(t, 0, &_new.tm_isdst, &_new.__tm_gmtoff, &opp, &_new.__tm_zone);

    if (__secs_to_tm(t + _new.__tm_gmtoff, &_new) < 0)
    {
        goto error;
    }

    *tm = _new;
    return t;

error:
    errno = EOVERFLOW;
    return -1;
}
