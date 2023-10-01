#include <stdio.h>
#include <stdlib.h>

#include <hal/hal.h>

_Noreturn void _Exit(int ec)
{
    fprintf(stderr, LIBC_PREFIX "_Exit(%d)\n", ec);
    hal_mcu_halt();
}
