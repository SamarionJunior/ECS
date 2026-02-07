#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct str1{
  int a;
  float b;
} Str1;

typedef struct str2{
  char c;
} Str2;

typedef struct str{
  int id;
  Str1 str1;
  Str2 str2;
} Str;

typedef struct id{
  int id;
} Id;

void main(){
  Str str;
  str.id = 6748394;
  str.str1.a = 975362908;
  str.str1.b = 2.45f;
  str.str2.c = 'f';
  
  void* p = &str;
  Id* c = (Id*)p; 
  int b = c->id;
  printf("%d\n", b);

  // void* p = &str;
  // float* c = (unsigned char*)p; 
  // float b = *c;
  // printf("%f\n", b);
}
  // int a = 6;
  // void* p = &a;
  // unsigned char* c = (unsigned char*)p; 
  // int b = (int)(*c);
  // printf("%d\n", b);
