#include "stdio_impl.h"

static inline int do_getc(FILE* f)
{
    FLOCK(f);
    int c = getc_unlocked(f);
    FUNLOCK(f);

    return c;
}
