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

OUTPUT_FORMAT(elf32-littlearm)

ENTRY(hal_init)

MEMORY
{
    FLASH (rx)  : o = 0x00000000, l = 1M
    SRAM (rwx)  : o = 0x20000000, l = 256K
}

SECTIONS
{
    .text :
    {
        KEEP(*(.vtable))
        . = ALIGN(16);
        KEEP(*(.version))
        . = ALIGN(8);
        KEEP(*(.reset))
        . = ALIGN(8);
        *(.text*)
        . = ALIGN(8);
        *(.rodata*)
    } > FLASH

    .ARM.exidx :
    {
        . = ALIGN(16);
        *(.ARM.exidx*)
    } > FLASH

    g_ld_ldata = LOADADDR(.data);

    .data :
    {
        . = ALIGN(16);
        g_ld_data = .;
        *(.data*)
        g_ld_edata = .;
    } > SRAM AT> FLASH

    .bss (NOLOAD) :
    {
        . = ALIGN(16);
        g_ld_bss = .;
        *(.bss*)
        . = ALIGN(8);
        *(COMMON)
        g_ld_ebss = .;
    } > SRAM

    .noinit (NOLOAD) :
    {
        . = ALIGN(16);
        *(.noinit.common*)
        *(.noinit.stack*)
        *(.noinit.heap*)
    } > SRAM

    .fill :
    {
        . = ALIGN(16);
        LONG(0); /* Fill - 4 bytes. */
        LONG(0); /* Fill - 4 bytes. */
        LONG(0); /* Fill - 4 bytes. */
    } > FLASH

    .checksum :
    {
        . = ALIGN(4);
        LONG(0xFFFFFFFF); /* Place for CRC32 - 4 bytes. */
    } > FLASH
}
