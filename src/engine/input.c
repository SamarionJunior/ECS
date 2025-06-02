#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "input.h"
#include <SDL3/SDL.h>
#include "../architecture/components/components.h"
#include "../architecture/entities/entities.h"
#include "../architecture/systems/systems.h"
#include "../constants.h"
#include "../manager/WindowManage.h"

int arrayKey[TOTAL_MY_KEYS] = {false};

void process_input(int *game_is_running) {

	// printf("\n/////////////////////\n");
	// printf(  "/// PROCESS INPUT ///\n");
	// printf(  "/////////////////////\n\n");

	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_EVENT_QUIT:
			*game_is_running = CLOSE;
			break;
		case SDL_EVENT_KEY_UP:

			if (event.key.key == SDLK_W) {
				arrayKey[MY_TOP] = false;
				arrayKey[MY_CLIKER_TOP] = false;
			}

			if (event.key.key == SDLK_D) {
				arrayKey[MY_RIGHT] = false;
				arrayKey[MY_CLIKER_RIGHT] = false;
			}

			if (event.key.key == SDLK_S) {
				arrayKey[MY_BOTTOM] = false;
				arrayKey[MY_CLIKER_BOTTOM] = false;
			}

			if (event.key.key == SDLK_A) {
				arrayKey[MY_LEFT] = false;
				arrayKey[MY_CLIKER_LEFT] = false;
			}

			break;

		case SDL_EVENT_KEY_DOWN:

			if (event.key.key == SDLK_W && arrayKey[MY_CLIKER_TOP] == false) {
				// globalCount++;
				// printf("%d\n",globalCount);
				arrayKey[MY_TOP] = true;
				arrayKey[MY_SCORE] = true;
			}

			if (event.key.key == SDLK_D && arrayKey[MY_CLIKER_RIGHT] == false) {
				// globalCount++;
				// printf("%d\n",globalCount);
				arrayKey[MY_RIGHT] = true;
				arrayKey[MY_SCORE] = true;
			}

			if (event.key.key == SDLK_S && arrayKey[MY_CLIKER_BOTTOM] == false) {
				// globalCount++;
				// printf("%d\n",globalCount);
				arrayKey[MY_BOTTOM] = true;
				arrayKey[MY_SCORE] = true;
			}

			if (event.key.key == SDLK_A && arrayKey[MY_CLIKER_LEFT] == false) {
				// globalCount++;
				// printf("%d\n",globalCount);
				arrayKey[MY_LEFT] = true;
				arrayKey[MY_SCORE] = true;
			}

			if (event.key.key == SDLK_ESCAPE) {
				*game_is_running = CLOSE;
			}

			if(event.key.key == SDLK_1){
				// // // // printf("\nQ\n");
				*game_is_running = RESUME;
			}

			if(event.key.key == SDLK_2){
				// // // // printf("\nW\n");
				*game_is_running = PAUSE;
			}

			if(event.key.key == SDLK_3){
				// // // // printf("\nE\n");
				*game_is_running = RESTART;
			}

			if(event.key.key == SDLK_4){
				// // // // printf("\nR\n");
				*game_is_running = CLOSE;
			}

			break;
	}
	
	// printf("\n///////////////////////////\n");
	// printf(  "/// END - PROCESS INPUT ///\n");
	// printf(  "///////////////////////////\n\n");

}