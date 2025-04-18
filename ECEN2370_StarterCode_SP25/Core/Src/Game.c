#include "Game.h"


void Main_menu(){
    LCD_Main_menu();
    if (returnTouchStateAndLocation(&StaticTouchData) == STMPE811_State_Pressed){
        if (StaticTouchData.x > 20 && StaticTouchData.x < 220 && StaticTouchData.y > 20 && StaticTouchData.y < 70){
            One_player_game();
        }
        else if (StaticTouchData.x > 20 && StaticTouchData.x < 220 && StaticTouchData.y > 80 && StaticTouchData.y < 130){
            Two_player_game();
        } //this may be too precise. I do not have my board at the moment and cannot test this until later!
        else {
            Print_insult_for_main_menu(); //this is currently more of a test to see how well I can implement my RNG functionality! Only prints to the console!
        }
    }
} //already under development. currently called LCD_Main_menu in LCD_Driver.c. Think of something fun to add to this though!!

void One_player_game(){ //figure out how to make workflow for these two better. I want to make one game() function where I can
    bool game_running = GAME_RUNNING; //why is this 1 and not 0? Because I made it that way!!!

    while(game_running==GAME_RUNNING){
        //game logic here. I will probably have to make a few functions to handle the game logic, but I want to keep it simple for now.
        //also! reminding myself to make a function that will run after every turn, checking the game state and determining if the game is over or not.

        //For the lines: We was 7 columns and 6 rows!! I might have to make this game go sideways instead of up and down. I think that would be more fun to make too!!!
        LCD_Draw_Vertical_Line(200, 0, 320, LCD_COLOR_BLACK); //just realized there is no horizontal line function! I will have to add that later!
        LCD_Draw_Horizontal_Line(0, 200, 240, LCD_COLOR_BLACK);
        //Also keep in mind: We are flipping the screen to be landscape! So when it is turned... vertical is horizontal and horizontal is vertical!
        

        //I want to add logic so that we "see" the circle or box or whatever I end up doing "fall." I'm thinking a loop where it will redraw the circle 10 pixels lower than the last iteration of the loop (move it down by 10 pixels every iteration of the loop) ONLY CONCERN! That'll take a lot of loops and that draw circle function is already slow as hell!! My current thought is to make it "hollow" when it falls. Maybe if I just draw the outline it would be faster? I have to test!!!!
        
        if(Check_for_win() == GAME_WON){ //this will be the offloading of the win condition game logic. Make it print something like "ONE AWAY!" if you're at 3 in a row or something. May have to make this return something so don't be scared if this becomes a uint or smthn
            game_running = GAME_NOT_RUNNING; //this is the end condition. only set this when we want the game to end!
        }
    }

}
void Two_player_game(){ // write the majority of code for this.

}

void Lose(); //win and lose will be for one player. Hate to be that nerd but I'm going to draw inspiration from balatro,
void Win(); //where the joker card either insults or compliments you based on whether you win or lose. I'll use the RNG library to choose from a few nice or mean messages, so that requirement should be satisfied. 
//ASK ABOUT THIS LATER THO!!!

void Print_insult_for_main_menu(){
    rand int random_number = rand() % 5; //this is a placeholder.
    if(random_number == 0){
        printf("You are a loser!");
    } else if(random_number == 1){
        printf("You are a nerd!");
    } else if(random_number == 2){
        printf("You are a dork!");
    } else if(random_number == 3){
        printf("You are a fool!");
    } else if(random_number == 4){
        printf("You are a clown!");
    } else {
        printf("RNG NOT WORKING CORRECTLY IN Game.c, Print_insult_for_main_menu()");
    }
}