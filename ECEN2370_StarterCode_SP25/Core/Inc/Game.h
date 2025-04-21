#include "LCD_Driver.h"

#define GAME_RUNNING 1
#define GAME_NOT_RUNNING 0

#define GAME_WON 512
#define GAME_NOT_WON 256


void Main_menu(); //already under development. currently called Main_menu in LCD_Driver.c. Think of something fun to add to this though!!

uint8_t One_player_game(); //figure out how to make workflow for these two better. I want to make one game() function where I can
void Two_player_game(); // write the majority of code for this.
uint8_t AI_col(uint8_t row, uint8_t col);

void Lose(); //win and lose will be for one player. Hate to be that nerd but I'm going to draw inspiration from balatro,
void Win(); //where the joker card either insults or compliments you based on whether you win or lose. I'll use the RNG library to choose from a few nice or mean messages, so that requirement should be satisfied. 
//ASK ABOUT THIS LATER THO!!!

void Print_insult_for_main_menu(); //this is SPECIFICALLY for the main menu!

void Choose_colors(); //this may not be within the scope of my abilities... BUT!! Think of how fun it would be! just make a screen similar to the main menu where each player can choose their colors!
void Choose_shapes(); //this probably won't happen haha but think of the box vs circle battles!!

uint8_t Drop_piece(uint8_t col); //pass in the column we want to drop the piece into, the return the row number that it falls to!
uint8_t Check_for_win(uint8_t row, uint8_t col); //this will be the offloading of the win condition game logic. Make it print something like "ONE AWAY!" if you're at 3 in a row or something. May have to make this return something so don't be scared if this becomes a uint or smthn
//pass in the last row and column

void leaderboard(); //definitely implementing this last lol