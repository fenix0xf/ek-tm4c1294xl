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
#include <drv/tm4c129_int.h>
#include <drv/tm4c129_uart_dbg.h>

#include <tn.h>

#define HAL_PREFIX          "HAL: "

#define HAL_REBOOT_PAUSE_mS 1000

static void       hal_systick_handler(void);

HAL_NORETURN void hal_mcu_halt(void)
{
    hal_mcu_int_off();

#if TN_STACK_CHECK
    if (HAL_LIKELY(tn_system_is_running()))
    {
        tn_task_stack_check_all();
    }
#endif /* TN_STACK_CHECK */

    tm4c129_uart_dbg_puts("\n" HAL_PREFIX "System is halted!");
    tm4c129_uart_dbg_free();

    tm4c129_mcu_halt();
}

uint32_t hal_mcu_unique_id(void)
{
    uint32_t mcu_id[4];
    tm4c129_mcu_unique_id(&mcu_id[0], &mcu_id[1], &mcu_id[2], &mcu_id[3]);
    //    *id = hal_checksum_crc32_mpeg_calc(mcu_id, sizeof(mcu_id), HAL_CHECKSUM_CRC32_MPEG_SEED);
    return 0; // TODO
}

/*
 * Universal sleep function.
 */
void hal_sleep(size_t mS)
{
    if (HAL_LIKELY(tn_system_is_running()))
    {
        tn_task_sleep(mS);
    }
    else
    {
        hal_mcu_mdelay(mS);
    }
}

HAL_NORETURN void hal_system_startup(void)
{
    hal_mcu_int_off();

    hal_puts("\n" HAL_PREFIX "Starting OS kernel...\n");

    /*
     * Set PendSV handler for TN Kernel task switching.
     * See src/lib/tnkernel/arch/tn_arch_CortexM0_M7_asm.S and src/lib/tnkernel/arch/tn_arch.h
     */
    if (!tm4c129_int_register(FAULT_PENDSV, tn_pendsv_handler))
    {
        hal_error("tm4c129_int_register(FAULT_PENDSV, tn_pendsv_handler)");
        hal_mcu_halt();
    }

    if (!tm4c129_int_register(FAULT_SYSTICK, hal_systick_handler))
    {
        hal_error("tm4c129_int_register(FAULT_SYSTICK, hal_systick_handler)");
        hal_mcu_halt();
    }

    tm4c129_mcu_systick_on(HAL_SYSTICK_FREQUENCY);

    /* tn_app_init() is called inside. */
    int rc = tn_start_system(NULL, 0);

    /*
     * Never reach this.
     */
    hal_errorf("tn_start_system() returns %d!", rc);
    hal_mcu_halt();
}

HAL_NORETURN void hal_system_reboot(void)
{
    hal_mcu_int_off();

    tm4c129_uart_dbg_puts("\n" HAL_PREFIX "System reboot!");
    tm4c129_uart_dbg_free();

    hal_mcu_mdelay(HAL_REBOOT_PAUSE_mS);
    tm4c129_mcu_reset();
}

/*
 * Local functions.
 */
void hal_systick_handler(void)
{
    /* Calling the TNKernel scheduler every one millisecond. */
    tn_tick_int_processing();
    tn_int_exit();
}

void hal_print_version(void)
{
    uint32_t id0, id1, id2, id3;

    /* Get MCU full hardware ID. */
    tm4c129_mcu_unique_id(&id0, &id1, &id2, &id3);

    hal_printf("\n\n"
               "%s (%s) %s!\n"
               "Board: EK-TM4C1294XL Rev D\n"
               "MCU  : %s [%u MHz]\n"
               "SRAM : %u KiB\n"
               "FLASH: %u/%u KiB\n"
               "MCUID: 0x%08X, 0x%08X, 0x%08X, 0x%08X\n\n",

               "Test Firmware", /* hal_version(), */
               DEBUG ? "Debug" : "Release",
               "© 2023 Alexander Kotikov", /* hal_copyright(), */
               hal_mcu_name(),
               (unsigned)HAL_MCU_FREQUENCY_MHz,
               (unsigned)(hal_mcu_sram_size() / 1024),
               (unsigned)(hal_mcu_flash_size() / 1024),
               (unsigned)(hal_mcu_flash_sector_size() / 1024),
               (unsigned)id0,
               (unsigned)id1,
               (unsigned)id2,
               (unsigned)id3);
}
