#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "../../dependencies/my/dynamicarray/array.h"

typedef struct arrayofarray{
  Array* array;
} ArrayOfArray;


void main(){
  srand(time(NULL));
  Array* matrix = NULL;
  initializeArray(&matrix, 3, sizeof(ArrayOfArray));
  for (size_t i = 0; i < 3; i++){
    ArrayOfArray array;
    // Array* vector = NULL;
    initializeArray(&(array.array), 3, sizeof(int));
    for (size_t j = 0; j < 3; j++){
      int b = rand()%10;
      printf("%d", b);
      addArray(array.array, j, &b);
    }
    printf("\n");
    addArray(matrix, i, &array);
  }
  for (size_t i = 0; i < 3; i++){
    ArrayOfArray* a = (ArrayOfArray*)getArray(matrix, i);
    for (size_t j = 0; j < 3; j++){
      int* b = (int*)getArray(a->array, j);
      printf("%d", *b);
    }
    printf("\n");
  }
  for (size_t i = 0; i < 3; i++){
    ArrayOfArray* a = (ArrayOfArray*)getArray(matrix, i);
    for (size_t j = 0; j < 3; j++){
      int* b = (int*)getArray(a->array, j);
      printf("%d", *b);
    }
    printf("\n");
    destroyArray(a->array);
  }
  destroyArray(matrix);
}