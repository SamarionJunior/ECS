#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../dynamicarray/array.h"
#include "matrix.h"

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

bool addMatrix(Matrix* matrix, size_t index, Array array){
  
  if(matrix->matrixLength > matrix->maximumMatrix){
    printf(
      "Array taget maximum limit!: %d > %d\n", 
      matrix->matrixLength,
      matrix->maximumMatrix
    );
    return false;
  }

  Array* tempArray = 
    (matrix->array == NULL) ?
      (Array*)malloc((matrix->matrixLength + 1) * matrix->sizeData) :
      (Array*)realloc(matrix->array,  (matrix->matrixLength + 1) * matrix->sizeData); // verify

  // frre(DATA)
  if(tempArray == NULL){
    // printf("Temporary Array Not Can Allocate!\n");
    return false;
  }

  matrix->array = tempArray;

  matrix->matrixLength++;

  for (size_t i = (matrix->matrixLength - 1); i > index; i--){
    matrix->array[i] = matrix->array[(i - 1)];
  }

  matrix->array[index] = array;

  return true;

}
bool addMatrixArray(Matrix* matrix, size_t indexMatrix, size_t indexArray, void* data){
  Array* temp = &(matrix->array[indexMatrix]);
  addArray(temp, indexArray, data);
  return true;
}

bool removeMatrix(Matrix* matrix, size_t index){

  Array* temp = &(matrix->array[index]);
  destroyArray(temp);

  for (size_t j = index; j < (matrix->matrixLength - 1); j++){
    matrix->array[j] = matrix->array[(j + 1)];
  }

  matrix->array = realloc(matrix->array, matrix->matrixLength * matrix->sizeData); // verify
  matrix->matrixLength--;

  return true;

}
bool removeMatrixArray(Matrix* matrix, size_t indexMatrix, size_t indexArray){

  Array* temp = &(matrix->array[indexMatrix]);
  // destroyArray(&temp);

  removeArray(temp, indexArray);

  return true;

}

bool setMatrix(Matrix matrix, size_t index, Array array){
  /// DESALOCATE ARRAY MEMORY BEFOR
  Array temp = matrix.array[index];
  destroyArray(&temp);
  matrix.array[index] = array;
  return true;
}
bool setMatrixArray(Matrix matrix, size_t indexMatrix, size_t indexArray, void* data){
  /// DESALOCATE ARRAY MEMORY BEFOR
  // Array temp = matrix.array[index];
  // destroyArray(&temp);
  setArray(matrix.array[indexMatrix], indexArray, data);
  return true;
}

Array getMatrix(Matrix matrix, size_t index){

  return matrix.array[index];

}
void* getMatrixArray(Matrix matrix, size_t indexMatrix, size_t indexArray){

  return getArray(getMatrix(matrix, indexMatrix), indexArray);

}

bool fullMatrix(Matrix matrix){

	return matrix.matrixLength == matrix.maximumMatrix ? true : false;

}

bool emptyMatrix(Matrix matrix){

	return matrix.matrixLength == 0 ? true : false;

}

unsigned int lengthMatrix(Matrix matrix){
    
	return matrix.matrixLength;

}

bool initializeMatrix(Matrix* matrix, unsigned int maximumMatrix){

  // printf("Size Data: %d\n", sizeData);
    
  // *matrix = (Matrix*)malloc(sizeof(Matrix));

  // if(*matrix == NULL){
  //   printf("*matrix == NULL\n");
  //   return false;
  // }

  if(matrix == NULL){
    printf("Null Matrix\n");
    return false;
  }

  // if(matrix->array != NULL){
  //   printf("Null Already Allocated\n");
  //   return false;
  // }

  *matrix = (Matrix){
    .sizeData = sizeof(Array),
    .matrixLength = 0,
    .maximumMatrix = maximumMatrix,
    .array = NULL
  };
  
  // printf("initialize:\tarray == %p\n", *array);
  // printf("initialize:\tarray->data == %p\n", (*array)->data);

  // return true;

}

bool destroyMatrix(Matrix* matrix){

  if(matrix->array == NULL){
    printf("Not Allocated Matrix\n");
    return false;
  }

  for (size_t i = 0; i < matrix->matrixLength; i++){
    Array array = getMatrix(*matrix, i);
    destroyArray(&array);
  }

  free(matrix->array);

  matrix->array = NULL;

  return true;

}

