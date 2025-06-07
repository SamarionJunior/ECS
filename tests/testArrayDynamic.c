#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vector{
    int *data;
    unsigned int columnLength;
    unsigned int maximumCollumn;
} Vector;

bool verifyParams(Vector* vector, size_t collum){

    if(vector == NULL){
        printf("!(vector != NULL)\n");
        printf("Matrix - Address: %p\n\n", vector);
        return false;
    }
    if(!(vector->columnLength >= 0)){
        printf("!(vector->columnLength >= 0)\n");
        printf("matrix->collum[row] - value: %d\n\n", vector->columnLength);
        return false;
    }
    if(!(vector->maximumCollumn > 0)){
        printf("!(vector->maximumCollumn > 0)\n");
        printf("maximumCollumn - value: %d\n\n", vector->maximumCollumn);
        return false;
    }
    if(!(collum >= 0)){
        printf("!(collum >= 0)\n");
        printf("collum - value: %d\n\n", collum);
        return false;
    }
    if(!(collum <= vector->columnLength)){
        printf("!(collum <= vector->columnLength)\n");
        printf("collum - value: %d\n", collum);
        printf("matrix->collum[row] - value: %d\n\n", vector->columnLength);
        return false;
    }
    if(!(collum < vector->maximumCollumn)){
        printf("!(collum < vector->maximumCollumn)\n");
        printf("maximumCollumn - value: %d\n", vector->maximumCollumn);
        printf("collum - value: %d\n\n", collum);
        return false;
    }
    if(!(vector->columnLength < vector->maximumCollumn)){
        printf("!(vector->columnLength < vector->maximumCollumn)\n");
        printf("maximumCollumn - value: %d\n", vector->maximumCollumn);
        printf("matrix->collum[row] - value: %d\n\n", vector->columnLength);
        return false;
    }

    return true;
}

bool addCell(Vector* vector, size_t collum, int data){

    if(!verifyParams(vector, collum)){
        return false;
    }

    vector->columnLength++;
    int *tempColumn = 
        (vector->data == NULL) ?
            malloc(sizeof(int) * vector->columnLength) :
            realloc(vector->data, sizeof(int) * vector->columnLength); // verify

    // frre(DATA)
    if(tempColumn == NULL){
        vector->columnLength--;
        return false;
    }

    vector->data = tempColumn;

    for (size_t i = (vector->columnLength - 1); i > collum; i--){
        vector->data[i] = vector->data[i - 1];
    }

    vector->data[collum] = data;

    // printf("\nmatrix->collum[row] %d\n", matrix->collum[row]);
    return true;

}

bool removeCell(Vector* vector, size_t collum){

    if(!verifyParams(vector, collum)){
        return false;
    }

    for (size_t j = collum; j < (vector->columnLength - 1); j++){
        vector->data[j] = vector->data[j + 1];
    }

    // matrix->matrix[row][matrix->collum[row] - 1].data = NULL;
    // free(vector->data[vector->columnLength - 1]);

    vector->columnLength--;
    vector->data = realloc(vector->data, sizeof(int) * vector->columnLength); // verify

    return true;
}

bool setCell(Vector *vector, size_t collum, int data){

    if(!verifyParams(vector, collum)){
        return false;
    }

	// free(vector->data[collum]);

	vector->data[collum] = data;

    return true;

}

int getCell(Vector* vector, size_t collum){

    if(!verifyParams(vector, collum)){
        return false;
    }

	return vector->data[collum];

}

bool fullCollumn(Vector* vector){
    
    if(!verifyParams(vector, 0)){
        return false;
    }

	return (vector->data >= vector->maximumCollumn) ? true : false;

}

bool emptyCollumn(Vector* vector){
    
    if(!verifyParams(vector, 0)){
        return false;
    }

	return !(vector->data > 0) ? true : false;

}

int lengthCollumn(Vector* vector){

    if(!verifyParams(vector, 0)){
        return false;
    }
    
	return vector->columnLength;

}

bool printMatrix(Vector *vector){

    if(!verifyParams(vector, 0)){
        return false;
    }

    for (size_t j = 0; j < vector->columnLength; j++){
        printf("%p - [%d]: %d\n", &vector->data[j], j, vector->data[j]);
    }
    printf("\n");

    return true;
}

// Vector* initializeVector(unsigned int maximumCollumn){

//     if(maximumCollumn < 1){
//         printf("maximumCollumn < 0\n");
//         printf("initializeMatrix: Invalide Argument\n");
//         printf("maximumCollumn - value: %d\n", maximumCollumn);
//         return NULL;
//     }

//     Vector *vector = malloc(sizeof(Vector) * 1);
//     // vector = &(Vector){
//     //     .maximumCollumn = maximumCollumn,
//     //     .columnLength = 0,
//     //     .data = NULL,
//     // };

//     vector->maximumCollumn = maximumCollumn;
//     vector->columnLength = 0;
//     // vector->data = malloc(sizeof(int) * vector->columnLength);
//     vector->data = NULL;

//     printf("%p\n", vector);

//     return vector;

// }

void initializeVector(Vector **vector, unsigned int maximumCollumn){

    // if(maximumCollumn < 1){
    //     printf("maximumCollumn < 0\n");
    //     printf("initializeMatrix: Invalide Argument\n");
    //     printf("maximumCollumn - value: %d\n", maximumCollumn);
    //     return NULL;
    // }

    // Vector *vector = malloc(sizeof(Vector) * 1);
    **vector = (Vector){
        .maximumCollumn = maximumCollumn,
        .columnLength = 0,
        .data = NULL,
    };

    // vector->maximumCollumn = maximumCollumn;
    // vector->columnLength = 0;
    // // vector->data = malloc(sizeof(int) * vector->columnLength);
    // vector->data = NULL;

    // printf("%p\n", vector);

    // return vector;

}

bool destroyVector(Vector* vector){

    // for (size_t j = 0; j < vector->columnLength; j++){
    //     removeCell(vector, i, j);
    // }

    if(vector == NULL){
        return false;
    }

    if(vector->data == NULL){
        return false;
    }

    free(vector->data);

    // vector->data = NULL;
    // vector->columnLength = NULL;
    // vector->maximumCollumn = NULL;

    free(vector);

    vector = NULL;
}

int main(int argc, char const *argv[]){
    Vector *vector = malloc(sizeof(Vector) * 1);

    printf("%p\n", vector);
    printf("%d\n", vector->maximumCollumn);

    initializeVector(&vector, 10);

    printf("%p\n", vector);
    printf("%d\n", vector->maximumCollumn);
    
    destroyVector(vector);

    printf("%p\n", vector);
    printf("%d\n", vector->maximumCollumn);

    // printf("%p\n", vector);

    // printMatrix(vector);

    return 0;
}