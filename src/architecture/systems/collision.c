#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "systems.h"
#include "collision.h"
#include "../entities/entities.h"
#include "../components/components.h"
#include "../../constants.h"
#include "../../engine/update.h"

#include "../../../dependencies/my/dynamicvectors/vector.h"

#include "../../../dependencies/my/dynamicvectors/entities/entity.h"

#include "../../../dependencies/my/dynamicvectors/components/position.h"
#include "../../../dependencies/my/dynamicvectors/components/size.h"
#include "../../../dependencies/my/dynamicvectors/components/collider.h"

int isItColliding(float xA, float yA, float wA, float hA, float xB, float yB, float wB, float hB);
int isTheSameIndex(Position entityA, Position entityB);
void initializeCollisionVariables(Position entity, Size size, float* x, float* y, float* w, float* h);
bool *collisionBetween(Position *positionA, Size *sizeA);

int isItColliding(
	float xA, float yA, float wA, float hA,
	float xB, float yB, float wB, float hB
){
	if(
		// xA + wA >= xB &&
		// xA <= xB + wB &&
		// yA + hA >= yB &&
		// yA <= yB + hB
		xA + (wA - 1) >= xB &&
		xA <= xB + (wB - 1) &&
		yA + (hA - 1) >= yB &&
		yA <= yB + (hB - 1)
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

bool *collisionBetween(Position *positionA, Size *sizeA){

	// int count = 0;

	Position positionB;
	Size sizeB;

	float xA = 0, yA = 0, wA = 0, hA = 0;
	float xB = 0, yB = 0, wB = 0, hB = 0;

	initializeCollisionVariables(*positionA, *sizeA, &xA, &yA, &wA, &hA);
		
	for(int i = 0 ; i < lengthCollumnEntity(&vectorEntity); i++){

		Entity* id = getCellEntity(&vectorEntity, i);

		if(id == NULL){
			continue;
		}

		int index = id->index;

        if(index == positionA->id){
			continue;
        }

		int count = 0;

		Position* auxPosition = NULL;
		Size* auxSize = NULL;
		Collider* auxCollider = NULL;

		for (size_t j = 0; j < lengthCollumnPosition(&vectorPosition); j++){
			Position* tempPosition = getCellPosition(&vectorPosition, j);
			if(tempPosition != NULL){
				if(tempPosition->id == index){
					auxPosition = tempPosition;
					count++;
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
					break;
				}
			}
		}
		for (size_t j = 0; j < lengthCollumnCollider(&vectorCollider); j++){
			Collider* tempCollider = getCellCollider(&vectorCollider, j);
			if(tempCollider != NULL){
				if(tempCollider->id == index){
					auxCollider = tempCollider;
					count++;
					break;
				}
			}
		}

		if(count != 3){
			continue;
		}
		
		Position positionB = *auxPosition;
		Size sizeB = *auxSize;
		
		// if(isTheSameIndex(*positionA, *positionB)){
		// 	continue;
		// }

		initializeCollisionVariables(positionB, sizeB, &xB, &yB, &wB, &hB);

		if(isItColliding(xA, yA, wA, hA, xB, yB, wB, hB)){

			// // // // printf("%d >> %s - x: %f - y: %f\n", rand() % (999 - 100 + 1) + 100, comp->information->name, xB, yB);

			return true;
		}
	}

	return false;

}

void setIsItColliding(int entity, int count, int future){
	// if(count > 0){
	// 	components[0].collision[entity].isItColliding = true;
	// }else if (count == 0 && future == 0){
	// 	components[0].collision[entity].isItColliding = false;
	// 	components[0].collision[entity].direction[TOP] = false;
	// 	components[0].collision[entity].direction[BOTTOM] = false;
	// 	components[0].collision[entity].direction[RIGHT] = false;
	// 	components[0].collision[entity].direction[LEFT] = false;
	// }else if (count == 0 && future > 0){
	// 	components[0].collision[entity].isItColliding = false;
	// }
}

int isItCollidingBottom(
	float yA, float hA,
	float yB, float hB,
	float size
){
	if(
		(yA + hA) + size >= yB &&
		(yA + hA) <= yB + hB
	){
		return true;
	}
	return false;
}

int isItCollidingTop(
	float yA,
	float yB, float hB,
	float size
){
	if(
		yA - size >= yB &&
		yA <= yB + hB
	){
		return true;
	}
	return false;
}

int isItCollidingRight(
	float xA, float wA,
	float xB, float wB,
	float size
){
	if(
		(xA + wA) + size >= xB &&
		xA + wA <= xB + wB
	){
		return true;
	}
	return false;
}

int isItCollidingLeft(
	float xA,
	float xB, float wB,
	float size
){
	if(
		xA - size <= xB + wB &&
		xA >= xB
	){
		return true;
	}
	return false;
}