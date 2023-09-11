/* ---------------------------------------------------------------------------
     TNKernel RTOS port for ARM(c) Cortex-M0..M7(c) CPU

     Copyright © 2004, 2016  Yuri Tiomkin
     Copyright © 2007, 2013  Vyacheslav Ovsiyenko
     Copyright © 2008        Sergey Koshkin
     Copyright © 2014        Dmitry Frank

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
----------------------------------------------------------------------------*/

#include <hal/hal_def_arch.h>

#if __GNUC__

#define TN_NAME(x)             x
#define TN_LOCAL_NAME(x)       L ## x
#define TN_EXTERN(x)           .extern x
#define TN_GLOBAL(x)           .global x
#define TN_EQU(symbol, value)  .equ symbol, value
#define TN_LABEL(label)        TN_NAME(label):
#define TN_LOCAL_LABEL(label)  TN_LOCAL_NAME(label):
#define TN_END()
#define TN_THUMB_FUNC()        .thumb_func

#else
#error Currently only GCC is supported!
#endif

#if !HAL_IS_CORTEX_M0_M7
#error Unsupported ARM architecture, only armv6-m, armv7-m, armv7e-m are supported!
#endif

#if __GNUC__

   .text
   .syntax unified
   .thumb

#else
#error Currently only GCC is supported!
#endif

  //-- External references

TN_EXTERN(tn_curr_run_task)
TN_EXTERN(tn_next_task_to_run)
TN_EXTERN(tn_system_state)
TN_EXTERN(tn_func_exit_stack_start)
TN_EXTERN(delete_task_resources)
TN_EXTERN(tn_check_stack)
TN_EXTERN(tn_os_idle_task)

  //-- Public functions declared in this file

TN_GLOBAL(tn_task_exit_asm)
TN_GLOBAL(tn_switch_context)
TN_GLOBAL(tn_start_exe)
TN_GLOBAL(tn_pendsv_handler)
TN_GLOBAL(tn_int_exit)

#if HAL_IS_ARM_CLZ_SUPPORTED
TN_GLOBAL(ffs_asm)
#endif

 //--  Interrupt Control and State Register Address

TN_EQU(ICSR_ADDR, 0xE000ED04)

 //--  pendSV bit in the Interrupt Control and State Register

TN_EQU(PENDSVSET, 0x10000000)

 //--  System Handlers 12-15 Priority Register Address

TN_EQU(PR_12_15_ADDR, 0xE000ED20)


#if TN_ARCH_CORTEX_M0 || TN_ARCH_CORTEX_M0P

 //--  PRI_14 (PendSV) priority in the System Handlers 14-15 Priority Register Address
 //--  PendSV priority is minimal (0xC0)
TN_EQU(PENDS_VPRIORITY, 0x00C00000)
TN_EQU(VECTACTIVE, 0x0000003F)   /* Bits[5:0]*/

#else

 //--  PRI_14 (PendSV) priority in the System Handlers 12-15 Priority Register Address
 //--  PendSV priority is minimal (0xFF)
TN_EQU(PENDS_VPRIORITY, 0x00FF0000)
TN_EQU(VECTACTIVE, 0x000001FF)   /* Bits[8:0]*/

#endif

 //-- M0  System Handlers 12-15 Priority Register Address

TN_EQU(PR_14_15_ADDR, 0xE000ED20)

//----------------------------------------------------------------------------
// Core interrupt is not enabled (yet)
//----------------------------------------------------------------------------
TN_THUMB_FUNC()
TN_LABEL(tn_start_exe)
#if HAL_IS_ARMV6_M
       ldr    r1, =PR_14_15_ADDR        // Load the System 14-15 Priority Register
       ldr    r0, [r1]

       ldr    r2, =PENDS_VPRIORITY
       orrs   r0, r0, r2                // set PRI_14 (PendSV) to 0xFF - minimal
       str    r0, [r1]

       ldr    r1, =tn_system_state      // Indicate that system has started
       movs   r0, #1                    // 1 -> TN_SYS_STATE_RUNNING
       strb   r0, [r1]

  //---------------

       ldr    r1, =tn_curr_run_task     // =tn_next_task_to_run
       ldr    r2, [r1]
       ldr    r0, [r2]                  // in r0 - new task SP

       adds   r0, r0, #16
       ldmia  r0!, {r4-r7}              // restore new context (r8-r11)
       mov    r8, r4
       mov    r9, r5
       mov    r10, r6
       mov    r11, r7
       subs   r0, r0,#32
       ldmia  r0!, {r4-r7}              // restore new context (r4-r7)
       adds   r0, r0, #16

       msr    psp, r0
       isb

       movs   r1, #4                    // Force to new process PSP
       mov    r0, lr
       orrs   r0, r0, r1
       mov    lr, r0

       ldr    r1, =ICSR_ADDR            // Trigger PendSV exception for context switching
       ldr    r0, =PENDSVSET
       str    r0, [r1]

       cpsie  i                         // Enable core interrupts
       b      .                         // Never reach this

#elif HAL_IS_ARMV7_M

       ldr    r1, =PR_12_15_ADDR        // Load the System 12-15 Priority Register
       ldr    r0, [r1]
       orr    r0, r0, #PENDS_VPRIORITY  // Set PRI_14 (PendSV) to 0xFF - minimal
       str    r0, [r1]

       ldr    r1, =tn_system_state      // Indicate that system has started
       mov    r0, #1                    // 1 -> TN_SYS_STATE_RUNNING
       strb   r0, [r1]

       ldr    r1, =tn_curr_run_task     // =tn_next_task_to_run
       ldr    r2, [r1]
       ldr    r0, [r2]                  // in r0 - new task SP

#if (TN_SUPPORT_FPU == 1)
       ldmia   R0!, {R4-R11, LR}
#else
       ldmia   R0!, {R4-R11}
#endif
       msr     PSP, R0

       ldr     r1, =ICSR_ADDR           // Trigger PendSV exception for context switching
       ldr     r0, =PENDSVSET
       str     r0, [r1]

       movs    r0, #0                   // Clear FPCA bit (if any) also
       msr     control, r0              // Use the MSP before PendSv switch
       isb

       cpsie   if                       // Enable core interrupts
       b       .                        // Never reach this
#endif
TN_END()

//----------------------------------------------------------------------------
TN_THUMB_FUNC()
TN_LABEL(tn_pendsv_handler)
#if HAL_IS_ARMV6_M
       cpsid  i                          // Disable core int

       ldr    r3, =tn_curr_run_task      // in R3 - =tn_curr_run_task
       ldr    r1, [r3]                   // in R1 - tn_curr_run_task
       ldr    r2, =tn_next_task_to_run
       ldr    r2, [r2]                   // in R2 - tn_next_task_to_run
       cmp    r1, r2
       beq    exit_context_switch

       mrs    r0, psp               // in PSP - process(task) stack pointer, put it to R0

       subs   r0, r0, #32           // expected stack pos
       str    r0, [r1]              // save own sp in tcb

       stmia  r0!, {r4-r7}          // save old context (r4-r7)
       mov    r4, r8
       mov    r5, r9
       mov    r6, r10
       mov    r7, r11
       stmia  r0!,{r4-r7}           // save old context (r8-r11)

       str    r2, [r3]              // in r3 - =tn_curr_run_task
       ldr    r0, [r2]              // in r0 - new task sp

       adds   r0, r0, #16           // position in stack where r8..11 are stored
       ldmia  r0!, {r4-r7}          // restore  r8..r11 to r4..r7
       mov    r8, r4                // move r8..r11  contents to the original location
       mov    r9, r5
       mov    r10, r6
       mov    r11, r7
       subs   r0, r0, #32           // position in stack where r4..7 are stored
       ldmia  r0!, {r4-r7}          // restore new context (r4-r7)
       adds   r0, r0, #16           // R0 = Stack ptr

       msr    psp, r0               // New stack - in R0, put it to the PSP
       isb

       movs   r1, #4                // Force to new process PSP
       mov    r0, lr
       orrs   r0, r0, r1
       mov    lr, r0

TN_LABEL(exit_context_switch)
       cpsie i                      // enable core int
       bx    lr

#elif HAL_IS_ARMV7_M

       cpsid i                          // disable core int
       isb

       ldr      r3, =tn_curr_run_task   // in R3 - =tn_curr_run_task
       ldr      r1, [r3]                // in R1 - tn_curr_run_task
       ldr      r2, =tn_next_task_to_run
       ldr      r2, [r2]                // in R2 - tn_next_task_to_run
       cmp      r1, r2
       beq      exit_context_switch

       mrs      r0, psp                 // in PSP - process (task) stack pointer
#if (TN_SUPPORT_FPU == 1)
       tst      lr, #0x10               // if FPU context is active
       it       eq                      // we should save its registers
       vstmdbeq r0!, {s16-s31}          // on the process stack
       stmdb    r0!, {r4-r11, lr}
#else
       stmdb    r0!, {r4-r11}
#endif
       str      r0, [r1]                // save own SP in current task TCB

#if TN_STACK_CHECK
       push     {lr}                    // to save LR
       mov      r0, r1                  // set R1 tn_curr_run_task TN_TCB for the function 'tn_check_stack'
       mov      r1, #1                  // set opt=TN_CHECK_STACK_HALT for the function 'tn_check_stack'
       ldr      r3, =tn_check_stack
       blx      r3
       pop      {lr}                    // restore LR
       ldr      r3, =tn_curr_run_task   // in R3 - =tn_curr_run_task
       ldr      r1, [r3]                // in R1 - tn_curr_run_task
       ldr      r2, =tn_next_task_to_run
       ldr      r2, [r2]                // in R2 - tn_next_task_to_run
#endif

       str      r2, [r3]                // in R3 - =tn_curr_run_task
       ldr      r0, [r2]                // in R0 - new task SP
#if (TN_SUPPORT_FPU == 1)                      
       ldmia    r0!, {r4-r11, lr}       // restore the high GPRs
       tst      lr, #0x10               // look whether the active FPU context
       it       eq
       vldmiaeq r0!, {S16-S31}
#else
       ldmia    r0!, {r4-r11}
#endif
       msr      psp, r0
       isb

TN_LABEL(exit_context_switch)
       orr      lr, lr, #0x04           // Force to new process PSP
       cpsie    i                       // enable core int
       bx       lr
#endif // HAL_IS_ARMV7_M
TN_END()

//-----------------------------------------------------------------------------

TN_THUMB_FUNC()
TN_LABEL(tn_task_exit_asm)

       ldr    r1,  =tn_curr_run_task
       ldr    r2,  [r1]
       mov    r1,   r2      // -- Save r2
  
  //--- Set exit stack
   
       ldr    r0,  =tn_func_exit_stack_start
       ldr    r0,  [r0]
       msr    psp, r0

#if HAL_IS_ARMV6_M
       movs   r1, #4         // Force to new process PSP
       mov    r0, lr
       orrs   r0, r0, r1
       mov    lr, r0
#elif HAL_IS_ARMV7_M
       orr    lr, lr, #0x04  // Force to exit stack
#endif
       mov    r0,   r2       // -- Set parameter for the function 'delete_task_resources()'
       ldr    r1, =delete_task_resources
       blx    r1

  //--- MSP stack

       mrs    r0,  msp
       adds   r0,  r0, #32   // 8*4 - 8 automatically saved registers at the PendSV interrupt
       msr    msp, r0

       movs   r0,  #0        // Default stack MSP(Main stack pointer) is used
       msr    control, r0
       dsb
       isb 

  //-------------------------------

       ldr    r1, =ICSR_ADDR // Trigger PendSV exception for context switching
       ldr    r0, =PENDSVSET
       str    r0,  [r1]
       cpsie  i              // Enable core interrupts
       b      .              // Should never reach
TN_END()

//-----------------------------------------------------------------------------
TN_THUMB_FUNC()
TN_LABEL(tn_switch_context)
       ldr    r1, =ICSR_ADDR // Trigger PendSV exception for context switching
       ldr    r0, =PENDSVSET
       str    r0, [r1]
       bx     lr
TN_END()

//-----------------------------------------------------------------------------
TN_THUMB_FUNC()
TN_LABEL(tn_int_exit)
       ldr    r1, =ICSR_ADDR // Trigger PendSV exception for context switching
       ldr    r0, =PENDSVSET
       str    r0, [r1]
       bx     lr
TN_END()

//-----------------------------------------------------------------------------
#if HAL_IS_ARM_CLZ_SUPPORTED
TN_THUMB_FUNC()
TN_LABEL(ffs_asm)
       mov    r1, r0                    //-- tmp = in
       rsbs   r0, r1, #0                //-- in = -in
       ands   r0, r0, r1                //-- in = in & tmp
       clz.w  r0, r0
       rsb    r0, r0, #0x20             //-- 32 - in
       bx     lr
TN_END()
#endif
