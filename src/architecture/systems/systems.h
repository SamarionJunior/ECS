#ifndef SYSTEMS_H_
#define SYSTEMS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../entities/entities.h"
#include "../components/components.h"
#include "../../../dependencies/my/matrix/matrix.h"

typedef enum{
	GRAVITY,
	COLLISION,
	LAYERS,
	MOVE,
	SCORE
} TypesOfSystems;

typedef struct ComponentsForGravity{
	Information *information;
	Position *position;
	Direction *direction; 
	Velocity *velocity;
	Acceleration *acceleration;
	Collider *collider;
}ComponentsForGravity;

typedef struct ComponentsForCollision{
	Information *information;
	Position *position;
	Direction *direction; 
	Velocity *velocity;
	Acceleration *acceleration;
	Size *size;
	Collider *collider;
}ComponentsForCollision;

typedef struct ComponentsForLayer{
	Information *information;
	Position *position;
	Size *size;
	Color *color;
	Layer *layer;
}ComponentsForLayer;

typedef struct ComponentsForMove{
	Information *information;
	Position *position;
	Direction *direction; 
	Velocity *velocity;
	Acceleration *acceleration;
	Size *size;
	Collider *collider;
}ComponentsForMove;

typedef struct ComponentsForScore{
	Information *information;
	Position *position;
	Direction *direction; 
	Velocity *velocity;
	Acceleration *acceleration;
	Size *size;
	Collider *collider;
}ComponentsForScore;

// typedef enum {
// 	NOSYSTEMS = -1,
// 	GRAVITY,
// 	Collider
// } SYSTEMS;

#define MAX_SYSTEMS 4

// extern int lengthSystems;

// extern int systems[MAX_SYSTEMS];
extern char *namesOfSystems[MAX_SYSTEMS];

extern Matrix componentsForGravity;
extern Matrix componentsForCollision;
extern Matrix componentsForLayer;
extern Matrix componentsForMove;
extern Matrix componentsForScore;

#define SUBSYSTEMS 2

void initializeSystems();
bool addSystem(Matrix *componentsForSystem, size_t row, size_t collum, Data data);
void *getCompontFromSystem(Matrix *componentsForSystem, size_t scene, size_t index);
void destroySystem();

#endif