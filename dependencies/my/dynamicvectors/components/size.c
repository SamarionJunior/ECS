#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "size.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsSize(VectorSize* vectorSize, size_t collum){

    if(vectorSize == NULL){
        printf("\n");
        printf("vectorSize == NULL\n");
        printf("vectorSize - Address: %p\n", vectorSize);
        printf("\n");
        return false;
    }
    if(vectorSize->data == NULL){
        printf("\n");
        printf("vectorSize->data\n");
        printf("vectorSize - Address: %p\n", vectorSize->data);
        printf("\n");
        return false;
    }
    if(vectorSize->columnLength < 0){
        printf("\n");
        printf("vectorSize->columnLength < 0\n");
        printf("vectorSize->columnLength = %d\n", vectorSize->columnLength);
        printf("\n");
        return false;
    }
    if(vectorSize->maximumCollumn < 0){
        printf("\n");
        printf("vectorSize->maximumCollumn < 0\n");
        printf("vectorSize->maximumCollumn = %d\n", vectorSize->maximumCollumn);
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
    if(collum > vectorSize->columnLength){
        printf("\n");
        printf("collum > vectorSize->columnLength\n");
        printf("collum = %d\n", collum);
        printf("vectorSize->columnLength = %d\n", vectorSize->columnLength);
        printf("\n");
        return false;
    }
    if(collum == vectorSize->maximumCollumn){
        printf("\n");
        printf("collum == vectorSize->maximumCollumn\n");
        printf("collum = %d\n", collum);
        printf("vectorSize->maximumCollumn = %d\n", vectorSize->maximumCollumn);
        printf("\n");
        return false;
    }

    return true;
}

bool addCellSize(VectorSize* vectorSize, size_t collum, Size data){

    if(!verifyParamsSize(vectorSize, collum)){
        return false;
    }

    if(vectorSize->columnLength == vectorSize->maximumCollumn){
        printf("\n");
        printf("vectorSize->columnLength == vectorSize->maximumCollumn\n");
        printf("maximumCollumn - value: %d\n", vectorSize->maximumCollumn);
        printf("matrix->collum[row] - value: %d\n", vectorSize->columnLength);
        printf("\n");
        return false;
    }

    // printf("collum = %d\n", collum);

    vectorSize->columnLength++;
    Size *tempColumn = 
        (vectorSize->data == NULL) ?
            malloc(sizeof(Size) * vectorSize->columnLength) :
            realloc(vectorSize->data, sizeof(Size) * vectorSize->columnLength); // verify

    // frre(DATA)
    if(tempColumn == NULL){
        vectorSize->columnLength--;
        return false;
    }

    vectorSize->data = tempColumn;

    for (size_t i = (vectorSize->columnLength - 1); i > collum; i--){
        vectorSize->data[i] = vectorSize->data[i - 1];
    }

    vectorSize->data[collum] = data;

    // printf("\nmatrix->collum[row] %d\n", matrix->collum[row]);
    return true;

}

bool removeCellSize(VectorSize* vectorSize, size_t collum){

    if(!verifyParamsSize(vectorSize, collum)){
        return false;
    }

    for (size_t j = collum; j < (vectorSize->columnLength - 1); j++){
        vectorSize->data[j] = vectorSize->data[j + 1];
    }

    // matrix->matrix[row][matrix->collum[row] - 1].data = NULL;
    // free(vectorSize->data[vectorSize->columnLength - 1]);

    vectorSize->columnLength--;
    vectorSize->data = realloc(vectorSize->data, sizeof(Size) * vectorSize->columnLength); // verify

    return true;
}

bool setCellSize(VectorSize* vectorSize, size_t collum, Size data){

    if(!verifyParamsSize(vectorSize, collum)){
        return false;
    }

	// free(vectorSize->data[collum]);

	vectorSize->data[collum] = data;

    return true;

}

int* getCellSize(VectorSize* vectorSize, size_t collum){

    if(!verifyParamsSize(vectorSize, collum)){
        return NULL;
    }

	return &(vectorSize->data[collum]);

}

bool fullCollumnSize(VectorSize* vectorSize){
    
    if(!verifyParamsSize(vectorSize, 0)){
        return false;
    }

	return vectorSize->columnLength == vectorSize->maximumCollumn ? true : false;

}

bool emptyCollumnSize(VectorSize* vectorSize){
    
    if(!verifyParamsSize(vectorSize, 0)){
        return false;
    }

	return vectorSize->columnLength == 0 ? true : false;

}

int lengthCollumnSize(VectorSize* vectorSize){

    if(!verifyParamsSize(vectorSize, 0)){
        return false;
    }
    
	return vectorSize->columnLength;

}

bool printVectorSize(VectorSize* vectorSize){

    if(!verifyParamsSize(vectorSize, 0)){
        return false;
    }

    for (size_t j = 0; j < vectorSize->columnLength; j++){
        printf("%p - [%d]: %d\n", &vectorSize->data[j], j, vectorSize->data[j]);
    }
    printf("\n");

    return true;
}

void initializeVectorSize(VectorSize* vectorSize, unsigned int maximumCollumn){

    if(vectorSize == NULL){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("vector - address: %p\n", *vectorSize);
        return NULL;
    }

    if(maximumCollumn < 1){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("maximumCollumn - value: %d\n", maximumCollumn);
        return NULL;
    }

    *vectorSize = (VectorSize){
        .maximumCollumn = maximumCollumn,
        .columnLength = 0,
        .data = malloc(sizeof(Size)),
    };

}

bool destroyVectorSize(VectorSize* vectorSize){

    if(vectorSize == NULL){
        return false;
    }

    if(vectorSize->data != NULL){
        printf("vectorSize->data == %p\n", vectorSize->data);
        printf("vectorSize->data[0] == %i\n", vectorSize->data[0]);
        free(vectorSize->data);
        vectorSize->data = NULL;
    }
}
