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

#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include <hal/hal_def.h>
#include <hal/hal_con.h>
#include <drv/tm4c129_mcu.h>

#define HAL_MCU_FREQUENCY     TM4C129_MCU_FREQUENCY
#define HAL_MCU_FREQUENCY_MHz TM4C129_MCU_TICKS_PER_uS

#define HAL_SYSTICK_FREQUENCY 1000

HAL_INLINE const char* hal_mcu_name(void)
{
    return tm4c129_mcu_name();
}

HAL_INLINE size_t hal_mcu_sram_size(void)
{
    return tm4c129_mcu_sram_size();
}

HAL_INLINE size_t hal_mcu_flash_size(void)
{
    return tm4c129_mcu_flash_size();
}

HAL_INLINE size_t hal_mcu_flash_sector_size(void)
{
    return tm4c129_mcu_flash_sector_size();
}

HAL_INLINE void hal_mcu_int_on(void)
{
    tm4c129_mcu_int_on();
}

HAL_INLINE void hal_mcu_int_off(void)
{
    tm4c129_mcu_int_off();
}

/**
 * Disable MCU interrupts and return previous interrupts disable state.
 *
 * @return  1 - previous interrupts state is disabled,
 *          0 - previous interrupts state is enabled.
 */
HAL_INLINE size_t hal_mcu_int_off_dstate(void)
{
    size_t dstate;
    tm4c129_mcu_int_off_primask(dstate);
    return dstate;
}

HAL_INLINE void hal_mcu_int_restore(size_t dstate)
{
    tm4c129_mcu_int_restore(dstate);
}

/**
 * @brief Determining whether we are inside an interrupt.
 *
 * @return Current ISR number if we are in an interrupt or 0 (zero) if we are in the thread mode.
 */
HAL_INLINE size_t hal_mcu_inside_int(void)
{
    size_t inum;
    tm4c129_mcu_int_active_get(inum);
    return inum;
}

HAL_INLINE void hal_mcu_mdelay(size_t milliseconds)
{
    tm4c129_mcu_mdelay(milliseconds);
}

HAL_INLINE void hal_mcu_udelay(size_t microseconds)
{
    tm4c129_mcu_udelay(microseconds);
}

HAL_NORETURN void hal_mcu_halt(void);

uint32_t hal_mcu_unique_id(void);

/**
 * Universal sleep function.
 */
void hal_sleep(size_t mS);

/**
 * Assert with MCU halt if assert failed.
 */
#define hal_assert(cond, message)  \
    do {                           \
        if (HAL_UNLIKELY(!(cond))) \
        {                          \
            hal_error(message);    \
            hal_mcu_halt();        \
        }                          \
    } while (0)

/**
 * @brief HAL low level critical sections.
 */
#define hal_ll_cr_sect_enter()       size_t hal_mcu_int_dstate = hal_mcu_int_off_dstate()
#define hal_ll_cr_sect_enter_reuse() hal_mcu_int_dstate = hal_mcu_int_off_dstate()
#define hal_ll_cr_sect_leave()       hal_mcu_int_restore(hal_mcu_int_dstate)

/**
 * Timestamp functions. All values in milliseconds.
 *
 * @details
 *
 * Maximum timestamp value is 4294967000 milliseconds = 4294967 seconds =
 * 71582,78(3) minutes = 1193,0463(8) hours = 49,71 days.
 */
uint32_t hal_timestamp_get(void);

HAL_INLINE uint32_t hal_timestamp_span(uint32_t ts)
{
    return hal_timestamp_get() - ts;
}

/**
 * Common part.
 */
HAL_NORETURN void hal_system_startup(void);
HAL_NORETURN void hal_system_reboot(void);

void hal_uart_dbg_switch_to_fail_safe(void);
void hal_print_version(void);
