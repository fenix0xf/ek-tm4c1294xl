/*

  TNKernel real-time kernel

  Copyright © 2004, 2016 Yuri Tiomkin
  All rights reserved.

  Permission to use, copy, modify, and distribute this software in source
  and binary forms and its documentation for any purpose and without fee
  is hereby granted, provided that the above copyright notice appear
  in all copies and that both that copyright notice and this permission
  notice appear in supporting documentation.

  THIS SOFTWARE IS PROVIDED BY THE YURI TIOMKIN AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL YURI TIOMKIN OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
  SUCH DAMAGE.

*/

/* ver 3  */

#pragma once

#include <stddef.h>
#include <stdint.h>

#include <hal/hal.h>
#include <hal/hal_con.h>
#include <hal/hal_tls.h>

#ifdef __cplusplus
extern "C"
{
#endif

#if HAL_IS_CORTEX_M0_M7

#define TN_INLINE          HAL_INLINE
#define TN_STACK(name)     HAL_ALIGNED(HAL_STACK_ALIGN) HAL_STACK_SECTION(name)
#define TN_NORETURN        HAL_NORETURN
#define TN_LIKELY(e)       HAL_LIKELY(e)
#define TN_UNLIKELY(e)     HAL_UNLIKELY(e)

#define TN_DQUEUE_ELEMENT  void*
#define TN_NO_WAIT         0u
#define TN_INVALID_VAL_UL  0xFFFFFFFFul

#define TN_STACK_ITEM_SIZE HAL_STACK_ISIZE

#if TN_SUPPORT_FPU && (__ARM_FP & ~4u)
#error Bit 1 - Half precision FPU (16-bit) and Bit 3 - double precision FPU (64-bit) is not supported.
#endif

#if (__ARM_FP & 4u) // Bit 2 - single precision FPU support (32-bit).
#define TN_STACK_SIZE_MIN (TN_SUPPORT_FPU ? 96u : 64u)
#else
#define TN_STACK_SIZE_MIN 64u // No FPU
#endif

#define TN_BITS_IN_INT     32u

#define TN_ALIG            sizeof(void*)
#define MAKE_ALIG(a)       ((sizeof(a) + (TN_ALIG - 1u)) & (~(TN_ALIG - 1u)))

#define TN_NUM_PRIORITY    TN_BITS_IN_INT //-- 0..31  Priority 0 always is used by timers task
#define TN_MAX_PRIORITY    0u
#define TN_MIN_PRIORITY    (TN_NUM_PRIORITY - 1)

#define TN_WAIT_INFINITE   0xFFFFFFFFu
#define TN_FILL_STACK_VAL  0xDEADBEEFu
#define TN_INVALID_VAL     0xFFFFFFFFu

#define TN_SYSTICKS_PER_S  HAL_SYSTICK_FREQUENCY
#define TN_MS_TO_TICKS(ms) (((ms)*TN_SYSTICKS_PER_S) / 1000)

extern volatile unsigned long tn_sys_tick_count;

unsigned int* tn_stack_init(void (*task_func)(void* param), void* stack_start, void* param);

//-- Assembler functions prototypes

void tn_switch_context_exit(void);
void tn_switch_context(void);

void tn_start_exe(void);
void tn_pendsv_handler(void);
int  ffs_asm(unsigned int val);

void tn_int_exit(void);
void tn_task_exit_asm(void* tcb);

/**
 * TN_TCB forward declaration.
 */
struct _TN_TCB;
typedef struct _TN_TCB TN_TCB;

#define TN_CHECK_STACK_NONE  0x0u
#define TN_CHECK_STACK_HALT  0x1u
#define TN_CHECK_STACK_FORCE 0x2u

void tn_check_stack(TN_TCB* task, size_t opt);

/**
 * @brief Determining whether we are inside an interrupt.
 *
 * @return Current ISR number if we are in an interrupt or 0 (zero) if we are in the thread mode.
 */
TN_INLINE size_t tn_inside_int(void)
{
    return hal_mcu_inside_int();
}

TN_INLINE TN_NORETURN void tn_halt(void)
{
    hal_mcu_halt();
}

TN_INLINE unsigned long tn_get_sys_ticks(void)
{
    return tn_sys_tick_count;
}

#define tn_puts(s)          hal_puts(s)
#define tn_print(s)         hal_print(s)
#define tn_printf(fmt, ...) hal_printf(fmt __VA_OPT__(, ) __VA_ARGS__)

//-- Interrupt processing - the CPU specific

// All Cortex-M CPU supports nested interrupts

#define TN_INTSAVE_DATA_INT     size_t tn_save_status_reg;
#define TN_INTSAVE_DATA         size_t tn_save_status_reg;
#define tn_disable_interrupt()  tn_save_status_reg = hal_mcu_int_off_dstate()
#define tn_enable_interrupt()   hal_mcu_int_restore(tn_save_status_reg)

#define tn_idisable_interrupt() tn_save_status_reg = hal_mcu_int_off_dstate()
#define tn_ienable_interrupt()  hal_mcu_int_restore(tn_save_status_reg)

// disable interrupts without saving status reg
#define tn_disable_interrupt_nsc() hal_mcu_int_off()

#else

#error "TNKernel port is not defined"

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
