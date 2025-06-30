#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../constants.h"

#include "entities.h"
#include "../../../dependencies/my/dynamicvectors/vector.h"
#include "../../../dependencies/my/dynamicvectors/entities/entity.h"

static int id = 0;

int getId();
int setId(int idnew);
void initializeEntities();
bool addEntity(VectorEntity* vectorEntity, size_t row, int *id);
void destroyEntities();
// bool existEntities(size_t scene, size_t index);
// void printEntity(size_t scene, size_t index);
// void printEntities(size_t scene);

int getId(){
	return id;
}

int setId(int idnew){
	id = idnew;
	return id;
}

void initializeEntities(){
	initializeVectorEntity(&vectorEntity, MAX_ENTITIES);
}

bool addEntity(VectorEntity* vectorEntity, size_t row, int *id){

	if(fullCollumnEntity(vectorEntity)){
		printf("Entity is full\n");
		return false;
	}

	// *id = idcount;
	// idcount++;

	Entity auxEntity = (Entity){
		.index = id
	};

	/////////////////////////
	/// CREATE TYPE FILES ///
	/////////////////////////

	printf("\n\n%d\n\n", lengthCollumnEntity(&vectorEntity));

	addCellEntity(&vectorEntity, lengthCollumnEntity(&vectorEntity), auxEntity);
	return true;
}

void destroyEntities(){
	destroyVectorEntity(&vectorEntity);
}

// bool existEntities(size_t scene, size_t index){
// 	// printf("\nid in existEntities: %d\n", id);
// 	if(!(index >= 0 && scene >= 0 && scene < entities.row && index < entities.collum[index])){
// 		// // // // printf("\nPosição invalida: [%d][%d]\n", scene, index);
// 		return false;
// 	}else{
// 		return true;
// 	}
// 	// getCell(&entities, scene, index);
// 	// return true;
// }

// void printEntity(size_t scene, size_t index){
// 	// // // // printf("\n");
// 	// // // // printf("id: 	%d\n", *(int*)(getCell(&entities, scene, index)->data));
// 	// // // // printf("\n");
// }

// void printEntities(size_t scene){
// 	// // // // printf("\n/// ENTITIES ///\n\n");
// 	for (size_t i = 0; i < lengthRow(&entities, scene); i++){
// 		// if(existEntities(scene, i)){
// 			// // // // printf("id: %d\n", *(int*)(getCell(&entities, scene, i)->data));
// 		// }
// 	}
// 	// // // // printf("\n////////////////\n");
// }

// int printAllComponentByEntity(int id){
// 	if(!existEntities(id)){
// 		return ERROR;
// 	}
// 	// printf("\n");
// 	// printf("id:				%d\n", entities[id]);
// 	// printf("Information: 	%d\n", entities[id]);
// 	// printf("Position: 		%d\n", entities[id]);
// 	// printf("Size:			%d\n", entities[id]);
// 	// printf("Color:			%d\n", entities[id]);
// 	// printf("Collision:		%d\n", entities[id]);
// 	// printf("\n");
// 	return SUCESS;
// }