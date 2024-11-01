/*
 * fsm_automatic.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Acer
 */

#include "fsm_automatic.h"

int substatus = 0;
int tempdec_red, tempdec_amber, tempdec_green;

void fsm_automatic_run()
{
	switch (status)
	{
		case INIT:
			status = AUTO_RED_GREEN;
			OffLight();
			setTimer1(green * 500);
			setTimer3(500);
			tempdec_red = red;
			tempdec_amber = amber;
			tempdec_green = green;
			break;
		case AUTO_RED_GREEN:
			RedGreen();
			if (timer1_flag == 1)
			{
				status = AUTO_RED_AMBER;
				setTimer1(amber * 500);
				timer2_flag = 1;
				tempdec_red--;
				setTimer3(500);
			}
			if (timer2_flag == 1)
			{
				setTimer2(250);
				switch(substatus)
				{
					case 0:
						display7SEG_2(tempdec_red / 10, 0);
						display7SEG(tempdec_green / 10, 0);
						substatus = 1;
						break;
					case 1:
						display7SEG_2(tempdec_red % 10, 1);
						display7SEG(tempdec_green % 10, 1);
						substatus = 0;
						break;
					default:
						break;
				}

			}
			if (timer3_flag == 1)
			{
				setTimer3(500);
				tempdec_red--;
				tempdec_green--;
			}

			if (isButton1Pressed() == 1)
			{
				status = MODE_1;
				setTimer1(10000);
			}
			break;
		case AUTO_RED_AMBER:
			RedAmber();
			if (timer1_flag == 1)
			{
				status = AUTO_GREEN_RED;
				setTimer1(green * 500);
				timer2_flag = 1;
				setTimer3(500);
				tempdec_red = red;
				tempdec_green = green;
				tempdec_amber = amber;
			}
			if (timer2_flag == 1)
			{
				setTimer2(250);
				switch(substatus)
				{
					case 0:
						display7SEG_2(tempdec_red / 10, 0);
						display7SEG(tempdec_amber / 10, 0);
						substatus = 1;
						break;
					case 1:
						display7SEG_2(tempdec_red % 10, 1);
						display7SEG(tempdec_amber % 10, 1);
						substatus = 0;
						break;
					default:
						break;
				}

			}
			if (timer3_flag == 1)
			{
				setTimer3(500);
				timer2_flag = 1;
				tempdec_red--;
				tempdec_amber--;
			}

			break;
		case AUTO_GREEN_RED:
			GreenRed();
			if (timer1_flag == 1)
			{
				status = AUTO_AMBER_RED;
				setTimer1(amber * 500);
				tempdec_red--;
				setTimer3(500);
			}
			if (timer2_flag == 1)
			{
				setTimer2(250);
				switch(substatus)
				{
					case 0:
						display7SEG_2(tempdec_green / 10, 0);
						display7SEG(tempdec_red / 10, 0);
						substatus = 1;
						break;
					case 1:
						display7SEG_2(tempdec_green % 10, 1);
						display7SEG(tempdec_red % 10, 1);
						substatus = 0;
						break;
					default:
						break;
				}

			}
			if (timer3_flag == 1)
			{
				setTimer3(500);
				tempdec_red--;
				tempdec_green--;
			}
			break;
		case AUTO_AMBER_RED:
			AmberRed();
			if (timer1_flag == 1)
			{
				status = AUTO_RED_GREEN;
				setTimer1(green * 500);
				timer2_flag = 1;
				setTimer3(500);
				tempdec_red = red;
				tempdec_green = green;
				tempdec_amber = amber;
			}
			if (timer2_flag == 1)
			{
				setTimer2(250);
				switch(substatus)
				{
					case 0:
						display7SEG_2(tempdec_red / 10, 0);
						display7SEG(tempdec_amber / 10, 0);
						substatus = 1;
						break;
					case 1:
						display7SEG_2(tempdec_red % 10, 1);
						display7SEG(tempdec_amber % 10, 1);
						substatus = 0;
						break;
					default:
						break;
				}

			}
			if (timer3_flag == 1)
			{
				setTimer3(500);
				tempdec_red--;
				tempdec_amber--;
			}
			break;
		default:
			break;
	}
}
