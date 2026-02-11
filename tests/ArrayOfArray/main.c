#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
// #include <string.h>

#include "../../dependencies/my/dynamicarray/array.h"
#include "../../dependencies/my/dynamicmatrix/matrix.h"

void main(){
  srand(time(NULL));
  // void** a;
  // a = (void**)malloc(sizeof(int*)*3);
  // for (size_t i = 0; i < 3; i++){
  //   a[i] = (int*)malloc(sizeof(int)*3);
  //   for (size_t j = 0; j < 3; j++){
  //     int* b = a[i];
  //     b[j] = rand()%10;
  //     printf("%d", b[j]);
  //   }
  //   printf("\n");
  // }
  // for (size_t i = 0; i < 3; i++){
  //   printf("|");
  //   for (size_t j = 0; j < 3; j++){
  //     int* b = a[i];
  //     printf("%p|", &b[j]);
  //   }
  //   printf("\n");
  // }
  // for (size_t i = 0; i < 3; i++){
  //   for (size_t j = 0; j < 3; j++){
  //     int* b = a[i];
  //     printf("%d", b[j]);
  //   }
  //   printf("\n");
  //   free(a[i]);
  // }
  // free(a);
  Matrix matrix;
  initializeMatrix(&matrix, 3);
  for (size_t i = 0; i < 3; i++){
    Array array;
    initializeArray(&array, 3, sizeof(int));
    for (size_t j = 0; j < 3; j++){
      int b = rand()%10;
      printf("%d", b);
      addArray(&array, j, &b);
    }
    printf("\n");
    addMatrix(&matrix, i, array);
  }
  printf("---\n");
  for (size_t i = 0; i < 3; i++){
    Array array = getMatrix(matrix, i);
    for (size_t j = 0; j < 3; j++){
      int* b = (int*)getArray(array, j);
      printf("%d", *b);
    }
    printf("\n");
  }
  printf("---\n");
  for (size_t i = 0; i < 3; i++){
    Array array = getMatrix(matrix, i);
    for (size_t j = 0; j < 3; j++){
      int* b = (int*)getArray(array, j);
      printf("%d", *b);
    }
    printf("\n");
    destroyArray(&array);
  }
  destroyMatrix(&matrix);
}