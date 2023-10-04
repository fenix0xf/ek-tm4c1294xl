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

#include <hal/hal_def.h>

#include <string.h>

#define HAL_INIT_MSG_LEN 40

#define HAL_INIT_ASSERT(msg, init_func)                   \
    do {                                                  \
        const char* m = msg;                              \
        size_t      l = strlen(m);                        \
        int         p = HAL_INIT_MSG_LEN - (int)l;        \
        hal_print(m);                                     \
        if (init_func)                                    \
        {                                                 \
            hal_printf("%*s\n", p > 0 ? p : 0, "[done]"); \
        }                                                 \
        else                                              \
        {                                                 \
            hal_error(HAL_STFN(init_func));               \
            hal_mcu_halt();                               \
        }                                                 \
    } while (0)

/* HAL initialization function. Used as reset ISR handler. */
HAL_USED HAL_NORETURN void hal_init(void);
