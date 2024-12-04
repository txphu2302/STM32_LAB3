/*
 * scheduler.h
 *
 *  Created on: Nov 11, 2024
 *      Author: Acer
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#define ERROR_SCH_TOO_MANY_TASKS 1
#define ERROR_SCH_CANNOT_DELETE_TASK 2
#define RETURN_ERROR 0
#define RETURN_NORMAL 1


#include <stdint.h>

typedef struct{
	void (*pTask)(void);
	uint32_t	Delay;
	uint32_t	Period;
	uint8_t		RunMe;

	uint32_t	TaskID;
}sTasks;

typedef unsigned char tByte;


#define SCH_MAX_TASKS	40
#define NO_TASK_ID 		0


// scheduler.h
extern unsigned char Error_code_G;

void SCH_init(void);

unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

unsigned char SCH_Delete_Task(const tByte TASK_INDEX);




#endif /* INC_SCHEDULER_H_ */
