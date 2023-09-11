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
#include <stdbool.h>

#include <inc/hw_ints.h>

/**
 * Interrupt priority definitions. The top 3 bits of these values are
 * significant with lower values indicating higher priority interrupts.
 *
 * Bit num: 7 6 5 4 3 2 1 0
 * Bit val: X X X - - - - -
 *
 * INT_PRI0 - highest priority.
 * INT_PRI7 - lowest priority.
 *
 */
enum tm4c129_int_pri {
    TM4C129_ISR_PRI0 = (0 << 5), /// 0x00, highest priority.
    TM4C129_ISR_PRI1 = (1 << 5), /// 0x20
    TM4C129_ISR_PRI2 = (2 << 5), /// 0x40
    TM4C129_ISR_PRI3 = (3 << 5), /// 0x60
    TM4C129_ISR_PRI4 = (4 << 5), /// 0x80
    TM4C129_ISR_PRI5 = (5 << 5), /// 0xA0
    TM4C129_ISR_PRI6 = (6 << 5), /// 0xC0
    TM4C129_ISR_PRI7 = (7 << 5)  /// 0xE0, lowest priority.
};

bool tm4c129_int_init(void);

/**
 * @param isr     - INT_XXX from <inc/hw_ints.h>.
 * @param handler - use NULL for unregister.
 */
bool tm4c129_int_register(size_t isr, void (*handler)(void));
bool tm4c129_int_pri_set(size_t isr, enum tm4c129_int_pri pri);
void tm4c129_int_nvic_enable(size_t isr);
void tm4c129_int_nvic_disable(size_t isr);
