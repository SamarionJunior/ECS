#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "../../../../src/architecture/entities/entities.h"

bool verifyParamsEntity(VectorEntity* vectorEntity, size_t collum){

    if(vectorEntity == NULL){
        printf("\n");
        printf("vectorEntity == NULL\n");
        printf("vectorEntity - Address: %p\n", vectorEntity);
        printf("\n");
        return false;
    }
    if(vectorEntity->data == NULL){
        printf("\n");
        printf("vectorEntity->data\n");
        printf("vectorEntity - Address: %p\n", vectorEntity->data);
        printf("\n");
        return false;
    }
    if(vectorEntity->columnLength < 0){
        printf("\n");
        printf("vectorEntity->columnLength < 0\n");
        printf("vectorEntity->columnLength = %d\n", vectorEntity->columnLength);
        printf("\n");
        return false;
    }
    if(vectorEntity->maximumCollumn < 0){
        printf("\n");
        printf("vectorEntity->maximumCollumn < 0\n");
        printf("vectorEntity->maximumCollumn = %d\n", vectorEntity->maximumCollumn);
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
    if(collum > vectorEntity->columnLength){
        printf("\n");
        printf("collum > vectorEntity->columnLength\n");
        printf("collum = %d\n", collum);
        printf("vectorEntity->columnLength = %d\n", vectorEntity->columnLength);
        printf("\n");
        return false;
    }
    if(collum == vectorEntity->maximumCollumn){
        printf("\n");
        printf("collum == vectorEntity->maximumCollumn\n");
        printf("collum = %d\n", collum);
        printf("vectorEntity->maximumCollumn = %d\n", vectorEntity->maximumCollumn);
        printf("\n");
        return false;
    }

    return true;
}

bool addCellEntity(VectorEntity* vectorEntity, size_t collum, Entity data){

    if(!verifyParamsEntity(vectorEntity, collum)){
        return false;
    }

    if(vectorEntity->columnLength == vectorEntity->maximumCollumn){
        printf("\n");
        printf("vectorEntity->columnLength == vectorEntity->maximumCollumn\n");
        printf("maximumCollumn - value: %d\n", vectorEntity->maximumCollumn);
        printf("matrix->collum[row] - value: %d\n", vectorEntity->columnLength);
        printf("\n");
        return false;
    }

    // printf("collum = %d\n", collum);

    vectorEntity->columnLength++;
    Entity *tempColumn = 
        (vectorEntity->data == NULL) ?
            malloc(sizeof(Entity) * vectorEntity->columnLength) :
            realloc(vectorEntity->data, sizeof(Entity) * vectorEntity->columnLength); // verify

    // frre(DATA)
    if(tempColumn == NULL){
        vectorEntity->columnLength--;
        return false;
    }

    vectorEntity->data = tempColumn;

    for (size_t i = (vectorEntity->columnLength - 1); i > collum; i--){
        vectorEntity->data[i] = vectorEntity->data[i - 1];
    }

    vectorEntity->data[collum] = data;

    // printf("\nmatrix->collum[row] %d\n", matrix->collum[row]);
    return true;

}

bool removeCellEntity(VectorEntity* vectorEntity, size_t collum){

    if(!verifyParamsEntity(vectorEntity, collum)){
        return false;
    }

    for (size_t j = collum; j < (vectorEntity->columnLength - 1); j++){
        vectorEntity->data[j] = vectorEntity->data[j + 1];
    }

    // matrix->matrix[row][matrix->collum[row] - 1].data = NULL;
    // free(vectorEntity->data[vectorEntity->columnLength - 1]);

    vectorEntity->columnLength--;
    vectorEntity->data = realloc(vectorEntity->data, sizeof(Entity) * vectorEntity->columnLength); // verify

    return true;
}

bool setCellEntity(VectorEntity* vectorEntity, size_t collum, Entity data){

    if(!verifyParamsEntity(vectorEntity, collum)){
        return false;
    }

	// free(vectorEntity->data[collum]);

	vectorEntity->data[collum] = data;

    return true;

}

Entity* getCellEntity(VectorEntity* vectorEntity, size_t collum){

    if(!verifyParamsEntity(vectorEntity, collum)){
        return NULL;
    }
    // printf("\n%d\n", collum);

	return &(vectorEntity->data[collum]);

}

bool fullCollumnEntity(VectorEntity* vectorEntity){
    
    if(!verifyParamsEntity(vectorEntity, 0)){
        return false;
    }

	return vectorEntity->columnLength == vectorEntity->maximumCollumn ? true : false;

}

bool emptyCollumnEntity(VectorEntity* vectorEntity){
    
    if(!verifyParamsEntity(vectorEntity, 0)){
        return false;
    }

	return vectorEntity->columnLength == 0 ? true : false;

}

int lengthCollumnEntity(VectorEntity* vectorEntity){

    if(!verifyParamsEntity(vectorEntity, 0)){
        return false;
    }
    
	return vectorEntity->columnLength;

}

bool printVectorEntity(VectorEntity* vectorEntity){

    if(!verifyParamsEntity(vectorEntity, 0)){
        return false;
    }

    for (size_t j = 0; j < vectorEntity->columnLength; j++){
        printf("%p - [%d]: %d\n", &vectorEntity->data[j].index, j, vectorEntity->data[j].index);
    }
    printf("\n");

    return true;
}

void initializeVectorEntity(VectorEntity* vectorEntity, unsigned int maximumCollumn){

    if(vectorEntity == NULL){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("vector - address: %p\n", *vectorEntity);
        return NULL;
    }

    if(maximumCollumn < 1){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("maximumCollumn - value: %d\n", maximumCollumn);
        return NULL;
    }

    *vectorEntity = (VectorEntity){
        .maximumCollumn = maximumCollumn,
        .columnLength = 0,
        .data = malloc(sizeof(Entity)),
    };

}

bool destroyVectorEntity(VectorEntity* vectorEntity){

    if(vectorEntity == NULL){
        return false;
    }

    if(vectorEntity->data != NULL){
        printf("vectorEntity->data == %p\n", vectorEntity->data);
        printf("vectorEntity->data[0] == %i\n", vectorEntity->data[0]);
        free(vectorEntity->data);
        vectorEntity->data = NULL;
    }
}
