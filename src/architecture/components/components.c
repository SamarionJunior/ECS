#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "components.h"

#include "../../constants.h"

Color black = {0, 0, 0, 255};

Array informationArray;
Array positionArray;
// Array directionArray;
// Array velocityArray;
// Array accelerationArray;
Array sizeArray;
Array colorArray;
Array colliderArray;
Array layer0Array;
Array layer1Array;
Array layer2Array;

Array playerArray;
Array collectibleArray;
Array anchorArray;

Array* arrayOfArrayComponents[TOTALCOMPONENTS];

char *namesOfCompenents[TOTALCOMPONENTS] = {
	"Information",
	"Position",
	// "Direction",
	// "Velocity",
	// "Acceleration",
	"Size",
	"Color",
	"Collider",
	"Layer",
	"Player",
	"Anchor",
	"Collectible"
};

void destroyComponents(){

	///// RESOLVER PROBLEMA DE COPIA DE REFERENCIA DO PONTEIRO "NAME" AO INCIALIZAR COMPONENTE INFORMATION ////
	// for (size_t i = 0; i < lengthArray(informationArray); i++){
	// 	Information* temporaryInformation = getArray(informationArray, i);
	// 	free(temporaryInformation->name);
	// } <- RESOLVER PROBLEMA DE COPIA DE REFERENCIA DO PONTEIRO "NAME" AO INCIALIZAR COMPONENTE INFORMATION
	destroyArray(&informationArray);

	destroyArray(&positionArray);
	// destroyArray(directionArray);
	// destroyArray(velocityArray);
	// destroyArray(accelerationArray);
	destroyArray(&sizeArray);
	destroyArray(&colorArray);
	destroyArray(&colliderArray);
	destroyArray(&layer0Array);
	destroyArray(&layer1Array);
	destroyArray(&layer2Array);

	destroyArray(&playerArray);
	destroyArray(&collectibleArray);
	destroyArray(&anchorArray);
}