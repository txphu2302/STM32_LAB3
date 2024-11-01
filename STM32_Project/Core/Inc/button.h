/*
 * button.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Acer
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

int isButton1Pressed();

int isButton1LongPressed();

int isButton2Pressed();

int isButton2LongPressed();

int isButton3Pressed();

int isButton3LongPressed();

void getKeyInput();

#endif /* INC_BUTTON_H_ */
