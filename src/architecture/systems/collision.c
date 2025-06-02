#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "systems.h"
#include "collision.h"
#include "../entities/entities.h"
#include "../components/components.h"
#include "../../constants.h"
#include "../../engine/update.h"

#include "../../../dependencies/my/matrix/matrix.h"
#include "../../../dependencies/my/matrix/length.h"
#include "../../../dependencies/my/matrix/get.h"

int isItColliding(float xA, float yA, float wA, float hA, float xB, float yB, float wB, float hB);
int isTheSameIndex(Position entityA, Position entityB);
void initializeCollisionVariables(Position entity, Size size, float* x, float* y, float* w, float* h);
ComponentsForCollision *collisionBetween(Position *positionA, Size *sizeA);

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

ComponentsForCollision *collisionBetween(Position *positionA, Size *sizeA){

	// int count = 0;

	Position *positionB = NULL;
	Size *sizeB = NULL;

	float xA = 0, yA = 0, wA = 0, hA = 0;
	float xB = 0, yB = 0, wB = 0, hB = 0;

	initializeCollisionVariables(*positionA, *sizeA, &xA, &yA, &wA, &hA);
		
	for (size_t j = 0; j < lengthRow(&componentsForCollision, 0); j++){

		ComponentsForCollision *comp = (ComponentsForCollision*)(getCell(&componentsForCollision, 0, j)->data);
		
		positionB = comp->position;
		sizeB = comp->size;
		
		if(isTheSameIndex(*positionA, *positionB)){
			continue;
		}

		initializeCollisionVariables(*positionB, *sizeB, &xB, &yB, &wB, &hB);

		if(isItColliding( xA, yA, wA, hA, xB, yB, wB, hB)){

			// // // // printf("%d >> %s - x: %f - y: %f\n", rand() % (999 - 100 + 1) + 100, comp->information->name, xB, yB);

			return comp;
		}
	}

	return NULL;

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

// if(isItCollidingBottom(yA, hA, yB, hB, colliderSizeVirtual)){

				// 	// // // // printf("\nCollision Bottom: %d", rand()%100);

				// 	((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[BOTTOM] = true;

				// 	((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = yB - hA - 20;
				// 	// ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = 0;
				// 	// ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldX;
				// 	// // // // printf("\n%f\n", yA);
				// 	initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
				// 	// // // // printf("\n%f\n", yA);

				// 	isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);
				// 	continue;

				// }

				// if(isItCollidingTop(yA, yB, hB, colliderSizeVirtual)){

				// 	// // // // printf("\nCollision Top: %d", rand()%100);
				// 	((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[TOP] = true;

				// 	((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = yB + hB + 20;
				// 	// ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldX;

				// 	initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
				// 	isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);
				// 	continue;
				
				// }

				// if(isItCollidingRight(xA, wA, xB, wB, colliderSizeVirtual)){

				// 	// // // // printf("\nCollision Rigth: %d", rand()%100);
				// 	((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[RIGHT] = true;
	
				// 	((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = xB - wA - 20;
				// 		// ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldY;
					
				// 	initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
				// 	isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);
				// 	continue;
				
				// }

				// if(isItCollidingLeft(xA, xB, wB, colliderSizeVirtual)){

				// 	// // // // printf("\nCollision Left: %d", rand()%100);
				// 	((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[LEFT] = true;

				// 	((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = xB + wB + 20;
				// 	// ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldY;

				// 	initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
				// 	isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);
				// 	continue;
				
				// }


// if(isItCollidingRight(xA, wA, xB, xB, colliderSizeVirtual)){

// 	// printf("\nCollision Rigth");

// 	((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[RIGHT] = true;
	
// 	// if(((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->isStatic == false){
		
// 	// 	((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = xB - wA;
// 	// 	// ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldY;
	
// 	// }

// 	// initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);

// 	// continue;

// }

// void collision(){

	// int entityA, entityB;

	// float xA = 0, yA = 0, wA = 0, hA = 0;
	// float xB = 0, yB = 0, wB = 0, hB = 0;

	// int count = 0;
	
	// int future = 0;

	// float colliderSizeVirtual = 0;

	// float colliderSizeVirtualFuture = 1.0f;

	// for (size_t i = 0, count = 0; i < getLengthSystem(COLLIDER); i++){

	// 	entityA = *((int *)getIdInSystem(COLLIDER, i));

	// 	// for (size_t i = 0; i < getLengthSystem(COLLIDER); i++){
	// 	// 	// // // // printf("\n%d\n", *((int *)getIdInSystem(COLLIDER, i)));
	// 	// }

	// 	// printf("\n%d\n", i);
	// 	// printf("\n%d\n", entityA);
		
	// 	initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
			
	// 	for (size_t j = 0; j < getLengthSystem(COLLIDER); j++){
			
	// 		if(
	// 			// !existEntities(systems[0].collision[j]) && 
	// 			isTheSameIndex(j, i)
	// 		){
	// 			continue;
	// 		}
			
	// 		entityB = *(int *)getIdInSystem(COLLIDER, j);

	// 		initializeCollisionVariables(entityB, &xB, &yB, &wB, &hB);

	// 		int isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);

	// 		if(isItCollidingAux && ((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->isStatic == true){

	// 			count++;

	// 			if(isItCollidingBottom(yA, hA, yB, hB, colliderSizeVirtual)){
	// 				// printf("\nCollision Bottom");
	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[BOTTOM] = true;
	// 			}

	// 			if(isItCollidingTop(yA, yB, hB, colliderSizeVirtual)){
	// 				// printf("\nCollision Top");
	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[TOP] = true;
	// 			}

	// 			if(isItCollidingRight(xA, wA, xB, xB, colliderSizeVirtual)){
	// 				// printf("\nCollision Rigth");
	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[RIGHT] = true;
	// 			}

	// 			if(isItCollidingLeft(xA, xB, xB, colliderSizeVirtual)){
	// 				// printf("\nCollision Left");
	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[LEFT] = true;
	// 			}
	// 		}

	// 		float spaceAux = 0.1;

	// 		while(isItCollidingAux && ((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->isStatic == false){
				
	// 			count++;

	// 			if(
	// 				isItCollidingBottom(yA, hA, yB, hB, colliderSizeVirtual) && 
	// 				isItCollidingRight(xA, wA, xB, wB, colliderSizeVirtual) &&
	// 				isItCollidingLeft(xA, xB, wB, colliderSizeVirtual)
	// 			){

	// 				// // // // printf("\nCollision Bottom: %d", rand()%100);

	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[BOTTOM] = true;

	// 				((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = yB - hA - spaceAux;
	// 				// ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = 0;
	// 				((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldX;
	// 				// printf("\n%f\n", yA);
	// 				initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
	// 				// printf("\n%f\n", yA);

	// 				isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);
	// 				continue;

	// 			}

	// 			if(
	// 				isItCollidingTop(yA, yB, hB, colliderSizeVirtual) && 
	// 				isItCollidingRight(xA, wA, xB, wB, colliderSizeVirtual) &&
	// 				isItCollidingLeft(xA, xB, wB, colliderSizeVirtual)
	// 			){

	// 				// // // // printf("\nCollision Top: %d", rand()%100);
	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[TOP] = true;

	// 				((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = yB + hB + spaceAux;
	// 				((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldX;

	// 				initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
	// 				isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);
	// 				continue;
				
	// 			}

	// 			if(
	// 				isItCollidingRight(xA, wA, xB, wB, colliderSizeVirtual) && 
	// 				isItCollidingTop(yA, yB, hB, colliderSizeVirtual) && 
	// 				isItCollidingBottom(yA, hA, yB, hB, colliderSizeVirtual) 
	// 			){

	// 				// // // // printf("\nCollision Rigth: %d", rand()%100);
	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[RIGHT] = true;
	
	// 				((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = xB - wA - spaceAux;
	// 					((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldY;
					
	// 				initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
	// 				isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);
	// 				continue;
				
	// 			}

	// 			if(
	// 				isItCollidingLeft(xA, xB, wB, colliderSizeVirtual) && 
	// 				isItCollidingTop(yA, yB, hB, colliderSizeVirtual) && 
	// 				isItCollidingBottom(yA, hA, yB, hB, colliderSizeVirtual) 
	// 			){

	// 				// // // // printf("\nCollision Left: %d", rand()%100);
	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[LEFT] = true;

	// 				((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = xB + wB + spaceAux;
	// 				((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldY;

	// 				initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
	// 				isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);
	// 				continue;
				
	// 			}
				
	// 			if(
	// 				isItCollidingBottom(yA, hA, yB, hB, colliderSizeVirtual) && 
	// 				isItCollidingRight(xA, wA, xB, wB, colliderSizeVirtual)
	// 			){

	// 				// // // // printf("\nCollision Bottom Right: %d", rand()%100);

	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[BOTTOM] = true;
	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[RIGHT] = true;

	// 				((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldY;
	// 				((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldX;
					
	// 				initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
					

	// 				isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);
	// 				continue;

	// 			}
				
	// 			if(
	// 				isItCollidingBottom(yA, hA, yB, hB, colliderSizeVirtual) &&
	// 				isItCollidingLeft(xA, xB, wB, colliderSizeVirtual)
	// 			){

	// 				// // // // printf("\nCollision Bottom Left: %d", rand()%100);

	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[BOTTOM] = true;
	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[LEFT] = true;

	// 				((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldY;
	// 				((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldX;
					
	// 				initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
					

	// 				isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);
	// 				continue;

	// 			}
				
	// 			if(
	// 				isItCollidingTop(yA, yB, hB, colliderSizeVirtual) && 
	// 				isItCollidingLeft(xA, xB, wB, colliderSizeVirtual)
	// 			){

	// 				// // // // printf("\nCollision Top Left: %d", rand()%100);

	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[TOP] = true;
	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[LEFT] = true;

	// 				((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldY;
	// 				((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldX;
					
	// 				initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
					

	// 				isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);
	// 				continue;

	// 			}
				
	// 			if(
	// 				isItCollidingTop(yA, yB, hB, colliderSizeVirtual) &&
	// 				isItCollidingRight(xA, wA, xB, wB, colliderSizeVirtual)
	// 			){

	// 				// // // // printf("\nCollision Top Right: %d", rand()%100);

	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[TOP] = true;
	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[RIGHT] = true;

	// 				((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldY;
	// 				((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldX;
					
	// 				initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
					

	// 				isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);
	// 				continue;

	// 			}

	// 			// isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB)

	// 			break;
	// 		}



	// 		while(
	// 			(isItColliding( xA + 1.0f, yA, wA, hA, xB, yB, wB, hB) ||
	// 			isItColliding( xA - 1.0f, yA, wA, hA, xB, yB, wB, hB) ||
	// 			isItColliding( xA, yA + 1.0f, wA, hA, xB, yB, wB, hB) ||
	// 			isItColliding( xA, yA - 1.0f, wA, hA, xB, yB, wB, hB)) &&
	// 			((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->isStatic == false
	// 		){
				
	// 			future++;
				
	// 			if(
	// 				isItColliding( xA, yA+ 1.0f, wA, hA, xB, yB, wB, hB)
	// 			){

	// 				// // // // printf("\nCollision Future Bottom: %d", rand()%100);
	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[BOTTOM] = true;

	// 			}
				
	// 			if(
	// 				isItColliding( xA, yA - 1.0f, wA, hA, xB, yB, wB, hB)
	// 			){

	// 				// // // // printf("\nCollision Future Top: %d", rand()%100);
	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[TOP] = true;

	// 			}
				
	// 			if(
	// 				isItColliding( xA + 1.0f, yA, wA, hA, xB, yB, wB, hB)
	// 			){

	// 				// // // // printf("\nCollision Future Right: %d", rand()%100);
	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[RIGHT] = true;

	// 			}
				
	// 			if(
	// 				isItColliding( xA - 1.0f, yA, wA, hA, xB, yB, wB, hB)
	// 			){

	// 				// // // // printf("\nCollision Future Left: %d", rand()%100);
	// 				((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[LEFT] = true;

	// 			}

	// 			break;
	// 		}
	// 	}

	// 	setIsItColliding(entityA, count, future);
		
	// }
// }

// if(isItCollidingBottom(yA, hA, yB, hB, colliderSizeVirtual)){

				// 	// // // // printf("\nCollision Bottom: %d", rand()%100);

				// 	((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[BOTTOM] = true;

				// 	((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = yB - hA - 20;
				// 	// ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = 0;
				// 	// ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldX;
				// 	// // // // printf("\n%f\n", yA);
				// 	initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
				// 	// // // // printf("\n%f\n", yA);

				// 	isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);
				// 	continue;

				// }

				// if(isItCollidingTop(yA, yB, hB, colliderSizeVirtual)){

				// 	// // // // printf("\nCollision Top: %d", rand()%100);
				// 	((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[TOP] = true;

				// 	((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = yB + hB + 20;
				// 	// ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldX;

				// 	initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
				// 	isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);
				// 	continue;
				
				// }

				// if(isItCollidingRight(xA, wA, xB, wB, colliderSizeVirtual)){

				// 	// // // // printf("\nCollision Rigth: %d", rand()%100);
				// 	((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[RIGHT] = true;
	
				// 	((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = xB - wA - 20;
				// 		// ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldY;
					
				// 	initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
				// 	isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);
				// 	continue;
				
				// }

				// if(isItCollidingLeft(xA, xB, wB, colliderSizeVirtual)){

				// 	// // // // printf("\nCollision Left: %d", rand()%100);
				// 	((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[LEFT] = true;

				// 	((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = xB + wB + 20;
				// 	// ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldY;

				// 	initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);
				// 	isItCollidingAux = isItColliding( xA, yA, wA, hA, xB, yB, wB, hB);
				// 	continue;
				
				// }


// if(isItCollidingRight(xA, wA, xB, xB, colliderSizeVirtual)){

// 	// printf("\nCollision Rigth");

// 	((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->direction[RIGHT] = true;
	
// 	// if(((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entityA))->isStatic == false){
		
// 	// 	((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->x = xB - wA;
// 	// 	// ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->y = ((Position *)readComponentByIdAndReturnReferenc(POSITION, entityA))->oldY;
	
// 	// }

// 	// initializeCollisionVariables(entityA, &xA, &yA, &wA, &hA);

// 	// continue;

// }