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

#define HAL_INIT_ASSERT(msg, init_func)     \
    do {                                    \
        hal_print(HAL_PREFIX msg);          \
        if (init_func)                      \
        {                                   \
            hal_puts("[done]");             \
        }                                   \
        else                                \
        {                                   \
            hal_error(HAL_STFN(init_func)); \
            hal_mcu_halt();                 \
        }                                   \
    } while (0)

/**
 * @brief Low level hardware initialization
 */
static void hal_hardware_init(void)
{
    HAL_INIT_ASSERT("NVIC module...", tm4c129_int_init());
    HAL_INIT_ASSERT("DMA module...", tm4c129_dma_init());

//    HAL_INIT_ASSERT("DBG UART module...", tm4c129_uart_dbg_init());
//    crt_stdout_func_set(tm4c129_uart_dbg_send_buf);

    HAL_INIT_ASSERT("CCM module...", tm4c129_ccm_init());
}

/**
 * HAL initialization function. Used as reset ISR handler.
 *
 * Ignore clang-tidy error: Non-ASM statement in naked function is not supported.
 * It is correct in this case and it is fine for GCC.
 *
 * @warning
 *
 */
HAL_NORETURN void hal_init(void)
{
    /**
     * @warning
     *
     * This function is called before initialization of C standard library.
     * Non constant static variables are in a non-initialized state!
     * Don't use non constant static variables here!
     */

    /**
     * Disable all interrupts.
     */
    tm4c129_mcu_int_off();

    /**
     * Initialize the FPU module and set MCU OSC clock.
     */
    if (!tm4c129_mcu_init())
    {
        /**
         * stderr and stdout is not initialized here yet.
         * Stop the system without any print to stdout.
         */
        tm4c129_mcu_halt();
    }

    /**
     * Initialize the debug UART.
     *
     * After UART and CRT initialization stdout will be ready to work.
     */
    if (!tm4c129_uart_dbg_fail_safe_init())
    {
        /**
         * stderr and stdout is not initialized here yet.
         * Stop the system without any print to stdout.
         */
        tm4c129_mcu_halt();
    }

    /**
     * Initialize the C runtime library.
     * This function initialize C standard library (global variables, internal CRT structures, etc.).
     *
     * After this call stdout is ready to work.
     */
    crt_init();
    crt_stdout_func_set(tm4c129_uart_dbg_fail_safe_send_buf);

    /**
     * Print startup info.
     */
    hal_print_version();

    hal_puts(HAL_PREFIX "Hardware initialization:\n");

    /**
     * Initialize hardware modules.
     */
    hal_hardware_init();

    /**
     * TN Kernel initialization and start.
     */
    hal_system_startup();

    /**
     * Never reach this.
     */
    hal_mcu_halt();
}
