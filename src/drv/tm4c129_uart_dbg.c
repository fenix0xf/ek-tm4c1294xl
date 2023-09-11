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

#include "tm4c129_uart_dbg.h"

#include <drv/tm4c129.h>
#include <drv/tm4c129_mcu.h>

/**
 * Configure UART7 as debug console.
 */
#define UART_PERIPH      SYSCTL_PERIPH_UART7
#define UART_BASE        UART7_BASE
#define UART_SPEED       1228800
#define UART_CFG         (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE)

#define UART_GPIO_PERIPH SYSCTL_PERIPH_GPIOC
#define UART_GPIO_PORT   GPIO_PORTC_BASE
#define UART_GPIO_PINS   (GPIO_PIN_4 | GPIO_PIN_5)

#define UART_GPIO_RX_CFG GPIO_PC4_U7RX
#define UART_GPIO_TX_CFG GPIO_PC5_U7TX

#define UART_UDMA_TX_CH  UDMA_CH21_UART7TX

// #define UART_DMA_BUF_SIZE 256
//
// struct uart_dma_buf
//{
//     uint8_t rx_buf[2][UART_DMA_BUF_SIZE];
//     uint8_t tx_buf[2][UART_DMA_BUF_SIZE];
// };
//
// static struct uart_dma_buf g_buf;
//
// static void tm4c129_uart_dbg_init_dma(void)
//{
//     UARTFIFOLevelSet(UART_BASE, UART_FIFO_TX4_8, UART_FIFO_RX4_8);
//
//     UARTDMAEnable(UART_BASE, UART_DMA_TX);
//
//     uDMAChannelAssign(UART_UDMA_TX_CH);
//
//     uDMAChannelAttributeDisable(UART_UDMA_TX_CH, UDMA_ATTR_ALL);
//     uDMAChannelAttributeEnable(UART_UDMA_TX_CH, UDMA_ATTR_USEBURST);
//
//     uDMAChannelControlSet(UART_UDMA_TX_CH | UDMA_PRI_SELECT,
//                           UDMA_SIZE_8 | UDMA_SRC_INC_8 | UDMA_DST_INC_NONE | UDMA_ARB_4);
//
//     //    uDMAChannelModeGet(UDMA_CHANNEL_UART1RX | UDMA_ALT_SELECT);
// }

/**
 * Interface functions.
 *
 */
bool tm4c129_uart_dbg_fail_safe_init(void)
{
    if (!tm4c129_periph_init(UART_GPIO_PERIPH, TM4C129_PERIPH_OPT_SLEEP))
    {
        return false;
    }

    GPIOPinConfigure(UART_GPIO_RX_CFG);
    GPIOPinConfigure(UART_GPIO_TX_CFG);
    GPIOPinTypeUART(UART_GPIO_PORT, UART_GPIO_PINS);

    if (!tm4c129_periph_init(UART_PERIPH, TM4C129_PERIPH_OPT_RESET | TM4C129_PERIPH_OPT_SLEEP))
    {
        return false;
    }

    UARTConfigSetExpClk(UART_BASE, TM4C129_MCU_FREQUENCY, UART_SPEED, UART_CFG);
    return true;
}

intptr_t tm4c129_uart_dbg_fail_safe_puts(const char* s)
{
    intptr_t rc = tm4c129_uart_dbg_fail_safe_print(s);
    UARTCharPut(UART_BASE, (uint8_t)'\n');
    return rc + 1;
}

intptr_t tm4c129_uart_dbg_fail_safe_print(const char* s)
{
    const char* const p = s;
    while (*s) { UARTCharPut(UART_BASE, (uint8_t)(*s++)); }
    return (intptr_t)(s - p);
}

void tm4c129_uart_dbg_fail_safe_send_buf(const void* buf, size_t size)
{
    uint8_t* p = (uint8_t*)buf;
    while (size--) { UARTCharPut(UART_BASE, (uint8_t)(*p++)); }
}

void tm4c129_uart_dbg_fail_safe_send_byte(uint8_t b)
{
    UARTCharPut(UART_BASE, b);
}

void tm4c129_uart_dbg_fail_safe_flush(void)
{
    /// Wait for end of TX.
    while (HWREG(UART_BASE + UART_O_FR) & UART_FR_BUSY) {}
}

void tm4c129_uart_dbg_fail_safe_free(void)
{
    /// Wait for end of TX.
    UARTDisable(UART_BASE);

    tm4c129_periph_free(UART_PERIPH);
    tm4c129_periph_free(UART_GPIO_PERIPH);
}

bool tm4c129_uart_dbg_init(void)
{
    return 0;
}

bool tm4c129_uart_dbg_free(void)
{
    return 0;
}

intptr_t tm4c129_uart_dbg_puts(const char* s)
{
    (void)s;
    return 0;
}

intptr_t tm4c129_uart_dbg_print(const char* s)
{
    (void)s;
    return 0;
}

void tm4c129_uart_dbg_send_buf(const void* buf, size_t size)
{
    (void)buf;
    (void)size;
}

void tm4c129_uart_dbg_send_byte(uint8_t b)
{
    (void)b;
}

void tm4c129_uart_dbg_flush(void)
{
}
