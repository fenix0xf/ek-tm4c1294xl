#include "stdio_impl.h"

int puts(const char* s)
{
    int rc;
    FLOCK(stdout);
    rc = -(fputs(s, stdout) < 0 || putc_unlocked('\n', stdout) < 0);
    FUNLOCK(stdout);
    return rc;
}
