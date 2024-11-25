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
 * Block device information and callbacks.
 */
struct hal_block_io
{
    size_t size;     /// Block device full size.
    size_t rd_align; /// Block device read and write align.
    size_t pg_size;  /// Block device align for erase() function (sector size). pg_size >= rd_align.

    void*  pg_buf; /// Buffer for unaligned read/write operations. Size of pg_buf == [pg_size].

    bool (*read)(uintptr_t addr, void* buf, size_t len);           /// Block device aligned read function.
    bool (*pg_write)(uintptr_t addr, const void* buf, size_t len); /// Block device aligned write function.
    bool (*pg_erase)(uintptr_t addr);                              /// Block device aligned erase function with [ealign] block size.
};

bool hal_block_io_is_correct(const struct hal_block_io* io);

/**
 * Unaligned read data from block device.
 */
bool hal_block_io_read(const struct hal_block_io* io, uintptr_t addr, void* buf, size_t len);

/**
 * Unaligned write data to block device.
 */
bool hal_block_io_write(const struct hal_block_io* io, uintptr_t addr, const void* buf, size_t len);
