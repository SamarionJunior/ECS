#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../architecture/components/components.h"
#include "../architecture/entities/entities.h"
#include "../architecture/systems/systems.h"
#include "../constants.h"

// #define MY_KEYS 5

typedef enum {
	MY_TOP,
	MY_RIGHT,
	MY_BOTTOM,
	MY_LEFT,
	MY_CLIKER_TOP,
	MY_CLIKER_RIGHT,
	MY_CLIKER_BOTTOM,
	MY_CLIKER_LEFT,
	MY_SCORE,
	TOTAL_MY_KEYS
} Arrow;

extern int arrayKey[TOTAL_MY_KEYS];

void process_input(int *game_is_running);

#endif