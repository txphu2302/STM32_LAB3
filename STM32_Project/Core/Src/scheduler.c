/*
 * scheduler.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Acer
 */

#include "scheduler.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

// scheduler.c
unsigned char Error_code_G = 0;

void SCH_init(void)
{
	unsigned char i;
	for (i = 0; i < SCH_MAX_TASKS; i++) {
	    SCH_Delete_Task(i);
	}

}

unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD) {
    unsigned char Index = 0;

    // First, find a gap in the array (if there is one)
    while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS)) {
        Index++;
    }

    // Have we reached the end of the list?
    if (Index == SCH_MAX_TASKS) {
        // Task list is full
        // Set the global error variable
        Error_code_G = ERROR_SCH_TOO_MANY_TASKS;

        // Also return an error code
        return SCH_MAX_TASKS;
    }

    // If we're here, there is a space in the task array
    SCH_tasks_G[Index].pTask = pFunction;
    SCH_tasks_G[Index].Delay = DELAY;
    SCH_tasks_G[Index].Period = PERIOD / 10;
    SCH_tasks_G[Index].RunMe = 0;

    // Return position of task (to allow later deletion)
    return Index;
}


void SCH_Update(void) {
    unsigned char Index;

    // NOTE: Calculations are in *TICKS* (not milliseconds)
    for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
        // Check if there is a task at this location
        if (SCH_tasks_G[Index].pTask) {
            if (SCH_tasks_G[Index].Delay == 0) {
                // The task is due to run
                // Increment the 'RunMe' flag
                SCH_tasks_G[Index].RunMe += 1;

                if (SCH_tasks_G[Index].Period) {
                    // Schedule periodic tasks to run again
                    SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
                }
            } else {
                // Not yet ready to run: just decrement the delay
                SCH_tasks_G[Index].Delay -= 1;
            }
        }
    }
}

void SCH_Dispatch_Tasks(void) {
    unsigned char Index;

    // Dispatches (runs) the next task if one is ready
    for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
        if (SCH_tasks_G[Index].RunMe > 0) {
            // Run the task
            (*SCH_tasks_G[Index].pTask)();

            // Reset/reduce RunMe flag
            SCH_tasks_G[Index].RunMe -= 1;

            // If this is a 'one-shot' task, remove it from the array
            if (SCH_tasks_G[Index].Period == 0) {
                SCH_Delete_Task(Index);
            }
        }
    }
}

unsigned char SCH_Delete_Task(const tByte TASK_INDEX) {
    unsigned char Return_code;

    if (SCH_tasks_G[TASK_INDEX].pTask == 0) {
        // No task at this location
        // Set the global error variable
        Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;

        // Also return an error code
        Return_code = RETURN_ERROR;
    } else {
        // Task found, prepare to delete
        Return_code = RETURN_NORMAL;

        // Clear task details
        SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
        SCH_tasks_G[TASK_INDEX].Delay = 0;
        SCH_tasks_G[TASK_INDEX].Period = 0;
        SCH_tasks_G[TASK_INDEX].RunMe = 0;
    }

    // Return status
    return Return_code;
}


