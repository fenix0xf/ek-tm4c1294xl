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

/**
 * TM4C129 MCU core frequency in Hz.
 *
 */
#define TM4C129_MCU_FREQUENCY 120000000

/**
 * TM4C129 MCU ticks values:
 * 1. In one microsecond - TM4C129_MCU_TICKS_PER_uS.
 * 2. In one millisecond - TM4C129_MCU_TICKS_PER_mS.
 * 3. In one second      - TM4C129_MCU_TICKS_PER_S.
 */
#define TM4C129_MCU_TICKS_PER_uS (TM4C129_MCU_FREQUENCY / 1000000)
#define TM4C129_MCU_TICKS_PER_mS (TM4C129_MCU_FREQUENCY / 1000)
#define TM4C129_MCU_TICKS_PER_S  (TM4C129_MCU_FREQUENCY)

/**
 * TM4C129 MCU common part.
 */
bool              tm4c129_mcu_init(void);
HAL_NORETURN void tm4c129_mcu_halt(void);
HAL_NORETURN void tm4c129_mcu_reset(void);

/**
 * TM4C129 MCU SysTick.
 *
 * @param frequency is SysTick interrupt frequency in Hz.
 */
void tm4c129_mcu_systick_on(size_t frequency);

/**
 * TM4C129 MCU information part.
 */
const char* tm4c129_mcu_name(void);
size_t      tm4c129_mcu_sram_size(void);
size_t      tm4c129_mcu_flash_size(void);
size_t      tm4c129_mcu_flash_sector_size(void);

/**
 * TM4C129 MCU interrupts.
 *
 * @details tm4c129_mcu_int_off_primask(pm_out) - reads Priority Mask Register into the pm_out variable:
 *          1 - prevents the activation of all interrupts with configurable priority,
 *          0 - all interrupts with configurable priority are enabled.
 *
 *          tm4c129_mcu_int_restore(pm) - restores interrupt state based on the Priority Mask Register value
 *          obtained earlier from the tm4c129_mcu_int_off_primask(pm_out) macro.
 *
 *          tm4c129_mcu_int_active_get(isr_num_out) - reads Interrupt Program Status Register (IPSR) into
 *          the isr_num_out variable.
 */
#define tm4c129_mcu_int_on()  __asm volatile("cpsie i\n" ::: "memory")
#define tm4c129_mcu_int_off() __asm volatile("cpsid i\n" ::: "memory")
#define tm4c129_mcu_int_off_primask(pm_out) \
    __asm volatile("mrs %0, primask\n"      \
                   "cpsid i\n" : "=r"(pm_out)::"memory")
#define tm4c129_mcu_int_restore(pm)             __asm volatile("msr primask, %0\n" ::"r"(pm) : "memory")
#define tm4c129_mcu_int_active_get(isr_num_out) __asm volatile("mrs %0, ipsr" : "=r"(isr_num_out)::"memory");

/**
 * TM4C129 MCU delay loop.
 */
void tm4c129_mcu_3cycles_delay(uint32_t count);

HAL_INLINE void tm4c129_mcu_mdelay(size_t milliseconds)
{
    /// The loop takes 3 cycles/loop.
    tm4c129_mcu_3cycles_delay((TM4C129_MCU_TICKS_PER_mS * milliseconds) / 3);
}

HAL_INLINE void tm4c129_mcu_udelay(size_t microseconds)
{
    /// The loop takes 3 cycles/loop.
    tm4c129_mcu_3cycles_delay((TM4C129_MCU_TICKS_PER_uS * microseconds) / 3);
}

/**
 * MCU flash memory prefetch buffers on/off.
 */
void tm4c129_mcu_prefetch_off(void);
void tm4c129_mcu_prefetch_on(void);

/**
 * MCU hardware unique id.
 */
void tm4c129_mcu_unique_id(uint32_t* id0, uint32_t* id1, uint32_t* id2, uint32_t* id3);

/**
 * Break into the debugger.
 */
#define TM4C129_MCU_BKPT() __asm volatile("bkpt #0\n")

/**
 * No operation. This instruction can be used for code alignment purposes.
 */
#define TM4C129_MCU_XNOP() __asm volatile("nop\n")

/**
 * Wait For Interrupt is a hint instruction that suspends execution until one of a number of events occurs.
 */
#define TM4C129_MCU_XWFI() __asm volatile("wfi\n")

/**
 * Wait For Event is a hint instruction that permits the processor to enter a low-power state
 * until one of a number of events occurs.
 */
#define TM4C129_MCU_XWFE() __asm volatile("wfe\n")

/**
 * Send Event is a hint instruction. It causes an event to be signaled to the CPU.
 */
#define TM4C129_MCU_XSEV() __asm volatile("sev\n")

/**
 * Instruction Synchronization Barrier flushes the pipeline in the processor,
 * so that all instructions following the ISB are fetched from cache or memory,
 * after the instruction has been completed.
 */
#define TM4C129_MCU_XISB() __asm volatile("isb 0xF\n" ::: "memory")

/**
 * Data Synchronization Barrier.
 * Acts as a special kind of Data Memory Barrier.
 * It completes when all explicit memory accesses before this instruction complete.
 */
#define TM4C129_MCU_XDSB() __asm volatile("dsb 0xF\n" ::: "memory")

/**
 * Data Memory Barrier.
 * Ensures the apparent order of the explicit memory operations before
 * and after the instruction, without ensuring their completion.
 */
#define TM4C129_MCU_XDMB() __asm volatile("dmb 0xF\n" ::: "memory")

/**
 * LDR Exclusive (32 bit).
 * Executes a exclusive LDR instruction for 32 bit values.
 */
#define TM4C129_MCU_XLDREXW(result, addr) __asm volatile("ldrex %0, [%1]\n" : "=r"(result) : "r"(addr) : "memory")

/**
 * STR Exclusive (32 bit).
 * Executes a exclusive STR instruction for 32 bit values and remove the exclusive lock.
 * err == 0, succeeded,
 * err != 0, failed.
 */
#define TM4C129_MCU_XSTREXW(err, value, addr) \
    __asm volatile("strex %0, %1, [%2]\n" : "=r"(err) : "r"(value), "r"(addr) : "memory")

/**
 * Remove the exclusive lock.
 * Removes the exclusive lock which is created by LDREX.
 */
#define TM4C129_MCU_XCLREX() __asm volatile("clrex\n")
