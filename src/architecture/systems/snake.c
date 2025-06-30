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

#include "../../../dependencies/my/dynamicvectors/vector.h"

#include "../../../dependencies/my/dynamicvectors/entities/entity.h"

#include "../../../dependencies/my/dynamicvectors/components/position.h"
#include "../../../dependencies/my/dynamicvectors/components/size.h"
#include "../../../dependencies/my/dynamicvectors/components/collider.h"
#include "../../../dependencies/my/dynamicvectors/components/player.h"
#include "../../../dependencies/my/dynamicvectors/components/anchor.h"

int getSnakeTail();
void iterationSnake();

Anchor* getAnchorByParent(int idParent, int* count){
	Anchor* tempAnchor = NULL;
	for (size_t j = 0; j < lengthCollumnAnchor(&vectorAnchor); j++){
		tempAnchor = getCellAnchor(&vectorAnchor, j);
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

	int index = -1;
		
	for(int i = 0 ; i < lengthCollumnPlayer(&vectorPlayer); i++){

		Player* player = getCellPlayer(&vectorPlayer, i);

		if(player == NULL){continue;}

		int idA = player->id;

		index = idA;
		
		Anchor* tail = NULL;
		
		while(true){
			int count = 0;

			tail = getAnchorByParent(idA, &count);

			if(tail == NULL){
				break;
			}

			idA = tail->id;

			index = tail->id;

		}

	}

	return index;

}

void iterationSnake(){

	for(int i = 0 ; i < lengthCollumnPlayer(&vectorPlayer); i++){

		Player* player = getCellPlayer(&vectorPlayer, i);

		if(player == NULL){continue;}

		int idA = player->id, countA = 0;

		Position* auxPositionA = getPositionById(idA, &countA);

		float oldX = auxPositionA->old2.x, oldY = auxPositionA->old2.y;

		// printf("%f - %f\n", oldX, oldY);

		Anchor* tail = NULL;
		
		while(true){
			int countB = 0;

			tail = getAnchorByParent(idA, &countB);

			if(tail == NULL){
				break;
			}

			Position* auxPositionB = getPositionById(tail->id, &countB);

			// printf("%f - %f\n", oldX, oldY);

			float tempX = auxPositionB->current2.x, tempY = auxPositionB->current2.y;

			auxPositionB->current2.x = oldX;
			auxPositionB->current2.y = oldY;

			oldX = tempX;
			oldY = tempY;

			idA = tail->id;

		}

	}

}