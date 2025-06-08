#ifndef GET_COMPONENT_H_
#define GET_COMPONENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "components.h"

Information* getInformationById(int id, int* count);
Position* getPositionById(int id, int* count);
Size* getSizeById(int id, int* count);
Color* getColorById(int id, int* count);
Collider* getColliderById(int id, int* count);
Layer* getLayerById(int id, int* count);

Player* getPlayerById(int id, int* count);

Collectible* getCollectibleById(int id, int* count);

// "¨"* get"¨"(int id, int* count);

#endif

