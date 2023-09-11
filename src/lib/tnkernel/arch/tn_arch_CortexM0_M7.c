/*

  TNKernel real-time kernel

  Copyright © 2004, 2016 Yuri Tiomkin
  Copyright © 2008       Sergey Koshkin (Cortex - M3 port)
  Copyright © 2007, 2013 Vyacheslav Ovsiyenko (Cortex - M4F port)

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

/* ver 3 */

#include "tn.h"

#include <assert.h>

#define TN_STACK_PREFIX "STACK: "

volatile unsigned long tn_sys_tick_count;

//----------------------------------------------------------------------------
//   Processor specific routine - here for Cortex CPU
//
//   sizeof(void*) = sizeof(int)
//----------------------------------------------------------------------------
unsigned int* tn_stack_init(void (*task_func)(void* param), void* stack_start, void* param)
{
    unsigned int* stk;
    unsigned long tmp;

    static_assert(sizeof(int) == sizeof(void*), "Invalid integer size!");
    static_assert(sizeof(int) == sizeof(long), "Invalid integer size!");

    //-- Filling register's position in the stack - for debugging only

    stk = (unsigned int*)stack_start; //-- Load stack pointer

    *stk = 0x01000000ul;              //-- xPSR
    stk--;

    tmp   = (unsigned long)task_func;
    tmp  |= 1u;
    *stk  = tmp;
    stk--;

    tmp   = (unsigned long)tn_task_exit;
    tmp  |= 1u;
    *stk  = tmp;
    stk--;

    *stk = 0x12121212ul; //-- R12
    stk--;
    *stk = 0x03030303ul; //-- R3
    stk--;
    *stk = 0x02020202ul; //-- R2
    stk--;
    *stk = 0x01010101ul; //-- R1
    stk--;

    tmp  = (unsigned long)param;
    *stk = tmp; //-- R0 - task's function argument
    stk--;

#if (TN_SUPPORT_FPU == 1)
    // Return to Thread mode, exception return uses non-floating-point state
    // from the PSP and execution uses PSP after return
    *stk = 0xFFFFFFFDul;
    stk--;
#endif

    *stk = 0x11111111ul; //-- R11
    stk--;
    *stk = 0x10101010ul; //-- R10
    stk--;
    *stk = 0x09090909ul; //-- R9
    stk--;
    *stk = 0x08080808ul; //-- R8
    stk--;
    *stk = 0x07070707ul; //-- R7
    stk--;
    *stk = 0x06060606ul; //-- R6
    stk--;
    *stk = 0x05050505ul; //-- R5
    stk--;
    *stk = 0x04040404ul; //-- R4

    return stk;
}

#if TN_STACK_CHECK

void tn_check_stack(TN_TCB* task, enum tn_check_stack_opt opt)
{
    uintptr_t* end_sp = task->stk_start - task->stk_size + 1;

    if (TN_UNLIKELY(*end_sp != TN_FILL_STACK_VAL))
    {
        if (TN_LIKELY((opt & TN_CHECK_STACK_FORCE) == 0))
        {
            tn_print("\n");
        }

        tn_printf(TN_STACK_PREFIX
                  "Task \"%s\" - Fatal! Stack overflow! The stack size has exceeded %u dw (%u bytes)!\n",
                  task->task_name,
                  task->stk_size,
                  task->stk_size * TN_STACK_ITEM_SIZE);

        if (opt & TN_CHECK_STACK_HALT)
        {
            tn_halt();
        }

        return;
    }

#if (TN_STACK_CHECK == 1) // TN_STACK_CHECK strictly == 1

    else if (TN_UNLIKELY(opt & TN_CHECK_STACK_FORCE))
    {
        size_t stack_usage     = (size_t)(task->stk_start - task->task_stk + 1);
        size_t stack_usage_pct = (stack_usage * 100) / task->stk_size;

        tn_printf(TN_STACK_PREFIX "Task \"%s\" - Stack usage: %u%%, %u/%u dw (%u/%u bytes).\n",
                  task->task_name,
                  stack_usage_pct,
                  stack_usage,
                  task->stk_size,
                  stack_usage * TN_STACK_ITEM_SIZE,
                  task->stk_size * TN_STACK_ITEM_SIZE);
    }

#elif (TN_STACK_CHECK >= 2)

    uintptr_t* next_sp = task->stk_start - task->stk_usage;

    while ((next_sp > end_sp) && (*next_sp != TN_FILL_STACK_VAL)) { next_sp--; }

    size_t stack_usage = (size_t)(task->stk_start - next_sp);

    if (TN_UNLIKELY(task->stk_usage != stack_usage))
    {
        tn_stack_usage_update(task, stack_usage);
    }

    if (TN_UNLIKELY(opt & TN_CHECK_STACK_FORCE))
    {
        task->stk_usage_ticks = tn_get_sys_ticks();
    }
    else
    {
#if (TN_STACK_CHECK == 2) && (TN_STACK_CHECK_WARN_SYS_TASKS_EXCLUDE)
        // TN_STACK_CHECK strictly == 2, exclude system tasks warnings in mode 2
        if (TN_UNLIKELY((task == &tn_os_idle_task) || (task == &tn_os_tick_task)))
        {
            return;
        }
#endif
        size_t sys_ticks     = tn_get_sys_ticks();
        size_t timeout_ticks = sys_ticks - task->stk_usage_ticks;

        if (TN_LIKELY(timeout_ticks < TN_MS_TO_TICKS(TN_STACK_CHECK_WARN_TIMEOUT)))
        {
            return;
        }

        task->stk_usage_ticks = sys_ticks;
    }

    const char* warning = ((TN_STACK_CHECK >= 3) || (opt & TN_CHECK_STACK_FORCE)) ? "\0" : NULL;

    if (TN_UNLIKELY(task->stk_usage_pct <= TN_STACK_CHECK_WARN_LO_PCT))
    {
        warning = " is too low!";
    }
    else if (TN_UNLIKELY(task->stk_usage_pct >= TN_STACK_CHECK_WARN_HI_PCT))
    {
        warning = " is too high!";
    }

    if (TN_UNLIKELY(warning))
    {
        if (TN_LIKELY((opt & TN_CHECK_STACK_FORCE) == 0))
        {
            tn_print("\n");
        }

        tn_printf(TN_STACK_PREFIX "Task \"%s\" - %sStack usage%s: %u%%, %u/%u dw (%u/%u bytes).\n",
                  task->task_name,
                  *warning ? "Warning! " : "",
                  warning,
                  task->stk_usage_pct,
                  task->stk_usage,
                  task->stk_size,
                  task->stk_usage * TN_STACK_ITEM_SIZE,
                  task->stk_size * TN_STACK_ITEM_SIZE);
    }
#endif // #if (TN_STACK_CHECK >= 2)
}

#endif // #if TN_STACK_CHECK
