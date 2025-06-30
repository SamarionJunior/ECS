#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../../src/architecture/components/components.h"
#include "../../../src/architecture/entities/entities.h"

typedef struct vectorInformation{
    Information *data;
    unsigned int columnLength;
    unsigned int maximumCollumn;
} VectorInformation;

typedef struct vectorPosition{
    Position *data;
    unsigned int columnLength;
    unsigned int maximumCollumn;
} VectorPosition;

typedef struct vectorSize{
    Size *data;
    unsigned int columnLength;
    unsigned int maximumCollumn;
} VectorSize;

typedef struct vectorColor{
    Color *data;
    unsigned int columnLength;
    unsigned int maximumCollumn;
} VectorColor;

typedef struct vectorCollider{
    Collider *data;
    unsigned int columnLength;
    unsigned int maximumCollumn;
} VectorCollider;

typedef struct vectorLayer{
    Layer *data;
    unsigned int columnLength;
    unsigned int maximumCollumn;
} VectorLayer;



typedef struct vectorPlayer{
    Player *data;
    unsigned int columnLength;
    unsigned int maximumCollumn;
} VectorPlayer;

typedef struct vectorCollectible{
    Collectible *data;
    unsigned int columnLength;
    unsigned int maximumCollumn;
} VectorCollectible;

typedef struct vectorAnchor{
    Anchor *data;
    unsigned int columnLength;
    unsigned int maximumCollumn;
} VectorAnchor;

//////////////////////////////////

typedef struct vectorEntity{
    Entity *data;
    unsigned int columnLength;
    unsigned int maximumCollumn;
} VectorEntity;

extern VectorInformation vectorInformation;
extern VectorPosition vectorPosition;
extern VectorSize vectorSize;
extern VectorColor vectorColor;
extern VectorCollider vectorCollider;
extern VectorLayer vectorLayer;

extern VectorPlayer vectorPlayer;
extern VectorCollectible vectorCollectible;
extern VectorAnchor vectorAnchor;

///////////////////////////////////////////

extern VectorEntity vectorEntity;

#endif

