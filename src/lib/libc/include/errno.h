/*

 MIT License

 Copyright © 2023 Alexander Kotikov, alexandr.kotikov@gmail.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

 */

#ifndef _ERRNO_H
#define _ERRNO_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <features.h>

#if __STDC_VERSION__ >= 201112L && __STDC_VERSION__ < 202311L
#include <threads.h>
#endif

#include <bits/errno.h>

#ifndef __error_t_are_defined
#define __error_t_are_defined 1
typedef int error_t;
#endif

#if __STDC_VERSION__ >= 201112L
extern thread_local error_t __tls_errno;
#define errno (__tls_errno)
#else
extern error_t __errno;
#define errno (__errno)
#endif

#ifdef __cplusplus
}
#endif

#endif
