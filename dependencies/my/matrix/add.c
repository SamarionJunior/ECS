// #include "../components.h"
// #include "updateComponent.h"
// #include <SDL3/SDL_stdinc.h>
// #include "../message.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"
#include "add.h"

int addCell(Matrix* matrix, size_t row, size_t collum, Data data);
int addRow(Matrix* matrix, size_t row, Data* data, unsigned int type);

int addCell(Matrix* matrix, size_t row, size_t collum, Data data){

    if(!(matrix != NULL)){
        printf("!(matrix != NULL)\n");
        printf("Matrix - Address: %p\n", matrix);
        printf("\n");
        return false;
    }
    if(!(matrix->row >= 0 && matrix->collum[row] >= 0)){
        printf("!(matrix->row >= 0 && matrix->collum[row] >= 0)\n");
        printf("matrix->row - value: %d\n", matrix->row);
        printf("matrix->collum[row] - value: %d\n", matrix->collum[row]);
        printf("\n");
        return false;
    }
    if(!(matrix->maximumRow > 0 && matrix->maximumCollum > 0)){
        printf("!(matrix->maximumRow > 0 && matrix->maximumCollum > 0)\n");
        printf("maximumRow - value: %d\n", matrix->maximumRow);
        printf("maximumCollum - value: %d\n", matrix->maximumCollum);
        printf("\n");
        return false;
    }
    if(!(row >= 0 && collum >= 0)){
        printf("!(row >= 0 && collum >= 0)\n");
        printf("row - value: %d\n", row);
        printf("collum - value: %d\n", collum);
        printf("\n");
        return false;
    }
    if(!(row < matrix->row && collum <= matrix->collum[row])){
        printf("!(row < matrix->row && collum <= matrix->collum[row])\n");
        printf("row - value: %d\n", row);
        printf("collum - value: %d\n", collum);
        printf("matrix->row - value: %d\n", matrix->row);
        printf("matrix->collum[row] - value: %d\n", matrix->collum[row]);
        printf("\n");
        return false;
    }
    if(!(row < matrix->maximumRow && collum < matrix->maximumCollum)){
        printf("!(row < matrix->maximumRow && collum < matrix->maximumCollum)\n");
        printf("maximumRow - value: %d\n", matrix->maximumRow);
        printf("maximumCollum - value: %d\n", matrix->maximumCollum);
        printf("row - value: %d\n", row);
        printf("collum - value: %d\n", collum);
        printf("\n");
        return false;
    }
    if(!(matrix->collum[row] < matrix->maximumCollum)){
        printf("!(matrix->collum[row] < matrix->maximumCollum)\n");
        printf("maximumCollum - value: %d\n", matrix->maximumCollum);
        printf("matrix->collum[row] - value: %d\n", matrix->collum[row]);
        printf("\n");
        return false;
    }
    
    if(
        !(matrix != NULL) ||
        !(matrix->row >= 0 && matrix->collum[row] >= 0) ||
        !(matrix->maximumRow > 0 && matrix->maximumCollum > 0) || 
        !(row >= 0 && collum >= 0) ||
        !(row < matrix->row && collum <= matrix->collum[row]) ||
        !(row < matrix->maximumRow && collum < matrix->maximumCollum) ||
        !(matrix->collum[row] < matrix->maximumCollum)
    ){
        printf("\n");
        printf("createMatrix: Invalide Argument\n");
        printf("Matrix - Address: %p\n", matrix);
        printf("maximumRow - value: %d\n", matrix->maximumRow);
        printf("maximumCollum - value: %d\n", matrix->maximumCollum);
        printf("row - value: %d\n", row);
        printf("collum - value: %d\n", collum);
        printf("matrix->row - value: %d\n", matrix->row);
        printf("matrix->collum[row] - value: %d\n", matrix->collum[row]);
        printf("\n");
        return false;
    }
    matrix->collum[row]++;
    Data *tempRow = 
        (matrix->matrix == NULL) ?
            malloc(sizeof(Data) * matrix->collum[row]) :
            realloc(matrix->matrix[row], sizeof(Data) * matrix->collum[row]); // verify
    // frre(DATA)
    if(tempRow == NULL){
        matrix->collum[row]++;
        return false;
    }
    matrix->matrix[row] = tempRow;
    for (size_t i = (matrix->collum[row] - 1); i > collum; i--){
        matrix->matrix[row][i] = matrix->matrix[row][i - 1];
    }
    matrix->matrix[row][collum] = data;
    // printf("\nmatrix->collum[row] %d\n", matrix->collum[row]);
    return true;

}
int addRow(Matrix* matrix, size_t row, Data* data, unsigned int type){
    
    if(
        !(matrix != NULL) ||
        !(matrix->row >= 0) ||
        !(matrix->maximumRow > 0 && matrix->maximumCollum > 0 && 
            row >= 0) ||
        !(row <= matrix->row) ||
        !(row < matrix->maximumRow) ||
        !(matrix->row < matrix->maximumRow)
    ){
        printf("createMatrix\n");
        return false;
    }

    matrix->row++;

    Data **tempMatrix = 
        (matrix->matrix == NULL) ?
            malloc(sizeof(Data*) * matrix->row) :
            realloc(matrix->matrix, sizeof(Data*) * matrix->row); // verify
    if(tempMatrix == NULL){
        matrix->row--;
        return false;
    }
    matrix->matrix = tempMatrix;
    for (size_t i = (matrix->row - 1); i > row; i--){
        matrix->matrix[i] = matrix->matrix[i - 1];
    }
    matrix->matrix[row] = data;

    int *tempCollum = 
        (matrix->collum == NULL) ?
            malloc(sizeof(int) * matrix->row) :
            realloc(matrix->collum, sizeof(int) * matrix->row);
    if(tempCollum == NULL){
        matrix->row--;
        return false;
    }
    matrix->collum = tempCollum;
    for (size_t i = (matrix->row - 1); i > row; i--){
        matrix->collum[i] = matrix->collum[i - 1];
    }
    matrix->collum[row] = 0;

    int *tempTypes = 
        (matrix->types == NULL) ?
            malloc(sizeof(unsigned int) * matrix->row) :
            realloc(matrix->types, sizeof(unsigned int) * matrix->row);
    if(tempTypes == NULL){
        matrix->row--;
        return false;
    }
    matrix->types = tempTypes;
    for (size_t i = (matrix->row - 1); i > row; i--){
        matrix->types[i] = matrix->types[i - 1];
    }
    matrix->types[row] = 0;

    return true;
    
}