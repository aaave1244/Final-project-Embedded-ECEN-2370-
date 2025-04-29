/*
 * Button_Driver.h
 *
 *  Created on: Apr 24, 2025
 *      Author: avepe
 */

#ifndef INC_BUTTON_DRIVER_H_
#define INC_BUTTON_DRIVER_H_

#include <stdbool.h>
#include "stm32f4xx_hal.h"

//#define AHB1_BASE_ADDR (0x40020000)
//user button is PA0
#define BUTTON_PIN GPIO_PIN_0
#define USER_BUTTON_PORT (GPIOA)
#define USER_BUTTON_PIN 0
#define USER_BUTTON_PRESSED 1
#define USER_BUTTON_NOT_PRESSED 0

void User_Button_Init();
bool Button_Pressed_Or_Nah();
void Interrupt_Button_Init();




#endif /* INC_BUTTON_DRIVER_H_ */
