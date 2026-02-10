#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../architecture/components/components.h"

#include "../architecture/entities/entities.h"
#include "../architecture/systems/systems.h"

#include "../constants.h"

#include "../../dependencies/my/dynamicarray/array.h"

#include "map.h"

Array* map;
FILE *txt = NULL;

FILE* openMap(char* path);
void setMapDimension(char* file);
void initilizeMatrix(int row, int col);
void parseMapToMatrix(char* file, Array* matrix);
void closeMap(FILE* file);
void destroyMap(Array *auxiliarymap);

void loadMap(){

	// // // // printf("\n////////////////\n");
	// // // // printf(  "/// LOAD MAP ///\n");
	// // // // printf(  "////////////////\n\n");

  txt = openMap(pathMap);
  setMapDimension(txt);
  
  initilizeMatrix(getROW(), getCOL());
  parseMapToMatrix(txt, map);

  closeMap(txt);

  printf(
    "col = %d - row = %d\n",
    getCOL(),
    getROW()
  );

	// // // // printf("\n//////////////////////\n");
	// // // // printf(  "/// END - LOAD MAP ///\n");
	// // // // printf(  "//////////////////////\n\n");

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

void initilizeMatrix(int row, int col){
  initializeArray(
    &map, 
    row, 
    sizeof(Array)
  );
  // int** auxMatrix = malloc(sizeof(int*) * row);
  for (size_t i = 0; i < row; i++){
    Array* line;
    initializeArray(
      &line, 
      col, 
      sizeof(int)
    );
    // printf("lenght %d\n", lengthArray(line));
    addArray(
      map,
      i,
      line
    );
  }
  // printf("lenght %d\n", lengthArray(map));

  for (size_t i = 0; i < row; i++){
    // for (size_t j = 0; j < col; j++){
    Array* a = (Array*)getArray(map, i);
      printf("%d f\n", lengthArray(a));
    // }
  }
  
}

void parseMapToMatrix(char* file, Array* matrix){
  int i = 0, j = 0, c = 0, CodeANSIConvertedInInteger = 0;
  while((c = fgetc(file)) != EOF){
    if(c == '\n'){
		  // printf("\n");
      j = 0;
      i++;
      // printf("i %d\n", i);
      continue;
    }
    CodeANSIConvertedInInteger = (int)(c - '0');
		// printf("[%d][%d]", i, j);
    Array* line = (Array*)getArray(matrix, i);
    // printf("j %d\n", j);
    addArray(line, j, &CodeANSIConvertedInInteger);
    // matrix[i][j] = CodeANSIConvertedInInteger;
    j++;
  }
	// printf("\n");
  fseek(file, 0, SEEK_SET);
}
  
void closeMap(FILE* file){
  fclose(file);
  file = NULL;
}

void destroyMap(Array *auxiliarymap){
	for (size_t i = 0; i < getROW(); i++){
		free(getArray(auxiliarymap, i));
	}
	free(auxiliarymap);
}
