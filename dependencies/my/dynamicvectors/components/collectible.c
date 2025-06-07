#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "collectible.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsCollectible(VectorCollectible* vectorCollectible, size_t collum){

    if(vectorCollectible == NULL){
        printf("\n");
        printf("vectorCollectible == NULL\n");
        printf("vectorCollectible - Address: %p\n", vectorCollectible);
        printf("\n");
        return false;
    }
    if(vectorCollectible->data == NULL){
        printf("\n");
        printf("vectorCollectible->data\n");
        printf("vectorCollectible - Address: %p\n", vectorCollectible->data);
        printf("\n");
        return false;
    }
    if(vectorCollectible->columnLength < 0){
        printf("\n");
        printf("vectorCollectible->columnLength < 0\n");
        printf("vectorCollectible->columnLength = %d\n", vectorCollectible->columnLength);
        printf("\n");
        return false;
    }
    if(vectorCollectible->maximumCollumn < 0){
        printf("\n");
        printf("vectorCollectible->maximumCollumn < 0\n");
        printf("vectorCollectible->maximumCollumn = %d\n", vectorCollectible->maximumCollumn);
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
    if(collum > vectorCollectible->columnLength){
        printf("\n");
        printf("collum > vectorCollectible->columnLength\n");
        printf("collum = %d\n", collum);
        printf("vectorCollectible->columnLength = %d\n", vectorCollectible->columnLength);
        printf("\n");
        return false;
    }
    if(collum == vectorCollectible->maximumCollumn){
        printf("\n");
        printf("collum == vectorCollectible->maximumCollumn\n");
        printf("collum = %d\n", collum);
        printf("vectorCollectible->maximumCollumn = %d\n", vectorCollectible->maximumCollumn);
        printf("\n");
        return false;
    }

    return true;
}

bool addCellCollectible(VectorCollectible* vectorCollectible, size_t collum, Collectible data){

    if(!verifyParamsCollectible(vectorCollectible, collum)){
        return false;
    }

    if(vectorCollectible->columnLength == vectorCollectible->maximumCollumn){
        printf("\n");
        printf("vectorCollectible->columnLength == vectorCollectible->maximumCollumn\n");
        printf("maximumCollumn - value: %d\n", vectorCollectible->maximumCollumn);
        printf("matrix->collum[row] - value: %d\n", vectorCollectible->columnLength);
        printf("\n");
        return false;
    }

    // printf("collum = %d\n", collum);

    vectorCollectible->columnLength++;
    Collectible *tempColumn = 
        (vectorCollectible->data == NULL) ?
            malloc(sizeof(Collectible) * vectorCollectible->columnLength) :
            realloc(vectorCollectible->data, sizeof(Collectible) * vectorCollectible->columnLength); // verify

    // frre(DATA)
    if(tempColumn == NULL){
        vectorCollectible->columnLength--;
        return false;
    }

    vectorCollectible->data = tempColumn;

    for (size_t i = (vectorCollectible->columnLength - 1); i > collum; i--){
        vectorCollectible->data[i] = vectorCollectible->data[i - 1];
    }

    vectorCollectible->data[collum] = data;

    // printf("\nmatrix->collum[row] %d\n", matrix->collum[row]);
    return true;

}

bool removeCellCollectible(VectorCollectible* vectorCollectible, size_t collum){

    if(!verifyParamsCollectible(vectorCollectible, collum)){
        return false;
    }

    for (size_t j = collum; j < (vectorCollectible->columnLength - 1); j++){
        vectorCollectible->data[j] = vectorCollectible->data[j + 1];
    }

    // matrix->matrix[row][matrix->collum[row] - 1].data = NULL;
    // free(vectorCollectible->data[vectorCollectible->columnLength - 1]);

    vectorCollectible->columnLength--;
    vectorCollectible->data = realloc(vectorCollectible->data, sizeof(Collectible) * vectorCollectible->columnLength); // verify

    return true;
}

bool setCellCollectible(VectorCollectible* vectorCollectible, size_t collum, Collectible data){

    if(!verifyParamsCollectible(vectorCollectible, collum)){
        return false;
    }

	// free(vectorCollectible->data[collum]);

	vectorCollectible->data[collum] = data;

    return true;

}

Collectible* getCellCollectible(VectorCollectible* vectorCollectible, size_t collum){

    if(!verifyParamsCollectible(vectorCollectible, collum)){
        return NULL;
    }

	return &(vectorCollectible->data[collum]);

}

bool fullCollumnCollectible(VectorCollectible* vectorCollectible){
    
    if(!verifyParamsCollectible(vectorCollectible, 0)){
        return false;
    }

	return vectorCollectible->columnLength == vectorCollectible->maximumCollumn ? true : false;

}

bool emptyCollumnCollectible(VectorCollectible* vectorCollectible){
    
    if(!verifyParamsCollectible(vectorCollectible, 0)){
        return false;
    }

	return vectorCollectible->columnLength == 0 ? true : false;

}

int lengthCollumnCollectible(VectorCollectible* vectorCollectible){

    if(!verifyParamsCollectible(vectorCollectible, 0)){
        return false;
    }
    
	return vectorCollectible->columnLength;

}

bool printVectorCollectible(VectorCollectible* vectorCollectible){

    if(!verifyParamsCollectible(vectorCollectible, 0)){
        return false;
    }

    for (size_t j = 0; j < vectorCollectible->columnLength; j++){
        printf("%p - [%d]: %d\n", &vectorCollectible->data[j], j, vectorCollectible->data[j]);
    }
    printf("\n");

    return true;
}

void initializeVectorCollectible(VectorCollectible* vectorCollectible, unsigned int maximumCollumn){

    if(vectorCollectible == NULL){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("vector - address: %p\n", *vectorCollectible);
        return NULL;
    }

    if(maximumCollumn < 1){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("maximumCollumn - value: %d\n", maximumCollumn);
        return NULL;
    }

    *vectorCollectible = (VectorCollectible){
        .maximumCollumn = maximumCollumn,
        .columnLength = 0,
        .data = malloc(sizeof(Collectible)),
    };

}

bool destroyVectorCollectible(VectorCollectible* vectorCollectible){

    if(vectorCollectible == NULL){
        return false;
    }

    if(vectorCollectible->data != NULL){
        printf("vectorCollectible->data == %p\n", vectorCollectible->data);
        printf("vectorCollectible->data[0] == %i\n", vectorCollectible->data[0]);
        free(vectorCollectible->data);
        vectorCollectible->data = NULL;
    }
}
