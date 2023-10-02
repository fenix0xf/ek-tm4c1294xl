#ifndef _UNISTD_H
#define _UNISTD_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <features.h>

#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#if __cplusplus >= 201103L
#define NULL nullptr
#elif defined(__cplusplus)
#define NULL 0L
#else
#define NULL ((void*)0)
#endif

#define __NEED_size_t
#define __NEED_ssize_t
#define __NEED_intptr_t

#include <bits/alltypes.h>

ssize_t read(int, void*, size_t);
ssize_t write(int, const void*, size_t);
void*   sbrk(intptr_t);

#ifdef __cplusplus
}
#endif

#endif
