#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "systems.h"
#include "../entities/entities.h"
#include "../components/components.h"
#include "../../constants.h"
#include "../../engine/update.h"

#include "../../../dependencies/my/matrix/matrix.h"
#include "../../../dependencies/my/matrix/initialize.h"
#include "../../../dependencies/my/matrix/full.h"
#include "../../../dependencies/my/matrix/add.h"
#include "../../../dependencies/my/matrix/length.h"
#include "../../../dependencies/my/matrix/get.h"
#include "../../../dependencies/my/matrix/destroy.h"

char *namesOfSystems[MAX_SYSTEMS] = {
	"Gravity",
	"Collision",
	"Layer",
	"Move"
};

Matrix componentsForGravity;
Matrix componentsForCollision;
Matrix componentsForLayer;
Matrix componentsForMove;
Matrix componentsForScore;

void initializeSystems();
bool addSystem(Matrix *componentsForSystem, size_t row, size_t collum, Data data);
void *getCompontFromSystem(Matrix *componentsForSystem, size_t scene, size_t index);
void destroySystem();

void initializeSystems(){
	initializeMatrix(&componentsForGravity, SUBSYSTEMS, MAX_COMPONENTS);
	// addRow(&componentsForGravity, 0, NULL, 0);
	initializeMatrix(&componentsForCollision, SUBSYSTEMS, MAX_COMPONENTS);
	// addRow(&componentsForCollision, 0, NULL, 0);
	initializeMatrix(&componentsForLayer, SUBSYSTEMS, MAX_COMPONENTS);
	// addRow(&componentsForLayer, 0, NULL, 0);
	initializeMatrix(&componentsForMove, SUBSYSTEMS, MAX_COMPONENTS);
	initializeMatrix(&componentsForScore, SUBSYSTEMS, MAX_COMPONENTS);
	// addRow(&componentsForMove, 0, NULL, 0);
	// for (size_t i = 0; i < SUBSYSTEMS; i++){
	// 	for (size_t j = 0; j < MAX_ENTITIES; j++){
	// 		systems[i].collision[j] = -1;
	// 		systems[i].gravity[j] = -1;
	// 		systems[i].layer[j] = -1;
	// 		systems[i].move[j] = -1;
	// 	}
	// 	for (size_t j = 0; j < MAX_SYSTEMS; j++){
	// 		systems[i].length[j] = 0;
	// 	}
	// }
}

bool addSystem(Matrix *componentsForSystem, size_t row, size_t collum, Data data){

	if(fullRow(componentsForSystem, row)){
		return false;
	}

	/////////////////////////
	/// CREATE TYPE FILES ///
	/////////////////////////

	// Data auxData;
	// auxData.data = malloc(sizeof(int) * 1);
	// *(int*)(auxData.data) = *id;

	// printf("Matrix - Address: %p\n", componentsForSystem);
	// printf("maximumRow - value: %d\n", componentsForSystem->maximumRow);
	// printf("maximumCollum - value: %d\n", componentsForSystem->maximumCollum);
	// printf("row - value: %d\n", 0);
	// printf("collum - value: %d\n", lengthMatrix(&componentsForSystem) - 1);
	// printf("matrix->row - value: %d\n", componentsForSystem->row);
	// printf("matrix->collum[row] - value: %d\n", componentsForSystem->collum[0]);

	addCell(componentsForSystem, row, collum, data);
	return true;
	// printf("\nGRAVITY - id: %d - length: %d\n", systems[0].gravity[systems[0].length[GRAVITY] - 1], systems[0].length[GRAVITY]);
}

void *getCompontFromSystem(Matrix *componentsForSystem, size_t scene, size_t index){
	return ((getCell(&componentsForSystem, scene, index)->data));
}

void destroySystem(){
	destroyMatrix(&componentsForGravity);
	destroyMatrix(&componentsForCollision);
	destroyMatrix(&componentsForLayer);
	destroyMatrix(&componentsForMove);
	destroyMatrix(&componentsForScore);
}