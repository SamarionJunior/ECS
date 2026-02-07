#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../constants.h"
#include "delay.h"

void resetDelay();
void delay(int *isPaused);

int last_frame_time = 0;
double delta_time = 0;

void resetDelay(){
	
	last_frame_time = SDL_GetTicks();
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
