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

#include "hal_init.h"

#include <hal/hal.h>
#include <hal/hal_crt.h>

#include <drv/tm4c129_mcu.h>
#include <drv/tm4c129_uart_dbg.h>

#include <drv/tm4c129_ccm.h>
#include <drv/tm4c129_int.h>
#include <drv/tm4c129_dma.h>

#define HAL_PREFIX "HAL: "

/*
 * Low level hardware initialization.
 */
static void hal_ll_hardware_init(void)
{
    HAL_INIT_ASSERT(HAL_PREFIX "NVIC module init...", tm4c129_int_init());
    HAL_INIT_ASSERT(HAL_PREFIX "DMA module init...", tm4c129_dma_init());
    HAL_INIT_ASSERT(HAL_PREFIX "CCM module init...", tm4c129_ccm_init());
}

/*
 * HAL initialization function. Used as reset ISR handler.
 */
HAL_USED HAL_NORETURN HAL_SECTION(".reset") void hal_init(void)
{
    /*
     * This function is called before initialization of C standard library. Non-constant static variables are in a non-initialized state!
     * Don't use non-constant static variables until hal_crt_init() is called!
     */

    /* Disable all interrupts. */
    tm4c129_mcu_int_off();

    /* Initialize the FPU module and set MCU OSC clock. */
    if (!tm4c129_mcu_init())
    {
        /* stderr and stdout is not initialized here yet. Stop the system without any print to stdout. */
        tm4c129_mcu_halt();
    }

    /* Initialize the debug UART. After UART and CRT initialization stdout will be ready to work. */
    if (!tm4c129_uart_dbg_init())
    {
        /* stderr and stdout is not initialized here yet. Stop the system without any print to stdout. */
        tm4c129_mcu_halt();
    }

    /*
     * Initialize the C runtime library.
     * This function initialize C standard library (global variables, internal CRT structures, etc.).
     * After this call non-constant static variables, stdout and stderr are ready to work.
     */
    hal_crt_init(tm4c129_uart_dbg_send_buf, tm4c129_uart_dbg_send_buf);

    /* Print startup info. */
    hal_print_version();

    /* Initialize hardware modules. */
    hal_ll_hardware_init();

    /* Check firmware checksum. It uses CCM module, call hal_ll_hardware_init() first. */
    hal_firmware_self_check();

    /* TN Kernel initialization and start. */
    hal_system_startup();

    /* Never reach this. */
    hal_mcu_halt();
}
