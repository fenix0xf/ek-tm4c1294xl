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

#include "tm4c129_dma.h"

#include <hal/hal.h>
#include <hal/hal_def.h>
#include <hal/hal_con.h>
#include <drv/tm4c129.h>
#include <drv/tm4c129_int.h>

#define DMA_PREFIX                   "DMA: "

#define TM4C129_DMA_PRI_CHANNELS_NUM 32
#define TM4C129_DMA_ALT_CHANNELS_NUM 32
#define TM4C129_DMA_CHANNELS_NUM     (TM4C129_DMA_PRI_CHANNELS_NUM + TM4C129_DMA_ALT_CHANNELS_NUM)

HAL_ALIGNED(1024) static tDMAControlTable g_dma_ctl_table[TM4C129_DMA_CHANNELS_NUM];

static void __dma_error_isr(void)
{
    static size_t error_count;

    uint32_t      status = uDMAErrorStatusGet();

    if (status)
    {
        uDMAErrorStatusClear();
        error_count++;

        hal_printf("\n" DMA_PREFIX "uDMA Error ISR, status %u, error count %u\n", status, error_count);
        hal_mcu_halt();
    }
}

bool tm4c129_dma_init(void)
{
    if (!tm4c129_periph_init(SYSCTL_PERIPH_UDMA, TM4C129_PERIPH_OPT_RESET | TM4C129_PERIPH_OPT_SLEEP))
    {
        return false;
    }

    uDMAEnable();
    uDMAControlBaseSet(g_dma_ctl_table);

    tm4c129_int_register(INT_UDMAERR, __dma_error_isr);
    tm4c129_int_nvic_enable(INT_UDMAERR);

    return true;
}
