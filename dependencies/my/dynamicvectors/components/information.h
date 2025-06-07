#ifndef VECTORINFORMATION_H_
#define VECTORINFORMATION_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsInformation(VectorInformation* vectorInformation, size_t collum);
bool addCellInformation(VectorInformation* vectorInformation, size_t collum, Information data);
bool removeCellInformation(VectorInformation* vectorInformation, size_t collum);
bool setCellInformation(VectorInformation* vectorInformation, size_t collum, Information data);
int* getCellInformation(VectorInformation* vectorInformation, size_t collum);
bool fullCollumnInformation(VectorInformation* vectorInformation);
bool emptyCollumnInformation(VectorInformation* vectorInformation);
int lengthCollumnInformation(VectorInformation* vectorInformation);
bool printVectorInformation(VectorInformation* vectorInformation);
void initializeVectorInformation(VectorInformation* vectorInformation, unsigned int maximumCollumn);
bool destroyVectorInformation(VectorInformation* vectorInformation);

#endif