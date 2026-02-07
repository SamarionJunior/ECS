#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "systems.h"
#include "setupCollision.h"
#include "../entities/entities.h"

#include "../components/components.h"
#include "../components/get.h"

#include "../../constants.h"
#include "../../engine/update.h"

#include "../../loader/map.h"

bool freeSpaces[18][18] = {false};

const int vazio = 0;
const int itIsFree = true;
const int NotFree = false;

void initializingFreeSpaces(){
	for (size_t y = 0; y < getROW(); y++){
		for (size_t x = 0; x < getCOL(); x++){
			if(mapMatrix[y][x] == vazio){
				freeSpaces[y][x] = itIsFree;
				continue;
			}
			freeSpaces[y][x] = NotFree;
		}
	}
}