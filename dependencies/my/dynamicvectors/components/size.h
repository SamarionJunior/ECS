#ifndef VECTORSIZE_H_
#define VECTORSIZE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsSize(VectorSize* vectorSize, size_t collum);
bool addCellSize(VectorSize* vectorSize, size_t collum, Size data);
bool removeCellSize(VectorSize* vectorSize, size_t collum);
bool setCellSize(VectorSize* vectorSize, size_t collum, Size data);
Size* getCellSize(VectorSize* vectorSize, size_t collum);
bool fullCollumnSize(VectorSize* vectorSize);
bool emptyCollumnSize(VectorSize* vectorSize);
int lengthCollumnSize(VectorSize* vectorSize);
bool printVectorSize(VectorSize* vectorSize);
void initializeVectorSize(VectorSize* vectorSize, unsigned int maximumCollumn);
bool destroyVectorSize(VectorSize* vectorSize);

#endif