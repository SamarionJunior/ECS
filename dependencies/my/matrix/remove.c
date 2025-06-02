// #include "../components.h"
// #include "updateComponent.h"
// #include <SDL3/SDL_stdinc.h>
// #include "../message.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"
#include "remove.h"

int removeCell(Matrix* matrix, size_t row, size_t collum);
int removeRow(Matrix* matrix, size_t row);

int removeCell(Matrix* matrix, size_t row, size_t collum){
    if(
        !(matrix != NULL) ||
        !(matrix->row > 0 && matrix->collum[row] > 0) ||
        !(matrix->maximumRow > 0 && matrix->maximumCollum > 0 && 
            row >= 0 && collum >= 0) ||
        !(row < matrix->row && collum < matrix->collum[row]) ||
        !(row < matrix->maximumRow && collum < matrix->maximumCollum) ||
        !(matrix->row <= matrix->maximumRow)
    ){
        return false;
    }
    for (size_t j = collum; j < (matrix->collum[row] - 1); j++){
        matrix->matrix[row][j] = matrix->matrix[row][j + 1];
    }
    // matrix->matrix[row][matrix->collum[row] - 1].data = NULL;
    free(matrix->matrix[row][matrix->collum[row] - 1].data);
    matrix->collum[row]--;
    matrix->matrix[row] = realloc(matrix->matrix[row], sizeof(Data) * matrix->collum[row]); // verify
    return true;
}
int removeRow(Matrix* matrix, size_t row){
    if(
        !(matrix != NULL) ||
        !(matrix->maximumRow > 0 && matrix->maximumCollum > 0 && 
            row >= 0) ||
        !(matrix->row > 0 && matrix->collum[row] > 0) ||
        !(row < matrix->row) ||
        !(row < matrix->maximumRow) ||
        !(matrix->row <= matrix->maximumRow)
    ){
        return false;
    }
    for (size_t i = row; i < matrix->row - 1; i++){
        matrix->matrix[i] = matrix->matrix[i + 1];
    }
    free(matrix->matrix[matrix->row - 1]);
    for (size_t i = row; i < matrix->row - 1; i++){
        matrix->collum[i] = matrix->collum[i + 1];
    }
    // free(matrix->collum[matrix->row - 1]);
    for (size_t i = row; i < matrix->row - 1; i++){
        matrix->types[i] = matrix->types[i + 1];
    }
    // free(matrix->types[matrix->row - 1]);
    matrix->row--;
    matrix->matrix = realloc(matrix->matrix, sizeof(Data*) * matrix->row); // verify
    matrix->collum = realloc(matrix->collum, sizeof(int) * matrix->row);
    matrix->types = realloc(matrix->types, sizeof(unsigned int) * matrix->row);
    return true;
}
