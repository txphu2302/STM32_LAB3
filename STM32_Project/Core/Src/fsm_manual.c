/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Acer
 */

#include "fsm_manual.h"

int sub_status = 0;

void blinking_mode_01()
{
	if (timer2_flag == 1)
	{
		setTimer2(250);
		switch(sub_status)
		{
			case 0:
				display7SEG_2(0, 0);
				display7SEG(0, 0);
				sub_status = 1;
				break;
			case 1:
				display7SEG_2(0, 0);
				display7SEG(1, 1);
				sub_status = 0;
				break;
			default:
				break;
		}

	}
}

void blinking_mode_02()
{
	if (timer2_flag == 1)
	{
		setTimer2(250);
		switch(sub_status)
		{
			case 0:
				display7SEG_2(red / 10, 0);
				display7SEG(0, 0);
				sub_status = 1;
				break;
			case 1:
				display7SEG_2(red % 10, 1);
				display7SEG(2, 1);
				sub_status = 0;
				break;
			default:
				break;
		}

	}
}

void blinking_mode_03()
{
	if (timer2_flag == 1)
	{
		setTimer2(250);
		switch(sub_status)
		{
			case 0:
				display7SEG_2(amber / 10, 0);
				display7SEG(0, 0);
				sub_status = 1;
				break;
			case 1:
				display7SEG_2(amber % 10, 1);
				display7SEG(3, 1);
				sub_status = 0;
				break;
			default:
				break;
		}

	}
}

void blinking_mode_04()
{
	if (timer2_flag == 1)
	{
		setTimer2(250);
		switch(sub_status)
		{
			case 0:
				display7SEG_2(green / 10, 0);
				display7SEG(0, 0);
				sub_status = 1;
				break;
			case 1:
				display7SEG_2(green % 10, 1);
				display7SEG(4, 1);
				sub_status = 0;
				break;
			default:
				break;
		}

	}
}

void fsm_manual_run()
{
	switch (status)
	{
	case MODE_1:
		blinking_mode_01();
		if (timer1_flag == 1)
		{
			status = INIT;
		}
		if (isButton1Pressed() == 1)
		{
			setTimer1(10000);
			status = MODE_2;
		}
		if (isButton3Pressed() == 1)
		{
			status = INIT;
		}
		break;
	case MODE_2:
		blinking_mode_02();
		if (timer1_flag == 1)
		{
			status = INIT;
		}
		if (isButton1Pressed() == 1)
		{
			setTimer1(10000);
			status = MODE_3;
		}
		if (isButton2Pressed() == 1)
		{
			setTimer1(10000);
			red++;
		}
		if (isButton3Pressed() == 1)
		{
			status = INIT;
		}
		break;
	case MODE_3:
		blinking_mode_03();
		if (timer1_flag == 1)
		{
			status = INIT;
		}
		if (isButton1Pressed() == 1)
		{
			setTimer1(10000);
			status = MODE_4;
		}
		if (isButton2Pressed() == 1)
		{
			setTimer1(10000);
			amber++;
		}
		if (isButton3Pressed() == 1)
		{
			status = INIT;
		}
		break;
	case MODE_4:
		blinking_mode_04();
		if (timer1_flag == 1)
		{
			status = INIT;
		}
		if (isButton1Pressed() == 1)
		{
			setTimer1(10000);
			status = MODE_1;
		}
		if (isButton2Pressed() == 1)
		{
			setTimer1(10000);
			green++;
		}
		if (isButton3Pressed() == 1)
		{
			status = INIT;
		}
		break;
	default:
		break;
	}
}
