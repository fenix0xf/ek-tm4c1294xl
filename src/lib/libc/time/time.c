#include <time.h>

time_t time(time_t* t)
{
    struct timespec ts = {.tv_sec = 0};
    //    __clock_gettime(CLOCK_REALTIME, &ts);
    if (t)
    {
        *t = ts.tv_sec;
    }
    return ts.tv_sec;
}
