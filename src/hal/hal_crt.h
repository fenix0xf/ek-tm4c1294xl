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

#pragma once

#include <time.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

/**
 * The Red Hat newlib C Library initialization and syscalls implementation.
 *
 */

typedef void (*crt_stdout_func_t)(const void* buf, size_t size);

/**
 * C Runtime Library initialization.
 */
void crt_init(void);

void crt_stdout_func_set(crt_stdout_func_t stdout_func);

/**
 * ts_strtok() is the thread safe implementation of strtok() function.
 *
 * @param pssave is ts_strtok() internal state variable.
 *
 * @example
 * char* pssave; // Temp variable for save ts_strtok() internal state.
 * ts_strtok(str, delim, &pssave);
 * ts_strtok(NULL, delim, &pssave);
 */
char* ts_strtok(char* s1, const char* s2, char** pssave);