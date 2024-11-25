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

#include "tm4c129_eth.h"

/**
 * Default TI MAC 00:1A:B6:00:64:00 (00:1A:B6 - Texas Instruments, 00:64:00 - TI BOOTP loader).
 */
static const uint8_t g_mac_def[TM4C129_ETH_MAC_ADDR_SIZE] = {0x00, 0x1A, 0xB6, 0x00, 0x64, 0x00};

/**
 * Set the PHY configuration to the default (internal) option.
 */
#define EMAC_PHY_CONFIG (EMAC_PHY_TYPE_INTERNAL | EMAC_PHY_INT_MDIX_EN | EMAC_PHY_AN_100B_T_FULL_DUPLEX)

bool tm4c129_eth_init(size_t sys_clk, const uint8_t* mac)
{
    if (!tm4c129_periph_init(SYSCTL_PERIPH_EMAC0, TM4C129_PERIPH_OPT_RESET))
    {
        return false;
    }

    if ((EMAC_PHY_CONFIG & EMAC_PHY_TYPE_MASK) == EMAC_PHY_TYPE_INTERNAL)
    {
        if (!tm4c129_periph_init(SYSCTL_PERIPH_EPHY0, TM4C129_PERIPH_OPT_RESET))
        {
            return false;
        }
    }

    EMACPHYConfigSet(EMAC0_BASE, EMAC_PHY_CONFIG);

    EMACInit(EMAC0_BASE, (uint32_t)sys_clk, EMAC_BCONFIG_MIXED_BURST | EMAC_BCONFIG_PRIORITY_FIXED, 4, 4, 0);

    EMACConfigSet(
        EMAC0_BASE,
        (EMAC_CONFIG_FULL_DUPLEX | EMAC_CONFIG_CHECKSUM_OFFLOAD | EMAC_CONFIG_7BYTE_PREAMBLE | EMAC_CONFIG_IF_GAP_96BITS |
         EMAC_CONFIG_USE_MACADDR0 | EMAC_CONFIG_SA_FROM_DESCRIPTOR | EMAC_CONFIG_BO_LIMIT_1024),
        (EMAC_MODE_RX_STORE_FORWARD | EMAC_MODE_TX_STORE_FORWARD | EMAC_MODE_TX_THRESHOLD_64_BYTES | EMAC_MODE_RX_THRESHOLD_64_BYTES),
        0);

    /**
     * Set MAC address.
     */
    EMACAddrSet(EMAC0_BASE, 0, (mac != NULL) ? mac : g_mac_def);

    if (!tm4c129_periph_init(SYSCTL_PERIPH_GPIOK, TM4C129_PERIPH_OPT_DEFAULT))
    {
        return false;
    }

    GPIOPinConfigure(GPIO_PK4_EN0LED0);
    GPIOPinConfigure(GPIO_PK6_EN0LED1);
    GPIOPinTypeEthernetLED(GPIO_PORTK_BASE, GPIO_PIN_4 | GPIO_PIN_6);

    /**
     * Inverse Ethernet LEDs.
     */
    HWREG(EMAC0_BASE + EMAC_O_CC) |= EMAC_CC_POL;
    return true;
}

uint8_t* tm4c129_eth_mac(void)
{
    static uint8_t buf[TM4C129_ETH_MAC_ADDR_SIZE];
    EMACAddrGet(EMAC0_BASE, 0, buf);
    return buf;
}
