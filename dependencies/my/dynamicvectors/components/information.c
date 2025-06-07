#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "information.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsInformation(VectorInformation* vectorInformation, size_t collum){

    if(vectorInformation == NULL){
        printf("\n");
        printf("vectorInformation == NULL\n");
        printf("vectorInformation - Address: %p\n", vectorInformation);
        printf("\n");
        return false;
    }
    if(vectorInformation->data == NULL){
        printf("\n");
        printf("vectorInformation->data\n");
        printf("vectorInformation - Address: %p\n", vectorInformation->data);
        printf("\n");
        return false;
    }
    if(vectorInformation->columnLength < 0){
        printf("\n");
        printf("vectorInformation->columnLength < 0\n");
        printf("vectorInformation->columnLength = %d\n", vectorInformation->columnLength);
        printf("\n");
        return false;
    }
    if(vectorInformation->maximumCollumn < 0){
        printf("\n");
        printf("vectorInformation->maximumCollumn < 0\n");
        printf("vectorInformation->maximumCollumn = %d\n", vectorInformation->maximumCollumn);
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
    if(collum > vectorInformation->columnLength){
        printf("\n");
        printf("collum > vectorInformation->columnLength\n");
        printf("collum = %d\n", collum);
        printf("vectorInformation->columnLength = %d\n", vectorInformation->columnLength);
        printf("\n");
        return false;
    }
    if(collum == vectorInformation->maximumCollumn){
        printf("\n");
        printf("collum == vectorInformation->maximumCollumn\n");
        printf("collum = %d\n", collum);
        printf("vectorInformation->maximumCollumn = %d\n", vectorInformation->maximumCollumn);
        printf("\n");
        return false;
    }

    return true;
}

bool addCellInformation(VectorInformation* vectorInformation, size_t collum, Information data){

    if(!verifyParamsInformation(vectorInformation, collum)){
        return false;
    }

    if(vectorInformation->columnLength == vectorInformation->maximumCollumn){
        printf("\n");
        printf("vectorInformation->columnLength == vectorInformation->maximumCollumn\n");
        printf("maximumCollumn - value: %d\n", vectorInformation->maximumCollumn);
        printf("matrix->collum[row] - value: %d\n", vectorInformation->columnLength);
        printf("\n");
        return false;
    }

    // printf("collum = %d\n", collum);

    vectorInformation->columnLength++;
    Information *tempColumn = 
        (vectorInformation->data == NULL) ?
            malloc(sizeof(Information) * vectorInformation->columnLength) :
            realloc(vectorInformation->data, sizeof(Information) * vectorInformation->columnLength); // verify

    // frre(DATA)
    if(tempColumn == NULL){
        vectorInformation->columnLength--;
        return false;
    }

    vectorInformation->data = tempColumn;

    for (size_t i = (vectorInformation->columnLength - 1); i > collum; i--){
        vectorInformation->data[i] = vectorInformation->data[i - 1];
    }

    vectorInformation->data[collum] = data;

    // printf("\nmatrix->collum[row] %d\n", matrix->collum[row]);
    return true;

}

bool removeCellInformation(VectorInformation* vectorInformation, size_t collum){

    if(!verifyParamsInformation(vectorInformation, collum)){
        return false;
    }

    for (size_t j = collum; j < (vectorInformation->columnLength - 1); j++){
        vectorInformation->data[j] = vectorInformation->data[j + 1];
    }

    // matrix->matrix[row][matrix->collum[row] - 1].data = NULL;
    // free(vectorInformation->data[vectorInformation->columnLength - 1]);

    vectorInformation->columnLength--;
    vectorInformation->data = realloc(vectorInformation->data, sizeof(Information) * vectorInformation->columnLength); // verify

    return true;
}

bool setCellInformation(VectorInformation* vectorInformation, size_t collum, Information data){

    if(!verifyParamsInformation(vectorInformation, collum)){
        return false;
    }

	// free(vectorInformation->data[collum]);

	vectorInformation->data[collum] = data;

    return true;

}

Information* getCellInformation(VectorInformation* vectorInformation, size_t collum){

    if(!verifyParamsInformation(vectorInformation, collum)){
        return NULL;
    }

	return &(vectorInformation->data[collum]);

}

bool fullCollumnInformation(VectorInformation* vectorInformation){
    
    if(!verifyParamsInformation(vectorInformation, 0)){
        return false;
    }

	return vectorInformation->columnLength == vectorInformation->maximumCollumn ? true : false;

}

bool emptyCollumnInformation(VectorInformation* vectorInformation){
    
    if(!verifyParamsInformation(vectorInformation, 0)){
        return false;
    }

	return vectorInformation->columnLength == 0 ? true : false;

}

int lengthCollumnInformation(VectorInformation* vectorInformation){

    if(!verifyParamsInformation(vectorInformation, 0)){
        return false;
    }
    
	return vectorInformation->columnLength;

}

bool printVectorInformation(VectorInformation* vectorInformation){

    if(!verifyParamsInformation(vectorInformation, 0)){
        return false;
    }

    for (size_t j = 0; j < vectorInformation->columnLength; j++){
        printf("%p - [%d]: %d\n", &vectorInformation->data[j], j, vectorInformation->data[j]);
    }
    printf("\n");

    return true;
}

void initializeVectorInformation(VectorInformation* vectorInformation, unsigned int maximumCollumn){

    if(vectorInformation == NULL){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("vector - address: %p\n", *vectorInformation);
        return NULL;
    }

    if(maximumCollumn < 1){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("maximumCollumn - value: %d\n", maximumCollumn);
        return NULL;
    }

    *vectorInformation = (VectorInformation){
        .maximumCollumn = maximumCollumn,
        .columnLength = 0,
        .data = malloc(sizeof(Information)),
    };

}

bool destroyVectorInformation(VectorInformation* vectorInformation){

    if(vectorInformation == NULL){
        return false;
    }

    if(vectorInformation->data != NULL){
        printf("vectorInformation->data == %p\n", vectorInformation->data);
        printf("vectorInformation->data[0] == %i\n", vectorInformation->data[0]);
        free(vectorInformation->data);
        vectorInformation->data = NULL;
    }
}
