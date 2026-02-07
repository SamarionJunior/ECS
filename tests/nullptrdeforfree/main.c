#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

void main(){
  int* a;
  printf("%p\n", a);
  a = malloc(sizeof(int) * 10);
  printf("%p\n", a);
  void* b = a;
  free(b);
  printf("%p\n", a);
  free(a);
  printf("%p\n", a);
}
