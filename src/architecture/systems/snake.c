#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "systems.h"
#include "snake.h"
#include "../entities/entities.h"

#include "../components/components.h"
#include "../components/get.h"

#include "../../constants.h"
#include "../../engine/update.h"

// #include "../../../dependencies/my/dynamicvectors/vector.h"

// #include "../../../dependencies/my/dynamicvectors/entities/entity.h"

// #include "../../../dependencies/my/dynamicvectors/components/position.h"
// #include "../../../dependencies/my/dynamicvectors/components/size.h"
// #include "../../../dependencies/my/dynamicvectors/components/collider.h"
// #include "../../../dependencies/my/dynamicvectors/components/player.h"
// #include "../../../dependencies/my/dynamicvectors/components/anchor.h"

int getSnakeTail();
void iterationSnake();

// void snakeSetup(){

// }

Anchor* getAnchorByParent(int idParent, int* count){
	Anchor* tempAnchor = NULL;
	for (size_t j = 0; j < lengthArray(anchorArray); j++){
		tempAnchor = (Anchor*)getArray(anchorArray, j);
		if(tempAnchor != NULL){
			if(tempAnchor->idParent == idParent){
				(*count)++;
				return tempAnchor;
			}
		}
	}
	return NULL;
}

int getSnakeTail(){

	int id = -1;

	Player* player;
	Anchor* tail;
	int count;
		
	for(int i = 0 ; i < lengthArray(playerArray); i++){

		if((player = (Player*)getArray(playerArray, i)) == NULL){
			continue;
		}

		id = player->id;
		
		tail = NULL;
		
		while(true){

			count = 0;

			if((tail = getAnchorByParent(id, &count)) == NULL){
				break;
			}

			id = tail->id;

		}

	}

	return id;

}

void iterationSnake(){

	Player* player;
	int idA;
	int idB;
	Position* auxPositionA = NULL;
	Position* auxPositionB = NULL;
	float oldX;
	float oldY;
	Anchor* tail;
	float tempX;
	float tempY;
	int countB;

	for(int i = 0 ; i < lengthArray(playerArray); i++){

		// printf("%d\n", countB);

		if((player = (Player*)getArray(playerArray, i)) == NULL){
			continue;
		}

		idA = player->id;

		if(getComponentById(positionArray, idA, &auxPositionA) == false){
			continue;
		}

		oldX = auxPositionA->old2.x;
		oldY = auxPositionA->old2.y;

		// printf("%f - %f\n", oldX, oldY);

		tail = NULL;
		
		while(true){
			countB = 0;

			// printf("%d\n", countB);

			if((tail = (Anchor*)getAnchorByParent(idA, &countB)) == NULL){
				// printf("%p\n", tail);
				break;
			}

			// printf("%d\n", countB);

			idA = tail->id;

			// printf("%d\n", idA);

			if(getComponentById(positionArray, idA, &auxPositionB) == false){
				continue;
			}

			// printf("%f - %f\n", oldX, oldY);

			if(
				auxPositionB->current2.x == oldX &&
				auxPositionB->current2.y == oldY 
			){
				break;
			}

			tempX = auxPositionB->current2.x;
			tempY = auxPositionB->current2.y;

			auxPositionB->current2.x = oldX;
			auxPositionB->current2.y = oldY;

			oldX = tempX;
			oldY = tempY;

			// idA = tail->id;

		}

	}

}