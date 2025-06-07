#ifndef VECTORPOSITION_H_
#define VECTORPOSITION_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsPosition(VectorPosition* vectorPosition, size_t collum);
bool addCellPosition(VectorPosition* vectorPosition, size_t collum, Position data);
bool removeCellPosition(VectorPosition* vectorPosition, size_t collum);
bool setCellPosition(VectorPosition* vectorPosition, size_t collum, Position data);
int* getCellPosition(VectorPosition* vectorPosition, size_t collum);
bool fullCollumnPosition(VectorPosition* vectorPosition);
bool emptyCollumnPosition(VectorPosition* vectorPosition);
int lengthCollumnPosition(VectorPosition* vectorPosition);
bool printVectorPosition(VectorPosition* vectorPosition);
void initializeVectorPosition(VectorPosition* vectorPosition, unsigned int maximumCollumn);
bool destroyVectorPosition(VectorPosition* vectorPosition);

#endif