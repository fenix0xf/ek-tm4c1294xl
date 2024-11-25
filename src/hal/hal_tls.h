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
#include <limits.h>

#include <hal/hal_def.h>

/*
 * Custom GCC TLS is supported since Iain Sandoe <iain@sandoe.co.uk> commit on Nov 19, 2021
 * https://github.com/gcc-mirror/gcc/commit/b9873b4e2c9a9955789318f4d550147ef9405b07
 *
 * libgcc, emutls: Allow building weak definitions of the emutls functions.
 */
#define HAL_TLS_IS_SUPPORTED                                                                                           \
    ((__GNUC__ >= 13) || ((__GNUC__ == 12) && (__GNUC_MINOR__ >= 1)) || ((__GNUC__ == 11) && (__GNUC_MINOR__ >= 3)) || \
     ((__GNUC__ == 10) && (__GNUC_MINOR__ >= 4)) || ((__GNUC__ == 9) && (__GNUC_MINOR__ >= 5)))

#if HAL_TLS_IS_SUPPORTED
typedef uint32_t hal_tls_item_t;
typedef uint32_t hal_tls_bs_slot_t;

#define HAL_TLS_MAX_ITEMS   8
#define HAL_TLS_BS_SLOT_BIT (sizeof(hal_tls_bs_slot_t) * CHAR_BIT)
#define HAL_TLS_BS_SLOT_NUM HAL_BITNSLOTS(HAL_TLS_MAX_ITEMS, HAL_TLS_BS_SLOT_BIT)

struct hal_tls_block
{
    hal_tls_item_t    items[HAL_TLS_MAX_ITEMS];
    hal_tls_bs_slot_t bitset[HAL_TLS_BS_SLOT_NUM];
};

#define HAL_DECLARE_TLS_BLOCK(name) static struct hal_tls_block name
#define HAL_GET_TLS_BLOCK(name)     (&name)

#else /* HAL_TLS_IS_SUPPORTED */
#error Thread Local Storage is not supported for this GCC version!
#endif /* HAL_TLS_IS_SUPPORTED */
