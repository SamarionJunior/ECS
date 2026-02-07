#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct a{
  int b;
} A;

void main(){
  A c = (A){.b = 10};
    printf("%d\n", c.b);
  if((c = (A){.b = 4}).b == 4){
    printf("%d\n", c.b);
  }
  printf("%d\n", c.b);
}