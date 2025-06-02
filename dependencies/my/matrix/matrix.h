#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// typedef enum types{
//     NOTYPES,
//     TEXT,
//     NUMBER,
//     MAXIMUMTYPES
// } Types;

// typedef struct component{
//     char id;
//     void* data;
// }Component;

typedef struct data{
    void* data;
}Data;

typedef struct matrix{
    Data **matrix;
    unsigned int row;
    unsigned int *collum;
    unsigned int *types;
    unsigned int maximumRow;
    unsigned int maximumCollum;
} Matrix;

#endif