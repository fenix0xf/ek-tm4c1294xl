#include <stdio.h>
#include <stdlib.h>

_Noreturn void exit(int code)
{
    fprintf(stderr, LIBC_PREFIX "exit(%d)\n", code);
    _Exit(code);
}
