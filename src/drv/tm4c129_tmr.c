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

#include "tm4c129_tmr.h"

#include <drv/tm4c129.h>
#include <drv/tm4c129_mcu.h>
#include <drv/tm4c129_int.h>

#include <hal/hal.h>

/**
 * Internal driver defines.
 *
 */
#define TM4C129_TIMER_ID       TIMER_A
#define TM4C129_TIMER_INT_FLAG TIMER_TIMA_TIMEOUT

/**
 * Internal timer data.
 *
 */
struct tm4c129_timer_entry
{
    const uintptr_t       periph;
    const uintptr_t       base;
    const size_t          interrupt;
    enum tm4c129_tmr_mode mode;
    size_t                timeout_ticks;
    size_t                timeout_uS;
    void (*callback)(size_t timeout_uS);
};

/**
 * Local variables.
 *
 */
static struct tm4c129_timer_entry g_tm4c129_timers[TM4C129_TMR_COUNT] = {
    {SYSCTL_PERIPH_TIMER0, TIMER0_BASE, INT_TIMER0A, TM4C129_TMR_MODE_ONE_SHOT, 0, 0, NULL},
    {SYSCTL_PERIPH_TIMER1, TIMER1_BASE, INT_TIMER1A, TM4C129_TMR_MODE_ONE_SHOT, 0, 0, NULL},
    {SYSCTL_PERIPH_TIMER2, TIMER2_BASE, INT_TIMER2A, TM4C129_TMR_MODE_ONE_SHOT, 0, 0, NULL},
    {SYSCTL_PERIPH_TIMER3, TIMER3_BASE, INT_TIMER3A, TM4C129_TMR_MODE_ONE_SHOT, 0, 0, NULL},
    {SYSCTL_PERIPH_TIMER4, TIMER4_BASE, INT_TIMER4A, TM4C129_TMR_MODE_ONE_SHOT, 0, 0, NULL},
    {SYSCTL_PERIPH_TIMER5, TIMER5_BASE, INT_TIMER5A, TM4C129_TMR_MODE_ONE_SHOT, 0, 0, NULL},
    {SYSCTL_PERIPH_TIMER6, TIMER6_BASE, INT_TIMER6A, TM4C129_TMR_MODE_ONE_SHOT, 0, 0, NULL},
    {SYSCTL_PERIPH_TIMER7, TIMER7_BASE, INT_TIMER7A, TM4C129_TMR_MODE_ONE_SHOT, 0, 0, NULL}
};

static bool     g_isr_is_init;

/**
 * Local functions.
 *
 */
HAL_INLINE bool timer_id_is_valid(enum tm4c129_tmr_id id)
{
    return ((unsigned)id < TM4C129_TMR_COUNT);
}

HAL_INLINE bool timer_is_init(const struct tm4c129_timer_entry* tmr)
{
    return tmr->callback != NULL;
}

HAL_INLINE void timer_timeout_set_ticks(struct tm4c129_timer_entry* tmr, size_t ticks)
{
    tmr->timeout_ticks = ticks;
    tmr->timeout_uS    = ticks / TM4C129_MCU_TICKS_PER_uS;
}

HAL_INLINE void timer_timeout_set_uS(struct tm4c129_timer_entry* tmr, size_t uS)
{
    tmr->timeout_uS    = uS;
    tmr->timeout_ticks = uS * TM4C129_MCU_TICKS_PER_uS;
}

static bool timer_mode_to_hw_mode(enum tm4c129_tmr_mode mode, size_t* hw_mode);

/**
 * Driver interrupts.
 *
 */
static void tm4c129_isr_timer0(void);
static void tm4c129_isr_timer1(void);
static void tm4c129_isr_timer2(void);
static void tm4c129_isr_timer3(void);
static void tm4c129_isr_timer4(void);
static void tm4c129_isr_timer5(void);
static void tm4c129_isr_timer6(void);
static void tm4c129_isr_timer7(void);

/**
 * Driver interface functions.
 *
 */
bool        tm4c129_tmr_init(enum tm4c129_tmr_id id, enum tm4c129_tmr_mode mode, void (*isr_callback)(size_t timeout_uS))
{
    if (isr_callback == NULL)
    {
        return false;
    }

    if (!g_isr_is_init)
    {
        g_isr_is_init = tm4c129_int_register(INT_TIMER0A, tm4c129_isr_timer0);
        g_isr_is_init = g_isr_is_init && tm4c129_int_register(INT_TIMER1A, tm4c129_isr_timer1);
        g_isr_is_init = g_isr_is_init && tm4c129_int_register(INT_TIMER2A, tm4c129_isr_timer2);
        g_isr_is_init = g_isr_is_init && tm4c129_int_register(INT_TIMER3A, tm4c129_isr_timer3);
        g_isr_is_init = g_isr_is_init && tm4c129_int_register(INT_TIMER4A, tm4c129_isr_timer4);
        g_isr_is_init = g_isr_is_init && tm4c129_int_register(INT_TIMER5A, tm4c129_isr_timer5);
        g_isr_is_init = g_isr_is_init && tm4c129_int_register(INT_TIMER6A, tm4c129_isr_timer6);
        g_isr_is_init = g_isr_is_init && tm4c129_int_register(INT_TIMER7A, tm4c129_isr_timer7);

        if (!g_isr_is_init)
        {
            return false;
        }
    }

    if (!timer_id_is_valid(id))
    {
        return false;
    }

    struct tm4c129_timer_entry* tmr = &g_tm4c129_timers[id];

    if (timer_is_init(tmr))
    {
        return false;
    }

    size_t hw_mode;

    if (!timer_mode_to_hw_mode(mode, &hw_mode))
    {
        return false;
    }

    tmr->mode     = mode;
    tmr->callback = isr_callback;

    if (!tm4c129_periph_init(tmr->periph, TM4C129_PERIPH_OPT_RESET))
    {
        return false;
    }

    TimerDisable(tmr->base, TM4C129_TIMER_ID);
    TimerConfigure(tmr->base, hw_mode);

    /// The timer stops counting if the processor enters debug mode.
    TimerControlStall(tmr->base, TM4C129_TIMER_ID, true);

    TimerIntEnable(tmr->base, TM4C129_TIMER_INT_FLAG);
    IntEnable(tmr->interrupt);

    timer_timeout_set_ticks(tmr, TimerLoadGet(tmr->base, TM4C129_TIMER_ID));
    return true;
}

bool tm4c129_tmr_timeout_set(enum tm4c129_tmr_id id, size_t timeout_uS)
{
    if (!timer_id_is_valid(id) || (timeout_uS == 0))
    {
        return false;
    }

    struct tm4c129_timer_entry* tmr = &g_tm4c129_timers[id];

    if (!timer_is_init(tmr))
    {
        return false;
    }

    timer_timeout_set_uS(tmr, timeout_uS);
    TimerLoadSet(tmr->base, TM4C129_TIMER_ID, tmr->timeout_ticks);
    return true;
}

bool tm4c129_tmr_timeout_get(enum tm4c129_tmr_id id, size_t* timeout_uS)
{
    if (!timer_id_is_valid(id) || (timeout_uS == NULL))
    {
        return false;
    }

    struct tm4c129_timer_entry* tmr = &g_tm4c129_timers[id];

    if (!timer_is_init(tmr))
    {
        return false;
    }

    timer_timeout_set_ticks(tmr, TimerLoadGet(tmr->base, TM4C129_TIMER_ID));
    *timeout_uS = tmr->timeout_uS;
    return true;
}

bool tm4c129_tmr_start(enum tm4c129_tmr_id id)
{
    if (!timer_id_is_valid(id))
    {
        return false;
    }

    struct tm4c129_timer_entry* tmr = &g_tm4c129_timers[id];

    if (!timer_is_init(tmr))
    {
        return false;
    }

    TimerEnable(tmr->base, TM4C129_TIMER_ID);
    return true;
}

bool tm4c129_tmr_stop(enum tm4c129_tmr_id id)
{
    if (!timer_id_is_valid(id))
    {
        return false;
    }

    struct tm4c129_timer_entry* tmr = &g_tm4c129_timers[id];

    if (!timer_is_init(tmr))
    {
        return false;
    }

    TimerDisable(tmr->base, TM4C129_TIMER_ID);
    return true;
}

/**
 * Local functions.
 *
 */
bool timer_mode_to_hw_mode(enum tm4c129_tmr_mode mode, size_t* hw_mode)
{
    if (hw_mode == NULL)
    {
        return false;
    }

    switch (mode)
    {
        case TM4C129_TMR_MODE_ONE_SHOT: *hw_mode = TIMER_CFG_ONE_SHOT; break;
        case TM4C129_TMR_MODE_PERIODIC: *hw_mode = TIMER_CFG_PERIODIC; break;
        default: return false;
    }

    return true;
}

/**
 * Driver interrupts.
 *
 */
void tm4c129_isr_timer0(void)
{
    const struct tm4c129_timer_entry* tmr = &g_tm4c129_timers[TM4C129_TMR0];
    TimerIntClear(tmr->base, TM4C129_TIMER_INT_FLAG);
    tmr->callback(tmr->timeout_uS);
}

void tm4c129_isr_timer1(void)
{
    const struct tm4c129_timer_entry* tmr = &g_tm4c129_timers[TM4C129_TMR1];
    TimerIntClear(tmr->base, TM4C129_TIMER_INT_FLAG);
    tmr->callback(tmr->timeout_uS);
}

void tm4c129_isr_timer2(void)
{
    const struct tm4c129_timer_entry* tmr = &g_tm4c129_timers[TM4C129_TMR2];
    TimerIntClear(tmr->base, TM4C129_TIMER_INT_FLAG);
    tmr->callback(tmr->timeout_uS);
}

void tm4c129_isr_timer3(void)
{
    const struct tm4c129_timer_entry* tmr = &g_tm4c129_timers[TM4C129_TMR3];
    TimerIntClear(tmr->base, TM4C129_TIMER_INT_FLAG);
    tmr->callback(tmr->timeout_uS);
}

void tm4c129_isr_timer4(void)
{
    const struct tm4c129_timer_entry* tmr = &g_tm4c129_timers[TM4C129_TMR4];
    TimerIntClear(tmr->base, TM4C129_TIMER_INT_FLAG);
    tmr->callback(tmr->timeout_uS);
}

void tm4c129_isr_timer5(void)
{
    const struct tm4c129_timer_entry* tmr = &g_tm4c129_timers[TM4C129_TMR5];
    TimerIntClear(tmr->base, TM4C129_TIMER_INT_FLAG);
    tmr->callback(tmr->timeout_uS);
}

void tm4c129_isr_timer6(void)
{
    const struct tm4c129_timer_entry* tmr = &g_tm4c129_timers[TM4C129_TMR6];
    TimerIntClear(tmr->base, TM4C129_TIMER_INT_FLAG);
    tmr->callback(tmr->timeout_uS);
}

void tm4c129_isr_timer7(void)
{
    const struct tm4c129_timer_entry* tmr = &g_tm4c129_timers[TM4C129_TMR7];
    TimerIntClear(tmr->base, TM4C129_TIMER_INT_FLAG);
    tmr->callback(tmr->timeout_uS);
}
