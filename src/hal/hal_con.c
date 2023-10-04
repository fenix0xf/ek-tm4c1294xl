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

#include "hal_con.h"

#include <hal/hal.h>
#include <drv/tm4c129_uart_dbg.h>

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#define STDIO_ERR_PREFIX "\nSTDIO ERR: "

static void __stdio_halt(const char* func, const char* msg)
{
    error_t err = errno;
    char    s[ITOA_BUFSIZ];

    hal_mcu_int_off();
    tm4c129_uart_dbg_fail_safe_init();

    tm4c129_uart_dbg_fail_safe_print(STDIO_ERR_PREFIX);
    tm4c129_uart_dbg_fail_safe_print(func);
    tm4c129_uart_dbg_fail_safe_print(", \"");

    if (msg && *msg)
    {
        size_t end   = strlen(msg) - 1;
        bool   end_n = msg[end] == '\n';

        tm4c129_uart_dbg_fail_safe_send_buf(msg, end_n ? end : end + 1);

        if (end_n)
        {
            tm4c129_uart_dbg_fail_safe_print("\\n");
        }
    }

    tm4c129_uart_dbg_fail_safe_print("\", errno=");
    tm4c129_uart_dbg_fail_safe_puts(itoa((int)err, s, 10));
    hal_mcu_halt();
}

int hal_puts(const char* s)
{
    int rc = puts(s);

    if (HAL_UNLIKELY(rc < 0))
    {
        goto halt;
    }

    if (HAL_UNLIKELY(fflush(stdout) < 0))
    {
        goto halt;
    }

    if (0)
    {
halt:
        __stdio_halt("hal_puts()", s);
    }

    return rc;
}

int hal_print(const char* s)
{
    int rc = fputs(s, stdout);

    if (HAL_UNLIKELY(rc < 0))
    {
        goto halt;
    }

    if (HAL_UNLIKELY(fflush(stdout) < 0))
    {
        goto halt;
    }

    if (0)
    {
halt:
        __stdio_halt("hal_print()", s);
    }

    return rc;
}

int hal_printf(const char* restrict fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int rc = vprintf(fmt, args);
    va_end(args);

    if (HAL_UNLIKELY(rc < 0))
    {
        goto halt;
    }

    if (HAL_UNLIKELY(fflush(stdout) < 0))
    {
        goto halt;
    }

    if (0)
    {
halt:
        __stdio_halt("hal_printf()", fmt);
    }

    return rc;
}

#if DEBUG
void hal_dbg_printbuf(const void* buf, size_t size)
{
    enum {
        COLUMNS_PER_LINE = 16,
    };

    hal_printf("Buffer data (addr: 0x%08X, size: %u):\n", buf, (unsigned)size);

    if ((buf == NULL) || (size == 0))
    {
        hal_puts("<<No data>>");
        return;
    }

    const uint8_t* p = (uint8_t*)buf;

    for (size_t i = 0; i < size; i++)
    {
        hal_printf("%02X", (unsigned)p[i]);

        if (((i + 1) % COLUMNS_PER_LINE) == 0)
        {
            hal_printf("\n");
        }
    }

    hal_printf("\n");
}
#endif /* DEBUG */
