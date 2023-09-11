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

#include "ring_buf.h"
#include <hal/hal.h>

/**
 * Local functions.
 *
 */
HAL_INLINE void ringbuf_index_update(volatile size_t* value, size_t delta, size_t buf_len)
{
    hal_cr_sect_enter();

    *value += delta;

    /// This loop need if (delta > buf_len).
    while (*value >= buf_len) { *value -= buf_len; }

    hal_cr_sect_leave();
}

/**
 * Interface functions.
 *
 */
void ring_buf_init(struct ring_buf* rb, void* buf, size_t len)
{
    rb->buf       = (uint8_t*)buf;
    rb->len       = len;
    rb->read_idx  = 0;
    rb->write_idx = 0;
}

bool ring_buf_is_full(struct ring_buf* rb)
{
    const size_t read_idx  = rb->read_idx;
    const size_t write_idx = rb->write_idx;
    return ((write_idx + 1) % rb->len) == read_idx;
}

bool ring_buf_is_empty(struct ring_buf* rb)
{
    const size_t read_idx  = rb->read_idx;
    const size_t write_idx = rb->write_idx;
    return write_idx == read_idx;
}

void ring_buf_flush(struct ring_buf* rb)
{
    hal_cr_sect_enter();
    rb->read_idx = rb->write_idx;
    hal_cr_sect_leave();
}

size_t ring_buf_used(struct ring_buf* rb)
{
    const size_t read_idx  = rb->read_idx;
    const size_t write_idx = rb->write_idx;
    return (write_idx >= read_idx) ? (write_idx - read_idx) : (rb->len - (read_idx - write_idx));
}

size_t ring_buf_free(struct ring_buf* rb)
{
    return ((rb->len - 1) - ring_buf_used(rb));
}

size_t ring_buf_contig_used(struct ring_buf* rb)
{
    const size_t read_idx  = rb->read_idx;
    const size_t write_idx = rb->write_idx;
    return (write_idx >= read_idx) ? (write_idx - read_idx) : (rb->len - read_idx);
}

size_t ring_buf_contig_free(struct ring_buf* rb)
{
    const size_t read_idx  = rb->read_idx;
    const size_t write_idx = rb->write_idx;

    if (read_idx > write_idx)
    {
        return (read_idx - write_idx) - 1;
    }

    return rb->len - write_idx - ((read_idx == 0) ? 1 : 0);
}

size_t ring_buf_size(struct ring_buf* rb)
{
    return rb->len;
}

uint8_t ring_buf_read_byte(struct ring_buf* rb)
{
    const uint8_t byte = rb->buf[rb->read_idx];
    ringbuf_index_update(&rb->read_idx, 1, rb->len);
    return byte;
}

void ring_buf_write_byte(struct ring_buf* rb, uint8_t byte)
{
    rb->buf[rb->write_idx] = byte;
    ringbuf_index_update(&rb->write_idx, 1, rb->len);
}

void ring_buf_read(struct ring_buf* rb, void* buf, size_t len)
{
    uint8_t* pbuf = (uint8_t*)buf;
    for (size_t i = 0; i < len; i++) { pbuf[i] = ring_buf_read_byte(rb); }
}

void ring_buf_write(struct ring_buf* rb, const void* buf, size_t len)
{
    const uint8_t* pbuf = (uint8_t*)buf;

    for (size_t i = 0; i < len; i++) { ring_buf_write_byte(rb, pbuf[i]); }
}

void ring_buf_advance_read(struct ring_buf* rb, size_t len)
{
    size_t rblen = ring_buf_used(rb);
    rblen        = (rblen < len) ? rblen : len;
    ringbuf_index_update(&rb->read_idx, rblen, rb->len);
}
