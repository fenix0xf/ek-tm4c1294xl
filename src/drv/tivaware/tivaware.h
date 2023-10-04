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

#include <inc/hw_adc.h>
#include <inc/hw_aes.h>
#include <inc/hw_can.h>
#include <inc/hw_ccm.h>
#include <inc/hw_comp.h>
#include <inc/hw_des.h>
#include <inc/hw_eeprom.h>
#include <inc/hw_emac.h>
#include <inc/hw_epi.h>
#include <inc/hw_fan.h>
#include <inc/hw_flash.h>
#include <inc/hw_gpio.h>
#include <inc/hw_hibernate.h>
#include <inc/hw_i2c.h>
#include <inc/hw_ints.h>
#include <inc/hw_lcd.h>
#include <inc/hw_memmap.h>
#include <inc/hw_nvic.h>
#include <inc/hw_onewire.h>
#include <inc/hw_pwm.h>
#include <inc/hw_qei.h>
#include <inc/hw_shamd5.h>
#include <inc/hw_ssi.h>
#include <inc/hw_sysctl.h>
#include <inc/hw_sysexc.h>
#include <inc/hw_timer.h>
#include <inc/hw_types.h>
#include <inc/hw_uart.h>
#include <inc/hw_udma.h>
#include <inc/hw_usb.h>
#include <inc/hw_watchdog.h>

#include <driverlib/adc.h>
#include <driverlib/aes.h>
#include <driverlib/can.h>
#include <driverlib/comp.h>
#include <driverlib/cpu.h>
#include <driverlib/crc.h>
#include <driverlib/debug.h>
#include <driverlib/des.h>
#include <driverlib/eeprom.h>
#include <driverlib/emac.h>
#include <driverlib/epi.h>
#include <driverlib/flash.h>
#include <driverlib/fpu.h>
#include <driverlib/gpio.h>
#include <driverlib/hibernate.h>
#include <driverlib/i2c.h>
#include <driverlib/interrupt.h>
#include <driverlib/lcd.h>
#include <driverlib/mpu.h>
#include <driverlib/onewire.h>
#include <driverlib/pwm.h>
#include <driverlib/qei.h>
#include <driverlib/shamd5.h>
#include <driverlib/ssi.h>
#include <driverlib/sw_crc.h>
#include <driverlib/sysctl.h>
#include <driverlib/sysexc.h>
#include <driverlib/systick.h>
#include <driverlib/timer.h>
#include <driverlib/uart.h>
#include <driverlib/udma.h>
#include <driverlib/usb.h>
#include <driverlib/watchdog.h>

/**
 * Mapping of peripherals to pins for concrete part.
 *
 * @note
 * Need to set global project define, e.g. -DPART_TM4C1294NCPDT.
 */
#include <driverlib/pin_map.h>

/**
 * Macros to facilitate calling functions in the MCU ROM.
 *
 * @note
 * Need to set global project define, e.g. -DTARGET_IS_TM4C129_RA2.
 */
#if TIVAWARE_USE_ROM
#include <driverlib/rom.h>
#endif
