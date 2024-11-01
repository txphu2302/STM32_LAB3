/*
 * software_timer.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Acer
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int TIMER_CYCLE;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);

void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
