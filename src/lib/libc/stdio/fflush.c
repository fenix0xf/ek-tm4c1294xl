#include "stdio_impl.h"

int fflush(FILE* f)
{
    if (!f)
    {
        int r = 0;

        r |= fflush(stderr);
        r |= fflush(stdout);

        return r;
    }

    FLOCK(f);

    /* If writing, flush output */
    if (f->wpos != f->wbase)
    {
        f->write(f, 0, 0);

        if (!f->wpos)
        {
            FUNLOCK(f);
            return EOF;
        }
    }

    /* Clear read and write modes */
    f->wpos = f->wbase = f->wend = 0;
    f->rpos = f->rend = 0;

    FUNLOCK(f);
    return 0;
}
