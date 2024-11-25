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
 * Ring buffer object.
 */
struct ring_buf
{
    uint8_t*        buf;
    size_t          len;

    volatile size_t read_idx;
    volatile size_t write_idx;
};

/**
 * Interface functions.
 *
 */

/**
 * Initialize a ring buffer object.
 */
void    ring_buf_init(struct ring_buf* rb, void* buf, size_t len);

/**
 * Determines whether the ring buffer whose pointers and size are provided is full or not.
 */
bool    ring_buf_is_full(struct ring_buf* rb);

/**
 * Determines whether the ring buffer whose pointers and size are provided is empty or not.
 */
bool    ring_buf_is_empty(struct ring_buf* rb);

/**
 * Empties the ring buffer.
 */
void    ring_buf_flush(struct ring_buf* rb);

/**
 * Returns number of bytes stored in ring buffer.
 */
size_t  ring_buf_used(struct ring_buf* rb);

/**
 * Returns number of bytes available in a ring buffer.
 */
size_t  ring_buf_free(struct ring_buf* rb);

/**
 * Returns number of contiguous bytes of data stored in ring buffer ahead of the current read pointer.
 */
size_t  ring_buf_contig_used(struct ring_buf* rb);

/**
 * Returns number of contiguous free bytes available in a ring buffer.
 */
size_t  ring_buf_contig_free(struct ring_buf* rb);

/**
 * Return size in bytes of a ring buffer.
 */
size_t  ring_buf_size(struct ring_buf* rb);

/**
 * Reads a single byte of data from a ring buffer.
 *
 * @note
 * Don't read data from different threads or interrupts!
 */
uint8_t ring_buf_read_byte(struct ring_buf* rb);

/**
 * Writes a single byte of data to a ring buffer.
 *
 * @note
 * Don't write data from different threads or interrupts!
 */
void    ring_buf_write_byte(struct ring_buf* rb, uint8_t byte);

/**
 * Reads data from a ring buffer.
 *
 * @note
 * Don't read data from different threads or interrupts!
 */
void    ring_buf_read(struct ring_buf* rb, void* buf, size_t len);

/**
 * Writes data to a ring buffer.
 *
 * @note
 * Don't write data from different threads or interrupts!
 */
void    ring_buf_write(struct ring_buf* rb, const void* buf, size_t len);

/**
 * Remove bytes from the ring buffer by advancing the read index.
 *
 * @note
 * Don't read data from different threads or interrupts!
 */
void    ring_buf_advance_read(struct ring_buf* rb, size_t len);
