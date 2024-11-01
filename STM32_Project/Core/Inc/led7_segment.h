/*
 * led7_segment.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Acer
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_

#include "main.h"
#include "global.h"

extern int red, amber, green;

void display7SEG(int num, int substatus);

void display7SEG_2(int num, int substatus);

void updateClockBuffer();

#endif /* INC_LED7_SEGMENT_H_ */
