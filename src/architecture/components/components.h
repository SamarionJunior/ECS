#ifndef COMPONENTS_H_
#define COMPONENTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL3/SDL_stdinc.h>
#include "../entities/entities.h"

// #include "../../../dependencies/my/matrix/matrix.h"

// #include "dynamicvectors/vector.h"

typedef enum {
	TOP,
	RIGHT,
	BOTTOM,
	LEFT,
	TOTALCOORDENATE
}
// Direction
Coordenate;

typedef enum{
	INFORMATION,
	POSITION,
	DIRECTION,
	VELOCITY,
	ACCELERATION,
	SIZE,
	COLOR,
	COLLIDER,
	LAYER,
	PLAYER,
	COLLECTIBLE,
	TOTALCOMPONENTS
} TypesOfComponents;

/// SUB STRUCT ///

typedef struct Vector2{
	float x;
	float y;
}Vector2;

typedef struct Vector3{
	float x;
	float y;
	float z;
}Vector3;

typedef struct Vector4{
	float x;
	float y;
	float z;
	float w;
}Vector4;

//////////////////////////

typedef struct Information{
	int id;
	char *name;
	unsigned int lengthName;
} Information;

typedef struct Position {
	int id;
	Vector2 current2;
	Vector2 old2;
} Position;

typedef struct Direction{
	int id;
	Vector2 vector2;
}Direction;

typedef struct Velocity{
	int id;
	Vector2 vector2;
}Velocity;

typedef struct Acceleration{
	int id;
	Vector2 vector2;
}Acceleration;

typedef struct Size{
	int id;
	Vector2 vector2;
} Size;

typedef struct Color{
	int id;
	Vector4 vector4;
} Color;

// top right bottom left

typedef struct Collider {
	int id;
	bool isItColliding;
	int collisionDirection[TOTALCOORDENATE];
	bool isStatic;
} Collider;

extern Color black;

#define MAX_LAYER 5

typedef struct Layer {
	int id;
	int layer;
} Layer;



typedef struct Player {
	int id;
} Player;

typedef struct Collectible {
	int id;
} Collectible;

#define QTD_TYPE_COMPONENTS TOTALCOMPONENTS

extern char *namesOfCompenents[QTD_TYPE_COMPONENTS];

#define MAX_COMPONENTS 1000

#define SUBCOMPONENTS 2

// int getDirectionCollision(int indexSubsistem, int id, Coordenate direction);
void destroyComponents();

#endif

// typedef enum types{
//     NOTYPES,
//     TEXT,
//     NUMBER,
//     MAXIMUMTYPES
// } Types;

// typedef struct component{
//     char id;
//     void* data;
// }Component;