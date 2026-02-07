#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "move.h"
#include "collision.h"
#include "systems.h"
#include "scoreCalculator.h"
#include "snake.h"
#include "../entities/entities.h"

#include "../components/components.h"
#include "../components/get.h"

#include "../../constants.h"
#include "../../engine/update.h"

#include "../../engine/input.h"

#include "../../manager/delay.h"

// #include "../../../dependencies/my/dynamicvectors/vector.h"

// #include "../../../dependencies/my/dynamicvectors/entities/entity.h"

// #include "../../../dependencies/my/dynamicvectors/components/position.h"
// #include "../../../dependencies/my/dynamicvectors/components/size.h"
// #include "../../../dependencies/my/dynamicvectors/components/player.h"

typedef enum keyblock{
	KEY_BLOCK_TOP,
	KEY_BLOCK_BOTTOM,
	KEY_BLOCK_RIGHT,
	KEY_BLOCK_LEFT,
	KEY_BLOCK_LENGHT
} KeyBlock;

static bool keyBlocks[KEY_BLOCK_LENGHT] = {false};

static double kmH = 70.7106781187;
static double moveDefualt = (double)300;
static double moveKMH = 0.0f;

static const float moveTop 		= -32.f;
static const float moveBottom 	= 32.f;
static const float moveRight 	= -32.f;
static const float moveLeft 		= 32.f;

// static int i = 0;

static Id* id = NULL;

static int count = 0;

int temporaryIndex = 0;

static Occurrence occurrencePosition;
static Occurrence occurrenceSize;
// static Occurrence occurrencesPlayer;

static Position* temporaryPointerPosition;

static Position temporaryPosition;
static Size temporarySize;

typedef enum way{
	VERTICAL,
	HORIZONTAL
} Way;

typedef struct moveconfig{
	bool* down;
	bool* up;
	Way way;
	float difference;
	bool* keyBlock
} MoveConfig;

static const int lenghtMoveConfig = 4;

static MoveConfig moveconfig[] = {
	(MoveConfig){
		.down = &keys[DOWN_TOP],
		.up = &keys[UP_TOP],
		.way = VERTICAL,
		.difference = moveTop,
		.keyBlock = &keyBlocks[KEY_BLOCK_TOP]
	},
	(MoveConfig){
		.down = &keys[DOWN_BOTTOM],
		.up = &keys[UP_BOTTOM],
		.way = VERTICAL,
		.difference = moveBottom,
		.keyBlock = &keyBlocks[KEY_BLOCK_BOTTOM]
	},
	(MoveConfig){
		.down = &keys[DOWN_RIGHT],
		.up = &keys[UP_RIGHT],
		.way = HORIZONTAL,
		.difference = moveRight,
		.keyBlock = &keyBlocks[KEY_BLOCK_RIGHT]
	},
	(MoveConfig){
		.down = &keys[DOWN_LEFT],
		.up = &keys[UP_LEFT],
		.way = HORIZONTAL,
		.difference = moveLeft,
		.keyBlock = &keyBlocks[KEY_BLOCK_LEFT]
	}
};

void updateOldPosition(Position *aux, Position temp){
	aux->old2.y = aux->current2.y;
	aux->current2.y = temp.current2.y;
	aux->old2.x = aux->current2.x;
	aux->current2.x = temp.current2.x;
}

void printPosition(Position *aux){
	printf(
		"X: %f - Y: %f - OldX: %f - OldY: %f\n",
		aux->current2.x,
		aux->current2.y,
		aux->old2.x,
		aux->old2.y
	);
}

bool isClickDown(MoveConfig moveconfig){
	return (
		*(moveconfig.down) == true && 
		*(moveconfig.up) == false &&
		*(moveconfig.keyBlock) == false
	);
}

void click(MoveConfig moveconfig){

	switch(moveconfig.way){
		case VERTICAL:
			temporaryPosition.current2.y += moveconfig.difference;
			break;
		case HORIZONTAL:
			temporaryPosition.current2.x += moveconfig.difference;
			break;
	}

	if(collisionBetween(temporaryPosition, temporarySize) == true){
		// printf("%d\n", rand());
		return;
	}

	updateOldPosition(
		temporaryPointerPosition, 
		temporaryPosition
	);
	
	*(moveconfig.keyBlock) = true;

}

void move(){

	if(lengthArray(playerArray) == 0){
		return;
	}

	moveKMH = (((moveDefualt * (double)delta_time)/100)*kmH);

	for(size_t i = 0 ; i < lengthArray(playerArray); i++){

		if((id = (Id*)getArray(playerArray, i)) == NULL){
			continue;
		}

		temporaryIndex = id->id;

		if(getOccurrenceById(positionArray, temporaryIndex, &occurrencePosition) == false){
			continue;
		}
		if(getOccurrenceById(sizeArray, temporaryIndex, &occurrenceSize) == false){
			continue;
		}

		temporaryPosition = (*((Position*)occurrencePosition.component));
		temporarySize = (*((Size*)occurrenceSize.component));

		temporaryPointerPosition = (Position*)occurrencePosition.component;

		for (size_t j = 0; j < lenghtMoveConfig; j++){

			MoveConfig currentMoveConfig = moveconfig[j];
			
			bool result;

			if((result = isClickDown(currentMoveConfig)) == false){

				if(
					*(currentMoveConfig.down) == false && 
					*(currentMoveConfig.up) == true
				){
					*(currentMoveConfig.keyBlock) = false;
				}

				continue;
			}

			// printf(
			// 	"%d: down = %d - %d\n", 
			// 	rand(),
			// 	*(currentMoveConfig.down), 
			// 	*(currentMoveConfig.up)
			// );

			// printf("%d\n", result);

			click(currentMoveConfig);

			// printf("%d\n", rand());

			scoreCalculator();

			iterationSnake();

		}
	}
}