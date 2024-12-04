/*
 * button.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Acer
 */

#ifndef SRC_BUTTON_C_
#define SRC_BUTTON_C_

#include "button.h"

int KeyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3[3]= {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int TimeOutForKeyPress = 200;
int button_pressed[3];
int button_flag[3];

int isButton1Pressed()
{
	if (button_flag[0] == 1)
	{
		button_flag[0] = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed()
{
	if (button_flag[1] == 1)
	{
		button_flag[1] = 0;
		return 1;
	}
	return 0;
}


int isButton3Pressed()
{
	if (button_flag[2] == 1)
	{
		button_flag[2] = 0;
		return 1;
	}
	return 0;
}


void subkeyProcess(int index)
{
	//TODO
	button_flag[index] = 1;
}

void getKeyInput()
{
	for (int i = 0; i < 3; i++)
	{
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		if (i == 0) KeyReg0[i] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
		else if (i == 1) KeyReg0[i] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
		else KeyReg0[i] = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);

		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i]))
		{
			if (KeyReg2[i] != KeyReg3[i])
			{
				KeyReg3[i] = KeyReg2[i];

				if (KeyReg3[i] == PRESSED_STATE)
				{
					subkeyProcess(i);
					TimeOutForKeyPress = 200;
				}
			}
			else
			{
				TimeOutForKeyPress--;
				if (TimeOutForKeyPress == 0)
				{
					if (KeyReg3[i] == PRESSED_STATE)
					{
						subkeyProcess(i);
					}
					TimeOutForKeyPress = 50;
				}
			}
		}
	}
}

#endif /* SRC_BUTTON_C_ */
