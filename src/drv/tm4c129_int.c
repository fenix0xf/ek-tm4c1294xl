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

#include "tm4c129_int.h"

#include <assert.h>

#include <drv/tm4c129.h>

#include <hal/hal.h>
#include <hal/hal_mm.h>
#include <hal/hal_def.h>
#include <hal/hal_con.h>
#include <hal/hal_init.h>

#define INT_PREFIX "ISR: "

/*
 * System stack for startup and interrupts.
 */
HAL_STACK_DECLARE(system, 2048);

/*
 * Type of vector table entry.
 */
typedef void (*tm4c129_int_entry_t)(void);

/*
 * Local functions.
 */
static void tm4c129_int_setup_defaults(void);

HAL_USED static void tm4c129_int_def(void);
HAL_USED static void tm4c129_int_nmi(void);
HAL_USED static void tm4c129_int_hard_fault(void);
HAL_USED static void tm4c129_int_mpu_fault(void);
HAL_USED static void tm4c129_int_bus_fault(void);
HAL_USED static void tm4c129_int_usage_fault(void);

/*
 * Interrupts vector table, see "src/firmware.ld" file.
 * Attribute HAL_USED is necessary for release build with -flto option.
 */
HAL_USED
HAL_ALIGNED(MM_VTABLE_ALIGN)
HAL_SECTION(".vtable")
const tm4c129_int_entry_t g_vtable[] = {
    (tm4c129_int_entry_t)HAL_STACK_PTRU(system), ///< 000 - The initial stack pointer,
    hal_init,                                    ///< 001 - The reset handler,
    tm4c129_int_def,                             ///< 002 - The NMI handler,
    tm4c129_int_def,                             ///< 003 - The hard fault handler,
    tm4c129_int_def,                             ///< 004 - The MPU fault handler,
    tm4c129_int_def,                             ///< 005 - The bus fault handler,
    tm4c129_int_def,                             ///< 006 - The usage fault handler,
    NULL,                                        ///< 007 - Reserved,
    NULL,                                        ///< 008 - Reserved,
    NULL,                                        ///< 009 - Reserved,
    NULL,                                        ///< 010 - Reserved,
    tm4c129_int_def,                             ///< 011 - SVCall handler,
    tm4c129_int_def,                             ///< 012 - Debug monitor handler,
    NULL,                                        ///< 013 - Reserved,
    tm4c129_int_def,                             ///< 014 - The PendSV handler,
    tm4c129_int_def,                             ///< 015 - The SysTick handler,
    tm4c129_int_def,                             ///< 016 - GPIO Port A,
    tm4c129_int_def,                             ///< 017 - GPIO Port B,
    tm4c129_int_def,                             ///< 018 - GPIO Port C,
    tm4c129_int_def,                             ///< 019 - GPIO Port D,
    tm4c129_int_def,                             ///< 020 - GPIO Port E,
    tm4c129_int_def,                             ///< 021 - UART0 Rx and Tx,
    tm4c129_int_def,                             ///< 022 - UART1 Rx and Tx,
    tm4c129_int_def,                             ///< 023 - SSI0 Rx and Tx,
    tm4c129_int_def,                             ///< 024 - I2C0 Master and Slave,
    tm4c129_int_def,                             ///< 025 - PWM Fault,
    tm4c129_int_def,                             ///< 026 - PWM Generator 0,
    tm4c129_int_def,                             ///< 027 - PWM Generator 1,
    tm4c129_int_def,                             ///< 028 - PWM Generator 2,
    tm4c129_int_def,                             ///< 029 - Quadrature Encoder 0,
    tm4c129_int_def,                             ///< 030 - ADC0 Sequence 0,
    tm4c129_int_def,                             ///< 031 - ADC0 Sequence 1,
    tm4c129_int_def,                             ///< 032 - ADC0 Sequence 2,
    tm4c129_int_def,                             ///< 033 - ADC0 Sequence 3,
    tm4c129_int_def,                             ///< 034 - Watchdog timer,
    tm4c129_int_def,                             ///< 035 - Timer 0 subtimer A,
    tm4c129_int_def,                             ///< 036 - Timer 0 subtimer B,
    tm4c129_int_def,                             ///< 037 - Timer 1 subtimer A,
    tm4c129_int_def,                             ///< 038 - Timer 1 subtimer B,
    tm4c129_int_def,                             ///< 039 - Timer 2 subtimer A,
    tm4c129_int_def,                             ///< 040 - Timer 2 subtimer B,
    tm4c129_int_def,                             ///< 041 - Analog Comparator 0,
    tm4c129_int_def,                             ///< 042 - Analog Comparator 1,
    tm4c129_int_def,                             ///< 043 - Analog Comparator 2,
    tm4c129_int_def,                             ///< 044 - System Control (PLL, OSC, BO),
    tm4c129_int_def,                             ///< 045 - FLASH Memory Control,
    tm4c129_int_def,                             ///< 046 - GPIO Port F,
    tm4c129_int_def,                             ///< 047 - GPIO Port G,
    tm4c129_int_def,                             ///< 048 - GPIO Port H,
    tm4c129_int_def,                             ///< 049 - UART2 Rx and Tx,
    tm4c129_int_def,                             ///< 050 - SSI1 Rx and Tx,
    tm4c129_int_def,                             ///< 051 - Timer 3 subtimer A,
    tm4c129_int_def,                             ///< 052 - Timer 3 subtimer B,
    tm4c129_int_def,                             ///< 053 - I2C1 Master and Slave,
    tm4c129_int_def,                             ///< 054 - CAN0,
    tm4c129_int_def,                             ///< 055 - CAN1,
    tm4c129_int_def,                             ///< 056 - Ethernet,
    tm4c129_int_def,                             ///< 057 - Hibernate,
    tm4c129_int_def,                             ///< 058 - USB0,
    tm4c129_int_def,                             ///< 059 - PWM Generator 3,
    tm4c129_int_def,                             ///< 060 - uDMA Software Transfer,
    tm4c129_int_def,                             ///< 061 - uDMA Error,
    tm4c129_int_def,                             ///< 062 - ADC1 Sequence 0,
    tm4c129_int_def,                             ///< 063 - ADC1 Sequence 1,
    tm4c129_int_def,                             ///< 064 - ADC1 Sequence 2,
    tm4c129_int_def,                             ///< 065 - ADC1 Sequence 3,
    tm4c129_int_def,                             ///< 066 - External Bus Interface 0,
    tm4c129_int_def,                             ///< 067 - GPIO Port J,
    tm4c129_int_def,                             ///< 068 - GPIO Port K,
    tm4c129_int_def,                             ///< 069 - GPIO Port L,
    tm4c129_int_def,                             ///< 070 - SSI2 Rx and Tx,
    tm4c129_int_def,                             ///< 071 - SSI3 Rx and Tx,
    tm4c129_int_def,                             ///< 072 - UART3 Rx and Tx,
    tm4c129_int_def,                             ///< 073 - UART4 Rx and Tx,
    tm4c129_int_def,                             ///< 074 - UART5 Rx and Tx,
    tm4c129_int_def,                             ///< 075 - UART6 Rx and Tx,
    tm4c129_int_def,                             ///< 076 - UART7 Rx and Tx,
    tm4c129_int_def,                             ///< 077 - I2C2 Master and Slave,
    tm4c129_int_def,                             ///< 078 - I2C3 Master and Slave,
    tm4c129_int_def,                             ///< 079 - Timer 4 subtimer A,
    tm4c129_int_def,                             ///< 080 - Timer 4 subtimer B,
    tm4c129_int_def,                             ///< 081 - Timer 5 subtimer A,
    tm4c129_int_def,                             ///< 082 - Timer 5 subtimer B,
    tm4c129_int_def,                             ///< 083 - FPU Exception,
    NULL,                                        ///< 084 - Reserved,
    NULL,                                        ///< 085 - Reserved,
    tm4c129_int_def,                             ///< 086 - I2C4 Master and Slave,
    tm4c129_int_def,                             ///< 087 - I2C5 Master and Slave,
    tm4c129_int_def,                             ///< 088 - GPIO Port M,
    tm4c129_int_def,                             ///< 089 - GPIO Port N,
    NULL,                                        ///< 090 - Reserved,
    tm4c129_int_def,                             ///< 091 - Tamper,
    tm4c129_int_def,                             ///< 092 - GPIO Port P (Summary or P0),
    tm4c129_int_def,                             ///< 093 - GPIO Port P1,
    tm4c129_int_def,                             ///< 094 - GPIO Port P2,
    tm4c129_int_def,                             ///< 095 - GPIO Port P3,
    tm4c129_int_def,                             ///< 096 - GPIO Port P4,
    tm4c129_int_def,                             ///< 097 - GPIO Port P5,
    tm4c129_int_def,                             ///< 098 - GPIO Port P6,
    tm4c129_int_def,                             ///< 099 - GPIO Port P7,
    tm4c129_int_def,                             ///< 100 - GPIO Port Q (Summary or Q0),
    tm4c129_int_def,                             ///< 101 - GPIO Port Q1,
    tm4c129_int_def,                             ///< 102 - GPIO Port Q2,
    tm4c129_int_def,                             ///< 103 - GPIO Port Q3,
    tm4c129_int_def,                             ///< 104 - GPIO Port Q4,
    tm4c129_int_def,                             ///< 105 - GPIO Port Q5,
    tm4c129_int_def,                             ///< 106 - GPIO Port Q6,
    tm4c129_int_def,                             ///< 107 - GPIO Port Q7,
    NULL,                                        ///< 108 - Reserved,
    NULL,                                        ///< 109 - Reserved,
    NULL,                                        ///< 110 - Reserved,
    NULL,                                        ///< 111 - Reserved,
    NULL,                                        ///< 112 - Reserved,
    NULL,                                        ///< 113 - Reserved,
    tm4c129_int_def,                             ///< 114 - Timer 6 subtimer A,
    tm4c129_int_def,                             ///< 115 - Timer 6 subtimer B,
    tm4c129_int_def,                             ///< 116 - Timer 7 subtimer A,
    tm4c129_int_def,                             ///< 117 - Timer 7 subtimer B,
    tm4c129_int_def,                             ///< 118 - I2C6 Master and Slave,
    tm4c129_int_def,                             ///< 119 - I2C7 Master and Slave,
    NULL,                                        ///< 120 - Reserved,
    NULL,                                        ///< 121 - Reserved,
    NULL,                                        ///< 122 - Reserved,
    NULL,                                        ///< 123 - Reserved,
    NULL,                                        ///< 124 - Reserved,
    tm4c129_int_def,                             ///< 125 - I2C8 Master and Slave,
    tm4c129_int_def,                             ///< 126 - I2C9 Master and Slave,
    NULL,                                        ///< 127 - Reserved,
    NULL,                                        ///< 128 - Reserved,
    NULL                                         ///< 129 - Reserved.
};

static_assert(sizeof(g_vtable) == MM_VTABLE_SIZE, "Invalid initial ISR table size!");

/*
 * ISR RAM table, aligned as 1024 bytes.
 */
HAL_USED
HAL_ALIGNED(MM_VTABLE_ALIGN)
static void (*g_vtable_ram[MM_VTABLE_ITEMS])(void);
static_assert(sizeof(g_vtable_ram) == MM_VTABLE_SIZE, "Invalid RAM vtable size!");

#ifdef __GNUC__
static_assert(__alignof(g_vtable_ram) == MM_VTABLE_ALIGN, "Invalid RAM vtable align!");
#endif

static const char* g_tm4c129_int_reason = INT_PREFIX "Unknown reason";

/*
 * Thumb assembler macro for stack unwind.
 *
 * Cortex-M4 Devices Generic User Guide.
 *
 * 2.3.7. Exception entry and return.
 * Table 2.17. Exception return behavior.
 *
 * EXC_RETURN[31:0] Description
 *
 * 0xFFFFFFF1 - Return to Handler mode, exception return uses non-floating-point state from MSP and execution
 * uses MSP after return.
 *
 * 0xFFFFFFF9 - Return to Thread mode, exception return uses non-floating-point state from MSP and execution
 * uses MSP after return.
 *
 * 0xFFFFFFFD - Return to Thread mode, exception return uses non-floating-point state from PSP and execution
 * uses PSP after return.
 *
 * 0xFFFFFFE1 - Return to Handler mode, exception return uses floating-point-state from MSP and execution
 * uses MSP after return.
 *
 * 0xFFFFFFE9 - Return to Thread mode, exception return uses floating-point state from MSP and execution
 * uses MSP after return.
 *
 * 0xFFFFFFED - Return to Thread mode, exception return uses floating-point state from PSP and execution
 * uses PSP after return.
 *
 * @note In ISR if bit 2 of LR is set, then execution uses PSP after return in interrupt.
 * if ((LR & 4) == 0) then use MSP.
 */
#define cortex_stack_unwind_thumb()                                                                          \
    __asm volatile("tst lr, #4\n"    /** Test bits (LR & 4), and set Z (Zero Flag) = 1, if bit 2 not set. */ \
                   "ite eq\n"        /** if ((LR & 4) == 0) {Z=1} */                                         \
                   "mrseq r0, msp\n" /** then R0 = MSP */                                                    \
                   "mrsne r0, psp\n" /** else R0 = PSP */                                                    \
                   "mrs r1, ipsr\n"  /** Read IPSR into R1 */                                                \
                   "b cortex_stack_unwind\n");

/*
 * Driver interface functions.
 */
bool tm4c129_int_init(void)
{
    if (!HAL_IS_ALIGNED((uintptr_t)g_vtable_ram, MM_VTABLE_ALIGN))
    {
        hal_errorf("g_vtable_ram align != %u!", (unsigned)MM_VTABLE_ALIGN);
        return false;
    }

    hal_ll_cr_sect_enter();

    /* Set default ISR handlers and enable some system interrupts. */
    tm4c129_int_setup_defaults();

    /* Set new ISR table pointer. */
    HWREG(NVIC_VTABLE) = (uintptr_t)g_vtable_ram;

    hal_ll_cr_sect_leave();
    return true;
}

bool tm4c129_int_register(size_t isr, void (*handler)(void))
{
    if ((isr < FAULT_NMI) || (isr >= NUM_INTERRUPTS))
    {
        return false;
    }

    hal_ll_cr_sect_enter();

    g_vtable_ram[isr] = (handler == NULL) ? tm4c129_int_def : handler;

    hal_ll_cr_sect_leave();

    return true;
}

bool tm4c129_int_pri_set(size_t isr, enum tm4c129_int_pri pri)
{
    if ((isr < FAULT_MPU) || (isr >= NUM_INTERRUPTS))
    {
        return false;
    }

    IntPrioritySet(isr, (uint8_t)pri);
    return true;
}

void tm4c129_int_nvic_enable(size_t isr)
{
    IntEnable(isr);
}

void tm4c129_int_nvic_disable(size_t isr)
{
    IntDisable(isr);
}

/*
 * Local functions.
 */
void tm4c129_int_setup_defaults(void)
{
    g_vtable_ram[0]             = g_vtable[0]; /* Initial stack pointer, it is not necessary for RAM vtable. */
    g_vtable_ram[1]             = g_vtable[1]; /* Reset handler, it is not necessary for RAM vtable. */
    g_vtable_ram[FAULT_NMI]     = tm4c129_int_nmi;
    g_vtable_ram[FAULT_HARD]    = tm4c129_int_hard_fault;
    g_vtable_ram[FAULT_MPU]     = tm4c129_int_mpu_fault;
    g_vtable_ram[FAULT_BUS]     = tm4c129_int_bus_fault;
    g_vtable_ram[FAULT_USAGE]   = tm4c129_int_usage_fault;
    g_vtable_ram[FAULT_SVCALL]  = tm4c129_int_def;
    g_vtable_ram[FAULT_DEBUG]   = tm4c129_int_def;
    g_vtable_ram[FAULT_PENDSV]  = tm4c129_int_def;
    g_vtable_ram[FAULT_SYSTICK] = tm4c129_int_def;

    for (size_t i = (FAULT_SYSTICK + 1); i < MM_VTABLE_ITEMS; i++) { g_vtable_ram[i] = tm4c129_int_def; }

    tm4c129_int_nvic_enable(FAULT_NMI);
    tm4c129_int_nvic_enable(FAULT_HARD);
    tm4c129_int_nvic_enable(FAULT_MPU);
    tm4c129_int_nvic_enable(FAULT_BUS);
    tm4c129_int_nvic_enable(FAULT_USAGE);
}

HAL_USED void tm4c129_int_def(void)
{
    g_tm4c129_int_reason = INT_PREFIX "Default interrupt!";
    cortex_stack_unwind_thumb();
}

HAL_USED void tm4c129_int_nmi(void)
{
    g_tm4c129_int_reason = INT_PREFIX "NMI interrupt!";
    cortex_stack_unwind_thumb();
}

HAL_USED void tm4c129_int_hard_fault(void)
{
    g_tm4c129_int_reason = INT_PREFIX "Hard fault!";
    cortex_stack_unwind_thumb();
}

HAL_USED void tm4c129_int_mpu_fault(void)
{
    g_tm4c129_int_reason = INT_PREFIX "MPU fault!";
    cortex_stack_unwind_thumb();
}

HAL_USED void tm4c129_int_bus_fault(void)
{
    g_tm4c129_int_reason = INT_PREFIX "Bus fault!";
    cortex_stack_unwind_thumb();
}

HAL_USED void tm4c129_int_usage_fault(void)
{
    g_tm4c129_int_reason = INT_PREFIX "Usage fault!";
    cortex_stack_unwind_thumb();
}

/*
 * cortex_stack_unwind() used only in assembler code.
 * HAL_USED is necessary for LTO builds.
 */
HAL_USED void cortex_stack_unwind(uintptr_t* sp, uintptr_t ipsr)
{
    const uintptr_t r0 = sp[0];
    const uintptr_t r1 = sp[1];
    const uintptr_t r2 = sp[2];
    const uintptr_t r3 = sp[3];

    const uintptr_t r12 = sp[4];
    const uintptr_t lr  = sp[5];
    const uintptr_t pc  = sp[6];
    const uintptr_t psr = sp[7];

    const uintptr_t fsr  = HWREG(NVIC_FAULT_STAT);
    const uintptr_t hfsr = HWREG(NVIC_HFAULT_STAT);
    const uintptr_t dsr  = HWREG(NVIC_DEBUG_STAT);
    const uintptr_t mmar = HWREG(NVIC_MM_ADDR);
    const uintptr_t far  = HWREG(NVIC_FAULT_ADDR);

    hal_printf("\n\n"
               "%s\n\n"
               "MCU Regs:\n"
               "R0  = 0x%08X, R1 = 0x%08X, R2 = 0x%08X, R3  = 0x%08X\n"
               "R12 = 0x%08X, LR = 0x%08X, PC = 0x%08X, PSR = 0x%08X\n\n"
               "IPSR = %d, FSR = 0x%08X, HFSR = 0x%08X, DSR = 0x%08X, MMAR = 0x%08X, FAR = 0x%08X\n\n",
               g_tm4c129_int_reason,
               r0,
               r1,
               r2,
               r3,
               r12,
               lr,
               pc,
               psr,
               ipsr,
               fsr,
               hfsr,
               dsr,
               mmar,
               far);

    hal_mcu_halt();
}
