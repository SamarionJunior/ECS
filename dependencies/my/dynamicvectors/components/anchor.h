#ifndef VECTORANCHOR_H_
#define VECTORANCHOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsAnchor(VectorAnchor* vectorAnchor, size_t collum);
bool addCellAnchor(VectorAnchor* vectorAnchor, size_t collum, Anchor data);
bool removeCellAnchor(VectorAnchor* vectorAnchor, size_t collum);
bool setCellAnchor(VectorAnchor* vectorAnchor, size_t collum, Anchor data);
Anchor* getCellAnchor(VectorAnchor* vectorAnchor, size_t collum);
bool fullCollumnAnchor(VectorAnchor* vectorAnchor);
bool emptyCollumnAnchor(VectorAnchor* vectorAnchor);
int lengthCollumnAnchor(VectorAnchor* vectorAnchor);
bool printVectorAnchor(VectorAnchor* vectorAnchor);
void initializeVectorAnchor(VectorAnchor* vectorAnchor, unsigned int maximumCollumn);
bool destroyVectorAnchor(VectorAnchor* vectorAnchor);

#endif