#ifndef COMPONENTS_H_
#define COMPONENTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL3/SDL_stdinc.h>
#include "../entities/entities.h"

#include "../../../dependencies/my/dynamicarray/array.h"

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

// top right bottom left

typedef struct Collider {
	int id;
	bool isItColliding;
	int collisionDirection[TOTALCOORDENATE];
	bool isStatic;
} Collider;

extern Color black;

#define MAX_LAYER 6

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

typedef struct anchor {
	int id;
	int idParent;
} Anchor;



extern Array* informationArray;
extern Array* positionArray;

// extern Array* directionArray;
// extern Array* velocityArray;
// extern Array* accelerationArray;

extern Array* sizeArray;
extern Array* colorArray;
extern Array* colliderArray;
extern Array* layerArray;

extern Array* playerArray;
extern Array* collectibleArray;
extern Array* anchorArray;

#define QTD_TYPE_COMPONENTS TOTALCOMPONENTS

extern char *namesOfCompenents[QTD_TYPE_COMPONENTS];


enum components_config {
    MAX_COMPONENTS = 20000
};

// #define MAX_COMPONENTS 20000

#define SUBCOMPONENTS 2

// int getDirectionCollision(int indexSubsistem, int id, Coordenate direction);
void destroyComponents();

typedef struct TemporaryComponent{
	int index;
	Information information;
	bool isThereInformation;
	Position position;
	bool isTherePosition;
	Direction direction;
	bool isThereDirection;
	Velocity velocity;
	bool isThereVelocity;
	Acceleration acceleration;
	bool isThereAcceleration;
	Size size;
	bool isThereSize;
	Color color;
	bool isThereColor;
	Collider collider;
	bool isThereCollider;
	Layer layer;
	bool isThereLayer;
	Player player;
	bool isTherePlayer;
	Collectible collectible;
	bool isThereCollectible;
	Anchor anchor;
	bool isThereAnchor;
	int arrayComponentTypes[QTD_TYPE_COMPONENTS];
	int lengtharrayComponentTypes;
} TemporaryComponent;

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

#endif