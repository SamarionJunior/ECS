#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "setup.h"

#include "setupUtility.h"

#include "../architecture/components/components.h"
// #include "../architecture/components/initialize.h"

#include "../architecture/entities/entities.h"
#include "../architecture/entities/utility.h"

#include "../architecture/systems/systems.h"

#include "../constants.h"

#include "../../dependencies/mycustom/myjson.h"

#include "../loader/json.h"
#include "../loader/map.h"

#include "../utilities/space.h"

#include "../architecture/systems/setupCollision.h"

void setup(void){
	
	setIsEmpty(true);

	score = 0;

	setId(-1);

	// int id = 0;
	
	initializeComponents();
	initializeEntities();

	// printf("Address: %p\n", arrayOfArrayComponents);
	// printf("Address: %p\n", informationArray);
	// printf("Address: %p\n", positionArray);

	arrayOfArrayComponents[INFORMATION] = informationArray;
	arrayOfArrayComponents[POSITION] = positionArray;
	arrayOfArrayComponents[SIZE] = sizeArray;
	arrayOfArrayComponents[COLOR] = colorArray;
	arrayOfArrayComponents[COLLIDER] = colliderArray;
	arrayOfArrayComponents[LAYER] = layerArray;
	arrayOfArrayComponents[PLAYER] = playerArray;
	arrayOfArrayComponents[COLLECTIBLE] = collectibleArray;
	arrayOfArrayComponents[ANCHOR] = anchorArray;

	// printf("Address: %p\n", arrayOfArrayComponents[POSITION]);

	// printf("%d oi\n", lengthArray(temporaryEntities));
	
	for (size_t i = 0; i < getROW(); i++){
		for (size_t j = 0; j < getCOL(); j++){
			for (size_t k = 0; k < lengthArray(temporaryEntities); k++){

				TemporaryEntity te = *((TemporaryEntity*)(getArray(temporaryEntities, k)));

				if((*((int*)(getArray(getArray(map, i), j)))) != te.entityType){
					continue;
				}

				float x, y;
				for (size_t l = 0; l < lengthArray(te.componentAndTypes); l++){
					ComponentAndType cap = *((ComponentAndType*)(getArray(te.componentAndTypes, l)));
					if(cap.type == POSITION){
						x = (*(Position*)(cap.component)).current2.x;
						y = (*(Position*)(cap.component)).current2.y;
						((Position*)(cap.component))->current2.x = j * SPRITE;
						((Position*)(cap.component))->current2.y = i * SPRITE;
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
			}
		}
	}

	initializingFreeSpaces();

	// // // // printf("\n///////////////////\n");
	// // // // printf(  "/// END - SETUP ///\n");
	// // // // printf(  "///////////////////\n\n");

}