#ifndef _LIMITS_H
#define _LIMITS_H

#include <features.h>

#include <bits/alltypes.h> /* __LONG_MAX */

/* Support signed or unsigned plain-char */

#if '\xff' > 0
#define CHAR_MIN 0
#define CHAR_MAX 255
#else
#define CHAR_MIN (-128)
#define CHAR_MAX 127
#endif

#define CHAR_BIT   8
#define SCHAR_MIN  (-128)
#define SCHAR_MAX  127
#define UCHAR_MAX  255
#define SHRT_MIN   (-1 - 0x7fff)
#define SHRT_MAX   0x7fff
#define USHRT_MAX  0xffff
#define INT_MIN    (-1 - 0x7fffffff)
#define INT_MAX    0x7fffffff
#define UINT_MAX   0xffffffffU
#define LONG_MIN   (-LONG_MAX - 1)
#define LONG_MAX   __LONG_MAX
#define ULONG_MAX  (2UL * LONG_MAX + 1)
#define LLONG_MIN  (-LLONG_MAX - 1)
#define LLONG_MAX  0x7fffffffffffffffLL
#define ULLONG_MAX (2ULL * LLONG_MAX + 1)

#define MB_LEN_MAX 4

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)

#include <bits/limits.h>

#define PIPE_BUF     4096
#define FILESIZEBITS 64
#ifndef NAME_MAX
#define NAME_MAX 255
#endif
#define PATH_MAX      4096
#define NGROUPS_MAX   32
#define ARG_MAX       131072
#define IOV_MAX       1024
#define SYMLOOP_MAX   40
#define WORD_BIT      32
#define SSIZE_MAX     LONG_MAX
#define TZNAME_MAX    6
#define TTY_NAME_MAX  32
#define HOST_NAME_MAX 255

#if LONG_MAX == 0x7fffffffL
#define LONG_BIT 32
#else
#define LONG_BIT 64
#endif

/* Implementation choices... */

#define PTHREAD_KEYS_MAX              128
#define PTHREAD_STACK_MIN             2048
#define PTHREAD_DESTRUCTOR_ITERATIONS 4
#define SEM_VALUE_MAX                 0x7fffffff
#define SEM_NSEMS_MAX                 256
#define DELAYTIMER_MAX                0x7fffffff
#define MQ_PRIO_MAX                   32768
#define LOGIN_NAME_MAX                256

/* Arbitrary numbers... */

#define BC_BASE_MAX                   99
#define BC_DIM_MAX                    2048
#define BC_SCALE_MAX                  99
#define BC_STRING_MAX                 1000
#define CHARCLASS_NAME_MAX            14
#define COLL_WEIGHTS_MAX              2
#define EXPR_NEST_MAX                 32
#define LINE_MAX                      4096
#define RE_DUP_MAX                    255

#define NL_ARGMAX                     9
#define NL_MSGMAX                     32767
#define NL_SETMAX                     255
#define NL_TEXTMAX                    2048

#endif

#endif /* _LIMITS_H */
