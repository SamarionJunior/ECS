#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <sys/time.h>

#include <SDL3/SDL.h>

#include "src/constants.h"
#include "src/utilities/space.h"

#include "src/manager/WindowManage.h"
#include "src/manager/fps.h"
#include "src/manager/signals.h"
#include "src/manager/delay.h"

#include "src/architecture/components/components.h"
#include "src/architecture/entities/entities.h"

#include "src/architecture/systems/systems.h"
#include "src/architecture/systems/gravity.h"
#include "src/architecture/systems/collision.h"
#include "src/architecture/systems/setupCollision.h"

#include "src/engine/setup.h"
#include "src/engine/input.h"
#include "src/engine/update.h"
#include "src/engine/render.h"

#include "src/loader/json.h"
#include "src/loader/map.h"

// #include "dependencies/my/dynamicvectors/vector.h"
// #include "dependencies/my/dynamicvectors/components/position.h"

float acerelacion = 1;

// int game_is_running = PAUSE;

void loop(){

	// // // // printf("\n////////////\n");
	// // // // printf(  "/// LOOP ///\n");
	// // // // printf(  "////////////\n\n");

	// score = 0;

	// printf("%d\n",score);

	bool execute = true;
	while(execute){

		// printf("\n////////////////////\n");
		// printf(  "/// LOOP - WHILE ///\n");
		// printf(  "////////////////////\n\n");

		startFrameCount();

		process_input(&game_is_running);

		// delay(&game_is_running);

		switch (game_is_running){
			case RESUME:
				resetDelay();
				game_is_running = RUN;
				break;
			case RUN:
				if(getIsEmpty() == true){
					update(&game_is_running);
				}else{
					game_is_running = RESTART;
				}
				break;
			case PAUSE:
				/// ENCERRAR THREADS ENTRE OUTROS
				break;
			case WIN:
				/// ENCERRAR THREADS ENTRE OUTROS
				break;
			case LOSS:
				/// ENCERRAR THREADS ENTRE OUTROS
				break;
			case RESTART:
				game_is_running = PAUSE;
				execute = false;
				// return;
				// setup();
				break;
			case CLOSE:
				return;
		}

		render();

		endFrameCount();
		calculateFramesNumber();

	}

	// // // // printf("\n//////////////////\n");
	// // // // printf(  "/// END - LOOP ///\n");
	// // // // printf(  "//////////////////\n\n");
	
}

void scene(void){

	// // // // printf("\n/////////////\n");
	// // // // printf(  "/// SCENE ///\n");
	// // // // printf(  "/////////////\n\n");

	do {

		// // // // printf("\n////////////////////////\n");
		// // // // printf(  "/// SCENE - DO WHILE ///\n");
		// // // // printf(  "////////////////////////\n\n");

		setup();
	
		loop();

		// // // // printf("\n//////////////////////////////\n");
		// // // // printf(  "/// END - SCENE - DO WHILE ///\n");
		// // // // printf(  "//////////////////////////////\n\n");

	}while(game_is_running != CLOSE);

	// // // // printf("\n///////////////////\n");
	// // // // printf(  "/// END - SCENE ///\n");
	// // // // printf(  "///////////////////\n\n");

}
void destroyGame(){

	destroyComponents();
	destroyEntities();
	// destroySystem();
	destroy_window();

	destroyTemporaryEntities(&temporaryEntities);
	destroyMap(map);
	destroyFreeSpaces();
}

int main(int argc, char* args[]) {

	// globalCount = 0;

	registerSignal();

	srand(time(NULL));

	// messageStart();
	// // // // printf("\n////////////\n");
	// // // // printf(  "/// MAIN ///\n");
	// // // // printf(  "////////////\n\n"); 

	if(initialize_window() == false){
		return 1;
	}

	scene();

	destroyGame();

	// // // // printf("\n//////////////////\n");
	// // // // printf(  "/// END - MAIN ///\n");
	// // // // printf(  "//////////////////\n\n");

	messageEnd();

	return 0;
}