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

#include "hal_crt.h"

#include <hal/hal.h>
#include <hal/hal_con.h>
#include <drv/tm4c129_uart_dbg.h>

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
// #include <malloc.h>
#include <unistd.h>

#define CRT_HEAP_DEBUG DEBUG
#define SYSCALL_PREFIX "SYSCALL: "

/* Linker symbols from src/firmware.ld.
 *
 * &g_ld_ldata  - address of .data section in FLASH memory.
 * &g_ld_data   - address of .data section in SRAM memory.
 * &g_ld_edata  - address of end of .data section in SRAM memory.
 * &g_ld_bss    - address of .bss section in SRAM memory.
 * &g_ld_ebss   - address of end of .bss section in SRAM memory.
 */
extern uintptr_t g_ld_ldata;
extern uintptr_t g_ld_data;
extern uintptr_t g_ld_edata;
extern uintptr_t g_ld_bss;
extern uintptr_t g_ld_ebss;

/*
 * Global heap for system malloc() function.
 */
HAL_HEAP_SECTION(g_heap)
static char g_heap[64 * 1024];

static intptr_t              g_heap_brk;
static hal_crt_stdout_func_t g_stdout_func;

void hal_crt_init(hal_crt_stdout_func_t stdout_func)
{
    /* Copy the data segment initializers from FLASH to SRAM. */
    uintptr_t* src = &g_ld_ldata;
    uintptr_t* dst = &g_ld_data;
    while (dst < &g_ld_edata) { *dst++ = *src++; }

    /* Zero fill the bss segment. */
    dst = &g_ld_bss;
    while (dst < &g_ld_ebss) { *dst++ = 0; }

    /* Set all global variables after data and bss segment initialization. */
    g_heap_brk = (intptr_t)g_heap; /* Heap initialization: malloc can be used after this. */
    hal_crt_stdout_func_set(stdout_func);
}

void hal_crt_stdout_func_set(hal_crt_stdout_func_t stdout_func)
{
    g_stdout_func = stdout_func;
}

/*
 * Implementation of LIBC platform syscalls.
 */

// int gettimeofday(struct timeval* ptimeval, struct timezone* tz)
//{
//     (void)ptimeval;
//     (void)tz;
//     return (-1); // todo to implement
// }

ssize_t read(int fd, void* buf, size_t nbyte)
{
    if (HAL_UNLIKELY(nbyte == 0))
    {
        return 0; /* It is EOF. */
    }

    if (HAL_UNLIKELY(nbyte > SSIZE_MAX))
    {
        errno = EINVAL;
        return (-1); /* It is not EOF but just an error. */
    }

    if (HAL_UNLIKELY(fd != STDIN_FILENO))
    {
        errno = EBADF;
        return (-1); /* It is not EOF but just an error. */
    }

    (void)buf; // todo

    return 0;
}

ssize_t write(int fd, const void* buf, size_t nbyte)
{
    if (HAL_UNLIKELY(nbyte == 0))
    {
        return 0; /* It is EOF. */
    }

    if (HAL_UNLIKELY(nbyte > SSIZE_MAX))
    {
        errno = EINVAL;
        return (-1); /* It is not EOF but just an error. */
    }

    /*
     * This handler only writes to "standard out" and "standard error", for all other file handles it returns failure.
     */
    if (HAL_UNLIKELY((fd != STDOUT_FILENO) && (fd != STDERR_FILENO)))
    {
        errno = EBADF;
        return (-1); /* It is not EOF but just an error. */
    }

    if (HAL_LIKELY(g_stdout_func != NULL))
    {
        g_stdout_func(buf, nbyte);
    }
    else
    {
        hal_mcu_halt();
    }

    return (ssize_t)nbyte;
}

void* sbrk(intptr_t incr)
{
    hal_ll_cr_sect_enter();

    intptr_t  brk  = g_heap_brk;
    ptrdiff_t used = brk - (intptr_t)g_heap;

    if (HAL_UNLIKELY((used + incr) > (intptr_t)sizeof(g_heap)))
    {
        hal_ll_cr_sect_leave();

        hal_errorf(SYSCALL_PREFIX "NO HEAP MEMORY! _sbrk(%d bytes), used/total: %d/%u bytes",
                   (int)incr,
                   used,
                   sizeof(g_heap));

        errno = ENOMEM;
        return (void*)(-1);
    }

    g_heap_brk += incr;

    hal_ll_cr_sect_leave();

    if (HAL_UNLIKELY(g_heap_brk < (ptrdiff_t)g_heap))
    {
        hal_errorf(SYSCALL_PREFIX "HEAP FREE ERROR! _sbrk(%d bytes), used/total: %d/%u bytes",
                   (int)incr,
                   used,
                   sizeof(g_heap));

        hal_mcu_halt();
    }

#if CRT_HEAP_DEBUG
    used = (ptrdiff_t)g_heap_brk - (ptrdiff_t)g_heap;
    hal_printf(SYSCALL_PREFIX "_sbrk(%d bytes), used/free/total: %d/%u/%u bytes\n",
               (int)incr,
               used,
               sizeof(g_heap) - (uintptr_t)used,
               sizeof(g_heap));
#endif

    return (void*)brk;
}
