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

#include <hal/hal.h>
#include <hal/hal_crt.h>
#include <hal/hal_con.h>
#include <hal/hal_init.h>

#include <tn.h>

#define OS_PREFIX "OS: "

#include <drv/display_kentec_boostxl_k350qvg_s1_ssd2119_spi.h>

void grlib_test(void)
{
    tContext   sContext;
    tRectangle sRect;

    Kentec320x240x16_SSD2119Init(HAL_MCU_FREQUENCY);

    //
    // Initialize the graphics context.
    //
    GrContextInit(&sContext, &g_sKentec320x240x16_SSD2119);

    //
    // Fill the top 24 rows of the screen with blue to create the banner.
    //
    sRect.i16XMin = 0;
    sRect.i16YMin = 0;
    sRect.i16XMax = GrContextDpyWidthGet(&sContext) - 1;
    sRect.i16YMax = 23;
    GrContextForegroundSet(&sContext, ClrDarkBlue);
    GrRectFill(&sContext, &sRect);

    //
    // Put a white box around the banner.
    //
    GrContextForegroundSet(&sContext, ClrWhite);
    GrRectDraw(&sContext, &sRect);

    //
    // Put the application name in the middle of the banner.
    //
    GrContextFontSet(&sContext, &g_sFontCm20);
    GrStringDrawCentered(&sContext, "grlib demo", -1, GrContextDpyWidthGet(&sContext) / 2, 8, 0);
}

/*
 * Before a call tn_app_init() all interrupts are disabled by the caller.
 * After returning from this function all interrupts will be enabled.
 * Do not use tn_task_sleep() here, because this function enables interrupts!
 */
int tn_app_init(void)
{
    HAL_INIT_ASSERT(OS_PREFIX "CRT stdio lock init...", hal_crt_stdio_lock_init());

    grlib_test();

    return TERR_NO_ERR;
}
