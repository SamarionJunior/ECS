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


	/////// CLICK ////////
	/////// JUMPER ///////

	// printf("\n////////////////////\n");
	// printf(  "/// END - UPDATE ///\n");
	// printf(  "////////////////////\n\n");

}
