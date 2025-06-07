#ifndef VECTORLAYER_H_
#define VECTORLAYER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsLayer(VectorLayer* vectorLayer, size_t collum);
bool addCellLayer(VectorLayer* vectorLayer, size_t collum, Layer data);
bool removeCellLayer(VectorLayer* vectorLayer, size_t collum);
bool setCellLayer(VectorLayer* vectorLayer, size_t collum, Layer data);
Layer* getCellLayer(VectorLayer* vectorLayer, size_t collum);
bool fullCollumnLayer(VectorLayer* vectorLayer);
bool emptyCollumnLayer(VectorLayer* vectorLayer);
int lengthCollumnLayer(VectorLayer* vectorLayer);
bool printVectorLayer(VectorLayer* vectorLayer);
void initializeVectorLayer(VectorLayer* vectorLayer, unsigned int maximumCollumn);
bool destroyVectorLayer(VectorLayer* vectorLayer);

#endif