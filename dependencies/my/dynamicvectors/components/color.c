#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "color.h"

bool verifyParamsColor(VectorColor* vectorColor, size_t collum){

    if(vectorColor == NULL){
        printf("\n");
        printf("vectorColor == NULL\n");
        printf("vectorColor - Address: %p\n", vectorColor);
        printf("\n");
        return false;
    }
    if(vectorColor->data == NULL){
        printf("\n");
        printf("vectorColor->data\n");
        printf("vectorColor - Address: %p\n", vectorColor->data);
        printf("\n");
        return false;
    }
    if(vectorColor->columnLength < 0){
        printf("\n");
        printf("vectorColor->columnLength < 0\n");
        printf("vectorColor->columnLength = %d\n", vectorColor->columnLength);
        printf("\n");
        return false;
    }
    if(vectorColor->maximumCollumn < 0){
        printf("\n");
        printf("vectorColor->maximumCollumn < 0\n");
        printf("vectorColor->maximumCollumn = %d\n", vectorColor->maximumCollumn);
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
    if(collum > vectorColor->columnLength){
        printf("\n");
        printf("collum > vectorColor->columnLength\n");
        printf("collum = %d\n", collum);
        printf("vectorColor->columnLength = %d\n", vectorColor->columnLength);
        printf("\n");
        return false;
    }
    if(collum == vectorColor->maximumCollumn){
        printf("\n");
        printf("collum == vectorColor->maximumCollumn\n");
        printf("collum = %d\n", collum);
        printf("vectorColor->maximumCollumn = %d\n", vectorColor->maximumCollumn);
        printf("\n");
        return false;
    }

    return true;
}

bool addCellColor(VectorColor* vectorColor, size_t collum, Color data){

    if(!verifyParamsColor(vectorColor, collum)){
        return false;
    }

    if(vectorColor->columnLength == vectorColor->maximumCollumn){
        printf("\n");
        printf("vectorColor->columnLength == vectorColor->maximumCollumn\n");
        printf("maximumCollumn - value: %d\n", vectorColor->maximumCollumn);
        printf("matrix->collum[row] - value: %d\n", vectorColor->columnLength);
        printf("\n");
        return false;
    }

    // printf("collum = %d\n", collum);

    vectorColor->columnLength++;
    Color *tempColumn = 
        (vectorColor->data == NULL) ?
            malloc(sizeof(Color) * vectorColor->columnLength) :
            realloc(vectorColor->data, sizeof(Color) * vectorColor->columnLength); // verify

    // frre(DATA)
    if(tempColumn == NULL){
        vectorColor->columnLength--;
        return false;
    }

    vectorColor->data = tempColumn;

    for (size_t i = (vectorColor->columnLength - 1); i > collum; i--){
        vectorColor->data[i] = vectorColor->data[i - 1];
    }

    vectorColor->data[collum] = data;

    // printf("\nmatrix->collum[row] %d\n", matrix->collum[row]);
    return true;

}

bool removeCellColor(VectorColor* vectorColor, size_t collum){

    if(!verifyParamsColor(vectorColor, collum)){
        return false;
    }

    for (size_t j = collum; j < (vectorColor->columnLength - 1); j++){
        vectorColor->data[j] = vectorColor->data[j + 1];
    }

    // matrix->matrix[row][matrix->collum[row] - 1].data = NULL;
    // free(vectorColor->data[vectorColor->columnLength - 1]);

    vectorColor->columnLength--;
    vectorColor->data = realloc(vectorColor->data, sizeof(Color) * vectorColor->columnLength); // verify

    return true;
}

bool setCellColor(VectorColor* vectorColor, size_t collum, Color data){

    if(!verifyParamsColor(vectorColor, collum)){
        return false;
    }

	// free(vectorColor->data[collum]);

	vectorColor->data[collum] = data;

    return true;

}

int* getCellColor(VectorColor* vectorColor, size_t collum){

    if(!verifyParamsColor(vectorColor, collum)){
        return NULL;
    }

	return &(vectorColor->data[collum]);

}

bool fullCollumnColor(VectorColor* vectorColor){
    
    if(!verifyParamsColor(vectorColor, 0)){
        return false;
    }

	return vectorColor->columnLength == vectorColor->maximumCollumn ? true : false;

}

bool emptyCollumnColor(VectorColor* vectorColor){
    
    if(!verifyParamsColor(vectorColor, 0)){
        return false;
    }

	return vectorColor->columnLength == 0 ? true : false;

}

int lengthCollumnColor(VectorColor* vectorColor){

    if(!verifyParamsColor(vectorColor, 0)){
        return false;
    }
    
	return vectorColor->columnLength;

}

bool printVectorColor(VectorColor* vectorColor){

    if(!verifyParamsColor(vectorColor, 0)){
        return false;
    }

    for (size_t j = 0; j < vectorColor->columnLength; j++){
        printf("%p - [%d]: %d\n", &vectorColor->data[j], j, vectorColor->data[j]);
    }
    printf("\n");

    return true;
}

void initializeVectorColor(VectorColor* vectorColor, unsigned int maximumCollumn){

    if(vectorColor == NULL){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("vector - address: %p\n", *vectorColor);
        return NULL;
    }

    if(maximumCollumn < 1){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("maximumCollumn - value: %d\n", maximumCollumn);
        return NULL;
    }

    *vectorColor = (VectorColor){
        .maximumCollumn = maximumCollumn,
        .columnLength = 0,
        .data = malloc(sizeof(Color)),
    };

}

bool destroyVectorColor(VectorColor* vectorColor){

    if(vectorColor == NULL){
        return false;
    }

    if(vectorColor->data != NULL){
        printf("vectorColor->data == %p\n", vectorColor->data);
        printf("vectorColor->data[0] == %i\n", vectorColor->data[0]);
        free(vectorColor->data);
        vectorColor->data = NULL;
    }
}
