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

/**
 * Driver interface functions.
 *
 */

/**
 * Initialize TM4C129 internal flash memory.
 */
bool tm4c129_flash_init(void);

size_t tm4c129_flash_size(void);
size_t tm4c129_flash_align(void);
size_t tm4c129_flash_ealign(void);

/**
 * @param block_addr - must be a multiple of tm4c129_flash_sect_size().
 */
bool tm4c129_flash_erase(uintptr_t block_addr);

/**
 * @param addr - must be a multiple of tm4c129_flash_align().
 * @param len  - must be a multiple of tm4c129_flash_align().
 */
bool tm4c129_flash_write(uintptr_t addr, const void* buf, size_t len);

/**
 * @param addr - must be a multiple of tm4c129_flash_align().
 * @param len  - must be a multiple of tm4c129_flash_align().
 */
bool tm4c129_flash_compare(uintptr_t addr, const void* buf, size_t len);

/**
 * JTAG module operations.
 */
bool tm4c129_flash_jtag_is_on(void);
void tm4c129_flash_jtag_permanently_off(void);
