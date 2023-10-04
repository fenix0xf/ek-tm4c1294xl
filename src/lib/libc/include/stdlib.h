#ifndef _STDLIB_H
#define _STDLIB_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <features.h>

#if __cplusplus >= 201103L
#define NULL nullptr
#elif defined(__cplusplus)
#define NULL 0L
#else
#define NULL ((void*)0)
#endif

#define __NEED_size_t
#define __NEED_wchar_t

#include <bits/alltypes.h>

int       atoi(const char*);
long      atol(const char*);
long long atoll(const char*);
double    atof(const char*);

#define ITOA_BUFSIZ (sizeof(int) * 8 + 1) /* non-ANSI */

char* itoa(int, char*, int);              /* non-ANSI */
char* utoa(unsigned int, char*, int);     /* non-ANSI */

float       strtof(const char* __restrict, char** __restrict);
double      strtod(const char* __restrict, char** __restrict);
long double strtold(const char* __restrict, char** __restrict);

long               strtol(const char* __restrict, char** __restrict, int);
unsigned long      strtoul(const char* __restrict, char** __restrict, int);
long long          strtoll(const char* __restrict, char** __restrict, int);
unsigned long long strtoull(const char* __restrict, char** __restrict, int);

int  rand(void);
void srand(unsigned);

void* malloc(size_t);
void* calloc(size_t, size_t);
void* realloc(void*, size_t);
void  free(void*);
void* aligned_alloc(size_t, size_t);

_Noreturn void abort(void);
_Noreturn void _Exit(int);

void* bsearch(const void*, const void*, size_t, size_t, int (*)(const void*, const void*));
void  qsort(void*, size_t, size_t, int (*)(const void*, const void*));

int       abs(int);
long      labs(long);
long long llabs(long long);

typedef struct
{
    int quot, rem;
} div_t;

typedef struct
{
    long quot, rem;
} ldiv_t;

typedef struct
{
    long long quot, rem;
} lldiv_t;

div_t   div(int, int);
ldiv_t  ldiv(long, long);
lldiv_t lldiv(long long, long long);

#define RAND_MAX (0x7fffffff)

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#include <alloca.h>
#endif

#ifdef __cplusplus
}
#endif

#endif
