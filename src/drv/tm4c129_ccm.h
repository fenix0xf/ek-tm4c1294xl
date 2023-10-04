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

bool tm4c129_ccm_init(void);
void tm4c129_ccm_free(void);

/**
 *  This CRC32 can be specified as:
 *      Width  : 32
 *      Poly   : 0x04C11DB7
 *      Init   : parameter, typically 0xFFFFFFFF
 *      RefIn  : false
 *      RefOut : false
 *      XorOut : 0
 *  This differs from the "standard" CRC-32 algorithm in that the values
 *  are not reflected, and there is no final XOR value.  These differences
 *  make it easy to compose the values of multiple blocks.
 */

/// Default initial value for tm4c129_ccm_crc32_mpeg_Xbit(buf, len, TM4C129_CCM_SEED);
#define TM4C129_CCM_SEED 0xFFFFFFFF

uint32_t tm4c129_ccm_crc32_mpeg_8bit(const void* buf, size_t len, uint32_t seed);
uint32_t tm4c129_ccm_crc32_mpeg_align32(const void* align32_buf, size_t align32_len, uint32_t seed);
