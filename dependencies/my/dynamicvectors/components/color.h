#ifndef VECTORCOLOR_H_
#define VECTORCOLOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsColor(VectorColor* vectorColor, size_t collum);
bool addCellColor(VectorColor* vectorColor, size_t collum, Color data);
bool removeCellColor(VectorColor* vectorColor, size_t collum);
bool setCellColor(VectorColor* vectorColor, size_t collum, Color data);
int* getCellColor(VectorColor* vectorColor, size_t collum);
bool fullCollumnColor(VectorColor* vectorColor);
bool emptyCollumnColor(VectorColor* vectorColor);
int lengthCollumnColor(VectorColor* vectorColor);
bool printVectorColor(VectorColor* vectorColor);
void initializeVectorColor(VectorColor* vectorColor, unsigned int maximumCollumn);
bool destroyVectorColor(VectorColor* vectorColor);

#endif