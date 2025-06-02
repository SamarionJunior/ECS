// #include "../components.h"
// #include "updateComponent.h"
// #include <SDL3/SDL_stdinc.h>
// #include "../message.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"
#include "initialize.h"

int initializeMatrix(Matrix* matrix, unsigned int maximumRow, unsigned int maximumCollum);

int initializeMatrix(Matrix* matrix, unsigned int maximumRow, unsigned int maximumCollum){

    if(
        !(matrix != NULL) ||
        !(maximumRow > 0) ||
        !(maximumCollum > 0)
    ){
        printf("initializeMatrix: Invalide Argument\n");
        printf("Matrix - Address: %p\n", matrix);
        printf("maximumRow - value: %d\n", maximumRow);
        printf("maximumCollum - value: %d\n", maximumCollum);
        return false;
    }

    matrix->row = 0;
    matrix->maximumRow = maximumRow;
    matrix->maximumCollum = maximumCollum;
    matrix->collum = NULL;
    matrix->matrix = NULL;
    matrix->types = NULL;

    return true;

}