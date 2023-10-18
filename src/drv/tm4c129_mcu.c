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

#include "tm4c129_mcu.h"

#include <drv/tm4c129.h>

/*
 * Get uint8_t part number from uint32_t register "Device Identification 1" value.
 */
#define U8PRTNO(n) (uint8_t)((n & SYSCTL_DID1_PRTNO_M) >> 16)

struct mcu_part
{
    const uint8_t     prtno;
    const char* const name;
};

/*
 * MCU TM4C129x table.
 */
static const struct mcu_part g_mcu_part[] = {
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C1290NCPDT), "TM4C1290NCPDT"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C1290NCZAD), "TM4C1290NCZAD"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C1292NCPDT), "TM4C1292NCPDT"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C1292NCZAD), "TM4C1292NCZAD"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C1294KCPDT), "TM4C1294KCPDT"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C1294NCPDT), "TM4C1294NCPDT"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C1294NCZAD), "TM4C1294NCZAD"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C1297NCZAD), "TM4C1297NCZAD"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C1299KCZAD), "TM4C1299KCZAD"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C1299NCZAD), "TM4C1299NCZAD"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C129CNCPDT), "TM4C129CNCPDT"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C129CNCZAD), "TM4C129CNCZAD"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C129DNCPDT), "TM4C129DNCPDT"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C129DNCZAD), "TM4C129DNCZAD"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C129EKCPDT), "TM4C129EKCPDT"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C129ENCPDT), "TM4C129ENCPDT"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C129ENCZAD), "TM4C129ENCZAD"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C129LNCZAD), "TM4C129LNCZAD"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C129XKCZAD), "TM4C129XKCZAD"},
    {U8PRTNO(SYSCTL_DID1_PRTNO_TM4C129XNCZAD), "TM4C129XNCZAD"},
    {0,                                        NULL           },
};

static void tm4c129_mcu_periph_power_off(uint32_t periph)
{
    if (SysCtlPeripheralPresent(periph))
    {
        SysCtlPeripheralPowerOff(periph);
    }
}

static void tm4c129_mcu_power_save_setup(void)
{
    tm4c129_mcu_periph_power_off(SYSCTL_PERIPH_CAN0);
    tm4c129_mcu_periph_power_off(SYSCTL_PERIPH_CAN1);
    tm4c129_mcu_periph_power_off(SYSCTL_PERIPH_EMAC0);
    tm4c129_mcu_periph_power_off(SYSCTL_PERIPH_EPHY0);
    tm4c129_mcu_periph_power_off(SYSCTL_PERIPH_LCD0);
    tm4c129_mcu_periph_power_off(SYSCTL_PERIPH_USB0);
}

/*
 * This function is called before initialization of C standard library.
 * Static variables are in a non-initialized state!
 * Don't use static variables here, use only variables on a stack!
 */
bool tm4c129_mcu_init(void)
{
    tm4c129_mcu_power_save_setup();

    FPUEnable();

    /*
     * Errata MEM#09
     *
     * Description: The ROM_SysCtlClockFreqSet() function does not properly configure the MOSC.
     * Due to this erratum, any ROM functions that rely on the proper operation of the MOSC,
     * such as the Ethernet boot loader, will not function correctly.
     *
     * Workaround(s): Use the TivaWare function of SysCtlClockFreqSet() in Flash memory.
     */
    size_t cpu_frequency = SysCtlClockFreqSet(SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_240,
                                              TM4C129_MCU_FREQUENCY);

    return cpu_frequency == TM4C129_MCU_FREQUENCY;
}

HAL_NORETURN void tm4c129_mcu_halt(void)
{
    tm4c129_mcu_int_off();

#if DEBUG
    /* If a debugger is present, then break into the debugger. */
    if (HWREG(NVIC_DBG_CTRL) & NVIC_DBG_CTRL_C_DEBUGEN)
    {
        TM4C129_MCU_BKPT();
    }
#endif

    for (;;) {}
}

HAL_NORETURN void tm4c129_mcu_reset(void)
{
    SysCtlReset();
    for (;;) {} /* To eliminate warning: 'noreturn' function does return. */
}

void tm4c129_mcu_systick_on(size_t frequency)
{
    SysTickDisable();
    SysTickPeriodSet(TM4C129_MCU_TICKS_PER_S / frequency);
    SysTickIntEnable();
    SysTickEnable();
}

const char* tm4c129_mcu_name(void)
{
    static char buf[32];

    if (*buf)
    {
        return buf;
    }

    if (!CLASS_IS_TM4C129)
    {
        /* MCU is not TM4C129 class. */
        return CLASS_IS_TM4C123 ? "TM4C123 class" : "Unknown";
    }

    /* Read "Device Identification 1" register and get part number as uint8_t. */
    const uint8_t prtno = U8PRTNO(HWREG(SYSCTL_DID1));

    const struct mcu_part* part = g_mcu_part;
    const char*            name;

    for (;; part++)
    {
        if (HAL_UNLIKELY(part->name == NULL))
        {
            /* Not found in TM4C129 MCU table. */
            name = "TM4C129 class";
            break;
        }
        else if (HAL_UNLIKELY(part->prtno == prtno))
        {
            name = part->name;
            break;
        }
    }

    /* Read "Device Identification 0" register and get major and minor revision as uint8_t. */
    const uint8_t rev_maj = (uint8_t)((HWREG(SYSCTL_DID0) & SYSCTL_DID0_MAJ_M) >> 8);
    const uint8_t rev_min = (uint8_t)(HWREG(SYSCTL_DID0) & SYSCTL_DID0_MIN_M);

    char* p = buf;

    /* "TM4C1294NCPDT Rev A2" */
    while ((*p++ = *name++)) {}
    p--;

    *p++ = ' ';
    *p++ = 'R';
    *p++ = 'e';
    *p++ = 'v';
    *p++ = ' ';
    *p++ = (char)('A' + rev_maj);
    *p++ = (char)('0' + rev_min);
    *p   = '\0';

    return buf;
}

size_t tm4c129_mcu_sram_size(void)
{
    return SysCtlSRAMSizeGet();
}

size_t tm4c129_mcu_flash_size(void)
{
    return SysCtlFlashSizeGet();
}

size_t tm4c129_mcu_flash_sector_size(void)
{
    return SysCtlFlashSectorSizeGet();
}

/*
 * Simple delay in 3 MCU cycles per one loop.
 * "count" is the number of delay loop iterations to perform.
 */
HAL_NAKED void tm4c129_mcu_3cycles_delay(HAL_UNUSED uint32_t count)
{
    __asm("subs r0, #1\n"                    /* 1 MCU cycle. */
          "bne  tm4c129_mcu_3cycles_delay\n" /* 2 MCU cycles if the branch is taken */
          "bx   lr\n");
}

void tm4c129_mcu_prefetch_off(void)
{
    HWREG(FLASH_CONF) |= (uintptr_t)FLASH_CONF_FPFOFF;
}

void tm4c129_mcu_prefetch_on(void)
{
    HWREG(FLASH_CONF) &= ~(uintptr_t)FLASH_CONF_FPFOFF;
}

void tm4c129_mcu_unique_id(uint32_t* id0, uint32_t* id1, uint32_t* id2, uint32_t* id3)
{
    if (id3 != NULL)
    {
        *id3 = HWREG(SYSCTL_UNIQUEID0);
    }

    if (id2 != NULL)
    {
        *id2 = HWREG(SYSCTL_UNIQUEID1);
    }

    if (id1 != NULL)
    {
        *id1 = HWREG(SYSCTL_UNIQUEID2);
    }

    if (id0 != NULL)
    {
        *id0 = HWREG(SYSCTL_UNIQUEID3);
    }
}
