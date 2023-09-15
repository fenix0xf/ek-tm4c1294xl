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

/* Don not use __align from C code, it refers to value at address 0x00000008 inside vtable. */
__align = 0x00000008;

SECTIONS
{
    .text :
    {
        . = ALIGN(__align);
        KEEP(*(.vtable))
        . = ALIGN(__align);
        KEEP(*(.version))
        . = ALIGN(__align);
        *(.psvhandler)
        . = ALIGN(__align);
        *(.text*)
        . = ALIGN(__align);
        *(.rodata*)
        . = ALIGN(__align);
    } > FLASH

    .ARM.exidx :
    {
        . = ALIGN(__align);
        *(.ARM.exidx*)
        . = ALIGN(__align);
    } > FLASH

    g_ld_ldata = LOADADDR(.data);

    .data :
    {
        . = ALIGN(__align);
        g_ld_data = .;
        *(.data*)
        g_ld_edata = .;
        . = ALIGN(__align);
    } > SRAM AT> FLASH

    .bss (NOLOAD) :
    {
        . = ALIGN(__align);
        g_ld_bss = .;
        *(.bss*)
        . = ALIGN(__align);
        *(COMMON)
        g_ld_ebss = .;
        . = ALIGN(__align);
    } > SRAM

    .noinit (NOLOAD) :
    {
        . = ALIGN(__align);
        *(.noinit.common*)
        *(.noinit.stack*)
        *(.noinit.heap*)
        . = ALIGN(__align);
    } > SRAM
}
