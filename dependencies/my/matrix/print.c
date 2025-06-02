// #include "../components.h"
// #include "updateComponent.h"
// #include <SDL3/SDL_stdinc.h>
// #include "../message.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"
#include "print.h"

int printMatrix(Matrix matrix);

int printMatrix(Matrix matrix){
    for (size_t i = 0; i < matrix.row; i++){
        for (size_t j = 0; j < matrix.collum[i]; j++){
            printf("[%d][%d]", i, j);
            printf("%p", &matrix.matrix[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
}