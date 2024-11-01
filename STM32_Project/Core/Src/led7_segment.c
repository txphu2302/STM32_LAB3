/*
 * led7_segment.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Acer
 */

#include "led7_segment.h"

int red, green, amber;

void display7SEG(int num, int substatus)
{
	if (substatus == 0)
	{
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	}
	else
	{
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	}
	switch(num)
	{
		case 0:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			break;
		default:
			break;
	}
}

void display7SEG_2(int num, int substatus)
{
	if (substatus == 0)
	{
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	}
	else
	{
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	}
	switch(num)
	{
		case 0:
			HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
			HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, RESET);
			HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
			HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, RESET);
			HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, RESET);
			HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, RESET);
			HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, SET);
			HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, RESET);
			HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
			HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, SET);
			HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, SET);
			HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, SET);
			HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
			HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, RESET);
			HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, SET);
			HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, RESET);
			HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, RESET);
			HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, SET);
			HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
			HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, RESET);
			HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
			HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, RESET);
			HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, SET);
			HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, SET);
			HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, SET);
			HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, RESET);
			HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
			HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, SET);
			HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, SET);
			HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, RESET);
			HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
			HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, SET);
			HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
			HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, RESET);
			HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, SET);
			HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, RESET);
			HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
			HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, SET);
			HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
			HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, RESET);
			HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, RESET);
			HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, RESET);
			HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
			HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, RESET);
			HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
			HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, SET);
			HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, SET);
			HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, SET);
			HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
			HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, RESET);
			HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
			HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, RESET);
			HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, RESET);
			HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, RESET);
			HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(SEG7_GPIO_Port, SEG7_Pin, RESET);
			HAL_GPIO_WritePin(SEG8_GPIO_Port, SEG8_Pin, RESET);
			HAL_GPIO_WritePin(SEG9_GPIO_Port, SEG9_Pin, RESET);
			HAL_GPIO_WritePin(SEG10_GPIO_Port, SEG10_Pin, RESET);
			HAL_GPIO_WritePin(SEG11_GPIO_Port, SEG11_Pin, SET);
			HAL_GPIO_WritePin(SEG12_GPIO_Port, SEG12_Pin, RESET);
			HAL_GPIO_WritePin(SEG13_GPIO_Port, SEG13_Pin, RESET);
			break;
		default:
			break;
	}
}


