#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

#include "../array.h"

int main(int argc, char const *argv[]){
  // Array a;
  // initializeArray(&a, 1000, sizeof());
  void* a = &(int){4};
  void* b = &a;
  void* c;
  void** d;

  // void** d = c;

  memcpy(c, b, sizeof(void*));

  d = c;

  printf("%d\n", *(int*)*d);

  // printf("%ld\n", sizeof(void*));
  // printf("%ld\n", sizeof(void**));
  // printf("%ld\n", sizeof(void***));
  return 0;
}
