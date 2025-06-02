#ifndef ENTITIES_H_
#define ENTITIES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../../dependencies/my/matrix/matrix.h"

#define MAX_ENTITIES 100

#define SUBENTITIES 2

extern Matrix entities;

void initializeEntities();
bool addEntity(size_t row, int *id);
// bool existEntities(size_t scene, size_t index);
void printEntity(size_t scene, size_t index);
void printEntities(size_t scene);
void destroyEntities();

#endif

// extern int lengthEntities;

// extern int entities[MAX_ENTITIES];