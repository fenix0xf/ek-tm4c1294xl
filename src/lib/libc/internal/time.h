#ifndef TIME_H
#define TIME_H

#include "../../include/time.h"

int __clock_gettime(clockid_t, struct timespec*);
int __clock_nanosleep(clockid_t, int, const struct timespec*, struct timespec*);

char*      __asctime_r(const struct tm*, char*);
struct tm* __gmtime_r(const time_t* restrict, struct tm* restrict);
struct tm* __localtime_r(const time_t* restrict, struct tm* restrict);

#endif
