// #include "../components.h"
// #include "updateComponent.h"
// #include <SDL3/SDL_stdinc.h>
// #include "../message.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"
#include "destroy.h"
#include "remove.h"

void destroyMatrix(Matrix* matrix);

void destroyMatrix(Matrix* matrix){
    for (size_t i = 0; i < matrix->row; i++){
        for (size_t j = 0; j < matrix->collum[i]; j++){
            removeCell(matrix, i, j);
        }
        removeRow(matrix, i);
    }
    free(matrix->matrix);

    free(matrix->collum);
    free(matrix->types);
    matrix->matrix = NULL;
    matrix->collum = NULL;
    matrix->types = NULL;
}