#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "scoreCalculator.h"
#include "collision.h"
#include "systems.h"
#include "../entities/entities.h"

#include "../components/components.h"
#include "../components/get.h"

#include "../../constants.h"
#include "../../engine/update.h"
#include <stdlib.h>

#include "../../engine/input.h"

#include "../../../dependencies/my/dynamicvectors/vector.h"

#include "../../../dependencies/my/dynamicvectors/entities/entity.h"

#include "../../../dependencies/my/dynamicvectors/components/position.h"
#include "../../../dependencies/my/dynamicvectors/components/size.h"
#include "../../../dependencies/my/dynamicvectors/components/player.h"
#include "../../../dependencies/my/dynamicvectors/components/collectible.h"

void  scoreCalculator();

void  scoreCalculator(){
		
	float xA = 0, yA = 0, wA = 0, hA = 0;
	float xB = 0, yB = 0, wB = 0, hB = 0;

	for(int i = 0 ; i < lengthCollumnEntity(&vectorEntity); i++){

		Entity* idA = getCellEntity(&vectorEntity, i);

		if(idA == NULL){continue;}

		int indexA = idA->index, countA = 0;

		Position* auxPositionA = getPositionById(indexA, &countA);
		Size* auxSizeA = getSizeById(indexA, &countA);
		Player* auxPlayerA = getPlayerById(indexA, &countA);

		if(countA != 3){continue;}

		Position tempPositionA = *auxPositionA;
		Size tempSizeA = *auxSizeA;

		initializeCollisionVariables(tempPositionA, tempSizeA, &xA, &yA, &wA, &hA);

		for(int i = 0 ; i < lengthCollumnEntity(&vectorEntity); i++){

            Entity* idB = getCellEntity(&vectorEntity, i);

            if(idB == NULL){continue;}

            int indexB = idB->index;

            if(indexB == indexA){continue;}

            int countB = 0;

            Position* auxPositionB = getPositionById(indexB, &countB);
            Size* auxSizeB = getSizeById(indexB, &countB);
            Collectible* auxCollectibleB = getCollectibleById(indexB, &countB);

            if(countB != 3){continue;}
            
            Position positionB = *auxPositionB;
            Size sizeB = *auxSizeB;
		
			initializeCollisionVariables(positionB, sizeB, &xB, &yB, &wB, &hB);

			if(isItColliding(xA, yA, wA, hA, xB, yB, wB, hB)){
                printf("\noi\n");
				if(arrayKey[MY_SCORE] == true){
					arrayKey[MY_SCORE] = false;
					system("clear");
					score++;
					printf("%d\n", score);

					float newX = 0, newY = 0;

					do{
						newX = ((rand() % (9 - 0 + 1) + 0)*SPRITE) + (SPRITE * 2);
						newY = ((rand() % (9 - 0 + 1) + 0)*SPRITE) + (SPRITE * 2);
					}while(newX == tempPositionA.current2.x && newY == tempPositionA.current2.y);
					
					// printf("new x:%f\n", newX);
					// printf("ort x:%f\n", auxPosMove.current2.x);
					// printf("new y:%f\n", newY);
					// printf("ort y:%f\n", auxPosMove.current2.y);

					auxPositionB->old2.x = auxPositionB->current2.y;
					auxPositionB->old2.y = auxPositionB->current2.y;
					auxPositionB->current2.x = newX;
					auxPositionB->current2.y = newY;
				}
			}

			continue;
		}

	}
}