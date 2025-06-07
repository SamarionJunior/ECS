#ifndef VECTORCOLLECTIBLE_H_
#define VECTORCOLLECTIBLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsCollectible(VectorCollectible* vectorCollectible, size_t collum);
bool addCellCollectible(VectorCollectible* vectorCollectible, size_t collum, Collectible data);
bool removeCellCollectible(VectorCollectible* vectorCollectible, size_t collum);
bool setCellCollectible(VectorCollectible* vectorCollectible, size_t collum, Collectible data);
Collectible* getCellCollectible(VectorCollectible* vectorCollectible, size_t collum);
bool fullCollumnCollectible(VectorCollectible* vectorCollectible);
bool emptyCollumnCollectible(VectorCollectible* vectorCollectible);
int lengthCollumnCollectible(VectorCollectible* vectorCollectible);
bool printVectorCollectible(VectorCollectible* vectorCollectible);
void initializeVectorCollectible(VectorCollectible* vectorCollectible, unsigned int maximumCollumn);
bool destroyVectorCollectible(VectorCollectible* vectorCollectible);

#endif