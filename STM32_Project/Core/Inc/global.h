/*
 * global.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Acer
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "led7_segment.h"
#include "software_timer.h"
#include "traffic_light.h"
#include "button.h"
#include "main.h"

#define INIT			1
#define AUTO_RED_GREEN	2
#define AUTO_RED_AMBER	3
#define AUTO_GREEN_RED	4
#define AUTO_AMBER_RED	5

#define MODE_1		12
#define MODE_2		13
#define MODE_3		14
#define MODE_4		15

extern int status;



#endif /* INC_GLOBAL_H_ */
