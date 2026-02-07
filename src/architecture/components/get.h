#ifndef GET_COMPONENT_H_
#define GET_COMPONENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "components.h"

typedef struct occurrence{
	void* component;
	int index;
} Occurrence;

typedef struct occurrences{
	int size; // 1 ... N
	Occurrence* array;
} Occurrences;

// Occurrence getComponentsById(Array *array, int id);

bool getOccurrenceById(Array *array, int id, Occurrence* temporaryOccurrence);

void freeComponent(Occurrences* Occurrences);

void freeComponents(int size, ...);

// Information* getInformationById(int id, int* count);
// Position* getPositionById(int id, int* count);
// Size* getSizeById(int id, int* count);
// Color* getColorById(int id, int* count);
// Collider* getColliderById(int id, int* count);
// Layer* getLayerById(int id, int* count);

// Player* getPlayerById(int id, int* count);

// Collectible* getCollectibleById(int id, int* count);

// Anchor* getAnchorById(int id, int* count);

// "¨"* get"¨"ById(int id, int* count);

#endif

