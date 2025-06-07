#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "scoreCalculator.h"
#include "collision.h"
#include "systems.h"
#include "../entities/entities.h"
#include "../components/components.h"
#include "../../constants.h"
#include "../../engine/update.h"
#include <stdlib.h>

#include "../../engine/input.h"

#include "../../../dependencies/my/matrix/matrix.h"
#include "../../../dependencies/my/matrix/length.h"
#include "../../../dependencies/my/matrix/get.h"

// void  scoreCalculator();

// void  scoreCalculator(){

// 	ComponentsForScore *compScore = NULL;
// 	ComponentsForScore auxCompScore;
// 	Position auxPosScore;
// 	Size auxSizScore;

// 	ComponentsForScore *compMove = NULL;
// 	ComponentsForScore auxCompMove;
// 	Position auxPosMove;
// 	Size auxSizMove;
		
// 	float xA = 0, yA = 0, wA = 0, hA = 0;
// 	float xB = 0, yB = 0, wB = 0, hB = 0;


// 	for (size_t i = 0; i < lengthRow(&componentsForScore, 0); i++){
		
// 		compScore = ((ComponentsForScore *)(getCell(&componentsForScore, 0, i)->data));

// 		auxCompScore = *compScore;
// 		auxPosScore = *(auxCompScore.position);
// 		auxSizScore = *(auxCompScore.size);

// 		initializeCollisionVariables(auxPosScore, auxSizScore, &xA, &yA, &wA, &hA);

// 		for (size_t i = 0; i < lengthRow(&componentsForMove, 0); i++){
			
// 			compMove = ((ComponentsForMove *)(getCell(&componentsForMove, 0, i)->data));

// 			auxCompMove = *compMove;
// 			auxPosMove = *(auxCompMove.position);
// 			auxSizMove = *(auxCompMove.size);
				
// 			if(isTheSameIndex(auxPosScore, auxPosMove)){
// 				continue;
// 			}
		
// 			initializeCollisionVariables(auxPosMove, auxSizMove, &xB, &yB, &wB, &hB);

// 			if(isItColliding( xA, yA, wA, hA, xB, yB, wB, hB)){
// 				if(arrayKey[MY_SCORE] == true){
// 					arrayKey[MY_SCORE] = false;
// 					system("clear");
// 					score++;
// 					printf("%d\n", score);

// 					float newX = 0, newY = 0;

// 					do{
// 						newX = ((rand() % (9 - 0 + 1) + 0)*SPRITE) + (SPRITE * 2);
// 						newY = ((rand() % (9 - 0 + 1) + 0)*SPRITE) + (SPRITE * 2);
// 					}while(newX == auxPosMove.current2.x && newY == auxPosMove.current2.y);
					
// 					// printf("new x:%f\n", newX);
// 					// printf("ort x:%f\n", auxPosMove.current2.x);
// 					// printf("new y:%f\n", newY);
// 					// printf("ort y:%f\n", auxPosMove.current2.y);

// 					compScore->position->old2.x = compScore->position->current2.y;
// 					compScore->position->old2.y = compScore->position->current2.y;
// 					compScore->position->current2.x = newX;
// 					compScore->position->current2.y = newY;
// 				}
// 			}

// 			continue;
// 		}

// 	}
// }