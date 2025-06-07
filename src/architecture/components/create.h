#ifndef CREATE_COMPONENT_H_
#define CREATE_COMPONENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "components.h"

Information createInformation(int id, char *name, unsigned int lengthName);
Position createPosition(int id, float x, float y, float oldX, float oldY);
Direction createDirection(int id, float x, float y);
Velocity createVelocity(int id, float x, float y);
Acceleration createAcceleration(int id, float x, float y);
Size createSize(int id, float width, float height);
Color createColor(int id, int red, int green, int blue, int alpha);
Collider createCollider(int id, int isItColliding, int *direction, int isStatic);
Layer createLayer(int id, int number);

Player createPlayer(int id);
Collectible createCollectible(int id);

#endif

