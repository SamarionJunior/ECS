#ifndef VECTORPLAYER_H_
#define VECTORPLAYER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../vector.h"
#include "player.h"
#include "../../../../src/architecture/components/components.h"

bool verifyParamsPlayer(VectorPlayer* vectorPlayer, size_t collum);
bool addCellPlayer(VectorPlayer* vectorPlayer, size_t collum, Player data);
bool removeCellPlayer(VectorPlayer* vectorPlayer, size_t collum);
bool setCellPlayer(VectorPlayer* vectorPlayer, size_t collum, Player data);
Player* getCellPlayer(VectorPlayer* vectorPlayer, size_t collum);
bool fullCollumnPlayer(VectorPlayer* vectorPlayer);
bool emptyCollumnPlayer(VectorPlayer* vectorPlayer);
int lengthCollumnPlayer(VectorPlayer* vectorPlayer);
bool printVectorPlayer(VectorPlayer* vectorPlayer);
void initializeVectorPlayer(VectorPlayer* vectorPlayer, unsigned int maximumCollumn);
bool destroyVectorPlayer(VectorPlayer* vectorPlayer);

#endif