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

#include <drv/tm4c129_uart_dbg.h>

#include <stdio.h>
#include <stdarg.h>

int hal_puts(const char* s)
{
    int ret = puts(s);
    fflush(stdout);
    return ret;
}

int hal_print(const char* s)
{
    int ch, chars = 0;

    while ((ch = *s++))
    {
        putc(ch, stdout);
        chars++;
    }

    fflush(stdout);
    return chars;
}

int hal_printf(const char* restrict fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int rc = vprintf(fmt, args);
    va_end(args);

    fflush(stdout);
    return rc;
}

#ifdef DEBUG

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

#endif // #ifdef DEBUG
