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

#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * Timer id's.
 */
enum tm4c129_tmr_id
{
    TM4C129_TMR0,
    TM4C129_TMR1,
    TM4C129_TMR2,
    TM4C129_TMR3,
    TM4C129_TMR4,
    TM4C129_TMR5,
    TM4C129_TMR6,
    TM4C129_TMR7,

    TM4C129_TMR_COUNT,
};

/**
 * Timer modes.
 */
enum tm4c129_tmr_mode
{
    TM4C129_TMR_MODE_ONE_SHOT,
    TM4C129_TMR_MODE_PERIODIC,
};

/**
 * Timers driver interface functions.
 *
 */

/**
 * Initialize timer.
 */
bool tm4c129_tmr_init(enum tm4c129_tmr_id id, enum tm4c129_tmr_mode mode, void (*isr_callback)(size_t timeout_uS));
/**
 * Set timer load value.
 *
 * @param timeout - value in microseconds.
 *
 * @details
 * If the timer is running then the timeout value is immediately loaded into the timer counter register.
 *
 */
bool tm4c129_tmr_timeout_set(enum tm4c129_tmr_id id, size_t timeout_uS);

/**
 * Get current timer load value.
 *
 * @param timeout - value in microseconds.
 */
bool tm4c129_tmr_timeout_get(enum tm4c129_tmr_id id, size_t* timeout_uS);

/**
 * Start timer.
 */
bool tm4c129_tmr_start(enum tm4c129_tmr_id id);

/**
 * Stop timer.
 */
bool tm4c129_tmr_stop(enum tm4c129_tmr_id id);
