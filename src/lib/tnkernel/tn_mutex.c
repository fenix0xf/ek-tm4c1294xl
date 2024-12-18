/*

  TNKernel real-time kernel

  Copyright © 2004, 2016 Yuri Tiomkin
  All rights reserved.

  Permission to use, copy, modify, and distribute this software in source
  and binary forms and its documentation for any purpose and without fee
  is hereby granted, provided that the above copyright notice appear
  in all copies and that both that copyright notice and this permission
  notice appear in supporting documentation.

  THIS SOFTWARE IS PROVIDED BY THE YURI TIOMKIN AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL YURI TIOMKIN OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
  SUCH DAMAGE.

*/

/* ver 3  */

#include "tn.h"
#include "tn_utils.h"

#if TN_USE_MUTEXES

//----------------------------------------------------------------------------
//  the field lock->id_mutex should be set to 0
//----------------------------------------------------------------------------
int tn_mutex_create(TN_MUTEX* mutex, unsigned int attribute)
{
    int rc = TERR_NO_ERR;

#if TN_CHECK_PARAM
    if (lock == NULL || lock->id_mutex != 0UL) //-- no recreation
    {
        rc = TERR_WPARAM;
    }
    else
#endif
        if (attribute != TN_MUTEX_NO_ATTR && attribute != TN_MUTEX_ATTR_INHERIT)
    {
        rc = TERR_WPARAM;
    }
    else if (tn_inside_int()) //   Check the call is not in the interrupt context
    {
        rc = TERR_WCONTEXT;
    }
    else
    {
        queue_reset(&(mutex->wait_queue));
        queue_reset(&(mutex->mutex_queue));

        mutex->attr      = attribute;
        mutex->holder    = NULL;
        mutex->cnt       = 0;
        mutex->id_mutex  = TN_ID_MUTEX & TN_ID_MASK; // Static creation
        mutex->pi_active = false;
    }
    return rc;
}

//----------------------------------------------------------------------------
#if TN_USE_DYN_OBJ

//----------------------------------------------------------------------------
TN_MUTEX* tn_mutex_create_dyn(unsigned int attribute, int* err) /* [OUT] */
{
    TN_MUTEX* lock;
    int       rc;

    if (tn_inside_int()) //  Check the call context
    {
        lock = NULL;
        if (err != NULL)
        {
            *err = TERR_WCONTEXT;
        }
    }
    else
    {
        lock = (TN_MUTEX*)tn_alloc(&tn_objects_mem, sizeof(TN_MUTEX));
        if (lock != NULL)
        {
            lock->id_mutex = 0UL;
            rc             = tn_mutex_create(lock, attribute);
            if (rc != TERR_NO_ERR)
            {
                (void)tn_dealloc(&tn_objects_mem, lock);
                lock = NULL;
                if (err != NULL)
                {
                    *err = rc;
                }
            }
        }
        else
        {
            if (err != NULL)
            {
                *err = TERR_OUT_OF_MEM;
            }
        }

        if (lock != NULL)
        {
            lock->id_mutex |= TN_DYN_CREATED;
            if (err != NULL)
            {
                *err = TERR_NO_ERR;
            }
        }
    }
    return lock;
}

#endif /* #if TN_USE_DYN_OBJ */

//----------------------------------------------------------------------------
int tn_mutex_delete(TN_MUTEX* mutex)
{
    TN_INTSAVE_DATA

    int rc = TERR_NO_ERR;
    int fYield;
#if TN_USE_DYN_OBJ
    unsigned long id;
#endif

#if TN_CHECK_PARAM
    if (lock == NULL)
    {
        rc = TERR_WPARAM;
    }
    else
#endif
        if ((mutex->id_mutex & TN_ID_MASK) != TN_ID_MUTEX)
    {
        rc = TERR_NOEXS;
    }
    else if (tn_inside_int()) // Check the call is not in the interrupt context
    {
        rc = TERR_WCONTEXT;
    }
    else
    {
        //-- Remove all tasks(if any) from the lock's wait queue

        tn_disable_interrupt();

        fYield = tn_release_wait_que(&(mutex->wait_queue));

        (void)do_mutex_unlock(mutex->holder, mutex);

#if TN_USE_DYN_OBJ
        id = lock->id_mutex;
#endif
        mutex->id_mutex = 0UL; // Mutex set as 'not exists' now

        tn_enable_interrupt();

#if TN_USE_DYN_OBJ
        if ((id & TN_DYN_MASK) == TN_DYN_CREATED) // was created dynamically
        {
            (void)tn_dealloc(&tn_objects_mem, lock);
        }
#endif
        if (fYield == true)
        {
            tn_switch_context();
        }
    }
    return rc;
}

//----------------------------------------------------------------------------
int tn_mutex_lock(TN_MUTEX* mutex, unsigned long timeout)
{
    TN_INTSAVE_DATA

    int wait_reason = TSK_WAIT_REASON_MUTEX; // Just lock without priority changing things
    int fYield      = false;
    int rc          = TERR_WCONTEXT;

#if TN_CHECK_PARAM
    if (lock == NULL)
    {
        rc = TERR_WPARAM;
    }
    else
#endif
        if ((mutex->id_mutex & TN_ID_MASK) != TN_ID_MUTEX)
    {
        rc = TERR_NOEXS;
    }
    else if (tn_inside_int()) //   Check the call is not in the interrupt context
    {
        rc = TERR_WCONTEXT;
    }
    else
    {
        tn_disable_interrupt();

        if (tn_curr_run_task == mutex->holder) //-- Recursive locking
        {
            mutex->cnt++;
            rc = TERR_NO_ERR;
        }
        else
        {
            if (mutex->holder == NULL) //-- lock not locked
            {
                mutex->holder = tn_curr_run_task;

                //-- Add lock to task's locked mutexes queue
                queue_add_tail(&(tn_curr_run_task->mutex_queue), &(mutex->mutex_queue));

                if ((mutex->attr & TN_MUTEX_ATTR_INHERIT) == TN_MUTEX_ATTR_INHERIT)
                {
                    tn_curr_run_task->num_hold_pi_mutexes++;
                }

                rc = TERR_NO_ERR;
            }
            else //-- the lock is already locked
            {
                if (timeout == TN_NO_WAIT)
                {
                    rc = TERR_UNDERFLOW;
                }
                else
                {
                    if ((mutex->attr & TN_MUTEX_ATTR_INHERIT) == TN_MUTEX_ATTR_INHERIT)
                    {
                        wait_reason = TSK_WAIT_REASON_MUTEX_I;
                    }

                    task_curr_to_wait_action(&(mutex->wait_queue), wait_reason, timeout);

                    if (wait_reason == TSK_WAIT_REASON_MUTEX_I)
                    {
                        if (tn_curr_run_task->priority < mutex->holder->base_priority)
                        {
                            if (mutex->pi_active == false)
                            {
                                mutex->pi_active = true; // inheritance_active

                                mutex->holder->num_pi_active_op++;
                            }

                            //-- increase priority of the lock holder

                            if (tn_curr_run_task->priority < mutex->holder->priority)
                            {
                                tn_update_priority(mutex->holder, tn_curr_run_task->priority);
                            }
                        }
                    }

                    fYield = true;
                }
            }
        }

        tn_enable_interrupt();

        if (fYield == true)
        {
            tn_switch_context();
            rc = tn_curr_run_task->task_wait_rc;

            if (rc == TERR_WAIT_COMPLETE)
            {
                rc = TERR_NO_ERR;
            }
        }
    }

    return rc;
}

//----------------------------------------------------------------------------
int tn_mutex_unlock(TN_MUTEX* mutex)
{
    TN_INTSAVE_DATA
    volatile int rc;

#if TN_CHECK_PARAM
    if (lock == NULL)
    {
        rc = TERR_WPARAM;
    }
    else
#endif
        if ((mutex->id_mutex & TN_ID_MASK) != TN_ID_MUTEX)
    {
        rc = TERR_NOEXS;
    }
    else if (tn_inside_int()) // Check the call is not in the interrupt context
    {
        rc = TERR_WCONTEXT;
    }
    else
    {
        tn_disable_interrupt();

        rc = do_mutex_unlock(tn_curr_run_task, mutex);

        tn_enable_interrupt();

        tn_switch_context();
    }

    return rc;
}

//----------------------------------------------------------------------------
int do_mutex_unlock(TN_TCB* task, TN_MUTEX* mutex)
{
    int         rc = TERR_WCONTEXT;
    TN_TCB*     curr_wait_task;
    TN_TCB*     new_holder_task;
    CDLL_QUEUE* curr_que;
    int         fPriorityUpdate = false;

    //-- Unlocking is enabled only for the holder and already locked lock

    if (task != mutex->holder || mutex->holder == NULL)
    {
        rc = TERR_ILUSE;
    }
    else if (mutex->cnt > 0)
    {
        mutex->cnt--;
        rc = TERR_NO_ERR;
    }
    else
    {
        //-- Remove lock from the task's locked mutexes queue
        queue_remove_entry(&(mutex->mutex_queue));

        if ((mutex->attr & TN_MUTEX_ATTR_INHERIT) == TN_MUTEX_ATTR_INHERIT)
        {
            if (mutex->pi_active == true)
            {
                mutex->pi_active = false;

                task->num_pi_active_op--;

                if (task->num_pi_active_op == 0)
                {
                    fPriorityUpdate = true;
                }
            }

            task->num_hold_pi_mutexes--;

            if (task->num_pi_active_op == task->num_hold_pi_mutexes)
            {
                task->restore_priority = task->base_priority;

                if (task->num_hold_pi_mutexes == 0 && task->priority != task->restore_priority)
                {
                    fPriorityUpdate = true; // Restore base priority
                }
            }
        }

        if (is_queue_empty(&(mutex->wait_queue)) == true) // No task waits a lock
        {
            mutex->holder = NULL;
            rc            = TERR_NO_ERR;
        }
        else // some task(s) is wait for the lock - the first in the queue will be a new holder
        {
            // Obtain a new lock holder
            curr_que        = queue_remove_head(&(mutex->wait_queue));
            new_holder_task = get_task_by_tsk_queue(curr_que);

            if (new_holder_task != NULL)
            {
                (void)task_wait_complete(new_holder_task);

                mutex->holder = new_holder_task;

                queue_add_tail(&(new_holder_task->mutex_queue), &(mutex->mutex_queue));

                if ((mutex->attr & TN_MUTEX_ATTR_INHERIT) == TN_MUTEX_ATTR_INHERIT)
                {
                    new_holder_task->num_hold_pi_mutexes++;

                    // if we have another task(s) waiting for the lock

                    if (is_queue_empty(&(mutex->wait_queue)) == false)
                    {
                        curr_que       = mutex->wait_queue.next; // get first, not remove
                        curr_wait_task = get_task_by_tsk_queue(curr_que);

                        if (curr_wait_task != NULL)
                        {
                            if (curr_wait_task->priority < new_holder_task->base_priority)
                            {
                                mutex->pi_active = true;
                                new_holder_task->num_pi_active_op++;
                            }
                        }
                    }
                }

                rc = TERR_NO_ERR;
            }
        }

        if (fPriorityUpdate == true)
        {
            tn_update_priority(task, task->restore_priority); // Do it last.
        }
    }
    return rc;
}

//----------------------------------------------------------------------------
void do_release_mutex_queue(TN_TCB* task)
{
    CDLL_QUEUE* que;
    TN_MUTEX*   mutex;

    while (is_queue_empty(&(task->mutex_queue)) == false)
    {
        que   = queue_remove_head(&(task->mutex_queue));
        mutex = get_mutex_by_mutex_queque(que);

        if (mutex != NULL)
        {
            (void)do_mutex_unlock(task, mutex);
        }
    }
}

//----------------------------------------------------------------------------
//  Context - When 'task' is deleted and 'task' is in the TSK_STATE_WAIT state
//            and  'task_wait_reason' is TSK_WAIT_REASON_MUTEX_I
//----------------------------------------------------------------------------
void do_set_mutex_holder_max_priority(TN_TCB* task)
{
    TN_MUTEX*    mutex;
    TN_TCB*      wait_task;
    CDLL_QUEUE*  que;
    unsigned int priority;

    mutex = get_mutex_by_wait_queque(task->pwait_queue);
    if (mutex != NULL)
    {
        if (is_queue_empty(&(mutex->wait_queue)) == false)
        {
            //-- first in 'wait_queue' - highest priority
            que       = mutex->wait_queue.next; // get first, not remove
            wait_task = get_task_by_tsk_queue(que);
            if (wait_task != NULL && mutex->holder != NULL) // Sanity
            {
                //-- The lock holder priority should be set as highest (minimal val) from
                //--  - wait_task->priority
                //--  - lock holder->priority
                //--  - lock holder->restore priority

                if (mutex->holder->priority < mutex->holder->restore_priority)
                {
                    priority = mutex->holder->priority;
                }
                else
                {
                    priority = mutex->holder->restore_priority;
                }

                if (wait_task->priority < priority)
                {
                    priority = wait_task->priority;
                }

                mutex->holder->priority = priority;
            }
        }
        else // No more tasks wait a lock - restore the holder original priority
        {
            if (mutex->holder != NULL) // Sanity
            {
                mutex->holder->priority = mutex->holder->restore_priority;
            }
        }
    }
}

#endif /* #if TN_USE_MUTEXES */
