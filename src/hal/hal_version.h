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
#include "hal_def.h"

#define HAL_VERSION_SIG      "VER0"
#define HAL_VERSION_MAJOR    0
#define HAL_VERSION_MINOR    1
#define HAL_VERSION_REVISION 0
#define HAL_VERSION_BUILD    0

HAL_PACKED struct hal_version
{
    union
    {
        char     str[4];
        uint32_t dw;
    } sig; /* HAL_VERSION_SIG = "VER0" */

    uint32_t git_hash; /* First 8 digits of git hash as uint32_t. */

    uint64_t timestamp; /* Unix timestamp. */

    uint32_t major;
    uint32_t minor;

    uint32_t revision;
    uint32_t build;

    uint64_t reserved[2];
};

extern struct hal_version g_hal_version;
