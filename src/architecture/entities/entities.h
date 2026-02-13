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

extern Array entityArray;

#endif