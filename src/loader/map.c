#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../architecture/components/components.h"

#include "../architecture/entities/entities.h"
#include "../architecture/systems/systems.h"

#include "../constants.h"

#include "../../dependencies/mycustom/myjson.h"

#include "json.h"

#include "map.h"

int **mapMatrix = NULL;

void loadMap(){

  mapMatrix = malloc(sizeof(int*)*ROW);

  for (size_t i = 0; i < ROW; i++){
      mapMatrix[i] = malloc(sizeof(int)*COL);
  }
    

	// // // // printf("\n////////////////\n");
	// // // // printf(  "/// LOAD MAP ///\n");
	// // // // printf(  "////////////////\n\n");
    
  FILE *mapTxt = fopen("./data/map.txt", "r");
  
  if(mapTxt == NULL){
      free(mapTxt);
      // printf("\nSucess\n");
  }
  
  for (size_t i = 0; i < ROW; i++){
      for (size_t j = 0; j < COL; j++){
          mapMatrix[i][j] = 9;
      }
  }

  int c = 0;

  size_t i = 0, j = 0, count = 0;
  while((c = fgetc(mapTxt)) != EOF){
    if(c == '\n'){
      // printf("%d\n", rand());
      j = 0;
      i++;
      continue;
    }

    // printf("ROW - I - %d - COL - J- %d\n", i, j);

    int conv = (int)(c - '0');
    mapMatrix[i][j] = conv;

    count++;
    j++;
  }

  fclose(mapTxt);

  mapTxt = NULL;

	// // // // printf("\n//////////////////////\n");
	// // // // printf(  "/// END - LOAD MAP ///\n");
	// // // // printf(  "//////////////////////\n\n");

}
  
    // printf("||||||\n");
    // for (size_t a = 0; a < ROW; a++){
    //   for (size_t b = 0; b < COL; b++){
    //       printf("%d", mapMatrix[a][b]);
    //   }
    //   printf("\n");
    // }
    // printf("||||||\n");

  // char *buffer = NULL;
  // buffer = malloc(sizeof(char) * 1000);

  // fread(buffer, sizeof(char), 1000, mapTxt);
  
  // for (size_t i = 0; i < 12; i++){
  //     for (size_t j = 0; j < 13; j++){
  //         if ((i*13)+j == ((12*13)-1)){
  //             break;
  //         }
  //         printf("%c", buffer[(i*13)+j]);
  //     }
  // }
  // printf("\n");

  // for(size_t i = 0; i < ROW ; i++){
  //     for (size_t j = 0; j < COL ; j++){
  //         int conv = (int)(buffer[(i*(COL+1))+j] - '0');
  //         mapMatrix[i][j] = conv;
  //     }
  // }

  // int dsd = 0;

  
  // for (size_t i = 0; i < 12; i++){
  //     for (size_t j = 0; j < 12; j++){
  //         printf("%d", mapMatrix[i][j]);
  //     }
  //     printf("\n");
  // }
  // free(buffer);

  // printf("\n");

    // exit(1);

// for(size_t count = 0, i = 0, j = 0; 1 ;count++){
    
//     if(buffer[count] == '\0'){
//         break;
//     }

//     if(buffer[count] == '\n'){
//         // printf("\n");
//         i++;
//         j = 0;
//         continue;
//     }

//     // printf("|%d|", buffer[count]);
//     if(i < ROW && j < COL && count < 1000){
//         int conv = (int)(buffer[count] - '0');
//         mapMatrix[i][j] = conv;
//     }else{
//         printf("i: %d\n", i);
//         printf("j: %d\n", j);
//         printf("count: %d\n", count);
//     }

//     j++;
    
// }
// printf("\n");

// void loadMapOld(){

//     char buffer[10000];
    
//     FILE *mapTxt = fopen("data/map.txt", "r");
//     if(mapTxt == NULL){
//         printf("\nSucess\n");
//     }
    
//     fread(buffer, 1, sizeof(buffer), mapTxt);
//     printf("\n%s\n", buffer);
//     printf("\n");

//     for (size_t i = 0; i < 12; i++){
//         for (size_t j = 0, k = 0; j < 12; j++, k++){
//             // if(buffer[j] == '\n')
//             printf("|%d|", buffer[((i*(12)) + i)+j]);
//             mapMatrix[i][k] = buffer[((i*(12)) + i)+j] - '0';
//         }
//         printf("\n");
//     }

//     fclose(mapTxt);

//     printf("\n");
    
//     for (size_t i = 0; i < 12; i++){
//         for (size_t j = 0; j < 12; j++){
//             printf("%d", mapMatrix[i][j]);
//         }
//         printf("\n");
//     }

//     printf("\n");
// }
