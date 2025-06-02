#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "entities.h"
#include "../../constants.h"

#include "../../../dependencies/my/matrix/matrix.h"
#include "../../../dependencies/my/matrix/initialize.h"
#include "../../../dependencies/my/matrix/full.h"
#include "../../../dependencies/my/matrix/add.h"
#include "../../../dependencies/my/matrix/length.h"
#include "../../../dependencies/my/matrix/get.h"
#include "../../../dependencies/my/matrix/destroy.h"

Matrix entities;

int idcount = 0;

Data entityDefualt = (Data){.data = &(int){-1}};

void initializeEntities();
bool addEntity(size_t row, int *id);
// bool existEntities(size_t scene, size_t index);
void printEntity(size_t scene, size_t index);
void printEntities(size_t scene);
void destroyEntities();

void initializeEntities(){
	initializeMatrix(&entities, SUBENTITIES, MAX_ENTITIES);
	// entityDefualt.data = &(int){-1};
	// for (size_t i = 0; i < MAX_ENTITIES; i++){
	// 	entities[i] = -1;
	// }
}

bool addEntity(size_t row, int *id){

	if(fullRow(&entities, row)){
		// // // // printf("cdsds\n");
		return false;
	}

	*id = idcount;
	idcount++;

	/////////////////////////
	/// CREATE TYPE FILES ///
	/////////////////////////

	Data auxData;
	auxData.data = malloc(sizeof(int) * 1);
	*(int*)(auxData.data) = *id;
	
	// addRow(&entities, lengthMatrix(&entities), NULL, 0); // type is missing
	addCell(&entities, row, (lengthMatrix(&entities) - 1), auxData);
	return true;
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

void printEntity(size_t scene, size_t index){
	// // // // printf("\n");
	// // // // printf("id: 	%d\n", *(int*)(getCell(&entities, scene, index)->data));
	// // // // printf("\n");
}

void printEntities(size_t scene){
	// // // // printf("\n/// ENTITIES ///\n\n");
	for (size_t i = 0; i < lengthRow(&entities, scene); i++){
		// if(existEntities(scene, i)){
			// // // // printf("id: %d\n", *(int*)(getCell(&entities, scene, i)->data));
		// }
	}
	// // // // printf("\n////////////////\n");
}

void destroyEntities(){
	destroyMatrix(&entities);
}

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