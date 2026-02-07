#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct array{
    void *data;
    unsigned int sizeData;
    unsigned int arrayLength;
    unsigned int maximumArray;
} Array;

//////////////////////////////////

// extern Array array;

//////////////////////////////////

bool addArray(Array* array, size_t collum, void* data);
bool removeArray(Array* array, size_t collum);
bool setArray(Array* array, size_t collum, void* data);
void* getArray(Array* array, size_t collum);
bool fullArray(Array* array);
bool emptyArray(Array* array);
unsigned int lengthArray(Array* array);
bool initializeArray(Array** array, unsigned int maximumArray, unsigned int sizeData);
bool destroyArray(Array* array);

#endif

