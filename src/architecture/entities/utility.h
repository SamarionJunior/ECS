#ifndef ENTITIESUTILITY_H_
#define ENTITIESUTILITY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../../dependencies/my/dynamicarray/array.h"

#include "entities.h"

int getId();
int setId(int idnew);
void addEntity();
void initializeEntities();
void destroyEntities();
bool removeEntity(int id);

#endif