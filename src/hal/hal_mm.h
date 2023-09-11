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

#include <inc/hw_ints.h>

/**
 * Memory Map
 *
 * In release build first of 32 KiB flash memory used for bootloader.
 * In debug build bootloader is not used.
 * Next block of 240 KiB of flash memory used for common firmware.
 * Second block of 240 KiB of flash memory used as temporary buffer for firmware updates.
 * Total used only 1024 KiB on chip flash memory.
 *
 */

#define MM_VTABLE_SP_NUM 1                                   ///< First item in ISR table is initial stack pointer.

#define MM_VTABLE_ALIGN  1024                                ///< ISR table align: 1024 for TM4C1294NCPDT.
#define MM_VTABLE_ITEMS  (MM_VTABLE_SP_NUM + NUM_INTERRUPTS) ///< ISR table items number: 130 for TM4C1294NCPDT.
#define MM_VTABLE_ISIZE  sizeof(void*)                       ///< ISR table item size: 4 bytes.
#define MM_VTABLE_SIZE   (MM_VTABLE_ITEMS * MM_VTABLE_ISIZE) ///< ISR table size: 130 * 4 = 520 bytes (0x208).
