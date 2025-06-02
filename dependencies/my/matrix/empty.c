#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"
#include "empty.h"

bool fullRow(Matrix* matrix, size_t row);
bool fullMatrix(Matrix* matrix);

bool fullRow(Matrix* matrix, size_t row){
    
    if(
        !(matrix != NULL) ||
        !(matrix->row >= 0 && matrix->collum[row] >= 0) ||
        !(matrix->maximumRow > 0 && matrix->maximumCollum > 0) || 
        !(row >= 0) ||
        !(row < matrix->row) ||
        !(row < matrix->maximumRow) ||
        !(matrix->collum[row] <= matrix->maximumCollum)
    ){
        printf("\n");
        printf("fullRow: Invalide Argument\n");
        printf("Matrix - Address: %p\n", matrix);
        printf("maximumRow - value: %d\n", matrix->maximumRow);
        printf("maximumCollum - value: %d\n", matrix->maximumCollum);
        printf("row - value: %d\n", row);
        printf("matrix->row - value: %d\n", matrix->row);
        printf("matrix->collum[row] - value: %d\n", matrix->collum[row]);
        printf("\n");
        return false;
    }

	return (matrix->collum[row] == matrix->maximumCollum) ? true : false;

}
bool fullMatrix(Matrix* matrix){
    
    if(
        !(matrix != NULL) ||
        !(matrix->row >= 0) ||
        !(matrix->maximumRow > 0) ||
        !(matrix->row < matrix->maximumRow)
    ){
        printf("emptyMatrix\n");
        return false;
    }

	return (matrix->row == matrix->maximumRow) ? true : false;
    
}