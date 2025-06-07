#ifndef VECTORENTITY_H_
#define VECTORENTITY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "../../../../src/architecture/entities/entities.h"

bool verifyParamsEntity(VectorEntity* vectorEntity, size_t collum);
bool addCellEntity(VectorEntity* vectorEntity, size_t collum, Entity data);
bool removeCellEntity(VectorEntity* vectorEntity, size_t collum);
bool setCellEntity(VectorEntity* vectorEntity, size_t collum, Entity data);
int* getCellEntity(VectorEntity* vectorEntity, size_t collum);
bool fullCollumnEntity(VectorEntity* vectorEntity);
bool emptyCollumnEntity(VectorEntity* vectorEntity);
int lengthCollumnEntity(VectorEntity* vectorEntity);
bool printVectorEntity(VectorEntity* vectorEntity);
void initializeVectorEntity(VectorEntity* vectorEntity, unsigned int maximumCollumn);
bool destroyVectorEntity(VectorEntity* vectorEntity);

#endif