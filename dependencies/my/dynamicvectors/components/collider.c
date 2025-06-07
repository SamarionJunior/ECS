#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "collider.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsCollider(VectorCollider* vectorCollider, size_t collum){

    if(vectorCollider == NULL){
        printf("\n");
        printf("vectorCollider == NULL\n");
        printf("vectorCollider - Address: %p\n", vectorCollider);
        printf("\n");
        return false;
    }
    if(vectorCollider->data == NULL){
        printf("\n");
        printf("vectorCollider->data\n");
        printf("vectorCollider - Address: %p\n", vectorCollider->data);
        printf("\n");
        return false;
    }
    if(vectorCollider->columnLength < 0){
        printf("\n");
        printf("vectorCollider->columnLength < 0\n");
        printf("vectorCollider->columnLength = %d\n", vectorCollider->columnLength);
        printf("\n");
        return false;
    }
    if(vectorCollider->maximumCollumn < 0){
        printf("\n");
        printf("vectorCollider->maximumCollumn < 0\n");
        printf("vectorCollider->maximumCollumn = %d\n", vectorCollider->maximumCollumn);
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
    if(collum > vectorCollider->columnLength){
        printf("\n");
        printf("collum > vectorCollider->columnLength\n");
        printf("collum = %d\n", collum);
        printf("vectorCollider->columnLength = %d\n", vectorCollider->columnLength);
        printf("\n");
        return false;
    }
    if(collum == vectorCollider->maximumCollumn){
        printf("\n");
        printf("collum == vectorCollider->maximumCollumn\n");
        printf("collum = %d\n", collum);
        printf("vectorCollider->maximumCollumn = %d\n", vectorCollider->maximumCollumn);
        printf("\n");
        return false;
    }

    return true;
}

bool addCellCollider(VectorCollider* vectorCollider, size_t collum, Collider data){

    if(!verifyParamsCollider(vectorCollider, collum)){
        return false;
    }

    if(vectorCollider->columnLength == vectorCollider->maximumCollumn){
        printf("\n");
        printf("vectorCollider->columnLength == vectorCollider->maximumCollumn\n");
        printf("maximumCollumn - value: %d\n", vectorCollider->maximumCollumn);
        printf("matrix->collum[row] - value: %d\n", vectorCollider->columnLength);
        printf("\n");
        return false;
    }

    // printf("collum = %d\n", collum);

    vectorCollider->columnLength++;
    Collider *tempColumn = 
        (vectorCollider->data == NULL) ?
            malloc(sizeof(Collider) * vectorCollider->columnLength) :
            realloc(vectorCollider->data, sizeof(Collider) * vectorCollider->columnLength); // verify

    // frre(DATA)
    if(tempColumn == NULL){
        vectorCollider->columnLength--;
        return false;
    }

    vectorCollider->data = tempColumn;

    for (size_t i = (vectorCollider->columnLength - 1); i > collum; i--){
        vectorCollider->data[i] = vectorCollider->data[i - 1];
    }

    vectorCollider->data[collum] = data;

    // printf("\nmatrix->collum[row] %d\n", matrix->collum[row]);
    return true;

}

bool removeCellCollider(VectorCollider* vectorCollider, size_t collum){

    if(!verifyParamsCollider(vectorCollider, collum)){
        return false;
    }

    for (size_t j = collum; j < (vectorCollider->columnLength - 1); j++){
        vectorCollider->data[j] = vectorCollider->data[j + 1];
    }

    // matrix->matrix[row][matrix->collum[row] - 1].data = NULL;
    // free(vectorCollider->data[vectorCollider->columnLength - 1]);

    vectorCollider->columnLength--;
    vectorCollider->data = realloc(vectorCollider->data, sizeof(Collider) * vectorCollider->columnLength); // verify

    return true;
}

bool setCellCollider(VectorCollider* vectorCollider, size_t collum, Collider data){

    if(!verifyParamsCollider(vectorCollider, collum)){
        return false;
    }

	// free(vectorCollider->data[collum]);

	vectorCollider->data[collum] = data;

    return true;

}

Collider* getCellCollider(VectorCollider* vectorCollider, size_t collum){

    if(!verifyParamsCollider(vectorCollider, collum)){
        return NULL;
    }

	return &(vectorCollider->data[collum]);

}

bool fullCollumnCollider(VectorCollider* vectorCollider){
    
    if(!verifyParamsCollider(vectorCollider, 0)){
        return false;
    }

	return vectorCollider->columnLength == vectorCollider->maximumCollumn ? true : false;

}

bool emptyCollumnCollider(VectorCollider* vectorCollider){
    
    if(!verifyParamsCollider(vectorCollider, 0)){
        return false;
    }

	return vectorCollider->columnLength == 0 ? true : false;

}

int lengthCollumnCollider(VectorCollider* vectorCollider){

    if(!verifyParamsCollider(vectorCollider, 0)){
        return false;
    }
    
	return vectorCollider->columnLength;

}

bool printVectorCollider(VectorCollider* vectorCollider){

    if(!verifyParamsCollider(vectorCollider, 0)){
        return false;
    }

    for (size_t j = 0; j < vectorCollider->columnLength; j++){
        printf("%p - [%d]: %d\n", &vectorCollider->data[j], j, vectorCollider->data[j]);
    }
    printf("\n");

    return true;
}

void initializeVectorCollider(VectorCollider* vectorCollider, unsigned int maximumCollumn){

    if(vectorCollider == NULL){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("vector - address: %p\n", *vectorCollider);
        return NULL;
    }

    if(maximumCollumn < 1){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("maximumCollumn - value: %d\n", maximumCollumn);
        return NULL;
    }

    *vectorCollider = (VectorCollider){
        .maximumCollumn = maximumCollumn,
        .columnLength = 0,
        .data = malloc(sizeof(Collider)),
    };

}

bool destroyVectorCollider(VectorCollider* vectorCollider){

    if(vectorCollider == NULL){
        return false;
    }

    if(vectorCollider->data != NULL){
        printf("vectorCollider->data == %p\n", vectorCollider->data);
        printf("vectorCollider->data[0] == %i\n", vectorCollider->data[0]);
        free(vectorCollider->data);
        vectorCollider->data = NULL;
    }
}
