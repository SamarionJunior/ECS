#ifndef COMPONENTS_H_
#define COMPONENTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL3/SDL_stdinc.h>

// #include "../entities/entities.h"

#include "../../../dependencies/my/dynamicarray/array.h"

typedef enum coordenate{
	TOP,
	RIGHT,
	BOTTOM,
	LEFT,
	TOTALCOORDENATE
} Coordenate;

typedef enum typesofcomponents{
	INFORMATION,
	POSITION,
	// DIRECTION,
	// VELOCITY,
	// ACCELERATION,
	SIZE,
	COLOR,
	COLLIDER,
	LAYER0,
	LAYER1,
	LAYER2,
	PLAYER,
	COLLECTIBLE,
	ANCHOR,
	TOTALCOMPONENTS
} TypesOfComponents;

/// SUB STRUCT ///

typedef struct id{
	int id;
}Id;

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

extern Color black;

// top right bottom left

typedef struct Collider {
	int id;
	bool isItColliding;
	int collisionDirection[TOTALCOORDENATE];
	bool isStatic;
} Collider;

#define MAX_LAYER 6

typedef struct Layer {
	int id;
} Layer;

typedef struct Player {
	int id;
} Player;

typedef struct Collectible {
	int id;
} Collectible;

typedef struct anchor {
	int id;
	int idParent;
} Anchor;

extern Array informationArray;
extern Array positionArray;
// extern Array directionArray;
// extern Array velocityArray;
// extern Array accelerationArray;
extern Array sizeArray;
extern Array colorArray;
extern Array colliderArray;
extern Array layer0Array;
extern Array layer1Array;
extern Array layer2Array;

extern Array playerArray;
extern Array collectibleArray;
extern Array anchorArray;

extern Array* arrayOfArrayComponents[TOTALCOMPONENTS];

extern char *namesOfCompenents[TOTALCOMPONENTS];

enum components_config {
    MAX_COMPONENTS = 20000
};

void destroyComponents();

typedef struct componentandtype{
	void* component;
	TypesOfComponents type;
} ComponentAndType;

typedef struct temporaryentity{
	int entityType;
	Array componentAndTypes;
} TemporaryEntity;

#endif