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

#include "tm4c129.h"

#include <hal/hal.h>
#include <hal/hal_def.h>
#include <hal/hal_con.h>

/**
 * Default peripheral wait timeout is 100 microseconds.
 */
#define TM4C129_PERIPH_WAIT_STEP_uS    1
#define TM4C129_PERIPH_WAIT_DEFAULT_uS 100

/**
 * Common API part
 *
 */
static bool periph_ready_wait(uint32_t periph)
{
    size_t delay = 0;

    while (!SysCtlPeripheralReady(periph))
    {
        hal_mcu_udelay(TM4C129_PERIPH_WAIT_STEP_uS);

        delay += TM4C129_PERIPH_WAIT_STEP_uS;

        if (delay >= TM4C129_PERIPH_WAIT_DEFAULT_uS)
        {
            return false;
        }
    }

    return true;
}

bool tm4c129_periph_init(uint32_t periph, size_t opt)
{
    if (!SysCtlPeripheralPresent(periph))
    {
        return false;
    }

    SysCtlPeripheralEnable(periph);

    if (HAL_BITS_TEST(opt, TM4C129_PERIPH_OPT_SLEEP))
    {
        SysCtlPeripheralSleepEnable(periph);
    }

    if (HAL_BITS_TEST(opt, TM4C129_PERIPH_OPT_DEEP_SLEEP))
    {
        SysCtlPeripheralDeepSleepEnable(periph);
    }

    if (HAL_BITS_TEST(opt, TM4C129_PERIPH_OPT_RESET))
    {
        SysCtlPeripheralReset(periph);
    }

    return periph_ready_wait(periph);
}

void tm4c129_periph_free(uint32_t periph)
{
    if (SysCtlPeripheralPresent(periph))
    {
        SysCtlPeripheralDisable(periph);
    }
}

#ifdef DEBUG
void __error__(char* filename, uint32_t line)
{
    hal_printf("TIVAWARE ASSERT(\"%s\":%u);\n", filename, (unsigned)line);
    hal_mcu_halt();
}
#endif
