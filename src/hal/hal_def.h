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

#include <assert.h>
#include <stdint.h>

#include "hal_def_arch.h"

/*
 * Compiler independent C attributes.
 */
#ifdef __GNUC__

#define HAL_INLINE        static inline __attribute__((always_inline))
#define HAL_NOINLINE      __attribute__((noinline))
#define HAL_NORETURN      __attribute__((noreturn))
#define HAL_NAKED         __attribute__((naked))
#define HAL_USED          __attribute__((used))
#define HAL_UNUSED        __attribute__((unused))
#define HAL_ALIGNED(n)    __attribute__((aligned(n)))
#define HAL_SECTION(s)    __attribute__((section(s)))
#define HAL_PACKED        __attribute__((packed))
#define HAL_LIKELY(exp)   __builtin_expect(!!(exp), 1)
#define HAL_UNLIKELY(exp) __builtin_expect(!!(exp), 0)

#else
#error Currently only GCC is supported!
#endif

/*
 * Stringification macros.
 */
#define HAL_STFN_0(s) #s
#define HAL_STFN(s)   HAL_STFN_0(s)

/*
 * Linker sections macros.
 */
#define HAL_STACK_SECTION(name) HAL_SECTION(".noinit.stack." HAL_STFN(name))
#define HAL_HEAP_SECTION(name)  HAL_SECTION(".noinit.heap." HAL_STFN(name))

/*
 * Platform stack defines.
 */
#if HAL_IS_CORTEX_M0_M7

#define HAL_STACK_ITEM_TYPE unsigned int
#define HAL_STACK_ALIGN     8
#define HAL_STACK_ISIZE     sizeof(HAL_STACK_ITEM_TYPE)
#define HAL_STACK_MIN_ITEMS 96

#else
#error Currently only Cortex M0-M7 is supported!
#endif

#define HAL_STACK_DECLARE(name, size_bytes)                                                                   \
    enum { g_stack_##name##_items = (size_bytes) / HAL_STACK_ISIZE };                                         \
    static_assert((((size_bytes) % HAL_STACK_ALIGN) == 0) && (g_stack_##name##_items >= HAL_STACK_MIN_ITEMS), \
                  "HAL_STACK_DECLARE() invalid parameters!");                                                 \
    HAL_ALIGNED(HAL_STACK_ALIGN)                                                                              \
    HAL_STACK_SECTION(name)                                                                                   \
    static HAL_STACK_ITEM_TYPE g_stack_##name[g_stack_##name##_items]

#define HAL_STACK_PTR(name)   (&g_stack_##name[g_stack_##name##_items - 1])
#define HAL_STACK_PTRU(name)  ((uintptr_t)&g_stack_##name[g_stack_##name##_items - 1])
#define HAL_STACK_ITEMS(name) (g_stack_##name##_items)

/*
 * Math macros.
 */
#define HAL_IS_POW2(val)                (((val) != 0) && !((val) & ((val)-1)))
#define HAL_IS_POW2_ALIGNED(val, align) (HAL_IS_POW2(align) && !((val) & ((align)-1)))
#define HAL_CEIL_DIV(a, b)              (((a) + (b)-1) / (b))

/*
 * Bitset macros.
 */
#define HAL_BITMASK(b, s)     (1 << ((b) % (s)))
#define HAL_BITSLOT(b, s)     ((b) / (s))
#define HAL_BITSET(a, b, s)   ((a)[HAL_BITSLOT(b, s)] |= HAL_BITMASK(b, s))
#define HAL_BITCLEAR(a, b, s) ((a)[HAL_BITSLOT(b, s)] &= ~HAL_BITMASK(b, s))
#define HAL_BITTEST(a, b, s)  ((a)[HAL_BITSLOT(b, s)] & HAL_BITMASK(b, s))
#define HAL_BITNSLOTS(nb, s)  HAL_CEIL_DIV(nb, s)

/*
 * Utilities.
 */
#define HAL_NELEMS(a) (sizeof(a) / sizeof(*(a)))
