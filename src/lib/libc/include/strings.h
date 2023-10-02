#ifndef _STRINGS_H
#define _STRINGS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <features.h>

#define __NEED_size_t
#include <bits/alltypes.h>

int strcasecmp(const char*, const char*);
int strncasecmp(const char*, const char*, size_t);

#ifdef __cplusplus
}
#endif

#endif
