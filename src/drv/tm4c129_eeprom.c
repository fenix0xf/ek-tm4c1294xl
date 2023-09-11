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

#include "tm4c129_eeprom.h"

#include <hal/hal_def.h>
#include <drv/tm4c129.h>

enum { TM4C129_EEPROM_ALIGN = sizeof(uint32_t) };

bool tm4c129_eeprom_init(void)
{
    if (!tm4c129_periph_init(SYSCTL_PERIPH_EEPROM0, TM4C129_PERIPH_OPT_RESET))
    {
        return false;
    }

    /**
     * Errata MEM#11
     *
     * Description: The ROM_EEPROMInit API in TivaWare does not correctly initialize the EEPROM module
     * as described in the data sheet. It should not be used to initialize the EEPROM.
     *
     * Workaround: Use the Flash version of the EEPROMInit API in TivaWare version 2.1 or later.
     */
    return EEPROMInit() == EEPROM_INIT_OK;
}

size_t tm4c129_eeprom_size(void)
{
    return EEPROMSizeGet();
}

size_t tm4c129_eeprom_align(void)
{
    return TM4C129_EEPROM_ALIGN;
}

bool tm4c129_eeprom_mass_erase(void)
{
    return EEPROMMassErase() == 0;
}

bool tm4c129_eeprom_read(uintptr_t addr, void* buf, size_t len)
{
    if (!HAL_IS_POW2_ALIGNED(addr, TM4C129_EEPROM_ALIGN) || !HAL_IS_POW2_ALIGNED(len, TM4C129_EEPROM_ALIGN))
    {
        return false;
    }

    if ((addr + len) > tm4c129_eeprom_size())
    {
        return false;
    }

    EEPROMRead((uint32_t*)buf, addr, len);
    return true;
}

bool tm4c129_eeprom_write(uintptr_t addr, const void* buf, size_t len)
{
    if (!HAL_IS_POW2_ALIGNED(addr, TM4C129_EEPROM_ALIGN) || !HAL_IS_POW2_ALIGNED(len, TM4C129_EEPROM_ALIGN))
    {
        return false;
    }

    if ((addr + len) > tm4c129_eeprom_size())
    {
        return false;
    }

    return EEPROMProgram((uint32_t*)buf, addr, len) == 0;
}
