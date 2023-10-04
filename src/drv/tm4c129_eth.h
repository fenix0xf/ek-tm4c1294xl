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

#include <stdint.h>
#include <stdbool.h>
#include <drv/tm4c129.h>

#define TM4C129_ETH_EMAC_INTERRUPTS                                                                             \
    (EMAC_INT_RECEIVE | EMAC_INT_TRANSMIT | EMAC_INT_TX_STOPPED | EMAC_INT_RX_NO_BUFFER | EMAC_INT_RX_STOPPED | \
     EMAC_INT_PHY)

#define TM4C129_ETH_MAC_ADDR_SIZE 6

/**
 * Driver interface functions.
 *
 */

/**
 * @param [sys_clk] MCU Clock in Hz.
 * @param [mac] is uint8_t buf[TM4C129_ETH_MAC_ADDR_SIZE] MAC hardware address, if mac == NULL, then using default MAC.
 */
bool tm4c129_eth_init(size_t sys_clk, const uint8_t* mac);

/**
 * @return pointer to static uint8_t buf[TM4C129_ETH_MAC_ADDR_SIZE] with real MAC hardware address.
 */
uint8_t* tm4c129_eth_mac(void);

#define tm4c129_eth_int_enable()        EMACIntEnable(EMAC0_BASE, TM4C129_ETH_EMAC_INTERRUPTS)
#define tm4c129_eth_int_disable()       EMACIntDisable(EMAC0_BASE, TM4C129_ETH_EMAC_INTERRUPTS)
#define tm4c129_eth_int_status()        EMACIntStatus(EMAC0_BASE, true)
#define tm4c129_eth_int_status_clear(s) EMACIntClear(EMAC0_BASE, s)
#define tm4c129_eth_link_up()           (EMACPHYRead(EMAC0_BASE, 0, EPHY_BMSR) & EPHY_BMSR_LINKSTAT)
