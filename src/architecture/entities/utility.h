#ifndef ENTITIESUTILITY_H_
#define ENTITIESUTILITY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "entities.h"
#include "../../../dependencies/my/dynamicvectors/vector.h"

void initializeEntities();
bool addEntity(Entity* entity, size_t row, int *id);
// bool existEntities(size_t scene, size_t index);
// void printEntity(size_t scene, size_t index);
// void printEntities(size_t scene);
void destroyEntities();

#endif

// extern int lengthEntities;

// extern int entities[MAX_ENTITIES];

// #include "../../../dependencies/my/matrix/matrix.h"
// extern Entities entities;
// #define SUBENTITIES 2
// extern Matrix entities;