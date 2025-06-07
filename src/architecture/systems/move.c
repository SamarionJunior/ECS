#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "move.h"
#include "collision.h"
#include "systems.h"
#include "../entities/entities.h"
#include "../components/components.h"
#include "../../constants.h"
#include "../../engine/update.h"
#include <stdlib.h>

#include "../../engine/input.h"

#include "../../../dependencies/my/dynamicvectors/vector.h"

#include "../../../dependencies/my/dynamicvectors/entities/entity.h"

#include "../../../dependencies/my/dynamicvectors/components/position.h"
#include "../../../dependencies/my/dynamicvectors/components/size.h"
#include "../../../dependencies/my/dynamicvectors/components/player.h"

double kmH = 70.7106781187;

void move(){

	if(lengthCollumnPlayer(&vectorPlayer) == 0){
		return;
	}	
	
	double moveDefualt = (double)300;

	double moveKMH = (((moveDefualt * (double)delta_time)/100)*kmH);

	for(int i = 0 ; i < lengthCollumnEntity(&vectorEntity); i++){

		Entity* id = getCellEntity(&vectorEntity, i);

		if(id == NULL){
			continue;
		}

		// printf("\n%d\n", id);
		// printf("\n%d\n", id->index);

		int index = id->index;

		int count = 0;

		Position* auxPosition = NULL;
		Size* auxSize = NULL;
		Player* auxPlayer = NULL;

		for (size_t j = 0; j < lengthCollumnPosition(&vectorPosition); j++){
			Position* tempPosition = getCellPosition(&vectorPosition, j);
			if(tempPosition != NULL){
				if(tempPosition->id == index){
					auxPosition = tempPosition;
					count++;
					// printf("\nPosition: %d\n", count);
					break;
				}
			}
		}
		for (size_t j = 0; j < lengthCollumnSize(&vectorSize); j++){
			Size* tempSize = getCellSize(&vectorSize, j);
			if(tempSize != NULL){
				if(tempSize->id == index){
					auxSize = tempSize;
					count++;
					// printf("\nSize: %d\n", count);
					break;
				}
			}
		}
		for (size_t j = 0; j < lengthCollumnPlayer(&vectorPlayer); j++){
			Player* tempPlayer = getCellPlayer(&vectorPlayer, j);
			if(tempPlayer != NULL){
				if(tempPlayer->id == index){
					auxPlayer = tempPlayer;
					count++;
					// printf("\nPlayer: %d\n", count);
					break;
				}
			}
		}
		// printf("\n%d\n", index);
		// printf("\n%d\n", lengthCollumnPosition(&vectorPosition));
		// printf("\n%d\n", lengthCollumnSize(&vectorSize));
		// printf("\n%d\n", lengthCollumnPlayer(&vectorPlayer));

		if(count != 3){
			continue;
		}

		// printf("\n%d\n", count);

		Position tempPosition = *auxPosition;
		Size tempSize = *auxSize;

		if(arrayKey[MY_TOP] && arrayKey[MY_CLIKER_TOP] == false){
			tempPosition.current2.y -= 32;
			bool result = collisionBetween(&tempPosition, &tempSize);
			if(result != false){
				// printf("%s\n", auxCompB->information->name);
			}else{
				auxPosition->old2.y = auxPosition->current2.y;
				auxPosition->current2.y -= 32;
				// globalCount++;
			}
			arrayKey[MY_CLIKER_TOP] = true;
			continue;
		}

		if(arrayKey[MY_BOTTOM] && arrayKey[MY_CLIKER_BOTTOM] == false){
			tempPosition.current2.y += 32;
			bool result = collisionBetween(&tempPosition, &tempSize);
			if(result != false){
				// printf("%s\n", auxCompB->information->name);
			}else{
				auxPosition->old2.y = auxPosition->current2.y;
				auxPosition->current2.y += 32;
				// globalCount++;
			}
			arrayKey[MY_CLIKER_BOTTOM] = true;
			continue;
		}

		if(arrayKey[MY_RIGHT] && arrayKey[MY_CLIKER_RIGHT] == false){
			tempPosition.current2.x += 32;
			bool result = collisionBetween(&tempPosition, &tempSize);
			if(result != NULL){
				// printf("%s\n", auxCompB->information->name);
			}else{
				auxPosition->old2.x = auxPosition->current2.x;
				auxPosition->current2.x += 32;
				// globalCount++;
			}
			arrayKey[MY_CLIKER_RIGHT] = true;
			continue;
		}

		if(arrayKey[MY_LEFT] && arrayKey[MY_CLIKER_LEFT] == false){
			tempPosition.current2.x -= 32;
			bool result = collisionBetween(&tempPosition, &tempSize);
			if(result != NULL){
				// printf("%s\n", auxCompB->information->name);
			}else{
				auxPosition->old2.x = auxPosition->current2.x;
				auxPosition->current2.x -= 32;
				// globalCount++;
			}
			arrayKey[MY_CLIKER_LEFT] = true;
			continue;
		}

	}
	
	// Position auxPosA;
	// Size auxSizA;

	// for (size_t i = 0; i < lengthRow(&componentsForMove, 0); i++){
		
	// 	comp = ((ComponentsForMove *)(getCell(&componentsForMove, 0, i)->data));

	// 	auxCompA = *comp;
	// 	auxPosA = *(auxCompA.position);
	// 	auxSizA = *(auxCompA.size);

	// 	auxCompB = NULL;

	// 	if(arrayKey[MY_TOP] && arrayKey[MY_CLIKER_TOP] == false){

	// 		auxPosA.current2.y -= 32;

	// 		auxCompB = collisionBetween(&auxPosA, &auxSizA);

	// 		if(auxCompB != NULL){
	// 			// printf("%s\n", auxCompB->information->name);

	// 		}else{

	// 			comp->position->old2.y = comp->position->current2.y;
	
	// 			comp->position->current2.y -= 32;

	// 			// globalCount++;

	// 		}

	// 		arrayKey[MY_CLIKER_TOP] = true;

	// 		continue;
	// 	}

	// 	if(arrayKey[MY_BOTTOM] && arrayKey[MY_CLIKER_BOTTOM] == false){

	// 		auxPosA.current2.y += 32;

	// 		auxCompB = collisionBetween(&auxPosA, &auxSizA);

	// 		if(auxCompB != NULL){
	// 			// printf("%s\n", auxCompB->information->name);

	// 		}else{

	// 			comp->position->old2.y = comp->position->current2.y;
		
	// 			comp->position->current2.y += 32;

	// 			// globalCount++;

	// 		}

	// 		arrayKey[MY_CLIKER_BOTTOM] = true;

	// 		continue;
	// 	}

	// 	if(arrayKey[MY_RIGHT] && arrayKey[MY_CLIKER_RIGHT] == false){

	// 		auxPosA.current2.x += 32;

	// 		auxCompB = collisionBetween(&auxPosA, &auxSizA);

	// 		if(auxCompB != NULL){
	// 			// printf("%s\n", auxCompB->information->name);

	// 		}else{

	// 			comp->position->old2.x = comp->position->current2.x;
	
	// 			comp->position->current2.x += 32;

	// 			// globalCount++;

	// 		}

	// 		arrayKey[MY_CLIKER_RIGHT] = true;
			
	// 		continue;
	// 	}

	// 	if(arrayKey[MY_LEFT] && arrayKey[MY_CLIKER_LEFT] == false){

	// 		auxPosA.current2.x -= 32;

	// 		auxCompB = collisionBetween(&auxPosA, &auxSizA);

	// 		if(auxCompB != NULL){
	// 			// printf("%s\n", auxCompB->information->name);

	// 		}else{

	// 			comp->position->old2.x = comp->position->current2.x;
	
	// 			comp->position->current2.x -= 32;

	// 			// globalCount++;

	// 		}

	// 		arrayKey[MY_CLIKER_LEFT] = true;

	// 		continue;
	// 	}

	// }
}























	// if(arrayKey[MY_TOP] && arrayKey[MY_LEFT]){

	// 	comp->position->old2.y = comp->position->current2.y;
	// 	comp->position->old2.x = comp->position->current2.x;

	// 	comp->position->current2.y -= 32;
	// 	comp->position->current2.y -= 32;

	// 	continue;
	// }

	// if(arrayKey[MY_TOP] && arrayKey[MY_RIGHT]){

	// 	comp->position->old2.y = comp->position->current2.y;
	// 	comp->position->old2.x = comp->position->current2.x;

	// 	comp->position->current2.y -= 32;
	// 	comp->position->current2.y += 32;

	// 	continue;
	// }

	// if(arrayKey[MY_BOTTOM] && arrayKey[MY_LEFT]){

	// 	comp->position->old2.y = comp->position->current2.y;
	// 	comp->position->old2.x = comp->position->current2.x;

	// 	comp->position->current2.y += 32;
	// 	comp->position->current2.x -= 32;

	// 	continue;
	// }

	// if(arrayKey[MY_BOTTOM] && arrayKey[MY_RIGHT]){

	// 	comp->position->old2.y = comp->position->current2.y;
	// 	comp->position->old2.x = comp->position->current2.x;

	// 	comp->position->current2.y += 32;
	// 	comp->position->current2.y += 32;

	// 	continue;
	// }

	// int* entity;

	// // printf("\n%d\n", getLengthSystem(MOVE));

	// for (size_t i = 0; i < getLengthSystem(MOVE); i++){

	// 	// printf("\n%d\n", *(int *)getIdInSystem(MOVE, i));


	// 	// printf("\noi-2\n");

	// 	if(!existEntities(*(int *)getIdInSystem(MOVE, i))){
	// 		continue;
	// 	}
		
	// 	entity = (int *)getIdInSystem(MOVE, i);

	// 	double moveDefualt = (double)300;

	// 	double moveKMH = (((moveDefualt * (double)delta_time)/100)*kmH);
		
	// 	// printf("\n%d\n", getDirectionCollision(0, *entity, BOTTOM));

	// 	if(arrayKey[MY_TOP] && arrayKey[MY_LEFT]){
	// 		if(getDirectionCollision(0, *entity, TOP) == 0 && getDirectionCollision(0, *entity, LEFT) == 0){
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldY = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldX = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y -= (float)moveKMH;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x -= (float)moveKMH;
	// 			continue;
	// 		}else if(getDirectionCollision(0, *entity, TOP) == 0 && getDirectionCollision(0, *entity, LEFT) == 1){
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldX = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldY = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y -= (float)(moveDefualt * (double)delta_time);
	// 			continue;
	// 		}else if(getDirectionCollision(0, *entity, TOP) == 1 && getDirectionCollision(0, *entity, LEFT) == 0){
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldY = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldX = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x -= (float)(moveDefualt * (double)delta_time);
	// 			continue;
	// 		}
	// 	}

	// 	if(arrayKey[MY_TOP] && arrayKey[MY_RIGHT]){
	// 		if(getDirectionCollision(0, *entity, TOP) == 0 && getDirectionCollision(0, *entity, RIGHT) == 0){
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldY = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldX = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y -= (float)moveKMH;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x += (float)moveKMH;
	// 			continue;
	// 		}else if(getDirectionCollision(0, *entity, TOP) == 0 && getDirectionCollision(0, *entity, RIGHT) == 1){
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldX = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldY = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y -= (float)(moveDefualt * (double)delta_time);
	// 			continue;
	// 		}else if(getDirectionCollision(0, *entity, TOP) == 1 && getDirectionCollision(0, *entity, RIGHT) == 0){
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldY = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldX = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x += (float)(moveDefualt * (double)delta_time);
	// 			continue;
	// 		}
	// 	}

	// 	if(arrayKey[MY_BOTTOM] && arrayKey[MY_LEFT]){
	// 		if(getDirectionCollision(0, *entity, BOTTOM) == 0 && getDirectionCollision(0, *entity, LEFT) == 0){
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldY = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldX = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y += (float)moveKMH;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x -= (float)moveKMH;
	// 			continue;
	// 		}else if(getDirectionCollision(0, *entity, BOTTOM) == 0 && getDirectionCollision(0, *entity, LEFT) == 1){
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldX = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldY = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y += (float)(moveDefualt * (double)delta_time);
	// 			continue;
	// 		}else if(getDirectionCollision(0, *entity, BOTTOM) == 1 && getDirectionCollision(0, *entity, LEFT) == 0){
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldY = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldX = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x -= (float)(moveDefualt * (double)delta_time);
	// 			continue;
	// 		}
	// 	}

	// 	if(arrayKey[MY_BOTTOM] && arrayKey[MY_RIGHT]){
	// 		if(getDirectionCollision(0, *entity, BOTTOM) == 0 && getDirectionCollision(0, *entity, RIGHT) == 0){
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldY = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldX = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y += (float)moveKMH;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x += (float)moveKMH;
	// 			continue;
	// 		}else if(getDirectionCollision(0, *entity, BOTTOM) == 0 && getDirectionCollision(0, *entity, RIGHT) == 1){
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldX = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldY = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y += (float)(moveDefualt * (double)delta_time);
	// 			continue;
	// 		}else if(getDirectionCollision(0, *entity, BOTTOM) == 1 && getDirectionCollision(0, *entity, RIGHT) == 0){
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldY = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldX = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x;
	// 			((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x += (float)(moveDefualt * (double)delta_time);
	// 			continue;
	// 		}
	// 		continue;
	// 	}

	// 	if(arrayKey[MY_TOP] && getDirectionCollision(0, *entity, TOP) == 0){
	// 		// printf("arrow top\n");
	// 		((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldX = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x;
	// 		((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldY = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y;
	// 		((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y -= (float)(moveDefualt * (double)delta_time);
	// 		continue;
	// 	}

	// 	if(arrayKey[MY_BOTTOM] && getDirectionCollision(0, *entity, BOTTOM) == 0){
	// 		((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldX = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x;
	// 		((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldY = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y;
	// 		((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y += (float)(moveDefualt * (double)delta_time);
	// 		continue;
	// 	}

	// 	if(arrayKey[MY_RIGHT] && getDirectionCollision(0, *entity, RIGHT) == 0){
	// 		// printf("\n%d\n", getDirectionCollision(0, *entity, RIGHT));
	// 		((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldY = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y;
	// 		((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldX = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x;
	// 		((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x += (float)(moveDefualt * (double)delta_time);
	// 		continue;
	// 	}

	// 	if(arrayKey[MY_LEFT] && getDirectionCollision(0, *entity, LEFT) == 0){
	// 		((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldY = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->y;
	// 		((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->oldX = ((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x;
	// 		((Position *)readComponentByIdAndReturnReferenc(POSITION, *entity))->x -= (float)(moveDefualt * (double)delta_time);
	// 		continue;
	// 	}

	// }