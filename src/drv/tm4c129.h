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

#include <stdint.h>
#include <stdbool.h>

/**
 * Include TI driver library for all modules.
 *
 */
#include <tivaware.h>

#define TM4C129_PERIPH_OPT_DEFAULT    0x00000000u
#define TM4C129_PERIPH_OPT_RESET      0x00000001u ///< Resets a peripheral after enabling.
#define TM4C129_PERIPH_OPT_SLEEP      0x00000002u ///< Enables a peripheral in sleep mode.
#define TM4C129_PERIPH_OPT_DEEP_SLEEP 0x00000004u ///< Enables a peripheral in deep sleep mode.

/**
 * Init and wait for the peripheral to be ready.
 */
bool tm4c129_periph_init(uint32_t periph, size_t opt);
void tm4c129_periph_free(uint32_t periph);
