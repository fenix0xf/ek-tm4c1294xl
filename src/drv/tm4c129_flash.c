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

#include "tm4c129_flash.h"

#include <hal/hal_def.h>
#include <drv/tm4c129.h>

#define FLASH_FMA_BOOTCFG_WR 0x75100000

typedef uint32_t tm4c129_flash_aligned_t;

enum { TM4C129_FLASH_ADDR_ALIGN = sizeof(tm4c129_flash_aligned_t) };

bool tm4c129_flash_init(void)
{
    return true;
}

size_t tm4c129_flash_size(void)
{
    return SysCtlFlashSizeGet();
}

size_t tm4c129_flash_align(void)
{
    return TM4C129_FLASH_ADDR_ALIGN;
}

size_t tm4c129_flash_ealign(void)
{
    return SysCtlFlashSectorSizeGet();
}

bool tm4c129_flash_erase(uintptr_t block_addr)
{
    const size_t align = tm4c129_flash_ealign();

    if (!HAL_IS_POW2_ALIGNED(block_addr, align))
    {
        return false;
    }

    if ((block_addr + align) > tm4c129_flash_size())
    {
        return false;
    }

    return FlashErase(block_addr) == 0;
}

bool tm4c129_flash_write(uintptr_t addr, const void* buf, size_t len)
{
    if (!HAL_IS_POW2_ALIGNED(addr, TM4C129_FLASH_ADDR_ALIGN) || !HAL_IS_POW2_ALIGNED(len, TM4C129_FLASH_ADDR_ALIGN))
    {
        return false;
    }

    if ((addr + len) > tm4c129_flash_size())
    {
        return false;
    }

    return FlashProgram((uint32_t*)buf, addr, len) == 0;
}

bool tm4c129_flash_compare(uintptr_t addr, const void* buf, size_t len)
{
    if (!HAL_IS_POW2_ALIGNED(addr, TM4C129_FLASH_ADDR_ALIGN) || !HAL_IS_POW2_ALIGNED(len, TM4C129_FLASH_ADDR_ALIGN))
    {
        return false;
    }

    if ((addr + len) > tm4c129_flash_size())
    {
        return false;
    }

    const volatile tm4c129_flash_aligned_t* pbuf = (tm4c129_flash_aligned_t*)buf;

    for (const uintptr_t end = addr + len; addr < end; addr += TM4C129_FLASH_ADDR_ALIGN, pbuf++)
    {
        if (*(const volatile tm4c129_flash_aligned_t*)addr != *pbuf)
        {
            return false;
        }
    }

    return true;
}

bool tm4c129_flash_jtag_is_on(void)
{
    return (HWREG(FLASH_BOOTCFG) & FLASH_BOOTCFG_DBG1) == FLASH_BOOTCFG_DBG1;
}

void tm4c129_flash_jtag_permanently_off(void)
{
    /**
     * The Boot Configuration (BOOTCFG) register requires a power-on reset before the committed changes take effect.
     */
    if (tm4c129_flash_jtag_is_on())
    {
        HWREG(FLASH_FMA) = FLASH_FMA_BOOTCFG_WR;
        HWREG(FLASH_FMD) = HWREG(FLASH_BOOTCFG) & ~(uint32_t)FLASH_BOOTCFG_DBG1;
        HWREG(FLASH_FMC) = FLASH_FMC_WRKEY | FLASH_FMC_COMT;

        while (HWREG(FLASH_FMC) & FLASH_FMC_COMT) {}
    }
}
