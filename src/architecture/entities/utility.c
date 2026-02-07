#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../constants.h"

#include "../../../dependencies/my/dynamicarray/array.h"

#include "entities.h"
#include "../components/components.h"
#include "../components/get.h"

// // #include "../../../dependencies/my/dynamicvectors/vector.h"
// // #include "../../../dependencies/my/dynamicvectors/entities/entity.h"

static int id = 0;

int getId();
int setId(int idnew);
void initializeEntities();
void destroyEntities();
bool removeEntity(int id);

int getId(){
	return id;
}

int setId(int idnew){
	id = idnew;
	return id;
}

void initializeEntities(){
	initializeArray(&entityArray, MAX_ENTITIES, sizeof(Entity));
	// initializeVectorEntity(&vectorEntity, MAX_ENTITIES);
}

void destroyEntities(){
	destroyArray(entityArray);
}

static Occurrence temporaryComponent;

static Array* temporaryArray;

bool removeEntity(int id){

	printf("id: %d\n", id);

	Array* temporaryArrays[] = {
		informationArray,
		positionArray,
		sizeArray,
		colorArray,
		colliderArray,
		layerArray,
		playerArray,
		collectibleArray,
		anchorArray,
		entityArray
	};

	int lenghtTemporaryArrays = 10;

	for(size_t i = 0; i < lenghtTemporaryArrays ;i++){

		temporaryArray = temporaryArrays[i];

		if(getOccurrenceById(temporaryArray, id, &temporaryComponent) == false){
			continue;
		}

		if(((Id*)temporaryComponent.component)->id != id){
			printf("%d %d", ((Id*)temporaryComponent.component)->id, id);
			continue;
		}

		removeArray(
			temporaryArray,
			temporaryComponent.index
		);

	}

	// temporaryArray = informationArray;
	// if(getOccurrenceById(temporaryArray, id, &temporaryComponent)){
	// 	removeArray(
	// 		temporaryArray,
	// 		temporaryComponent.index
	// 	);
	// }

	// temporaryArray = positionArray;
	// if(getOccurrenceById(temporaryArray, id, &temporaryComponent)){
	// 	removeArray(
	// 		temporaryArray,
	// 		temporaryComponent.index
	// 	);
	// }

	// temporaryArray = sizeArray;
	// if(getOccurrenceById(temporaryArray, id, &temporaryComponent)){
	// 	removeArray(
	// 		temporaryArray,
	// 		temporaryComponent.index
	// 	);
	// }

	// temporaryArray = colorArray;
	// if(getOccurrenceById(temporaryArray, id, &temporaryComponent)){
	// 	removeArray(
	// 		temporaryArray,
	// 		temporaryComponent.index
	// 	);
	// }

	// temporaryArray = colliderArray;
	// if(getOccurrenceById(temporaryArray, id, &temporaryComponent)){
	// 	removeArray(
	// 		temporaryArray,
	// 		temporaryComponent.index
	// 	);
	// }

	// temporaryArray = layerArray;
	// if(getOccurrenceById(temporaryArray, id, &temporaryComponent)){
	// 	removeArray(
	// 		temporaryArray,
	// 		temporaryComponent.index
	// 	);
	// }

	// temporaryArray = collectibleArray;
	// if(getOccurrenceById(temporaryArray, id, &temporaryComponent)){
	// 	removeArray(
	// 		temporaryArray,
	// 		temporaryComponent.index
	// 	);
	// }

	// temporaryArray = anchorArray;
	// if(getOccurrenceById(temporaryArray, id, &temporaryComponent)){
	// 	removeArray(
	// 		temporaryArray,
	// 		temporaryComponent.index
	// 	);
	// }

	// temporaryArray = entityArray;
	// if(getOccurrenceById(temporaryArray, id, &temporaryComponent)){
	// 	removeArray(
	// 		temporaryArray,
	// 		temporaryComponent.index
	// 	);
	// }

	return true;
}