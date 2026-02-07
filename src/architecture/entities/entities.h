#ifndef ENTITIES_H_
#define ENTITIES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../../dependencies/my/dynamicarray/array.h"

enum entities_config {
    MAX_ENTITIES = 2000
};

typedef struct entity{
    int index;
} Entity;

extern Array* entityArray;

#endif

// typedef struct entity{
//     int index;
// } Entity;

// extern int lengthEntities;

// extern int entities[MAX_ENTITIES];

// #include "../../../dependencies/my/matrix/matrix.h"
// extern Entities entities;
// #define SUBENTITIES 2
// extern Matrix entities;