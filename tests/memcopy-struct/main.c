#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct str{
  int a;
  int b;
  int c;
} Str;

void main(){
  Str str = (Str){
    .a = 7,
    .b = 1,
    .c = 2
  };

  void* ptr = &str;

  memcpy(
    (ptr + (sizeof(int) * 1)),
    &(int){9},
    sizeof(int)
  );

  int* aux = (int*)ptr;

  *aux = 8;

  // *(aux + 1) = 6;

  // printf(
  //   "a = %d\nb = %d\nc = %d\n", 
  //   str.a, str.b, str.c
  // );
  printf(
    "a = %d\nb = %d\nc = %d\n", 
    *(int*)(ptr + (sizeof(int) * 0)), 
    *(int*)(ptr + (sizeof(int) * 1)), 
    *(int*)(ptr + (sizeof(int) * 2))
  );

  // void* hex; 

  // printf("%d\n", hex);
  // printf("%d\n", hex+1);
  // printf("%d\n", hex);
}