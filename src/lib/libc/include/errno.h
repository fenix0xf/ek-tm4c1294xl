#ifndef _ERRNO_H
#define _ERRNO_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <features.h>

#include <threads.h>

#include <bits/errno.h>

#ifndef __error_t_defined
typedef int error_t;
#define __error_t_defined 1
#endif

extern thread_local error_t __tls_errno;

#define errno (__tls_errno)

#ifdef __cplusplus
}
#endif

#endif
