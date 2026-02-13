#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "array.h"

bool addArray(Array* array, size_t index, void* data);
bool removeArray(Array* array, size_t index);
bool setArray(Array array, size_t index, void* data);
void* getArray(Array array, size_t index);
bool fullArray(Array array);
bool emptyArray(Array array);
unsigned int lengthArray(Array array);
bool initializeArray(Array* array, unsigned int maximumArray, unsigned int sizeData);
bool destroyArray(Array* array);

bool addArray(Array* array, size_t index, void* data){
  
  if(array->arrayLength > array->maximumArray){
    printf(
      "Array taget maximum limit!: %d > %d\n", 
      array->arrayLength, 
      array->maximumArray
    );
    return false;
  }

  void* tempColumn = 
    (array->data == NULL) ?
      malloc((array->arrayLength + 1) * array->sizeData) :
      realloc(array->data,  (array->arrayLength + 1) * array->sizeData); // verify

  // frre(DATA)
  if(tempColumn == NULL){
    // printf("Temporary Array Not Can Allocate!\n");
    return false;
  }

  array->data = tempColumn;

  array->arrayLength++;

  for (size_t i = (array->arrayLength - 1); i > index; i--){
    memcpy(array->data + i * array->sizeData, array->data + (i - 1) * array->sizeData, array->sizeData);
  }

  memcpy(array->data + index * array->sizeData, data, array->sizeData);

  return true;

}

bool removeArray(Array* array, size_t index){

    for (size_t j = index; j < (array->arrayLength - 1); j++){
        memcpy(array->data + j * array->sizeData, array->data + (j + 1) * array->sizeData, array->sizeData);
    }

    array->data = realloc(array->data, array->arrayLength * array->sizeData); // verify
    array->arrayLength--;

    return true;
}

bool setArray(Array array, size_t index, void* data){

    memcpy(array.data + index * array.sizeData, data, array.sizeData);

    return true;

}

void* getArray(Array array, size_t index){

	return array.data + index * array.sizeData;

}

bool fullArray(Array array){

	return array.arrayLength == array.maximumArray ? true : false;

}

bool emptyArray(Array array){

	return array.arrayLength == 0 ? true : false;

}

unsigned int lengthArray(Array array){
    
	return array.arrayLength;

}

bool initializeArray(Array* array, unsigned int maximumArray, unsigned int sizeData){

  // printf("Size Data: %d\n", sizeData);
    
  // *array = (Array*)malloc(sizeof(Array));

  if(array == NULL){
    printf("Null Array\n");
    return false;
  }

  *array = (Array){
    .sizeData = sizeData,
    .arrayLength = 0,
    .maximumArray = maximumArray,
    .data = NULL
  };
  
  // printf("initialize:\tarray == %p\n", *array);
  // printf("initialize:\tarray->data == %p\n", (*array)->data);

  return true;

}

bool destroyArray(Array* array){

  printf("sasdASA\n");

  if(array->data == NULL){
    printf("array->data == NULL\n");
    return false;
  }

  free(array->data);

  array->data = NULL;

  // printf("destroy:\tarray == %p\n", array);
  // printf("destroy:\tarray->data == %p\n", array->data);

  // free(array);

  // printf("array %p\n", array);

  // printf("array->data %p\n", array->data);

  return true;

}
