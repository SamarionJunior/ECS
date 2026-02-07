#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../architecture/components/components.h"

#include "../architecture/entities/entities.h"
#include "../architecture/systems/systems.h"

#include "../constants.h"

// #include "../../dependencies/mycustom/myjson.h"

#include "map.h"

int **mapMatrix = NULL;
FILE *mapTxt = NULL;

int** initilizeMatrix(int row, int col);
FILE* openMap(char* path);
void setMapDimension(char* file);
void parseMapToMatrix(char* file, int **matrix);
void closeMap(FILE* file);
void destroyMap(int **auxiliaryMapMatrix);

void destroyMap(int **auxiliaryMapMatrix){
	for (size_t i = 0; i < getROW(); i++){
		free(auxiliaryMapMatrix[i]);
	}
	free(auxiliaryMapMatrix);
}

void loadMap(){

	// // // // printf("\n////////////////\n");
	// // // // printf(  "/// LOAD MAP ///\n");
	// // // // printf(  "////////////////\n\n");

  mapTxt = openMap(pathMap);
  setMapDimension(mapTxt);
  
  mapMatrix = initilizeMatrix(getROW(), getCOL());
  parseMapToMatrix(mapTxt, mapMatrix);

  closeMap(mapTxt);

  printf(
    "col = %d - row = %d\n",
    getCOL(),
    getROW()
  );

	// // // // printf("\n//////////////////////\n");
	// // // // printf(  "/// END - LOAD MAP ///\n");
	// // // // printf(  "//////////////////////\n\n");

}

int** initilizeMatrix(int row, int col){
  int** auxMatrix = malloc(sizeof(int*) * row);
  for (size_t i = 0; i < row; i++){
    auxMatrix[i] = malloc(sizeof(int) * col);
  }
  return auxMatrix;
}

FILE* openMap(char* path){
  FILE* file = fopen(path, "r");
  if(file == NULL){
    free(file);
    printf("Erro ao abrir o Arquivo: %s\n", path);
    return NULL;
  }
  return file;
}

void setMapDimension(char* file){
  int row = 0, collumn = 0, c = 0, greater = 0;
  while((c = fgetc(file)) != EOF){
    if(c == '\n'){
		  // printf("\n");
      if(greater < collumn){
        greater = collumn;
      }
      collumn = 0;
      row++;
      continue;
    }
    collumn++;
    // printf("[%d][%d]:%c", row, collumn, c);
  }
	// printf("\n");
  // printf("rows: %d - collumns: %d\n", row + 1, greater);
  setROW(row + 1);
  setCOL(greater);
  // printf("rows: %d - collumns: %d\n", getROW(), getCOL());
  fseek(file, 0, SEEK_SET);
}

void parseMapToMatrix(char* file, int **matrix){
  int i = 0, j = 0, c = 0, CodeANSIConvertedInInteger = 0;
  while((c = fgetc(file)) != EOF){
    if(c == '\n'){
		  // printf("\n");
      j = 0;
      i++;
      continue;
    }
    CodeANSIConvertedInInteger = (int)(c - '0');
		// printf("[%d][%d]", i, j);
    matrix[i][j] = CodeANSIConvertedInInteger;
    j++;
  }
	// printf("\n");
  fseek(file, 0, SEEK_SET);
}
  
void closeMap(FILE* file){
  fclose(file);
  file = NULL;
}

  // char buffer[(COL + 1)];
  // for(int j = 0; true; j++){
  //   fgets(buffer, (COL + 1), mapTxt);
  //   printf("%d-", buffer);
  //   char b = NULL;
  //   for (int i = 0; true; i++){
  //     if(b == EOF){
  //       break;
  //     }
  //     if(b == '\n'){
  //       printf("-oi\n");
  //       continue;
  //     }
  //     // convertedInteger = (int)(convertedInteger - '0');
  //     mapMatrix[i][j] = (int)(b - '0');
  //   }
  // }
  // free(buffer);
  // buffer = NULL;