#ifndef COLLISION_SYSTEMS_H_
#define COLLISION_SYSTEMS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../entities/entities.h"
#include "../components/components.h"
#include "systems.h"

// void collision();
int isItColliding(float xA, float yA, float wA, float hA, float xB, float yB, float wB, float hB);
int isTheSameIndex(Position entityA, Position entityB);
void initializeCollisionVariables(Position entity, Size size, float* x, float* y, float* w, float* h);
bool *collisionBetween(Position *positionA, Size *sizeA);

#endif
