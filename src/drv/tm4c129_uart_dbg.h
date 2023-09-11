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
#include <stdbool.h>

bool tm4c129_uart_dbg_fail_safe_init(void);
void tm4c129_uart_dbg_fail_safe_free(void);

intptr_t tm4c129_uart_dbg_fail_safe_puts(const char* s);
intptr_t tm4c129_uart_dbg_fail_safe_print(const char* s);
void     tm4c129_uart_dbg_fail_safe_send_buf(const void* buf, size_t size);
void     tm4c129_uart_dbg_fail_safe_send_byte(uint8_t b);
void     tm4c129_uart_dbg_fail_safe_flush(void);

bool tm4c129_uart_dbg_init(void);
bool tm4c129_uart_dbg_free(void);

intptr_t tm4c129_uart_dbg_puts(const char* s);
intptr_t tm4c129_uart_dbg_print(const char* s);
void     tm4c129_uart_dbg_send_buf(const void* buf, size_t size);
void     tm4c129_uart_dbg_send_byte(uint8_t b);
void     tm4c129_uart_dbg_flush(void);
