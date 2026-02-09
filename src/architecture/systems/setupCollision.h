#ifndef SETUP_COLLISION_SYSTEMS_H_
#define SETUP_COLLISION_SYSTEMS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../entities/entities.h"
#include "../components/components.h"
#include "systems.h"

extern bool** freeSpaces;

extern const int vazio;
extern const int itIsFree;
extern const int NotFree;

void initializingFreeSpaces();
void destroyFreeSpaces();

#endif
