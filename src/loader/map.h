#ifndef MAP_H_
#define MAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../architecture/components/components.h"

#include "../architecture/entities/entities.h"
#include "../architecture/systems/systems.h"

#include "../constants.h"

// #include "../../dependencies/mycustom/myjson.h"

#include "../../dependencies/my/dynamicarray/array.h"
#include "../../dependencies/my/dynamicmatrix/matrix.h"

extern Matrix map;

void loadMap();
void destroyMap();

#endif