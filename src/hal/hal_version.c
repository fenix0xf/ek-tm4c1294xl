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

#include "hal_version.h"

#include "version.h" /* Auto generated header. */

HAL_USED HAL_SECTION(".version") struct hal_version g_hal_version = {
    .sig.str     = HAL_VERSION_SIG,
    .git_hash    = VERSION_GIT_HASH,
    .timestamp   = VERSION_BUILD_TIME,
    .major       = HAL_VERSION_MAJOR,
    .minor       = HAL_VERSION_MINOR,
    .revision    = HAL_VERSION_REVISION,
    .build       = HAL_VERSION_BUILD,
    .reserved[0] = 0,
    .reserved[1] = 0,
};
