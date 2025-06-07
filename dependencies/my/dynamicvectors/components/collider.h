#ifndef VECTORCOLLIDER_H_
#define VECTORCOLLIDER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsCollider(VectorCollider* vectorCollider, size_t collum);
bool addCellCollider(VectorCollider* vectorCollider, size_t collum, Collider data);
bool removeCellCollider(VectorCollider* vectorCollider, size_t collum);
bool setCellCollider(VectorCollider* vectorCollider, size_t collum, Collider data);
int* getCellCollider(VectorCollider* vectorCollider, size_t collum);
bool fullCollumnCollider(VectorCollider* vectorCollider);
bool emptyCollumnCollider(VectorCollider* vectorCollider);
int lengthCollumnCollider(VectorCollider* vectorCollider);
bool printVectorCollider(VectorCollider* vectorCollider);
void initializeVectorCollider(VectorCollider* vectorCollider, unsigned int maximumCollumn);
bool destroyVectorCollider(VectorCollider* vectorCollider);

#endif
