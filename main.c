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

#include "src/architecture/components/components.h"
#include "src/architecture/entities/entities.h"

#include "src/architecture/systems/systems.h"
#include "src/architecture/systems/gravity.h"
#include "src/architecture/systems/collision.h"

#include "src/engine/setup.h"
#include "src/engine/input.h"
#include "src/engine/update.h"
#include "src/engine/render.h"

#include "src/loader/json.h"
#include "src/loader/map.h"

float acerelacion = 1;

// int game_is_running = PAUSE;
int game_is_running = RUN;

void treatsignal(int signal){
	// // // // printf("\nEncerrando\n");
	exit(0);
}

void loop(){

	// // // // printf("\n////////////\n");
	// // // // printf(  "/// LOOP ///\n");
	// // // // printf(  "////////////\n\n");

	// score = 0;

	// printf("%d\n",score);

	long int count = 0;

	long int media = 0;

	long int secunds = 0;

	long int countSecunds = 0.0;

	struct timeval stop, start;

	while (true) {

		gettimeofday(&start, NULL);

		// printf("\n////////////////////\n");
		// printf(  "/// LOOP - WHILE ///\n");
		// printf(  "////////////////////\n\n");

		process_input(&game_is_running);

		delay(&game_is_running);

		if(game_is_running == RESUME){
			resetDelay();
			game_is_running = RUN;
		}
		if(game_is_running == RUN){
			if(getIsEmpty() == true){
				update(&game_is_running);
			}else{
				printf("dsdsds\n");
				game_is_running = RESTART;
			}
		}
		if(game_is_running == PAUSE){
			/// ENCERRAR THREADS ENTRE OUTROS
		}
		if(game_is_running == RESTART){
			game_is_running = PAUSE;
			setup();
		}
		if(game_is_running == CLOSE){
			break;
		}
		render();

		gettimeofday(&stop, NULL);

		if(stop.tv_usec < start.tv_usec){
			long int q = 999999 - start.tv_usec;
			long int w = stop.tv_usec + q;
			countSecunds += w;
		}else{
			countSecunds += (stop.tv_usec - start.tv_usec);
		}

		count++;

		if (countSecunds > 999999){
			
			secunds++;

			media += count;

			printf("secunds: %lu | microsecunds: %lu | FPS: %lu | media: %lu\n", secunds, countSecunds, count, (media / secunds));
			// printf("start\t %lu us\n", start.tv_usec);
			// printf("stop\t %lu us\n", stop.tv_usec);
			countSecunds = 0.0;
			count = 0;
		}

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

		loadMap();

		loadJSON();

		setup();

		resetDelay();
	
		loop();

		// // // // printf("\n//////////////////////////////\n");
		// // // // printf(  "/// END - SCENE - DO WHILE ///\n");
		// // // // printf(  "//////////////////////////////\n\n");

	}while(!game_is_running == CLOSE);

	// // // // printf("\n///////////////////\n");
	// // // // printf(  "/// END - SCENE ///\n");
	// // // // printf(  "///////////////////\n\n");

}

int main(int argc, char* args[]) {

	// globalCount = 0;
	
	FILE * filePID = fopen("kill.sh", "w");
	// // // // printf("\nPID = %d\n", getpid());
	fprintf(filePID, "kill -15 %d", getpid());
	fclose(filePID);

	signal(15, treatsignal);

	srand(time(NULL));

	// messageStart();
	// // // // printf("\n////////////\n");
	// // // // printf(  "/// MAIN ///\n");
	// // // // printf(  "////////////\n\n"); 

	if(!initialize_window()){
		return 1;
	}

	scene();

	destroyComponents();
	destroyEntities();
	// destroySystem();
	destroy_window();

	for (size_t i = 0; i < getROW(); i++){
		free(mapMatrix[i]);
	}

	free(mapMatrix);

	for (size_t i = 0; i < lengthtemporaryComponents; i++){

		free(temporaryComponents[i].information.name);
		
	}

	// // // // printf("\n//////////////////\n");
	// // // // printf(  "/// END - MAIN ///\n");
	// // // // printf(  "//////////////////\n\n");

	messageEnd();
	return 0;

}