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
Array layerArray;

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

	destroyArray(&informationArray);
	destroyArray(&positionArray);
	// destroyArray(directionArray);
	// destroyArray(velocityArray);
	// destroyArray(accelerationArray);
	destroyArray(&sizeArray);
	destroyArray(&colorArray);
	destroyArray(&colliderArray);
	destroyArray(&layerArray);

	destroyArray(&playerArray);
	destroyArray(&collectibleArray);
	destroyArray(&anchorArray);
}