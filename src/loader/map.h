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

extern Array* map;

void loadMap();
void destroyMap(Array *auxiliarymap);

#endif