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
void addEntity();
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

void addEntity(){
	setId(getId() + 1);
	addArray(
		entityArray,
		lengthArray(entityArray),
		&(Entity){
			.index = getId()
		}
	);
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

	for(size_t i = 0; i < TOTALCOMPONENTS ;i++){

		temporaryArray = arrayOfArrayComponents[i];

		if(getOccurrenceById(temporaryArray, id, &temporaryComponent) == false){
			continue;
		}

		if(((Id*)temporaryComponent.component)->id != id){
			continue;
		}

		removeArray(
			temporaryArray,
			temporaryComponent.index
		);

	}

	return true;
}