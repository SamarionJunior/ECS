#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "player.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsPlayer(VectorPlayer* vectorPlayer, size_t collum){

    if(vectorPlayer == NULL){
        printf("\n");
        printf("vectorPlayer == NULL\n");
        printf("vectorPlayer - Address: %p\n", vectorPlayer);
        printf("\n");
        return false;
    }
    if(vectorPlayer->data == NULL){
        printf("\n");
        printf("vectorPlayer->data\n");
        printf("vectorPlayer - Address: %p\n", vectorPlayer->data);
        printf("\n");
        return false;
    }
    if(vectorPlayer->columnLength < 0){
        printf("\n");
        printf("vectorPlayer->columnLength < 0\n");
        printf("vectorPlayer->columnLength = %d\n", vectorPlayer->columnLength);
        printf("\n");
        return false;
    }
    if(vectorPlayer->maximumCollumn < 0){
        printf("\n");
        printf("vectorPlayer->maximumCollumn < 0\n");
        printf("vectorPlayer->maximumCollumn = %d\n", vectorPlayer->maximumCollumn);
        printf("\n");
        return false;
    }
    if(collum < 0){
        printf("\n");
        printf("collum < 0\n");
        printf("collum = %d\n", collum);
        printf("\n");
        return false;
    }
    if(collum > vectorPlayer->columnLength){
        printf("\n");
        printf("collum > vectorPlayer->columnLength\n");
        printf("collum = %d\n", collum);
        printf("vectorPlayer->columnLength = %d\n", vectorPlayer->columnLength);
        printf("\n");
        return false;
    }
    if(collum == vectorPlayer->maximumCollumn){
        printf("\n");
        printf("collum == vectorPlayer->maximumCollumn\n");
        printf("collum = %d\n", collum);
        printf("vectorPlayer->maximumCollumn = %d\n", vectorPlayer->maximumCollumn);
        printf("\n");
        return false;
    }

    return true;
}

bool addCellPlayer(VectorPlayer* vectorPlayer, size_t collum, Player data){

    if(!verifyParamsPlayer(vectorPlayer, collum)){
        return false;
    }

    if(vectorPlayer->columnLength == vectorPlayer->maximumCollumn){
        printf("\n");
        printf("vectorPlayer->columnLength == vectorPlayer->maximumCollumn\n");
        printf("maximumCollumn - value: %d\n", vectorPlayer->maximumCollumn);
        printf("matrix->collum[row] - value: %d\n", vectorPlayer->columnLength);
        printf("\n");
        return false;
    }

    // printf("collum = %d\n", collum);

    vectorPlayer->columnLength++;
    Player *tempColumn = 
        (vectorPlayer->data == NULL) ?
            malloc(sizeof(Player) * vectorPlayer->columnLength) :
            realloc(vectorPlayer->data, sizeof(Player) * vectorPlayer->columnLength); // verify

    // frre(DATA)
    if(tempColumn == NULL){
        vectorPlayer->columnLength--;
        return false;
    }

    vectorPlayer->data = tempColumn;

    for (size_t i = (vectorPlayer->columnLength - 1); i > collum; i--){
        vectorPlayer->data[i] = vectorPlayer->data[i - 1];
    }

    vectorPlayer->data[collum] = data;

    // printf("\nmatrix->collum[row] %d\n", matrix->collum[row]);
    return true;

}

bool removeCellPlayer(VectorPlayer* vectorPlayer, size_t collum){

    if(!verifyParamsPlayer(vectorPlayer, collum)){
        return false;
    }

    for (size_t j = collum; j < (vectorPlayer->columnLength - 1); j++){
        vectorPlayer->data[j] = vectorPlayer->data[j + 1];
    }

    // matrix->matrix[row][matrix->collum[row] - 1].data = NULL;
    // free(vectorPlayer->data[vectorPlayer->columnLength - 1]);

    vectorPlayer->columnLength--;
    vectorPlayer->data = realloc(vectorPlayer->data, sizeof(Player) * vectorPlayer->columnLength); // verify

    return true;
}

bool setCellPlayer(VectorPlayer* vectorPlayer, size_t collum, Player data){

    if(!verifyParamsPlayer(vectorPlayer, collum)){
        return false;
    }

	// free(vectorPlayer->data[collum]);

	vectorPlayer->data[collum] = data;

    return true;

}

Player* getCellPlayer(VectorPlayer* vectorPlayer, size_t collum){

    if(!verifyParamsPlayer(vectorPlayer, collum)){
        return NULL;
    }

	return &(vectorPlayer->data[collum]);

}

bool fullCollumnPlayer(VectorPlayer* vectorPlayer){
    
    if(!verifyParamsPlayer(vectorPlayer, 0)){
        return false;
    }

	return vectorPlayer->columnLength == vectorPlayer->maximumCollumn ? true : false;

}

bool emptyCollumnPlayer(VectorPlayer* vectorPlayer){
    
    if(!verifyParamsPlayer(vectorPlayer, 0)){
        return false;
    }

	return vectorPlayer->columnLength == 0 ? true : false;

}

int lengthCollumnPlayer(VectorPlayer* vectorPlayer){

    if(!verifyParamsPlayer(vectorPlayer, 0)){
        return false;
    }
    
	return vectorPlayer->columnLength;

}

bool printVectorPlayer(VectorPlayer* vectorPlayer){

    if(!verifyParamsPlayer(vectorPlayer, 0)){
        return false;
    }

    for (size_t j = 0; j < vectorPlayer->columnLength; j++){
        printf("%p - [%d]: %d\n", &vectorPlayer->data[j], j, vectorPlayer->data[j]);
    }
    printf("\n");

    return true;
}

void initializeVectorPlayer(VectorPlayer* vectorPlayer, unsigned int maximumCollumn){

    if(vectorPlayer == NULL){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("vector - address: %p\n", *vectorPlayer);
        return NULL;
    }

    if(maximumCollumn < 1){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("maximumCollumn - value: %d\n", maximumCollumn);
        return NULL;
    }

    *vectorPlayer = (VectorPlayer){
        .maximumCollumn = maximumCollumn,
        .columnLength = 0,
        .data = malloc(sizeof(Player)),
    };

}

bool destroyVectorPlayer(VectorPlayer* vectorPlayer){

    if(vectorPlayer == NULL){
        return false;
    }

    if(vectorPlayer->data != NULL){
        printf("vectorPlayer->data == %p\n", vectorPlayer->data);
        printf("vectorPlayer->data[0] == %i\n", vectorPlayer->data[0]);
        free(vectorPlayer->data);
        vectorPlayer->data = NULL;
    }
}
