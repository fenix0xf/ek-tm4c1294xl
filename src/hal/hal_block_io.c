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

#include "hal_block_io.h"
#include <hal/hal_con.h>

/**
 * Local functions.
 *
 */
static bool pg_erase_write(const struct hal_block_io* io, uintptr_t block_addr, const void* buf)
{
    if (!io->pg_erase(block_addr))
    {
        hal_errorf("io->pg_erase(0x%08X)", (unsigned)block_addr);
        return false;
    }

    if (!io->pg_write(block_addr, buf, io->pg_size))
    {
        hal_errorf("io->pg_write(0x%08X, %p, %u)", (unsigned)block_addr, buf, (unsigned)io->pg_size);
        return false;
    }

    return true;
}

/**
 * Library interface.
 *
 */
bool hal_block_io_is_correct(const struct hal_block_io* io)
{
    if ((io->rd_align == 0) || (io->rd_align & (io->rd_align - 1)))
    {
        hal_error("incorrect io->rd_align!");
        return false;
    }

    if ((io->pg_size == 0) || (io->pg_size & (io->pg_size - 1)))
    {
        hal_error("incorrect io->pg_size!");
        return false;
    }

    if (io->pg_size < io->rd_align)
    {
        hal_error("io->pg_size < io->rd_align");
        return false;
    }

    if ((io->size == 0) || (io->size < io->pg_size) || (io->size < io->rd_align) || (io->size % io->pg_size) || (io->size % io->rd_align))
    {
        hal_error("incorrect io->size!");
        return false;
    }

    if (io->pg_buf == NULL)
    {
        hal_error("io->pg_buf == NULL");
        return false;
    }

    /**
     * @note align of io->pg_buf == io->rd_align.
     */
    if (((uintptr_t)io->pg_buf & (io->rd_align - 1)) != 0)
    {
        hal_error("incorrect io->pg_buf align!");
        return false;
    }

    if (io->read == NULL)
    {
        hal_error("io->read == NULL");
        return false;
    }

    if (io->pg_write == NULL)
    {
        hal_error("io->pg_write == NULL");
        return false;
    }

    if (io->pg_erase == NULL)
    {
        hal_error("io->pg_erase == NULL");
        return false;
    }

    return true;
}

bool hal_block_io_read(const struct hal_block_io* io, uintptr_t addr, void* buf, size_t len)
{
    if (io->rd_align == sizeof(uint8_t))
    {
        return io->read(addr, buf, len);
    }

    const uintptr_t aligned_addr = addr & ~(io->rd_align - 1);

    uint8_t*        pbuf = (uint8_t*)buf;

    if (addr != aligned_addr)
    {
        if (!io->read(aligned_addr, io->pg_buf, io->rd_align))
        {
            hal_errorf("io->read(0x%08X, %p, %u)", (unsigned)aligned_addr, io->pg_buf, (unsigned)io->rd_align);
            return false;
        }

        const size_t   tshift = addr - aligned_addr;
        size_t         tlen   = io->rd_align - tshift;
        const uint8_t* tbuf   = (uint8_t*)io->pg_buf + tshift;

        addr += tlen;

        for (; len && tlen; len--, tlen--)
        {
            *pbuf++ = *tbuf++;
        }
    }

    if (len >= io->rd_align)
    {
        const size_t aligned_len = len & ~(io->rd_align - 1);

        if (!io->read(addr, pbuf, aligned_len))
        {
            hal_errorf("io->read(0x%08X, %p, %u)", (unsigned)addr, (void*)pbuf, (unsigned)aligned_len);
            return false;
        }

        addr += aligned_len;
        pbuf += aligned_len;
        len  -= aligned_len;
    }

    if (len == 0)
    {
        return true;
    }

    if (!io->read(addr, io->pg_buf, io->rd_align))
    {
        hal_errorf("io->read(0x%08X, %p, %u)", (unsigned)addr, io->pg_buf, (unsigned)io->rd_align);
        return false;
    }

    const uint8_t* tbuf = (uint8_t*)io->pg_buf;

    while (len--)
    {
        *pbuf++ = *tbuf++;
    }

    return true;
}

bool hal_block_io_write(const struct hal_block_io* io, uintptr_t addr, const void* buf, size_t len)
{
    const uintptr_t end_addr = addr + len;
    const uint8_t*  pbuf     = (uint8_t*)buf;

    for (uintptr_t block_addr = addr & ~(io->pg_size - 1); block_addr < end_addr; block_addr += io->pg_size)
    {
        const size_t bdata_addr = addr - block_addr;
        size_t       blen       = io->pg_size - bdata_addr;

        if (blen > len)
        {
            blen = len;
        }

        if ((addr != block_addr) || (blen != io->pg_size))
        {
            if (!io->read(block_addr, io->pg_buf, io->pg_size))
            {
                hal_errorf("io->read(0x%08X, %p, %u)", (unsigned)block_addr, io->pg_buf, (unsigned)io->pg_size);
                return false;
            }

            uint8_t* bbuf = (uint8_t*)io->pg_buf + bdata_addr;

            for (size_t i = 0; i < blen; ++i)
            {
                *bbuf++ = *pbuf++;
            }

            if (!pg_erase_write(io, block_addr, io->pg_buf))
            {
                return false;
            }
        }
        else
        {
            if (!pg_erase_write(io, block_addr, pbuf))
            {
                return false;
            }

            pbuf += io->pg_size;
        }

        addr += blen;
        len  -= blen;
    }

    return true;
}
