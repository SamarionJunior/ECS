#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL3/SDL.h>
#include "update.h"
#include "../architecture/components/components.h"
#include "../architecture/entities/entities.h"
#include "../architecture/systems/systems.h"
#include "../architecture/systems/gravity.h"
#include "../architecture/systems/collision.h"
#include "../architecture/systems/move.h"
#include "../architecture/systems/scoreCalculator.h"
#include "../architecture/systems/snake.h"
#include "../constants.h"
#include "input.h"

int last_frame_time = 0;

float delta_time = 0;

void resetDelay(void);
void delay(int *isPaused);
// void move();
// void point();

void update(int *game_is_running) {

	// printf("\n//////////////\n");
	// printf(  "/// UPDATE ///\n");
	// printf(  "//////////////\n\n");

	// delay(game_is_running);

	// gravity();
	// collision();
	
	/////// MOVE ////////
	
	move();

	// iterationSnake();

	/////// CLICK ////////
	/////// JUMPER ///////

	// printf("\n////////////////////\n");
	// printf(  "/// END - UPDATE ///\n");
	// printf(  "////////////////////\n\n");

}


void resetDelay(void){

	// // // // printf("\n///////////////////\n");
	// // // // printf(  "/// RESET DELAY ///\n");
	// // // // printf(  "///////////////////\n\n");
	
	last_frame_time = SDL_GetTicks();

	// // // // printf("\n/////////////////////////\n");
	// // // // printf(  "/// END - RESET DELAY ///\n");
	// // // // printf(  "/////////////////////////\n\n");
}

void delay(int *isPaused){

	if(*isPaused == RESUME){
		resetDelay();
		*isPaused = RUN;
	}

	int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

	if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) {
		SDL_Delay(time_to_wait);
	}

	delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;

	last_frame_time = SDL_GetTicks();
	
}
