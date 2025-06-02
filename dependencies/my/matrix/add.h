#ifndef ADD_MATRIX_H_
#define ADD_MATRIX_H_

// #include <stdio.h>
// #include "../components.h"
// #include "updateComponent.h"
// #include <SDL3/SDL_stdinc.h>
// #include "../message.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"

int addCell(Matrix* matrix, size_t row, size_t collum, Data data);
int addRow(Matrix* matrix, size_t row, Data* data, unsigned int type);

#endif

