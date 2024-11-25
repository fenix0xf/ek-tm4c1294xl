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

#include "tm4c129_spi.h"

#include <drv/tm4c129_mcu.h>
#include <drv/tm4c129.h>

#define TM4C129_SPI0_BITRATE_DEFAULT 2000000

bool tm4c129_spi0_init(void)
{
    if (!tm4c129_periph_init(SYSCTL_PERIPH_GPIOA, TM4C129_PERIPH_OPT_DEFAULT))
    {
        return false;
    }

    if (!tm4c129_periph_init(SYSCTL_PERIPH_SSI0, TM4C129_PERIPH_OPT_RESET))
    {
        return false;
    }

    SSIDisable(SSI0_BASE);

    GPIOPinConfigure(GPIO_PA2_SSI0CLK);
    GPIOPinConfigure(GPIO_PA4_SSI0XDAT0);
    GPIOPinConfigure(GPIO_PA5_SSI0XDAT1);

    GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_2 | GPIO_PIN_4 | GPIO_PIN_5);

    SSIConfigSetExpClk(SSI0_BASE, TM4C129_MCU_FREQUENCY, SSI_FRF_MOTO_MODE_0, SSI_MODE_MASTER, TM4C129_SPI0_BITRATE_DEFAULT, 8);

    SSIEnable(SSI0_BASE);
    return true;
}

void tm4c129_spi0_bitrate_set(size_t bitrate)
{
    SSIDisable(SSI0_BASE);
    SSIConfigSetExpClk(SSI0_BASE, TM4C129_MCU_FREQUENCY, SSI_FRF_MOTO_MODE_0, SSI_MODE_MASTER, (uint32_t)bitrate, 8);
    SSIEnable(SSI0_BASE);
}

uint8_t tm4c129_spi0_rw(uint8_t b)
{
    uint32_t buf;
    SSIDataPut(SSI0_BASE, (uint32_t)b);
    SSIDataGet(SSI0_BASE, &buf);
    return (uint8_t)buf;
}
