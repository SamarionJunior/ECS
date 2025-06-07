#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "layer.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsLayer(VectorLayer* vectorLayer, size_t collum){

    if(vectorLayer == NULL){
        printf("\n");
        printf("vectorLayer == NULL\n");
        printf("vectorLayer - Address: %p\n", vectorLayer);
        printf("\n");
        return false;
    }
    if(vectorLayer->data == NULL){
        printf("\n");
        printf("vectorLayer->data\n");
        printf("vectorLayer - Address: %p\n", vectorLayer->data);
        printf("\n");
        return false;
    }
    if(vectorLayer->columnLength < 0){
        printf("\n");
        printf("vectorLayer->columnLength < 0\n");
        printf("vectorLayer->columnLength = %d\n", vectorLayer->columnLength);
        printf("\n");
        return false;
    }
    if(vectorLayer->maximumCollumn < 0){
        printf("\n");
        printf("vectorLayer->maximumCollumn < 0\n");
        printf("vectorLayer->maximumCollumn = %d\n", vectorLayer->maximumCollumn);
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
    if(collum > vectorLayer->columnLength){
        printf("\n");
        printf("collum > vectorLayer->columnLength\n");
        printf("collum = %d\n", collum);
        printf("vectorLayer->columnLength = %d\n", vectorLayer->columnLength);
        printf("\n");
        return false;
    }
    if(collum == vectorLayer->maximumCollumn){
        printf("\n");
        printf("collum == vectorLayer->maximumCollumn\n");
        printf("collum = %d\n", collum);
        printf("vectorLayer->maximumCollumn = %d\n", vectorLayer->maximumCollumn);
        printf("\n");
        return false;
    }

    return true;
}

bool addCellLayer(VectorLayer* vectorLayer, size_t collum, Layer data){

    if(!verifyParamsLayer(vectorLayer, collum)){
        return false;
    }

    if(vectorLayer->columnLength == vectorLayer->maximumCollumn){
        printf("\n");
        printf("vectorLayer->columnLength == vectorLayer->maximumCollumn\n");
        printf("maximumCollumn - value: %d\n", vectorLayer->maximumCollumn);
        printf("matrix->collum[row] - value: %d\n", vectorLayer->columnLength);
        printf("\n");
        return false;
    }

    // printf("collum = %d\n", collum);

    vectorLayer->columnLength++;
    Layer *tempColumn = 
        (vectorLayer->data == NULL) ?
            malloc(sizeof(Layer) * vectorLayer->columnLength) :
            realloc(vectorLayer->data, sizeof(Layer) * vectorLayer->columnLength); // verify

    // frre(DATA)
    if(tempColumn == NULL){
        vectorLayer->columnLength--;
        return false;
    }

    vectorLayer->data = tempColumn;

    for (size_t i = (vectorLayer->columnLength - 1); i > collum; i--){
        vectorLayer->data[i] = vectorLayer->data[i - 1];
    }

    vectorLayer->data[collum] = data;

    // printf("\nmatrix->collum[row] %d\n", matrix->collum[row]);
    return true;

}

bool removeCellLayer(VectorLayer* vectorLayer, size_t collum){

    if(!verifyParamsLayer(vectorLayer, collum)){
        return false;
    }

    for (size_t j = collum; j < (vectorLayer->columnLength - 1); j++){
        vectorLayer->data[j] = vectorLayer->data[j + 1];
    }

    // matrix->matrix[row][matrix->collum[row] - 1].data = NULL;
    // free(vectorLayer->data[vectorLayer->columnLength - 1]);

    vectorLayer->columnLength--;
    vectorLayer->data = realloc(vectorLayer->data, sizeof(Layer) * vectorLayer->columnLength); // verify

    return true;
}

bool setCellLayer(VectorLayer* vectorLayer, size_t collum, Layer data){

    if(!verifyParamsLayer(vectorLayer, collum)){
        return false;
    }

	// free(vectorLayer->data[collum]);

	vectorLayer->data[collum] = data;

    return true;

}

Layer* getCellLayer(VectorLayer* vectorLayer, size_t collum){

    if(!verifyParamsLayer(vectorLayer, collum)){
        return NULL;
    }

	return &(vectorLayer->data[collum]);

}

bool fullCollumnLayer(VectorLayer* vectorLayer){
    
    if(!verifyParamsLayer(vectorLayer, 0)){
        return false;
    }

	return vectorLayer->columnLength == vectorLayer->maximumCollumn ? true : false;

}

bool emptyCollumnLayer(VectorLayer* vectorLayer){
    
    if(!verifyParamsLayer(vectorLayer, 0)){
        return false;
    }

	return vectorLayer->columnLength == 0 ? true : false;

}

int lengthCollumnLayer(VectorLayer* vectorLayer){

    if(!verifyParamsLayer(vectorLayer, 0)){
        return false;
    }
    
	return vectorLayer->columnLength;

}

bool printVectorLayer(VectorLayer* vectorLayer){

    if(!verifyParamsLayer(vectorLayer, 0)){
        return false;
    }

    for (size_t j = 0; j < vectorLayer->columnLength; j++){
        printf("%p - [%d]: %d\n", &vectorLayer->data[j], j, vectorLayer->data[j]);
    }
    printf("\n");

    return true;
}

void initializeVectorLayer(VectorLayer* vectorLayer, unsigned int maximumCollumn){

    if(vectorLayer == NULL){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("vector - address: %p\n", *vectorLayer);
        return NULL;
    }

    if(maximumCollumn < 1){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("maximumCollumn - value: %d\n", maximumCollumn);
        return NULL;
    }

    *vectorLayer = (VectorLayer){
        .maximumCollumn = maximumCollumn,
        .columnLength = 0,
        .data = malloc(sizeof(Layer)),
    };

}

bool destroyVectorLayer(VectorLayer* vectorLayer){

    if(vectorLayer == NULL){
        return false;
    }

    if(vectorLayer->data != NULL){
        printf("vectorLayer->data == %p\n", vectorLayer->data);
        printf("vectorLayer->data[0] == %i\n", vectorLayer->data[0]);
        free(vectorLayer->data);
        vectorLayer->data = NULL;
    }
}
