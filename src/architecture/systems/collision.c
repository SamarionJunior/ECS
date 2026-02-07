#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "systems.h"
#include "collision.h"
#include "../entities/entities.h"

#include "../components/components.h"
#include "../components/get.h"

#include "../../constants.h"
#include "../../engine/update.h"

bool isItColliding(float xA, float yA, float wA, float hA, float xB, float yB, float wB, float hB);
int isTheSameIndex(Position entityA, Position entityB);
void initializeCollisionVariables(Position entity, Size size, float* x, float* y, float* w, float* h);
void resetVariables();
bool collisionBetween(Position positionA, Size sizeA);

static float xA = 0, yA = 0, wA = 0, hA = 0,
			xB = 0, yB = 0, wB = 0, hB = 0;

static Position temporaryPositionB;
static Size temporarySizeB;

static Id* temporaryId = NULL;

static int temporaryIndex;

static Occurrence occurrencesPosition;
static Occurrence occurrencesSize;

bool isItColliding(float XA, float YA, float WA, float HA, float XB, float YB, float WB, float HB){
	if(
		// xA + wA >= xB &&
		// xA <= xB + wB &&
		// yA + hA >= yB &&
		// yA <= yB + hB
		XA + (WA - 1) >= XB &&
		XA <= XB + (WB - 1) &&
		YA + (HA - 1) >= YB &&
		YA <= YB + (HB - 1)
	){
		return true;
	}
	return false;
}

int isTheSameIndex(Position entityA, Position entityB){
	if(entityA.id == entityB.id){
		return true;
	}
	return false;
}

void initializeCollisionVariables(Position entity, Size size, float* x, float* y, float* w, float* h){
	*x = entity.current2.x;
	*y = entity.current2.y;
	*w = size.vector2.x;
	*h = size.vector2.y;
}

void resetVariables(){
	xA = 0; yA = 0; wA = 0; hA = 0;
	xB = 0; yB = 0; wB = 0; hB = 0;
}

bool collisionBetween(Position temporaryPositionA, Size temporarySizeA){

	resetVariables();

	initializeCollisionVariables(temporaryPositionA, temporarySizeA, &xA, &yA, &wA, &hA);
		
	for(size_t i = 0 ; i < lengthArray(colliderArray); i++){

		if((temporaryId = (Id*)getArray(colliderArray, i)) == NULL){
			continue;
		}

    if((temporaryIndex = temporaryId->id) == temporaryPositionA.id){
			continue;
		}

		if(getOccurrenceById(positionArray, temporaryIndex, &occurrencesPosition) == false){
			continue;
		}
		if(getOccurrenceById(sizeArray, temporaryIndex, &occurrencesSize) == false){
			continue;
		}
		
		temporaryPositionB = (*((Position*)occurrencesPosition.component));
		temporarySizeB = (*((Size*)occurrencesSize.component));

		initializeCollisionVariables(temporaryPositionB, temporarySizeB, &xB, &yB, &wB, &hB);

		if(isItColliding(xA, yA, wA, hA, xB, yB, wB, hB) == false){
			continue;
		}

		// // // // printf("%d >> %s - x: %f - y: %f\n", rand() % (999 - 100 + 1) + 100, comp->information->name, xB, yB);
		return true;
	}

		printf("oi\n");

	return false;
}
