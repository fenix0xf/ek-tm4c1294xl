#include "stdio_impl.h"

#include <unistd.h>

#undef stdout

static unsigned char buf[BUFSIZ + UNGET];

FILE __stdout_FILE = {
    .buf      = buf + UNGET,
    .buf_size = sizeof buf - UNGET,
    .fd       = STDOUT_FILENO,
    .flags    = F_PERM | F_NORD,
    .lbf      = -1,
    .write    = __stdio_write,
    .lock     = NULL,
};

FILE* const stdout = &__stdout_FILE;
