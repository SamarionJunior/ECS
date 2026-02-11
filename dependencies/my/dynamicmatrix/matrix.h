#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../dynamicarray/array.h"

typedef struct matrix{
    Array *array;
    unsigned int sizeData;
    unsigned int matrixLength;
    unsigned int maximumMatrix;
} Matrix;

//////////////////////////////////

// extern Matrix matrix;

//////////////////////////////////

bool addMatrix(Matrix* matrix, size_t index, Array array);
bool removeMatrix(Matrix* matrix, size_t index);
bool setMatrix(Matrix matrix, size_t index, Array array);
Array getMatrix(Matrix matrix, size_t index);
bool fullMatrix(Matrix matrix);
bool emptyMatrix(Matrix matrix);
unsigned int lengthMatrix(Matrix matrix);
bool initializeMatrix(Matrix* matrix, unsigned int maximumMatrix);
bool destroyMatrix(Matrix* matrix);

#endif

