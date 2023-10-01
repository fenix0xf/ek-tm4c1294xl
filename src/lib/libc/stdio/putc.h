#include "stdio_impl.h"

static inline int do_putc(int c, FILE* f)
{
    FLOCK(f);
    c = putc_unlocked(c, f);
    FUNLOCK(f);

    return c;
}
