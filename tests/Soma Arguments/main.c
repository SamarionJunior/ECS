#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int start = 48;

int stringToInteger(int index, char const *argv[]);
void printArgument(int index, char const *argv[]);
int somaArgument(int start, int limit, char const *argv[]);

int main(int argc, char const *argv[]){

  int soma = somaArgument(1, argc, argv);

  printf("soma: %d\n", soma);
  
  return 0;

}

int somaArgument(int start, int limit, char const *argv[]){

  int soma = 0;

  for (size_t index = start; index < limit; index++){
    printArgument(index, argv);
    soma += stringToInteger(index, argv);
  }

  return soma;
}

int stringToInteger(int index, char const *argv[]){
  return (((int)(argv[index][0])) - start);
}

void printArgument(int index, char const *argv[]){
  printf("%dº) Argumento: %s\n", index, argv[index]);
}
  // int soma = 0;
  // int start = 48;
  // for (size_t i = 1; i < argc; i++){
  //   printf("%s\n", argv[i]);
  //   printf("index: %d - char: %s - int: %d\n", i, argv[i], (((int)(argv[i][0])) - start));
  //   soma += (((int)(argv[i][0])) - start);
  // }
  // printf("soma: %d\n", soma);