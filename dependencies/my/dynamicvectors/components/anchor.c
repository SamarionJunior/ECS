#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "anchor.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsAnchor(VectorAnchor* vectorAnchor, size_t collum){

    if(vectorAnchor == NULL){
        printf("\n");
        printf("vectorAnchor == NULL\n");
        printf("vectorAnchor - Address: %p\n", vectorAnchor);
        printf("\n");
        return false;
    }
    if(vectorAnchor->data == NULL){
        printf("\n");
        printf("vectorAnchor->data\n");
        printf("vectorAnchor - Address: %p\n", vectorAnchor->data);
        printf("\n");
        return false;
    }
    if(vectorAnchor->columnLength < 0){
        printf("\n");
        printf("vectorAnchor->columnLength < 0\n");
        printf("vectorAnchor->columnLength = %d\n", vectorAnchor->columnLength);
        printf("\n");
        return false;
    }
    if(vectorAnchor->maximumCollumn < 0){
        printf("\n");
        printf("vectorAnchor->maximumCollumn < 0\n");
        printf("vectorAnchor->maximumCollumn = %d\n", vectorAnchor->maximumCollumn);
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
    if(collum > vectorAnchor->columnLength){
        printf("\n");
        printf("collum > vectorAnchor->columnLength\n");
        printf("collum = %d\n", collum);
        printf("vectorAnchor->columnLength = %d\n", vectorAnchor->columnLength);
        printf("\n");
        return false;
    }
    if(collum == vectorAnchor->maximumCollumn){
        printf("\n");
        printf("collum == vectorAnchor->maximumCollumn\n");
        printf("collum = %d\n", collum);
        printf("vectorAnchor->maximumCollumn = %d\n", vectorAnchor->maximumCollumn);
        printf("\n");
        return false;
    }

    return true;
}

bool addCellAnchor(VectorAnchor* vectorAnchor, size_t collum, Anchor data){

    if(!verifyParamsAnchor(vectorAnchor, collum)){
        return false;
    }

    if(vectorAnchor->columnLength == vectorAnchor->maximumCollumn){
        printf("\n");
        printf("vectorAnchor->columnLength == vectorAnchor->maximumCollumn\n");
        printf("maximumCollumn - value: %d\n", vectorAnchor->maximumCollumn);
        printf("matrix->collum[row] - value: %d\n", vectorAnchor->columnLength);
        printf("\n");
        return false;
    }

    // printf("collum = %d\n", collum);

    vectorAnchor->columnLength++;
    Anchor *tempColumn = 
        (vectorAnchor->data == NULL) ?
            malloc(sizeof(Anchor) * vectorAnchor->columnLength) :
            realloc(vectorAnchor->data, sizeof(Anchor) * vectorAnchor->columnLength); // verify

    // frre(DATA)
    if(tempColumn == NULL){
        vectorAnchor->columnLength--;
        return false;
    }

    vectorAnchor->data = tempColumn;

    for (size_t i = (vectorAnchor->columnLength - 1); i > collum; i--){
        vectorAnchor->data[i] = vectorAnchor->data[i - 1];
    }

    vectorAnchor->data[collum] = data;

    // printf("\nmatrix->collum[row] %d\n", matrix->collum[row]);
    return true;

}

bool removeCellAnchor(VectorAnchor* vectorAnchor, size_t collum){

    if(!verifyParamsAnchor(vectorAnchor, collum)){
        return false;
    }

    for (size_t j = collum; j < (vectorAnchor->columnLength - 1); j++){
        vectorAnchor->data[j] = vectorAnchor->data[j + 1];
    }

    // matrix->matrix[row][matrix->collum[row] - 1].data = NULL;
    // free(vectorAnchor->data[vectorAnchor->columnLength - 1]);

    vectorAnchor->columnLength--;
    vectorAnchor->data = realloc(vectorAnchor->data, sizeof(Anchor) * vectorAnchor->columnLength); // verify

    return true;
}

bool setCellAnchor(VectorAnchor* vectorAnchor, size_t collum, Anchor data){

    if(!verifyParamsAnchor(vectorAnchor, collum)){
        return false;
    }

	// free(vectorAnchor->data[collum]);

	vectorAnchor->data[collum] = data;

    return true;

}

Anchor* getCellAnchor(VectorAnchor* vectorAnchor, size_t collum){

    if(!verifyParamsAnchor(vectorAnchor, collum)){
        return NULL;
    }

	return &(vectorAnchor->data[collum]);

}

bool fullCollumnAnchor(VectorAnchor* vectorAnchor){
    
    if(!verifyParamsAnchor(vectorAnchor, 0)){
        return false;
    }

	return vectorAnchor->columnLength == vectorAnchor->maximumCollumn ? true : false;

}

bool emptyCollumnAnchor(VectorAnchor* vectorAnchor){
    
    if(!verifyParamsAnchor(vectorAnchor, 0)){
        return false;
    }

	return vectorAnchor->columnLength == 0 ? true : false;

}

int lengthCollumnAnchor(VectorAnchor* vectorAnchor){

    if(!verifyParamsAnchor(vectorAnchor, 0)){
        return false;
    }
    
	return vectorAnchor->columnLength;

}

bool printVectorAnchor(VectorAnchor* vectorAnchor){

    if(!verifyParamsAnchor(vectorAnchor, 0)){
        return false;
    }

    for (size_t j = 0; j < vectorAnchor->columnLength; j++){
        printf("%p - [%d]: %d\n", &vectorAnchor->data[j], j, vectorAnchor->data[j]);
    }
    printf("\n");

    return true;
}

void initializeVectorAnchor(VectorAnchor* vectorAnchor, unsigned int maximumCollumn){

    if(vectorAnchor == NULL){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("vector - address: %p\n", *vectorAnchor);
        return NULL;
    }

    if(maximumCollumn < 1){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("maximumCollumn - value: %d\n", maximumCollumn);
        return NULL;
    }

    *vectorAnchor = (VectorAnchor){
        .maximumCollumn = maximumCollumn,
        .columnLength = 0,
        .data = malloc(sizeof(Anchor)),
    };

}

bool destroyVectorAnchor(VectorAnchor* vectorAnchor){

    if(vectorAnchor == NULL){
        return false;
    }

    if(vectorAnchor->data != NULL){
        printf("vectorAnchor->data == %p\n", vectorAnchor->data);
        printf("vectorAnchor->data[0] == %i\n", vectorAnchor->data[0]);
        free(vectorAnchor->data);
        vectorAnchor->data = NULL;
    }
}
