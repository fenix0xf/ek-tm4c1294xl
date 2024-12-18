#ifndef _STRING_H
#define _STRING_H

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
#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define __NEED_locale_t
#endif

#include <bits/alltypes.h>

void*  memcpy(void* __restrict, const void* __restrict, size_t);
void*  memmove(void*, const void*, size_t);
void*  memset(void*, int, size_t);
int    memcmp(const void*, const void*, size_t);
void*  memchr(const void*, int, size_t);

char*  strcpy(char* __restrict, const char* __restrict);
char*  strncpy(char* __restrict, const char* __restrict, size_t);

char*  strcat(char* __restrict, const char* __restrict);
char*  strncat(char* __restrict, const char* __restrict, size_t);

int    strcmp(const char*, const char*);
int    strncmp(const char*, const char*, size_t);

char*  strchr(const char*, int);
char*  strrchr(const char*, int);

size_t strcspn(const char*, const char*);
size_t strspn(const char*, const char*);
char*  strpbrk(const char*, const char*);
char*  strstr(const char*, const char*);
char*  strtok(char* __restrict, const char* __restrict);

size_t strlen(const char*);

char*  strerror(int);

#if defined(_BSD_SOURCE) || defined(_GNU_SOURCE)
#include <strings.h>
#endif

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
size_t strnlen(const char*, size_t);
#endif

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
void* memccpy(void* __restrict, const void* __restrict, int, size_t);
#endif

#ifdef __cplusplus
}
#endif

#endif
