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
