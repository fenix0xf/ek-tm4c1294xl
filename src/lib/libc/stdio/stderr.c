#include "stdio_impl.h"

#include <unistd.h>

#undef stderr

static unsigned char buf[UNGET];

hidden FILE __stderr_FILE = {
    .buf      = buf + UNGET,
    .buf_size = 0,
    .fd       = STDERR_FILENO,
    .flags    = F_PERM | F_NORD,
    .lbf      = -1,
    .write    = __stdio_write,
    .mutex    = NULL,
};

FILE* const stderr = &__stderr_FILE;
