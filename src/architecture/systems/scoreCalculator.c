#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "scoreCalculator.h"
#include "collision.h"
#include "systems.h"
#include "snake.h"

#include "../entities/entities.h"

#include "../components/components.h"
#include "../components/create.h"
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

#include "../../loader/json.h"

void  scoreCalculator();

void  scoreCalculator(){
		
	float xA = 0, yA = 0, wA = 0, hA = 0;
	float xB = 0, yB = 0, wB = 0, hB = 0;

	int indexCollectible = -1;

	for(int i = 0 ; i < lengthCollumnPlayer(&vectorPlayer); i++){

		Player* idA = getCellPlayer(&vectorPlayer, i);

		if(idA == NULL){continue;}

		int indexA = idA->id, countA = 0;

		Position* auxPositionA = getPositionById(indexA, &countA);
		Size* auxSizeA = getSizeById(indexA, &countA);
		// Player* auxPlayerA = getPlayerById(indexA, &countA);

		if(countA != 2){continue;}

		Position tempPositionA = *auxPositionA;
		Size tempSizeA = *auxSizeA;

		initializeCollisionVariables(tempPositionA, tempSizeA, &xA, &yA, &wA, &hA);

		for(int i = 0 ; i < lengthCollumnCollectible(&vectorCollectible); i++){

			Collectible* idB = getCellCollectible(&vectorCollectible, i);

			if(idB == NULL){continue;}

			int indexB = idB->id;

			if(indexB == indexA){continue;}

			int countB = 0;

			Position* auxPositionB = getPositionById(indexB, &countB);
			Size* auxSizeB = getSizeById(indexB, &countB);
			// Collectible* auxCollectibleB = getCollectibleById(indexB, &countB);

			if(countB != 2){continue;}
			
			Position positionB = *auxPositionB;
			Size sizeB = *auxSizeB;
		
			initializeCollisionVariables(positionB, sizeB, &xB, &yB, &wB, &hB);

			if(isItColliding(xA, yA, wA, hA, xB, yB, wB, hB)){
        printf("\n%d\n", rand());
				if(arrayKey[MY_SCORE] == true){
					arrayKey[MY_SCORE] = false;
					// system("clear");

					score++;

					indexCollectible = indexB;

					// printf("%d\n", score);

					// float newX = 0, newY = 0;
					
					// printf("new x:%f\n", newX);
					// printf("ort x:%f\n", auxPosMove.current2.x);
					// printf("new y:%f\n", newY);
					// printf("ort y:%f\n", auxPosMove.current2.y);

					for (size_t k = 0; k < lengthtemporaryComponents; k++){
						if(temporaryComponents[k].index != 4){
							continue;
						}
						printf("%d\n", temporaryComponents[k].index);
						setId(getId() + 1);
						addCellEntity(
							&vectorEntity,
							lengthCollumnEntity(&vectorEntity),
							(Entity){
								.index = getId()
							}
						);
						for (size_t l = 0; l < temporaryComponents[k].lengtharrayComponentTypes; l++){
							printf("%d\n", temporaryComponents[k].arrayComponentTypes[l]);
							switch (temporaryComponents[k].arrayComponentTypes[l]){
								case INFORMATION:
									addCellInformation(
										&vectorInformation, 
										lengthCollumnInformation(&vectorInformation), 
										createInformation(
											getId(),
											temporaryComponents[k].information.name,
											(strlen(temporaryComponents[k].information.name) + 1)
										)
									);
									break;
								case POSITION:
									// printf("%f - %f\n", tempPositionA.old2.y, tempPositionA.old2.x);
									int count = 0;
									Position* pos = getPositionById(getSnakeTail(), &count);
									addCellPosition(
										&vectorPosition, 
										lengthCollumnInformation(&vectorPosition), 
										createPosition(
											getId(), 
											(pos->old2.x), 
											(pos->old2.y), 
											// (1*SPRITE) + (SPRITE * 1), 
											// (1*SPRITE) + (SPRITE * 1), 
											temporaryComponents[k].position.old2.x,
											temporaryComponents[k].position.old2.y
										)
									);
									break;
								case SIZE:
									addCellSize(
										&vectorSize, 
										lengthCollumnSize(&vectorSize), 
										createSize(
											getId(), 
											temporaryComponents[k].size.vector2.x,
											temporaryComponents[k].size.vector2.y
										)
									);
									break;
								case COLOR:
									addCellColor(
										&vectorColor, 
										lengthCollumnColor(&vectorColor), 
										createColor(
											getId(), 
											temporaryComponents[k].color.vector4.x,
											temporaryComponents[k].color.vector4.y,
											temporaryComponents[k].color.vector4.z,
											temporaryComponents[k].color.vector4.y
										)
									);
									break;
								case COLLIDER:
									addCellCollider(
										&vectorCollider, 
										lengthCollumnCollider(&vectorCollider), 
										createCollider(
											getId(), 
											temporaryComponents[k].collider.isItColliding,
											temporaryComponents[k].collider.collisionDirection,
											temporaryComponents[k].collider.isStatic
										)
									);
									break;
								case LAYER:
									addCellLayer(
										&vectorLayer, 
										lengthCollumnLayer(&vectorLayer), 
										createLayer(
											getId(), 
											temporaryComponents[k].layer.layer
										)
									);
									break;
								case PLAYER:
									// printf("\noi\n");
									addCellPlayer(
										&vectorPlayer, 
										lengthCollumnPlayer(&vectorPlayer), 
										createPlayer(
											getId()
										)
									);
									break;
								case COLLECTIBLE:
									// printf("\noi\n");
									addCellCollectible(
										&vectorCollectible, 
										lengthCollumnCollectible(&vectorCollectible), 
										createCollectible(
											getId()
										)
									);
									break;
								case ANCHOR:
									// printf("\noi\n");
									addCellAnchor(
										&vectorAnchor, 
										lengthCollumnAnchor(&vectorAnchor), 
										createAnchor(
											getId(),
											getSnakeTail()
											// -1
										)
									);
									break;
							}
						}
					}

					// do{
					// 	positionB.current2.x = ((rand() % (9 - 0 + 1) + 0)*SPRITE) + (SPRITE * 2);
					// 	positionB.current2.y = ((rand() % (9 - 0 + 1) + 0)*SPRITE) + (SPRITE * 2);
					// // }while(newX == tempPositionA.current2.x || newY == tempPositionA.current2.y);
					// }while(collisionBetween(&positionB, &sizeB));

					// auxPositionB->old2.x = auxPositionB->current2.y;
					// auxPositionB->old2.y = auxPositionB->current2.y;
					// auxPositionB->current2.x = positionB.current2.x;
					// auxPositionB->current2.y = positionB.current2.y;
				}

			}

			continue;

		}

	}

	iterationSnake();

	if(score < CRD){

		for(int i = 0 ; i < lengthCollumnCollectible(&vectorCollectible); i++){

			Collectible* idB = getCellCollectible(&vectorCollectible, i);

			if(idB == NULL){continue;}

			int indexB = idB->id;

			if(indexB != indexCollectible){continue;}

			if(arrayKey[MY_SCORE] != false){continue;}

			int countB = 0;

			Position* auxPositionB = getPositionById(indexB, &countB);
			Size* auxSizeB = getSizeById(indexB, &countB);

			if(countB != 2){continue;}
			
			Position positionB = *auxPositionB;
			Size sizeB = *auxSizeB;

			do{
				positionB.current2.x = ((rand() % ((COL - SPACE - 1) - 0 + 1) + 0)*SPRITE) + (SPRITE * 2);
				positionB.current2.y = ((rand() % ((ROW - SPACE - 1) - 0 + 1) + 0)*SPRITE) + (SPRITE * 2);
			}while(collisionBetween(&positionB, &sizeB));

			auxPositionB->old2.x = auxPositionB->current2.y;
			auxPositionB->old2.y = auxPositionB->current2.y;
			auxPositionB->current2.x = positionB.current2.x;
			auxPositionB->current2.y = positionB.current2.y;

		}

	}
}