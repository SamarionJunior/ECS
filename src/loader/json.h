#ifndef JSON_H_
#define JSON_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../architecture/components/components.h"

#include "../architecture/entities/entities.h"
#include "../architecture/systems/systems.h"

#include "../constants.h"

#include "../../dependencies/mycustom/myjson.h"

typedef struct TemporaryComponent{
	int index;
	Information information;
	Position position;
	Direction direction;
	Velocity velocity;
	Acceleration acceleration;
	Size size;
	Color color;
	Collider collider;
	Layer layer;
	Player player;
	Collectible collectible;
	int arrayComponentTypes[QTD_TYPE_COMPONENTS];
	int lengtharrayComponentTypes;
	int arraySystems[MAX_SYSTEMS];
	int lengthArraySystems;
} TemporaryComponent;

extern int lengthtemporaryComponents;

extern TemporaryComponent temporaryComponents[10];

void printJSONScene();

void loadJSON();

#endif