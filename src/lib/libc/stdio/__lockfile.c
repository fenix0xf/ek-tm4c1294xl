#include "stdio_impl.h"

#include <tn.h>
#include <hal/hal.h>
#include <hal/hal_con.h>

int __lockfile(FILE* f)
{
    TN_MUTEX* mutex = (TN_MUTEX*)f->mutex;

    if (HAL_UNLIKELY(!tn_system_is_running() || tn_inside_int() || (mutex == NULL)))
    {
        return 0;
    }

    int rc = tn_mutex_lock(mutex, TN_WAIT_INFINITE);

    if (HAL_UNLIKELY(rc != TERR_NO_ERR))
    {
        f->mutex = NULL; /* Preventing possible recursive calls. */

        hal_errorf("tn_mutex_lock(0x%p) == %d", mutex, rc);
        hal_mcu_halt();
    }

    return 1;
}

void __unlockfile(FILE* f)
{
    TN_MUTEX* mutex = (TN_MUTEX*)f->mutex;

    if (HAL_UNLIKELY(!tn_system_is_running() || tn_inside_int() || (mutex == NULL)))
    {
        return;
    }

    int rc = tn_mutex_unlock(mutex);

    if (HAL_UNLIKELY(rc != TERR_NO_ERR))
    {
        f->mutex = NULL; /* Preventing possible recursive calls. */

        hal_errorf("tn_mutex_unlock(0x%p) == %d", mutex, rc);
        hal_mcu_halt();
    }
}
