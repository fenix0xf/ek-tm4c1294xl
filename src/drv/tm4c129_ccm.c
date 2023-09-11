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

#include "tm4c129_ccm.h"
#include <drv/tm4c129.h>

/**
 * Driver interface functions.
 *
 */
bool tm4c129_ccm_init(void)
{
    return tm4c129_periph_init(SYSCTL_PERIPH_CCM0, TM4C129_PERIPH_OPT_RESET);
}

void tm4c129_ccm_free(void)
{
    tm4c129_periph_free(SYSCTL_PERIPH_CCM0);
}

uint32_t tm4c129_ccm_crc32_mpeg_8bit(const void* buf, size_t len, uint32_t seed)
{
    CRCConfigSet(CCM0_BASE, CRC_CFG_INIT_SEED | CRC_CFG_TYPE_P4C11DB7 | CRC_CFG_SIZE_8BIT);
    CRCSeedSet(CCM0_BASE, seed);

    return CRCDataProcess(CCM0_BASE, (uint32_t*)buf, (uint32_t)len, false);
}

uint32_t tm4c129_ccm_crc32_mpeg_32bit(const void* buf, size_t len, uint32_t seed)
{
    CRCConfigSet(CCM0_BASE, CRC_CFG_INIT_SEED | CRC_CFG_TYPE_P4C11DB7 | CRC_CFG_SIZE_32BIT);
    CRCSeedSet(CCM0_BASE, seed);

    return CRCDataProcess(CCM0_BASE, (uint32_t*)buf, (uint32_t)len, false);
}
