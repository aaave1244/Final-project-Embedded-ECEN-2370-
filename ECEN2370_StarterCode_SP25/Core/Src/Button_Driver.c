/*
 * Button_Driver.c
 *
 *  Created on: Feb 13, 2025
 *      Author: avepe
 */

#include "Button_Driver.h"

void User_Button_Init(){
	GPIO_PinConfig_t BUTTON_Config;
	BUTTON_Config.PinNumber = GPIO_PIN_NUM_0; // Pin Number
	BUTTON_Config.PinMode = GPIO_PIN_MODE_INPUT; // Pin Mode
	BUTTON_Config.OPType = GPIO_OUTPUT_TYPE_PP; // Output Type
	BUTTON_Config.PinSpeed = GPIO_PIN_SPEED_LOW; // Pin Speed
	BUTTON_Config.PinPuPdControl = GPIO_PUSH_PULL_CONFIG_NO_PP; // Pin Push up/ Pull Down Control

	GPIO_ClockControl(USER_BUTTON_PORT, ENABLE);
	GPIO_Init(USER_BUTTON_PORT, BUTTON_Config);
}


bool Button_Pressed_Or_Nah(){
//	bool test = ((USER_BUTTON_PORT->GPIOx_IDR >> Read_port(USER_BUTTON_PORT, USER_BUTTON_PIN)) & USER_BUTTON_PRESSED);
//	return test; //((USER_BUTTON_PORT->GPIOx_IDR >> Read_port(USER_BUTTON_PORT, USER_BUTTON_PIN)) & USER_BUTTON_PRESSED);

	if(Read_port(USER_BUTTON_PORT, USER_BUTTON_PIN) == USER_BUTTON_PRESSED){
		return true;
	} else {
		return false;
	}
}

void Interrupt_Button_Init(){
	GPIO_PinConfig_t button;
	button.PinNumber = USER_BUTTON_PIN;
	button.PinMode = GPIO_PIN_MODE_INPUT;
	button.OPType = GPIO_OUTPUT_TYPE_PP;
	button.PinSpeed = GPIO_PIN_SPEED_HIGH;
	button.PinPuPdControl = GPIO_PUSH_PULL_CONFIG_NO_PP;
	button.PinInterrupt = GPIO_RISING_AND_FALLING_EDGE_INTERRUPT;

	GPIO_ClockControl(USER_BUTTON_PORT, ENABLE);
	GPIO_Init(USER_BUTTON_PORT, button);
	toggle_NVIC_interrupt(EXTI0_IRQ_NUMBER, ENABLE);
}
