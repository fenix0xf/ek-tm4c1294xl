/*

 MIT License

 Copyright © 2023 Alexander Kotikov, alexandr.kotikov@gmail.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

 */

#include <hal/hal.h>
#include <hal/hal_con.h>
#include <hal/hal_init.h>

#include <tn.h>
#include <libc.h>
#include <stdbool.h>

#define OS_PREFIX "OS: "

bool init_stdio_lock(void)
{
    static TN_MUTEX stdin_mutex, stdout_mutex, stderr_mutex;
    bool            rc;

    rc  = tn_mutex_create(&stdin_mutex, TN_MUTEX_ATTR_INHERIT) == TERR_NO_ERR;
    rc &= tn_mutex_create(&stdout_mutex, TN_MUTEX_ATTR_INHERIT) == TERR_NO_ERR;
    rc &= tn_mutex_create(&stderr_mutex, TN_MUTEX_ATTR_INHERIT) == TERR_NO_ERR;

    if (rc)
    {
        libc_set_file_lock(stdin, &stdin_mutex);
        libc_set_file_lock(stdout, &stdout_mutex);
        libc_set_file_lock(stderr, &stderr_mutex);
    }

    return rc;
}

/*
 * Before a call tn_app_init() all interrupts are disabled by the caller.
 * After an return from this function all interrupts will be enabled.
 *
 * Do not use tn_task_sleep() inside! This function enable interrupts!
 */
int tn_app_init(void)
{
    HAL_INIT_ASSERT(OS_PREFIX "Stdio lock init...", init_stdio_lock());

    return TERR_NO_ERR;
}
