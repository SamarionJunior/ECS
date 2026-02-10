#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "scoreCalculator.h"
#include "collision.h"
#include "systems.h"
#include "snake.h"

#include "../entities/entities.h"
#include "../entities/utility.h"

#include "../components/components.h"
#include "../components/get.h"

#include "../../constants.h"

#include "../../engine/update.h"
#include "../../engine/input.h"
#include "../../engine/setupUtility.h"

#include "../../../dependencies/my/dynamicarray/array.h"

#include "../../loader/json.h"

// #include "../../../dependencies/my/dynamicvectors/vector.h"

// #include "../../../dependencies/my/dynamicvectors/entities/entity.h"

// #include "../../../dependencies/my/dynamicvectors/components/position.h"
// #include "../../../dependencies/my/dynamicvectors/components/size.h"
// #include "../../../dependencies/my/dynamicvectors/components/collider.h"
// #include "../../../dependencies/my/dynamicvectors/components/player.h"
// #include "../../../dependencies/my/dynamicvectors/components/collectible.h"

#include "../../engine/setup.h"

#include "../../loader/json.h"
#include "setupCollision.h"

void  scoreCalculator();

static float xA = 0, yA = 0, wA = 0, hA = 0;
static float xB = 0, yB = 0, wB = 0, hB = 0;
static int indexPlayer = -1;
static int indexCollectible = -1;

// int i = 0;

// int indexA = 0;
static int countA = 0;

static Id* idA = NULL;

static Occurrence auxPositionA;
static Occurrence auxSizeA;

static Position tempPositionA;
static Size tempSizeA;

// int j = 0;

static Id* idB = NULL;

// int indexB = 0;
static int countB = 0;

static Occurrence auxPositionB;
static Occurrence auxSizeB;

static Position positionB;
static Size sizeB;

static size_t k = 0;
// int count = 0;
static Occurrence pos;

typedef struct positionAux{
	bool active;
	float x;
	float y;
} PositionAux;

bool checkCollisionBetwenHeadAndFruit(){

	int count = 0;
	
	for(size_t i = 0; i < lengthArray(playerArray); i++){

		if((idA = (Id*)getArray(playerArray, i)) == NULL){
			continue;
		}

		indexPlayer = idA->id;

		if(getOccurrenceById(positionArray, indexPlayer, &auxPositionA) == false){
			continue;
		}
		if(getOccurrenceById(sizeArray, indexPlayer, &auxSizeA) == false){
			continue;
		}

		tempPositionA = (*(Position*)auxPositionA.component);
		tempSizeA = (*(Size*)auxSizeA.component);

		initializeCollisionVariables(tempPositionA, tempSizeA, &xA, &yA, &wA, &hA);

		for(size_t j = 0 ; j < lengthArray(collectibleArray); j++){

			if((idB = (Id*)getArray(collectibleArray, j)) == NULL){
				continue;
			}

			if((indexCollectible = idB->id) == indexPlayer){
				continue;
			}

			if(getOccurrenceById(positionArray, indexCollectible, &auxPositionB) == false){
				continue;
			}
			if(getOccurrenceById(sizeArray, indexCollectible, &auxSizeB) == false){
				continue;
			}
			// Collectible* auxCollectibleB = getCollectibleById(indexB, &countB);

			positionB = (*((Position*)auxPositionB.component));
			sizeB = (*((Size*)auxSizeB.component));
		
			initializeCollisionVariables(positionB, sizeB, &xB, &yB, &wB, &hB);

			if(isItColliding(xA, yA, wA, hA, xB, yB, wB, hB) == false){
				continue;
			}

			return true;

		}

	}

	return false;

}

typedef struct auxiliarycoordinate {
	int x;
	int y;
} AuxiliaryCoordinate;


void createNewFruit(){

	// int utilC = getUTILC(), utilR = getUTILR();

	Occurrences auxPos;

	const int auxLength = getROW() * getCOL();

	for (size_t y = 0; y < getROW(); y++){
		for (size_t x = 0; x < getCOL(); x++){
			freeSpaces[y][x] = itIsFree;
		}
	}

	// for (size_t y = 0; y < getROW(); y++){
	// 	for (size_t x = 0; x < getCOL(); x++){
	// 		printf("%d", freeSpaces[y][x]);
	// 	}
	// 	printf("\n");
	// }

	int count = 0;

	for (size_t i = 0; i < lengthArray(positionArray); i++){

		Position* auxPos;

		if((auxPos = (Position*)getArray(positionArray, i)) == NULL){
			continue;
		}

		freeSpaces[
			(int)(auxPos->current2.y / SPRITE)
		][
			(int)(auxPos->current2.x / SPRITE)
		] = NotFree;

		count++;

	}

	// for (size_t y = 0; y < getROW(); y++){
	// 	for (size_t x = 0; x < getCOL(); x++){
	// 		printf("%d", freeSpaces[y][x]);
	// 	}
	// 	printf("\n");
	// }

	// printf("Tail Lenght: %d\n", lengthArray(anchorArray));
	// printf("Position Lenght: %d\n", lengthArray(positionArray));

	// for (size_t i = 0; i < lengthArray(anchorArray); i++){
	// 	Anchor* auxAnchor = (Anchor*)getArray(anchorArray, i);
	// 	printf("Anchor id: %d\n", auxAnchor->id);
	// 	Occurrences auxOccurrences;
	// 	if((auxOccurrences = getComponentsById(positionArray, auxAnchor->id)).size == 0){
	// 		continue;
	// 	}
	// 	printf("Pos id: %d\n", ((Position*)(auxOccurrences.array[0].component))->id);
	// 	if(((Position*)(auxOccurrences.array[0].component))->id != auxAnchor->id){
	// 		continue;
	// 	}
	// 	printf("Pos id: %d\n", ((Position*)(auxOccurrences.array[0].component))->id);
	// 	int auxX = (int)(((Position*)(auxOccurrences.array[0].component))->current2.x / SPRITE);
	// 	int auxY = (int)(((Position*)(auxOccurrences.array[0].component))->current2.y / SPRITE);
	// 	printf(
	// 		"ID: %d - X: %d - Y: %d\n", 
	// 		((Position*)(auxOccurrences.array[0].component))->id,
	// 		auxX, 
	// 		auxY
	// 	);
	// }

	// for (size_t i = 0; i < lengthArray(positionArray); i++){
	// 	Position* auxPosition = (Position*)getArray(positionArray, i);
	// 	printf(
	// 		"ID: %d\tX: %d\tY: %d\n", 
	// 		auxPosition->id, 
	// 		(int) auxPosition->current2.x / SPRITE, 
	// 		(int) auxPosition->current2.y / SPRITE
	// 	);
	// }

	AuxiliaryCoordinate auxiliaryCoordinates[auxLength];

	const int countFreeSpace = auxLength - count;

	if(countFreeSpace <= 0){
		return;
	}

	// AuxiliaryCoordinate auxiliaryCoordinates[countFreeSpace];

	for (size_t i = 0; i < (countFreeSpace); i++){
		auxiliaryCoordinates[i] = (AuxiliaryCoordinate){
			.x = -1,
			.y = -1
		};
	}

	int count2 = 0;

	for (size_t y = 0; y < getROW(); y++){
		for (size_t x = 0; x < getCOL(); x++){
			if(freeSpaces[y][x] == itIsFree){
				auxiliaryCoordinates[count2] = (AuxiliaryCoordinate){
					.x = x,
					.y = y
				};
				count2++;
			}
		}
	}

	const int drawnNumber = rand() % ((countFreeSpace - 1) + 1 + 0) + 0;

	// printf("Drawn Number = %d\n", drawnNumber);

	AuxiliaryCoordinate selectedAuxiliaryCoordinate = auxiliaryCoordinates[drawnNumber];

	// printf(
	// 	"y = %d - x = %d\n",
	// 	selectedAuxiliaryCoordinate.y,
	// 	selectedAuxiliaryCoordinate.x
	// );

	for (k = 0; k < lengthArray(temporaryEntities); k++){

		TemporaryEntity te = *((TemporaryEntity*)(getArray(temporaryEntities, k)));

		if(te.entityType != 2){
			continue;
		}

		float x, y;
		for (size_t l = 0; l < lengthArray(te.componentAndTypes); l++){
			ComponentAndType cap = *((ComponentAndType*)(getArray(te.componentAndTypes, l)));
			if(cap.type == POSITION){
				x = ((Position*)(cap.component))->current2.x;
				y = ((Position*)(cap.component))->current2.y;
				((Position*)(cap.component))->current2.x = selectedAuxiliaryCoordinate.x * SPRITE;
				((Position*)(cap.component))->current2.y = selectedAuxiliaryCoordinate.y * SPRITE;
			}
		}

		createKindComponents(te);

		for (size_t l = 0; l < lengthArray(te.componentAndTypes); l++){
			ComponentAndType cap = *((ComponentAndType*)(getArray(te.componentAndTypes, l)));
			if(cap.type == POSITION){
				((Position*)(cap.component))->current2.x = x;
				((Position*)(cap.component))->current2.y = y;
			}
		}

		break;

	}
	
	// printf("%f\n", (*(Position*)pos.array[0].component).old2.x);

	// createKindComponents(
	// 	selectedAuxiliaryCoordinate.x,
	// 	selectedAuxiliaryCoordinate.y,
	// 	// rand() % ((getCOL() - 2) + 0 - WALLS) + WALLS,
	// 	// rand() % ((getROW() - 2) + 0 - WALLS) + WALLS,
	// 	// rand() % (getCOL() + 1 - 3),
	// 	// rand() % (getROW() + 1 - 3),
	// 	// (((*(Position*)pos.array[0].component).old2.x) - SPRITE) / SPRITE, 
	// 	// (((*(Position*)pos.array[0].component).old2.y) - SPRITE) / SPRITE, 
	// 	getSnakeTail(),
	// 	k
	// );

}

// bool isUnloackScore(){
// 	return 
// 		(arrayKey[MY_SCORE] == false) ?
// 			false :
// 			true;
// }

// bool unloackScore(){
// 	arrayKey[MY_SCORE] = false;
// 	return true;
// }

bool incrementScore(){
	score++;
	return true;
}

bool removeFruit(){
	return removeEntity(indexCollectible);
}

bool createTail(){

	// printf("Tail Lenght: %d\n", lengthArray(anchorArray));
	// printf("Position Lenght: %d\n", lengthArray(positionArray));

	// for (k = 0; k < lengthArray(temporaryEntities); k++){
	// 	TemporaryEntity te = *((TemporaryEntity*)(getArray(temporaryEntities, k)));
	// 	if(te.entityType == 4){
	// 		break;
	// 	}
	// }

	// printf("%d\n", temporaryComponents[k].index);

	if(getOccurrenceById(positionArray, indexPlayer, &pos) == false){
		printf("Player Position not find\n");
		return;
	}

	float x = ((*((Position*)pos.component)).old2.x);
	float y = ((*((Position*)pos.component)).old2.y);

	// printf("%f\n", (*(Position*)pos.array[0].component).old2.x);

	// printf("getSnakeTail: %d\n", getSnakeTail());

	// printf(
	// 	"X: %f - Y: %f\n", 
	// 	((*(Position*)pos.array[0].component).old2.x) / SPRITE, 
	// 	((*(Position*)pos.array[0].component).old2.y) / SPRITE
	// );

	for (k = 0; k < lengthArray(temporaryEntities); k++){

		TemporaryEntity te = *((TemporaryEntity*)(getArray(temporaryEntities, k)));

		if(te.entityType != 4){
			continue;
		}

		float tempX, tempY;
		int id;
		for (size_t l = 0; l < lengthArray(te.componentAndTypes); l++){
			ComponentAndType cap = *((ComponentAndType*)(getArray(te.componentAndTypes, l)));
			if(cap.type == POSITION){
				tempX = ((Position*)(cap.component))->current2.x;
				tempY = ((Position*)(cap.component))->current2.y;
				((Position*)(cap.component))->current2.x = x;
				((Position*)(cap.component))->current2.y = y;
			}
			if(cap.type == ANCHOR){
				id = ((Anchor*)(cap.component))->idParent;
				((Anchor*)(cap.component))->idParent = getSnakeTail();
			}
		}

		printf("createKindComponents\n");

		createKindComponents(te);

		for (size_t l = 0; l < lengthArray(te.componentAndTypes); l++){
			ComponentAndType cap = *((ComponentAndType*)(getArray(te.componentAndTypes, l)));
			if(cap.type == POSITION){
				((Position*)(cap.component))->current2.x = tempX;
				((Position*)(cap.component))->current2.y = tempY;
			}
			if(cap.type == ANCHOR){
				((Anchor*)(cap.component))->idParent = id;
			}
		}
	}

	// createKindComponents(
	// 	x, 
	// 	y, 
	// 	getSnakeTail(),
	// 	k
	// );

	// printf("Tail Lenght: %d\n", lengthArray(anchorArray));
	// printf("Tail id: %d\n", ((Anchor*)(getArray(anchorArray, lengthArray(anchorArray) - 1)))->id);
	// printf("Tail idParent: %d\n", ((Anchor*)(getArray(anchorArray, lengthArray(anchorArray) - 1)))->idParent);
	// printf("Position Lenght: %d\n", lengthArray(positionArray));
	// printf("Position id: %d\n", ((Position*)(getArray(positionArray, lengthArray(positionArray) - 1)))->id);

	return true;

}

void scoreCalculator(){

	xA = 0; yA = 0; wA = 0; hA = 0;	xB = 0; yB = 0; wB = 0; hB = 0;

	if(checkCollisionBetwenHeadAndFruit() == false){
		return;
	}

	if(incrementScore() == false){
		return;
	}

	if(removeFruit() == false){
		return;
	}

	if(createTail() == false){
		return;
	}

	iterationSnake();

	createNewFruit();

	// if(isUnloackScore() == false){
	// 	return;
	// }

	// if(unloackScore() == false){
	// 	return;
	// }

	// printf("score: %d\n", score);
}