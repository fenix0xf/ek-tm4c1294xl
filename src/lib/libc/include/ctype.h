#ifndef _CTYPE_H
#define _CTYPE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <features.h>

static __inline int isalpha(int c)
{
    return ((unsigned)c | 32) - 'a' < 26;
}

static __inline int isblank(int c)
{
    return (c == ' ' || c == '\t');
}

static __inline int iscntrl(int c)
{
    return (unsigned)c < 0x20 || c == 0x7f;
}

static __inline int isdigit(int c)
{
    return (unsigned)c - '0' < 10;
}

static __inline int isalnum(int c)
{
    return isalpha(c) || isdigit(c);
}

static __inline int isgraph(int c)
{
    return (unsigned)c - 0x21 < 0x5e;
}

static __inline int islower(int c)
{
    return (unsigned)c - 'a' < 26;
}

static __inline int isprint(int c)
{
    return (unsigned)c - 0x20 < 0x5f;
}

static __inline int ispunct(int c)
{
    return isgraph(c) && !isalnum(c);
}

static __inline int isspace(int c)
{
    return c == ' ' || (unsigned)c - '\t' < 5;
}

static __inline int isupper(int c)
{
    return (unsigned)c - 'A' < 26;
}

static __inline int isxdigit(int c)
{
    return isdigit(c) || ((unsigned)c | 32) - 'a' < 6;
}

static __inline int tolower(int c)
{
    if (isupper(c))
    {
        return c | 32;
    }

    return c;
}

static __inline int toupper(int c)
{
    if (islower(c))
    {
        return c & 0x5f;
    }

    return c;
}

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)

static __inline int isascii(int c)
{
    return !(c & ~0x7f);
}

static __inline int toascii(int c)
{
    return c & 0x7f;
}

#endif

#ifdef __cplusplus
}
#endif

#endif /* _CTYPE_H */
