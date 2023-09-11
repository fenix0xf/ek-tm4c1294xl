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

#include "conv.h"

#include <hal/hal_def.h>

/**
 * Local functions.
 *
 */
HAL_INLINE int inl_hex2int(int hex_ch)
{
    if ((hex_ch >= '0') && (hex_ch <= '9'))
    {
        return hex_ch - '0';
    }
    else if ((hex_ch >= 'A') && (hex_ch <= 'F'))
    {
        return hex_ch - 'A' + 10;
    }
    else if ((hex_ch >= 'a') && (hex_ch <= 'f'))
    {
        return hex_ch - 'a' + 10;
    }
    else
    {
        return -1;
    }
}

HAL_INLINE void inl_int2hex(char* hi, char* lo, uint8_t byte)
{
    int h = (byte >> 4) & 0xF;
    int l = byte & 0xF;

    h = h > 9 ? 'A' + h - 10 : '0' + h;
    l = l > 9 ? 'A' + l - 10 : '0' + l;

    *hi = (char)h;
    *lo = (char)l;
}

/**
 * Interface functions.
 *
 */
bool conv_hex2bin(void* out, size_t out_size, const char* in, size_t in_size)
{
    if ((out_size == 0) || (in_size == 0))
    {
        return false;
    }

    if ((out_size * 2) != in_size)
    {
        return false;
    }

    uint8_t* b_out = (uint8_t*)out;

    while (in_size)
    {
        int hi   = *in++;
        int lo   = *in++;
        in_size -= 2;

        hi = inl_hex2int(hi);
        lo = inl_hex2int(lo);

        if ((hi < 0) || (lo < 0))
        {
            return false;
        }

        *b_out++ = (uint8_t)((hi << 4) | lo);
    }

    return true;
}

bool conv_bin2hex(char* out, size_t out_size, const void* in, size_t in_size)
{
    if ((out_size == 0) || (in_size == 0))
    {
        return false;
    }

    if (out_size != (in_size * 2))
    {
        return false;
    }

    const uint8_t* b_in = (uint8_t*)in;

    while (in_size--)
    {
        char hi;
        char lo;

        inl_int2hex(&hi, &lo, *b_in++);

        *out++ = hi;
        *out++ = lo;
    }

    return true;
}
