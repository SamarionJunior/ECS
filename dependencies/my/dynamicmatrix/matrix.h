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
bool addMatrixArray(Matrix* matrix, size_t indexMatrix, size_t indexArray, void* data);
bool removeMatrix(Matrix* matrix, size_t index);
bool removeMatrixArray(Matrix* matrix, size_t indexMatrix, size_t indexArray);
bool setMatrix(Matrix matrix, size_t index, Array array);
bool setMatrixArray(Matrix matrix, size_t indexMatrix, size_t indexArray, void* data);
Array getMatrix(Matrix matrix, size_t index);
void* getMatrixArray(Matrix matrix, size_t indexMatrix, size_t indexArray);
bool fullMatrix(Matrix matrix);
bool emptyMatrix(Matrix matrix);
unsigned int lengthMatrix(Matrix matrix);
bool initializeMatrix(Matrix* matrix, unsigned int maximumMatrix);
bool destroyMatrix(Matrix* matrix);

#endif

