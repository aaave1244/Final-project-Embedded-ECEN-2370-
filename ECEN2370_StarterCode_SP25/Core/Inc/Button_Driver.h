/*
 * Button_Driver.h
 *
 *  Created on: Feb 13, 2025
 *      Author: avepe
 */

#include "GPIO_Driver.h"
#include <stdbool.h>

//#define AHB1_BASE_ADDR (0x40020000)
//user button is PA0
#define USER_BUTTON_PORT (GPIOA)
#define USER_BUTTON_PIN 0
#define USER_BUTTON_PRESSED 1
#define USER_BUTTON_NOT_PRESSED 0

void User_Button_Init();
bool Button_Pressed_Or_Nah();
void Interrupt_Button_Init();
