#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "position.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsPosition(VectorPosition* vectorPosition, size_t collum){

    if(vectorPosition == NULL){
        printf("\n");
        printf("vectorPosition == NULL\n");
        printf("vectorPosition - Address: %p\n", vectorPosition);
        printf("\n");
        return false;
    }
    if(vectorPosition->data == NULL){
        printf("\n");
        printf("vectorPosition->data\n");
        printf("vectorPosition - Address: %p\n", vectorPosition->data);
        printf("\n");
        return false;
    }
    if(vectorPosition->columnLength < 0){
        printf("\n");
        printf("vectorPosition->columnLength < 0\n");
        printf("vectorPosition->columnLength = %d\n", vectorPosition->columnLength);
        printf("\n");
        return false;
    }
    if(vectorPosition->maximumCollumn < 0){
        printf("\n");
        printf("vectorPosition->maximumCollumn < 0\n");
        printf("vectorPosition->maximumCollumn = %d\n", vectorPosition->maximumCollumn);
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
    if(collum > vectorPosition->columnLength){
        printf("\n");
        printf("collum > vectorPosition->columnLength\n");
        printf("collum = %d\n", collum);
        printf("vectorPosition->columnLength = %d\n", vectorPosition->columnLength);
        printf("\n");
        return false;
    }
    if(collum == vectorPosition->maximumCollumn){
        printf("\n");
        printf("collum == vectorPosition->maximumCollumn\n");
        printf("collum = %d\n", collum);
        printf("vectorPosition->maximumCollumn = %d\n", vectorPosition->maximumCollumn);
        printf("\n");
        return false;
    }

    return true;
}

bool addCellPosition(VectorPosition* vectorPosition, size_t collum, Position data){

    if(!verifyParamsPosition(vectorPosition, collum)){
        return false;
    }

    if(vectorPosition->columnLength == vectorPosition->maximumCollumn){
        printf("\n");
        printf("vectorPosition->columnLength == vectorPosition->maximumCollumn\n");
        printf("maximumCollumn - value: %d\n", vectorPosition->maximumCollumn);
        printf("matrix->collum[row] - value: %d\n", vectorPosition->columnLength);
        printf("\n");
        return false;
    }

    // printf("collum = %d\n", collum);

    vectorPosition->columnLength++;
    Position *tempColumn = 
        (vectorPosition->data == NULL) ?
            malloc(sizeof(Position) * vectorPosition->columnLength) :
            realloc(vectorPosition->data, sizeof(Position) * vectorPosition->columnLength); // verify

    // frre(DATA)
    if(tempColumn == NULL){
        vectorPosition->columnLength--;
        return false;
    }

    vectorPosition->data = tempColumn;

    for (size_t i = (vectorPosition->columnLength - 1); i > collum; i--){
        vectorPosition->data[i] = vectorPosition->data[i - 1];
    }

    vectorPosition->data[collum] = data;

    // printf("\nmatrix->collum[row] %d\n", matrix->collum[row]);
    return true;

}

bool removeCellPosition(VectorPosition* vectorPosition, size_t collum){

    if(!verifyParamsPosition(vectorPosition, collum)){
        return false;
    }

    for (size_t j = collum; j < (vectorPosition->columnLength - 1); j++){
        vectorPosition->data[j] = vectorPosition->data[j + 1];
    }

    // matrix->matrix[row][matrix->collum[row] - 1].data = NULL;
    // free(vectorPosition->data[vectorPosition->columnLength - 1]);

    vectorPosition->columnLength--;
    vectorPosition->data = realloc(vectorPosition->data, sizeof(Position) * vectorPosition->columnLength); // verify

    return true;
}

bool setCellPosition(VectorPosition* vectorPosition, size_t collum, Position data){

    if(!verifyParamsPosition(vectorPosition, collum)){
        return false;
    }

	// free(vectorPosition->data[collum]);

	vectorPosition->data[collum] = data;

    return true;

}

Position* getCellPosition(VectorPosition* vectorPosition, size_t collum){

    if(!verifyParamsPosition(vectorPosition, collum)){
        return NULL;
    }

	return &(vectorPosition->data[collum]);

}

bool fullCollumnPosition(VectorPosition* vectorPosition){
    
    if(!verifyParamsPosition(vectorPosition, 0)){
        return false;
    }

	return vectorPosition->columnLength == vectorPosition->maximumCollumn ? true : false;

}

bool emptyCollumnPosition(VectorPosition* vectorPosition){
    
    if(!verifyParamsPosition(vectorPosition, 0)){
        return false;
    }

	return vectorPosition->columnLength == 0 ? true : false;

}

int lengthCollumnPosition(VectorPosition* vectorPosition){

    if(!verifyParamsPosition(vectorPosition, 0)){
        return false;
    }
    
	return vectorPosition->columnLength;

}

bool printVectorPosition(VectorPosition* vectorPosition){

    if(!verifyParamsPosition(vectorPosition, 0)){
        return false;
    }

    for (size_t j = 0; j < vectorPosition->columnLength; j++){
        printf("%p - [%d]: %d\n", &vectorPosition->data[j], j, vectorPosition->data[j]);
    }
    printf("\n");

    return true;
}

void initializeVectorPosition(VectorPosition* vectorPosition, unsigned int maximumCollumn){

    if(vectorPosition == NULL){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("vector - address: %p\n", *vectorPosition);
        return NULL;
    }

    if(maximumCollumn < 1){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("maximumCollumn - value: %d\n", maximumCollumn);
        return NULL;
    }

    *vectorPosition = (VectorPosition){
        .maximumCollumn = maximumCollumn,
        .columnLength = 0,
        .data = malloc(sizeof(Position)),
    };

}

bool destroyVectorPosition(VectorPosition* vectorPosition){

    if(vectorPosition == NULL){
        return false;
    }

    if(vectorPosition->data != NULL){
        printf("vectorPosition->data == %p\n", vectorPosition->data);
        printf("vectorPosition->data[0] == %i\n", vectorPosition->data[0]);
        free(vectorPosition->data);
        vectorPosition->data = NULL;
    }
}
