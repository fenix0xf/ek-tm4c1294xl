#include "stdio_impl.h"

#include <unistd.h>

#undef stdin

static unsigned char buf[BUFSIZ + UNGET];

FILE                 __stdin_FILE = {
                    .buf      = buf + UNGET,
                    .buf_size = sizeof buf - UNGET,
                    .fd       = STDIN_FILENO,
                    .flags    = F_PERM | F_NOWR,
                    .read     = __stdio_read,
                    .lock     = NULL,
};

FILE* const stdin = &__stdin_FILE;
