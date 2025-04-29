/*
 * ApplicationCode.c
 *
 *  Created on: Dec 30, 2023 (updated 11/12/2024) Thanks Donavon! 
 *      Author: Xavion
 */

#include "ApplicationCode.h"

/* Static variables */


extern void initialise_monitor_handles(void); 

#if COMPILE_TOUCH_FUNCTIONS == 1
static STMPE811_TouchData StaticTouchData;
#endif // COMPILE_TOUCH_FUNCTIONS

void ApplicationInit(void)
{
	initialise_monitor_handles(); // Allows printf functionality
    LTCD__Init();
    LTCD_Layer_Init(0);
    LCD_Clear(0,LCD_COLOR_WHITE);

    #if COMPILE_TOUCH_FUNCTIONS == 1
	InitializeLCDTouch();

	// This is the orientation for the board to be direclty up where the buttons are vertically above the screen
	// Top left would be low x value, high y value. Bottom right would be low x value, low y value.
	StaticTouchData.orientation = STMPE811_Orientation_Portrait_2;

	User_Button_Init(); //I added this :3

	#endif // COMPILE_TOUCH_FUNCTIONS
}

void Start_Game(void)
{
	//visualDemo();
	Main_menu(); //I added this :)
	uint8_t WINNER = 0;
	while (WINNER==0) {
		if (returnTouchStateAndLocation(&StaticTouchData) == STMPE811_State_Pressed){
			StaticTouchData.y = FLIP_Y_VALUE(StaticTouchData.y); //this is just to flip the y value so that it is correct for the screen orientation.
			if (TM_STMPE811_TouchInRectangle(&StaticTouchData, 20, 20, 200, 80)){ //coordinates of the 1 player box
				WINNER = One_player_game();
				if(WINNER == 1){
					Win(WINNER);
				} else if (WINNER==2){
					Lose();
				}
			}
			else if (TM_STMPE811_TouchInRectangle(&StaticTouchData, 20, 120, 200, 80)){ //cooredinates of the 2 player box
				WINNER = Two_player_game();
				if(WINNER == 1){
					Win(WINNER);
				} else if (WINNER==2){
					Win(WINNER); //change later to a wi screen specific to player 
				}
			}
			// else {
			// 	Print_insult_for_main_menu(); //this is currently more of a test to see how well I can implement my RNG functionality! Only prints to the console!
			// }
		}
	}
}

#if COMPILE_TOUCH_FUNCTIONS == 0 //for polling implementation

//okay so now we're just gonna... implement polling :)


#endif //for polling implementation

#if COMPILE_TOUCH_FUNCTIONS == 1
void LCD_Touch_Polling_Demo(void)
{
	LCD_Clear(0,LCD_COLOR_GREEN);
	while (1) {
		/* If touch pressed */
		if (returnTouchStateAndLocation(&StaticTouchData) == STMPE811_State_Pressed) {
			/* Touch valid */
			printf("\nX: %03d\nY: %03d\n", StaticTouchData.x, StaticTouchData.y);
			LCD_Clear(0, LCD_COLOR_RED);
		} else {
			/* Touch not pressed */
			printf("Not Pressed\n\n");
			LCD_Clear(0, LCD_COLOR_GREEN);
		}
	}
}
#endif // COMPILE_TOUCH_FUNCTIONS

