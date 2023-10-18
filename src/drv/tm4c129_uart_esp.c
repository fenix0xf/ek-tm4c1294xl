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

#include "tm4c129_uart_esp.h"

#include <drv/tm4c129.h>
#include <drv/tm4c129_mcu.h>

/**
 * Configure UARTX as ESP module command channel.
 */
#define UART_PERIPH      SYSCTL_PERIPH_UART0
#define UART_BASE        UART0_BASE
#define UART_SPEED       115200 ///< Default ESP module UART baud rate
#define UART_CFG         (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE)

#define UART_GPIO_PERIPH SYSCTL_PERIPH_GPIOA
#define UART_GPIO_PORT   GPIO_PORTA_BASE
#define UART_GPIO_PINS   (GPIO_PIN_0 | GPIO_PIN_1)

#define UART_GPIO_RX_CFG GPIO_PA0_U0RX
#define UART_GPIO_TX_CFG GPIO_PA1_U0TX

/*
#define UART_UDMA_TX_CH  UDMA_CH21_UART7TX

#define DMA_BUF_SIZE     256
#define DMA_BUF_NUM      2
#define DMA_BUF_ALIGN    sizeof(uint32_t)

#define UART_FIFO_SIZE   16
#define UART_FIFO_HALF   (UART_FIFO_SIZE / 2)

struct dma_buf
{
    uint8_t         payload[DMA_BUF_NUM][DMA_BUF_SIZE];
    volatile size_t len[DMA_BUF_NUM];
    volatile size_t idx;
};

HAL_ALIGNED(4) static struct dma_buf g_buf_tx; */

/*
 * Local functions.
 */
/*HAL_INLINE size_t next_idx_get(size_t idx)
{
    return (idx + 1) % DMA_BUF_NUM;
}

size_t tx_buf_empty_get(uint8_t** buf)
{
    size_t idx = g_buf_tx.idx;
    *buf       = g_buf_tx.payload[idx];
    return g_buf_tx.len[idx];
}

void tx_buf_empty_set_len(size_t len)
{
    size_t idx = g_buf_tx.idx;

    hal_ll_cr_sect_enter();
    g_buf_tx.len[idx] = len;
    hal_ll_cr_sect_leave();
}

size_t tx_buf_full_get(uint8_t** buf)
{
    size_t next_idx = next_idx_get(g_buf_tx.idx);
    *buf            = g_buf_tx.payload[next_idx];
    return g_buf_tx.len[next_idx];
}

void tx_buf_full_set_len(size_t len)
{
    size_t next_idx = next_idx_get(g_buf_tx.idx);

    hal_ll_cr_sect_enter();
    g_buf_tx.len[next_idx] = len;
    hal_ll_cr_sect_leave();
}

bool tx_buf_swap_try(void)
{
    size_t idx = g_buf_tx.idx;

    if (g_buf_tx.len[idx])
    {
        size_t next_idx = next_idx_get(idx);

        hal_ll_cr_sect_enter();
        g_buf_tx.len[next_idx] = 0;        *//* Reset full buffer. *//*
        g_buf_tx.idx           = next_idx; *//* Swap full and empty buffers. *//*
        hal_ll_cr_sect_leave();

        return true;
    }

    return false;
}

bool tx_bufs_is_empty(void)
{
    size_t idx = g_buf_tx.idx;
    return !g_buf_tx.len[idx] && !g_buf_tx.len[next_idx_get(idx)];
}

static void __dma_transfer_restart(void)
{
    if (!uDMAChannelIsEnabled(UART_UDMA_TX_CH) && tx_buf_swap_try())
    {
        uint8_t* tx_buf;
        size_t   len = tx_buf_full_get(&tx_buf);

        uDMAChannelTransferSet(UART_UDMA_TX_CH | UDMA_PRI_SELECT,
                               UDMA_MODE_BASIC,
                               tx_buf,
                               (void*)(UART_BASE + UART_O_DR),
                               len);

        uDMAChannelEnable(UART_UDMA_TX_CH);
    }
}

static void __uart_isr(void)
{
    uint32_t status = UARTIntStatus(UART_BASE, true);

    UARTIntClear(UART_BASE, status);

    __dma_transfer_restart();
}

static void tm4c129_uart_dbg_init_dma(void)
{
    UARTFIFOEnable(UART_BASE);
    UARTFIFOLevelSet(UART_BASE, UART_FIFO_TX1_8, UART_FIFO_RX4_8);

    UARTDMAEnable(UART_BASE, UART_DMA_TX);

    uDMAChannelAssign(UART_UDMA_TX_CH);

    uDMAChannelAttributeDisable(UART_UDMA_TX_CH, UDMA_ATTR_ALL);
    uDMAChannelAttributeEnable(UART_UDMA_TX_CH, UDMA_ATTR_USEBURST);

    uDMAChannelControlSet(UART_UDMA_TX_CH | UDMA_PRI_SELECT,
                          UDMA_SIZE_8 | UDMA_SRC_INC_8 | UDMA_DST_INC_NONE | UDMA_ARB_4);

    UARTIntEnable(UART_BASE, UART_INT_DMATX);
    UARTTxIntModeSet(UART_BASE, UART_TXINT_MODE_FIFO);

    tm4c129_int_register(UART_INT, __uart_isr);
    tm4c129_int_nvic_enable(UART_INT);
}*/

/**
 * Interface functions.
 *
 */
bool tm4c129_uart_esp_init(void)
{
    if (!tm4c129_periph_init(UART_GPIO_PERIPH, TM4C129_PERIPH_OPT_DEFAULT))
    {
        return false;
    }

    GPIOPinConfigure(UART_GPIO_RX_CFG);
    GPIOPinConfigure(UART_GPIO_TX_CFG);
    GPIOPinTypeUART(UART_GPIO_PORT, UART_GPIO_PINS);

    if (!tm4c129_periph_init(UART_PERIPH, TM4C129_PERIPH_OPT_RESET))
    {
        return false;
    }

    UARTConfigSetExpClk(UART_BASE, TM4C129_MCU_FREQUENCY, UART_SPEED, UART_CFG);
    return true;
}

void tm4c129_uart_esp_baud_rate_set(size_t baud)
{
    UARTConfigSetExpClk(UART_BASE, TM4C129_MCU_FREQUENCY, baud, UART_CFG);
}

intptr_t tm4c129_uart_esp_puts(const char* s)
{
    intptr_t rc = tm4c129_uart_esp_print(s);
    UARTCharPut(UART_BASE, (uint8_t)'\r');
    UARTCharPut(UART_BASE, (uint8_t)'\n');
    return rc + 2;
}

intptr_t tm4c129_uart_esp_print(const char* s)
{
    const char* const p = s;
    while (*s) { UARTCharPut(UART_BASE, (uint8_t)(*s++)); }
    return (intptr_t)(s - p);
}

void tm4c129_uart_esp_send_buf(const void* buf, size_t len)
{
    const uint8_t* p = (uint8_t*)buf;
    while (len--) { UARTCharPut(UART_BASE, (uint8_t)(*p++)); }
}

void tm4c129_uart_esp_send_byte(uint8_t b)
{
    UARTCharPut(UART_BASE, b);
}

void tm4c129_uart_esp_flush(void)
{
    /// Wait for end of TX.
    while (HWREG(UART_BASE + UART_O_FR) & UART_FR_BUSY) {}
}

/*
void tm4c129_uart_dbg_send_buf(const void* buf, size_t size)
{
    const uint8_t* u8buf          = buf;
    size_t         unaligned_size = (uintptr_t)buf - ((uintptr_t)buf & ~(DMA_BUF_ALIGN - 1));

    while (size)
    {
        if (size <= UART_FIFO_SIZE)
        {
            if (uDMAChannelIsEnabled(UART_UDMA_TX_CH) || !tx_bufs_is_empty())
            {
                continue;
            }

            tm4c129_uart_dbg_fail_safe_send_buf(u8buf, size);
            tm4c129_uart_dbg_fail_safe_flush();
            break;
        }

        if (unaligned_size)
        {
            if (uDMAChannelIsEnabled(UART_UDMA_TX_CH) || !tx_bufs_is_empty())
            {
                continue;
            }

            tm4c129_uart_dbg_send_buf(u8buf, unaligned_size);
            tm4c129_uart_dbg_flush();
            size           -= unaligned_size;
            u8buf          += unaligned_size;
            unaligned_size  = 0;
        }

        uint8_t* tx_buf;
        size_t   len = tx_buf_empty_get(&tx_buf);

        if (len)
        {
            */
/* Waiting for free space in FIFO or DMA buffer. *//*

            continue;
        }

        if (size > DMA_BUF_SIZE)
        {
            memcpy(tx_buf, u8buf, DMA_BUF_SIZE);
            size  -= DMA_BUF_SIZE;
            u8buf += DMA_BUF_SIZE;

            tx_buf_empty_set_len(DMA_BUF_SIZE);
            __dma_transfer_restart();
        }
        else if (size > UART_FIFO_SIZE)
        {
            size_t aligned_size = size & ~(DMA_BUF_ALIGN - 1);

            memcpy(tx_buf, u8buf, aligned_size);
            size  -= aligned_size;
            u8buf += aligned_size;

            tx_buf_empty_set_len(aligned_size);
            __dma_transfer_restart();
        }
    }
}
*/
