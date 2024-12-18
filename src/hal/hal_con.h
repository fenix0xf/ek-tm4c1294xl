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

#include <stddef.h>
#include <stdint.h>
#include <hal/hal_def.h>

/*
 * stdout and stderr is used here, you should initialize C standard library low-level output first.
 */
int hal_puts(const char* s);
int hal_print(const char* s);
int hal_printf(const char* restrict fmt, ...);
int hal_eprintf(const char* restrict fmt, ...);
int hal_flush(void);

#define hal_error(s) hal_eprintf("ERROR: \"%s\" in %s(), " __FILE__ ":" HAL_STFN(__LINE__) "\n", (s), __func__)
#define hal_errorf(fmt, ...) \
    hal_eprintf("ERROR: \"" fmt "\" in %s(), " __FILE__ ":" HAL_STFN(__LINE__) "\n" __VA_OPT__(, ) __VA_ARGS__, __func__)

/*
 * Output for debug builds.
 */
#if DEBUG
#define hal_dbg_trace() hal_printf("TRACE: %s(), " __FILE__ ":" HAL_STFN(__LINE__) "\n", __func__)
#define hal_dbg_puts(s) hal_printf("DEBUG: \"%s\", %s(), " __FILE__ ":" HAL_STFN(__LINE__) "\n", (s), __func__)
#define hal_dbg_puts_fmt(fmt, ...) \
    hal_printf("DEBUG: \"" fmt "\" in %s(), " __FILE__ ":" HAL_STFN(__LINE__) "\n" __VA_OPT__(, ) __VA_ARGS__, __func__)
void hal_dbg_printbuf(const void* buf, size_t size);
#else
#define hal_dbg_trace()
#define hal_dbg_puts(s)
#define hal_dbg_puts_fmt(...)
#define hal_dbg_printbuf(buf, size)
#endif /* DEBUG */
