#include <stdio.h>
#include <stdlib.h>

_Noreturn void abort(void)
{
    fputs(LIBC_PREFIX "abort()\n", stderr);
    _Exit(127);
}
