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
        printf("\n");
        printf("!(vector != NULL)\n");
        printf("Vector - Address: %p\n", vector);
        printf("\n");
        return false;
    }
    if(vector->data == NULL){
        printf("\n");
        printf("vector->data\n");
        printf("Vector - Address: %p\n", vector->data);
        printf("\n");
        return false;
    }
    if(vector->columnLength < 0){
        printf("\n");
        printf("vector->columnLength < 0\n");
        printf("vector->columnLength = %d\n", vector->columnLength);
        printf("\n");
        return false;
    }
    if(vector->maximumCollumn < 0){
        printf("\n");
        printf("vector->maximumCollumn < 0\n");
        printf("vector->maximumCollumn = %d\n", vector->maximumCollumn);
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
    if(collum > vector->columnLength){
        printf("\n");
        printf("collum > vector->columnLength\n");
        printf("collum = %d\n", collum);
        printf("vector->columnLength = %d\n", vector->columnLength);
        printf("\n");
        return false;
    }
    if(collum == vector->maximumCollumn){
        printf("\n");
        printf("collum == vector->maximumCollumn\n");
        printf("collum = %d\n", collum);
        printf("vector->maximumCollumn = %d\n", vector->maximumCollumn);
        printf("\n");
        return false;
    }

    return true;
}

bool addCell(Vector* vector, size_t collum, int data){

    if(!verifyParams(vector, collum)){
        return false;
    }

    if(vector->columnLength == vector->maximumCollumn){
        printf("\n");
        printf("vector->columnLength == vector->maximumCollumn\n");
        printf("maximumCollumn - value: %d\n", vector->maximumCollumn);
        printf("matrix->collum[row] - value: %d\n", vector->columnLength);
        printf("\n");
        return false;
    }

    // printf("collum = %d\n", collum);

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

int* getCell(Vector* vector, size_t collum){

    if(!verifyParams(vector, collum)){
        return NULL;
    }

	return &(vector->data[collum]);

}

bool fullCollumn(Vector* vector){
    
    if(!verifyParams(vector, 0)){
        return false;
    }

	return vector->columnLength == vector->maximumCollumn ? true : false;

}

bool emptyCollumn(Vector* vector){
    
    if(!verifyParams(vector, 0)){
        return false;
    }

	return vector->columnLength == 0 ? true : false;

}

int lengthCollumn(Vector* vector){

    if(!verifyParams(vector, 0)){
        return false;
    }
    
	return vector->columnLength;

}

bool printVector(Vector *vector){

    if(!verifyParams(vector, 0)){
        return false;
    }

    for (size_t j = 0; j < vector->columnLength; j++){
        printf("%p - [%d]: %d\n", &vector->data[j], j, vector->data[j]);
    }
    printf("\n");

    return true;
}

void initializeVector(Vector *vector, unsigned int maximumCollumn){

    if(vector == NULL){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("vector - address: %p\n", *vector);
        return NULL;
    }

    if(maximumCollumn < 1){
        printf("maximumCollumn < 0\n");
        printf("initializeMatrix: Invalide Argument\n");
        printf("maximumCollumn - value: %d\n", maximumCollumn);
        return NULL;
    }

    *vector = (Vector){
        .maximumCollumn = maximumCollumn,
        .columnLength = 0,
        .data = malloc(sizeof(int)),
    };

}

bool destroyVector(Vector* vector){

    if(vector == NULL){
        return false;
    }

    if(vector->data != NULL){
        printf("vector->data == %p\n", vector->data);
        printf("vector->data[0] == %i\n", vector->data[0]);
        free(vector->data);
        vector->data = NULL;
    }
}

int main(int argc, char const *argv[]){
    Vector vector;

    printf("\n1: %d\n", vector.maximumCollumn);
    printf("1: %d\n", vector.columnLength);
    printf("1: %p\n\n", vector.data);

    initializeVector(&vector, 10);

    printf("\n2: %d\n", vector.maximumCollumn);
    printf("2: %d\n", vector.columnLength);
    printf("2: %p\n\n", vector.data);

    for(size_t i = 0; i < (vector.maximumCollumn);i++){
        addCell(&vector, vector.columnLength, i);
    }

    printf("\n3: %d\n", vector.maximumCollumn);
    printf("3: %d\n", vector.columnLength);
    printf("3: %p\n\n", vector.data);
    
    printVector(&vector);

    printf("\n4: %d\n", vector.maximumCollumn);
    printf("4: %d\n", vector.columnLength);
    printf("4: %p\n\n", vector.data);

    // for(size_t i = 0; i < 1;i++){
    //     removeCell(&vector, vector.columnLength - 1);
    // }

    printf("\n\nlength = %d\n\n", lengthCollumn(&vector));
    printf("\n\nempty = %d\n\n", emptyCollumn(&vector));
    printf("\n\nfull = %d\n\n", fullCollumn(&vector));
    printf("\n\nset = %d\n\n", setCell(&vector, 5, 95));
    int *in = getCell(&vector, 5);
    if(in != NULL){
        printf("\n\nget = %d\n\n", *in);
    }
    printf("\n\nset = %d\n\n", setCell(&vector, 9, 90));


    printf("\n5: %d\n", vector.maximumCollumn);
    printf("5: %d\n", vector.columnLength);
    printf("5: %p\n\n", vector.data);
    
    printVector(&vector);

    printf("\n6: %d\n", vector.maximumCollumn);
    printf("6: %d\n", vector.columnLength);
    printf("6: %p\n\n", vector.data);
    
    destroyVector(&vector);

    printf("\n7: %d\n", vector.maximumCollumn);
    printf("7: %d\n", vector.columnLength);
    printf("7: %p\n\n", vector.data);

    return 0;
}