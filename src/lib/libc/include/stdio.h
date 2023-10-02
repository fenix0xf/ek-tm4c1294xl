#ifndef _STDIO_H
#define _STDIO_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <features.h>

#define __NEED_FILE
#define __NEED___isoc_va_list
#define __NEED_size_t

#if __STDC_VERSION__ < 201112L
#define __NEED_struct__IO_FILE
#endif

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || \
    defined(_BSD_SOURCE)
#define __NEED_ssize_t
#define __NEED_off_t
#define __NEED_va_list
#endif

#include <bits/alltypes.h>

#if __cplusplus >= 201103L
#define NULL nullptr
#elif defined(__cplusplus)
#define NULL 0L
#else
#define NULL ((void*)0)
#endif

#undef EOF
#define EOF    (-1)

#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2

#define BUFSIZ 256

extern FILE* const stdin;
extern FILE* const stdout;
extern FILE* const stderr;

#define stdin  (stdin)
#define stdout (stdout)
#define stderr (stderr)

int  feof(FILE*);
int  ferror(FILE*);
int  fflush(FILE*);
void clearerr(FILE*);

size_t fread(void* __restrict, size_t, size_t, FILE* __restrict);
size_t fwrite(const void* __restrict, size_t, size_t, FILE* __restrict);

int fgetc(FILE*);
int getc(FILE*);
int getchar(void);
int ungetc(int, FILE*);

int fputc(int, FILE*);
int putc(int, FILE*);
int putchar(int);

char* fgets(char* __restrict, int, FILE* __restrict);
#if __STDC_VERSION__ < 201112L
char* gets(char*);
#endif

int fputs(const char* __restrict, FILE* __restrict);
int puts(const char*);

int printf(const char* __restrict, ...);
int fprintf(FILE* __restrict, const char* __restrict, ...);
int sprintf(char* __restrict, const char* __restrict, ...);
int snprintf(char* __restrict, size_t, const char* __restrict, ...);

int vprintf(const char* __restrict, __isoc_va_list);
int vfprintf(FILE* __restrict, const char* __restrict, __isoc_va_list);
int vsprintf(char* __restrict, const char* __restrict, __isoc_va_list);
int vsnprintf(char* __restrict, size_t, const char* __restrict, __isoc_va_list);

int scanf(const char* __restrict, ...);
int fscanf(FILE* __restrict, const char* __restrict, ...);
int sscanf(const char* __restrict, const char* __restrict, ...);
int vscanf(const char* __restrict, __isoc_va_list);
int vfscanf(FILE* __restrict, const char* __restrict, __isoc_va_list);
int vsscanf(const char* __restrict, const char* __restrict, __isoc_va_list);

void perror(const char*);

int  setvbuf(FILE* __restrict, char* __restrict, int, size_t);
void setbuf(FILE* __restrict, char* __restrict);

#ifdef __cplusplus
}
#endif

#endif
