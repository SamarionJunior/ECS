#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "scoreCalculator.h"
#include "collision.h"
#include "systems.h"
#include "snake.h"

#include "../entities/entities.h"

#include "../components/components.h"
#include "../components/create.h"
#include "../components/get.h"

#include "../../constants.h"
#include "../../engine/update.h"
#include <stdlib.h>

#include "../../engine/input.h"

#include "../../../dependencies/my/dynamicvectors/vector.h"

#include "../../../dependencies/my/dynamicvectors/entities/entity.h"

#include "../../../dependencies/my/dynamicvectors/components/position.h"
#include "../../../dependencies/my/dynamicvectors/components/size.h"
#include "../../../dependencies/my/dynamicvectors/components/collider.h"
#include "../../../dependencies/my/dynamicvectors/components/player.h"
#include "../../../dependencies/my/dynamicvectors/components/collectible.h"

#include "../../engine/setup.h"

#include "../../loader/json.h"

float xA = 0, yA = 0, wA = 0, hA = 0;
float xB = 0, yB = 0, wB = 0, hB = 0;
int indexCollectible = -1;

// int i = 0;

int indexA = 0, countA = 0;

Player* idA = NULL;

Position* auxPositionA = NULL;
Size* auxSizeA = NULL;

Position tempPositionA;
Size tempSizeA;

// int j = 0;

Collectible* idB = NULL;

int indexB = 0;
int countB = 0;

Position* auxPositionB = NULL;
Size* auxSizeB = NULL;

Position positionB;
Size sizeB;

size_t k = 0;
// int count = 0;
Position* pos = NULL;

void chekcCollisionBetwenHeadAndFruit_UnloackKey_IncrementScore_SetId_CreateTail(){

	int count = 0;
	
	for(size_t i = 0; i < lengthCollumnPlayer(&vectorPlayer); i++){

		idA = getCellPlayer(&vectorPlayer, i);

		if(idA == NULL){continue;}

		indexA = idA->id;
		countA = 0;

		auxPositionA = getPositionById(indexA, &countA);
		auxSizeA = getSizeById(indexA, &countA);

		if(countA != 2){continue;}

		tempPositionA = *auxPositionA;
		tempSizeA = *auxSizeA;

		initializeCollisionVariables(tempPositionA, tempSizeA, &xA, &yA, &wA, &hA);

		for(size_t j = 0 ; j < lengthCollumnCollectible(&vectorCollectible); j++){

			idB = getCellCollectible(&vectorCollectible, j);

			if(idB == NULL){continue;}

			indexB = idB->id;

			if(indexB == indexA){continue;}

			countB = 0;

			auxPositionB = getPositionById(indexB, &countB);
			auxSizeB = getSizeById(indexB, &countB);
			// Collectible* auxCollectibleB = getCollectibleById(indexB, &countB);

			if(countB != 2){continue;}
			
			positionB = *auxPositionB;
			sizeB = *auxSizeB;
		
			initializeCollisionVariables(positionB, sizeB, &xB, &yB, &wB, &hB);

			if(isItColliding(xA, yA, wA, hA, xB, yB, wB, hB)){
        // printf("\n%d\n", rand());
				if(arrayKey[MY_SCORE] == true){
					arrayKey[MY_SCORE] = false;
					// system("clear");

					score++;

					// printf("score: %d\n", score);

					indexCollectible = indexB;

					// printf("%d\n", score);

					// float newX = 0, newY = 0;
					
					// printf("new x:%f\n", newX);
					// printf("ort x:%f\n", auxPosMove.current2.x);
					// printf("new y:%f\n", newY);
					// printf("ort y:%f\n", auxPosMove.current2.y);

					for (k = 0; k < lengthtemporaryComponents; k++){
						if(temporaryComponents[k].index != 4){
							continue;
						}
						// printf("%d\n", temporaryComponents[k].index);
						count = 0;
						pos = getPositionById(getSnakeTail(), &count);
						createKindComponents((pos->old2.x), (pos->old2.y), k);
					}

					// do{
					// 	positionB.current2.x = ((rand() % (9 - 0 + 1) + 0)*SPRITE) + (SPRITE * 2);
					// 	positionB.current2.y = ((rand() % (9 - 0 + 1) + 0)*SPRITE) + (SPRITE * 2);
					// // }while(newX == tempPositionA.current2.x || newY == tempPositionA.current2.y);
					// }while(collisionBetween(&positionB, &sizeB));

					// auxPositionB->old2.x = auxPositionB->current2.y;
					// auxPositionB->old2.y = auxPositionB->current2.y;
					// auxPositionB->current2.x = positionB.current2.x;
					// auxPositionB->current2.y = positionB.current2.y;
				}

			}

			continue;

		}

	}

}

typedef struct positionAux{
	bool active;
	float x;
	float y;
} PositionAux;


void createNewFruit(){
	int count = 0;

	for(size_t i = 0 ; i < lengthCollumnCollectible(&vectorCollectible); i++){

		Collectible* idB = getCellCollectible(&vectorCollectible, i);

		if(idB == NULL){continue;}

		indexB = idB->id;

		if(indexB != indexCollectible){continue;}

		if(arrayKey[MY_SCORE] != false){continue;}

		countB = 0;

		auxPositionB = getPositionById(indexB, &countB);
		auxSizeB = getSizeById(indexB, &countB);

		if(countB != 2){continue;}
		
		positionB = *auxPositionB;
		sizeB = *auxSizeB;

		count = 0;
		int randX = 0, randY = 0, row = getROW(), col = getCOL(), utilR = getUTILR(), utilC = getUTILC();

		// int total = (row*col);
		// bool voids[total];
		// PositionAux pa[total];

		// for (size_t c = 0; c < total; c++){
		// 	voids[c] = false;
		// }

		// for (size_t f = 0; f < row; f++){
		// 	for (size_t g = 0; g < col; g++){
		// 		pa[(f * row) + g].active = true;
		// 		pa[(f * row) + g].x = (g * SPRITE) + (SPRITE * 2);
		// 		pa[(f * row) + g].y = (f * SPRITE) + (SPRITE * 2);
		// 	}
		// }

		// int countC = 0;
				
		// for(int d = 0 ; d < lengthCollumnCollider(&vectorCollider); d++){

		// 	Collider* id = getCellCollider(&vectorCollider, d);

		// 	if(id == NULL){continue;}

		// 	int index = id->id;

		// 	int count = 0;

		// 	Position* auxPosition = getPositionById(index, &count);

		// 	if(count != 1){continue;}
			
		// 	int j = ((((int) auxPosition->current2.y) / 32) - (SPACE / 2)), i = ((((int) auxPosition->current2.x) / 32 )- (SPACE / 2));

		// 	// printf("j: %d - i: %d\n", auxPosition->current2.y, auxPosition->current2.x);

		// 	voids[d] = true;

		// 	for (size_t f = 0; f < row; f++){
		// 		for (size_t g = 0; g < col; g++){
		// 			if(auxPosition->current2.y == pa[(f * row) + g].y && auxPosition->current2.x == pa[(f * row) + g].x){
		// 				countC++;
		// 				pa[(f * row) + g].active = false;
		// 			}
		// 			// pa[(f * row) + g].x = (g * SPRITE) + (SPRITE * 2);
		// 			// pa[(f * row) + g].y = (f * SPRITE) + (SPRITE * 2);
		// 		}
		// 	}

		// }

		// for (size_t f = 0; f < total; f++){
		// 	for (size_t g = 0; g < total; g++){
		// 		if(pa[f].active == false && pa[g].active == true){
		// 			PositionAux temp;
		// 			temp = pa[f];
		// 			pa[f] = pa[g];
		// 			pa[g] = temp;
		// 		}
		// 	}
		// }

		// int newTotal = total - countC;
		
		// randX = (rand() % ((newTotal - 1) - 0 + 1) + 0);

		// positionB.current2.x = pa[randX].x;
		// positionB.current2.y = pa[randX].y;

			randX = (rand() % (((utilC + 50) - 1) - 0 + 1) + (0 + utilC));
			randY = (rand() % (((utilC + 50) - 1) - 0 + 1) + (0 + utilC));
			positionB.current2.x = (randX * SPRITE) + (SPRITE * 2);
			positionB.current2.y = (randY * SPRITE) + (SPRITE * 2);

		auxPositionB->old2.x = auxPositionB->current2.x;
		auxPositionB->old2.y = auxPositionB->current2.y;
		auxPositionB->current2.x = positionB.current2.x;
		auxPositionB->current2.y = positionB.current2.y;

		// int total = utilR * utilC;
			// bool attemptMatrix[row][col];
			// for (size_t a = 0; a < row; a++){
			// 	for (size_t b = 0; b < col; b++){
			// 		attemptMatrix[a][b] = false;
			// 	}
			// }
				
			// for(int k = 0 ; k < lengthCollumnCollider(&vectorCollider); k++){

			// 	Collider* id = getCellCollider(&vectorCollider, k);

			// 	if(id == NULL){continue;}

			// 	int index = id->id;

			// 	int count = 0;

			// 	Position* auxPosition = getPositionById(index, &count);

			// 	if(count != 1){continue;}
				
			// 	int j = ((((int) auxPosition->current2.y) / 32) - (SPACE / 2)), i = ((((int) auxPosition->current2.x) / 32 )- (SPACE / 2));

			// 	// printf("j: %d - i: %d\n", auxPosition->current2.y, auxPosition->current2.x);

			// 	attemptMatrix[j][i] = true;

			// }

		// printf("%d\n", rand());
		// printf("||||||\n");
		// for (size_t a = 0; a < row; a++){
		// 	for (size_t b = 0; b < col; b++){
		// 		printf("%d", attemptMatrix[a][b]);
		// 	}
		// 	printf("\n");
		// }
		// printf("||||||\n");

			// int isEmpty = 0;
			// for (size_t a = 0; a < row; a++){
			// 	for (size_t b = 0; b < col; b++){
			// 		if(attemptMatrix[a][b] == false){
			// 			isEmpty++;
			// 		}
			// 	}
			// }
		// printf("%d\n", isEmpty);

			// if(isEmpty == 0){
			// 	setIsEmpty(false);
			// 	break;
			// }
		
		// do{
		// 	randX = (rand() % ((utilC - 1) - 0 + 1) + 0);
		// 	randY = (rand() % ((utilR - 1) - 0 + 1) + 0);
		// 	positionB.current2.x = (randX * SPRITE) + (SPRITE * 2);
		// 	positionB.current2.y = (randY * SPRITE) + (SPRITE * 2);
		// 	// if(attemptMatrix[randY][randX] == true){
		// 	// 	count++;
		// 	// }else{
		// 	// 	attemptMatrix[randY][randX] = true;
		// 	// }
		// 	// if(count == total){
		// 	// 	break;
		// 	// }
		// }while(collisionBetween(&positionB, &sizeB));

	}

}

void  scoreCalculator();

void  scoreCalculator(){
		
	xA = 0; yA = 0; wA = 0; hA = 0;	xB = 0; yB = 0; wB = 0; hB = 0;

	indexCollectible = -1;

	chekcCollisionBetwenHeadAndFruit_UnloackKey_IncrementScore_SetId_CreateTail();
	
	iterationSnake();

	createNewFruit();
}