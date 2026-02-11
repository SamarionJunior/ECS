#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../array.h"

// typedef struct str{
//   int a;
//   char b;
// } Str;

void printArray(Array* array){

  printf("array:\t");

  for (size_t i = 0; i < lengthArray(array); i++){
    printf(
      "float: %f ", 
      *((float*)getArray(array, i))
    );
  }

  printf("\n\n");

}

// void printArray(Array* array){

//   printf("array:\t");

//   for (size_t i = 0; i < lengthArray(array); i++){
//     printf(
//       "a: %d b: %c ", 
//       (*((Str*)getArray(array, i))).a,
//       (*((Str*)getArray(array, i))).b
//     );
//     // printf("%c ", *((char*)getArray(array, i)));
//   }

//   printf("\n\n");

// }

void printInformations(Array* array){

  printf("length:\t%d\n", lengthArray(array));
  printf("empty:\t%d\n", emptyArray(array));
  printf("full:\t%d\n", fullArray(array));

}

void printA(Array* array){

  printArray(array);

  // printInformations(array);

  printf("\n/////////////////////////\n\n");

}

int* f(){
  static int b;
  b = 4;
  return &b;
}

int main(int argc, char const *argv[]){

  printf("%p\n", f());
  printf("%p\n", f());

  // Array* array = NULL;

  // initializeArray(&array, 3, sizeof(float));

  // addArray(array, lengthArray(array), &(float){5.7});
  
  // printA(array);

  // addArray(array, lengthArray(array), &(float){8.4});
  
  // printA(array);

  // addArray(array, lengthArray(array), &(float){1.1});
  
  // printA(array);

  // destroyArray(array);

  return 0;

}
  // Array* array = NULL;

  // initializeArray(&array, 3, sizeof(Str));

  // addArray(array, lengthArray(array), &(Str){.a = 32, .b = 'q'});
  
  // printA(array);

  // addArray(array, lengthArray(array), &(Str){.a = 13, .b = 't'});
  
  // printA(array);

  // addArray(array, lengthArray(array), &(Str){.a = 25, .b = 'r'});
  
  // printA(array);

  // destroyArray(array);

  // return 0;



  ///////////////////////////////



  // printf("\n/////////////////////////\n\n");

  // removeArray(a, lengthArray(a)-1);

  // printf("length:\t%d\n", lengthArray(a));
  // printf("empty:\t%d\n", emptyArray(a));
  // printf("full:\t%d\n", fullArray(a));

  // printf("\n/////////////////////////\n\n");

  // setArray(a, length(a) - 1, &(char){'b'});
  // printf("get:\t%c\n", *((char*)getArray(a, lengthArray(a)-1)));

  // printf("length:\t%d\n", lengthArray(a));
  // printf("empty:\t%d\n", emptyArray(a));
  // printf("full:\t%d\n", fullArray(a));

  // int* func(int arg){
  //   // printf("%d\n", arg);
  //   int *v = malloc(sizeof(int));
  //   // printf("%p - %p\n", &v, v);
  //   v[0] = arg;
  //   return v;
  // }

  // char *ptr = NULL;
  // char cha = 'a';
  // printf("%ld\n", sizeof(ptr));
  // printf("%d\n", sizeof(cha));

  // int *a = func(6);
  // printf("%d - %p - %p\n", *a, a, &a);
  // int *b = func(9);
  // printf("%d - %p - %p\n", *b, b, &b);
  // int *c = func(3);
  // printf("%d - %p - %p\n", *c, c, &c);
  // printf("%d - %p - %p\n", *a, a, &a);
  // printf("%d - %p - %p\n", *b, b, &b);
  // printf("%d - %p - %p\n", *c, c, &c);
  // return 0;