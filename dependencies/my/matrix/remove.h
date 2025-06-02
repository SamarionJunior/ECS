#ifndef REMOVE_MATRIX_H_
#define REMOVE_MATRIX_H_

// #include <stdio.h>
// #include "../components.h"
// #include "updateComponent.h"
// #include <SDL3/SDL_stdinc.h>
// #include "../message.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"

int removeCell(Matrix* matrix, size_t row, size_t collum);
int removeRow(Matrix* matrix, size_t row);

#endif

