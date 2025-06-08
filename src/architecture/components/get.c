#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "components.h"
#include "get.h"

#include "../../../dependencies/my/dynamicvectors/vector.h"
#include "../../../dependencies/my/dynamicvectors/components/information.h"
#include "../../../dependencies/my/dynamicvectors/components/position.h"
#include "../../../dependencies/my/dynamicvectors/components/size.h"
#include "../../../dependencies/my/dynamicvectors/components/color.h"
#include "../../../dependencies/my/dynamicvectors/components/collider.h"
#include "../../../dependencies/my/dynamicvectors/components/layer.h"
#include "../../../dependencies/my/dynamicvectors/components/player.h"
#include "../../../dependencies/my/dynamicvectors/components/collectible.h"

Information* getInformationById(int id, int* count){
	Information* tempInformation = NULL;
	for (size_t j = 0; j < lengthCollumnInformation(&vectorInformation); j++){
		tempInformation = getCellInformation(&vectorInformation, j);
		if(tempInformation != NULL){
			if(tempInformation->id == id){
				(*count)++;
				return tempInformation;
			}
		}
	}
}
Position* getPositionById(int id, int* count){
	Position* tempPosition = NULL;
	for (size_t j = 0; j < lengthCollumnPosition(&vectorPosition); j++){
		tempPosition = getCellPosition(&vectorPosition, j);
		if(tempPosition != NULL){
			if(tempPosition->id == id){
				(*count)++;
				return tempPosition;
			}
		}
	}
}
Size* getSizeById(int id, int* count){
	Size* tempSize = NULL;
	for (size_t j = 0; j < lengthCollumnSize(&vectorSize); j++){
		tempSize = getCellSize(&vectorSize, j);
		if(tempSize != NULL){
			if(tempSize->id == id){
				(*count)++;
				return tempSize;
			}
		}
	}
}
Color* getColorById(int id, int* count){
	Color* tempColor = NULL;
	for (size_t j = 0; j < lengthCollumnColor(&vectorColor); j++){
		tempColor = getCellColor(&vectorColor, j);
		if(tempColor != NULL){
			if(tempColor->id == id){
				(*count)++;
				return tempColor;
			}
		}
	}
}
Collider* getColliderById(int id, int* count){
	Collider* tempCollider = NULL;
	for (size_t j = 0; j < lengthCollumnCollider(&vectorCollider); j++){
		tempCollider = getCellCollider(&vectorCollider, j);
		if(tempCollider != NULL){
			if(tempCollider->id == id){
				(*count)++;
				return tempCollider;
			}
		}
	}
}
Layer* getLayerById(int id, int* count){
	Layer* tempLayer = NULL;
	for (size_t j = 0; j < lengthCollumnLayer(&vectorLayer); j++){
		tempLayer = getCellLayer(&vectorLayer, j);
		if(tempLayer != NULL){
			if(tempLayer->id == id){
				(*count)++;
				return tempLayer;
			}
		}
	}
}

Player* getPlayerById(int id, int* count){
	Player* tempPlayer = NULL;
	for (size_t j = 0; j < lengthCollumnPlayer(&vectorPlayer); j++){
		tempPlayer = getCellPlayer(&vectorPlayer, j);
		if(tempPlayer != NULL){
			if(tempPlayer->id == id){
				(*count)++;
				return tempPlayer;
			}
		}
	}
}

Collectible* getCollectibleById(int id, int* count){
	Collectible* tempCollectible = NULL;
	for (size_t j = 0; j < lengthCollumnCollectible(&vectorCollectible); j++){
		tempCollectible = getCellCollectible(&vectorCollectible, j);
		if(tempCollectible != NULL){
			if(tempCollectible->id == id){
				(*count)++;
				return tempCollectible;
			}
		}
	}
}

/// TEMPLATE ///

	// ¨* temp¨ = NULL;
	// for (size_t j = 0; j < lengthCollumn¨(&vector¨); j++){
	// 	temp¨ = getCell¨(&vector¨, j);
	// 	if(temp¨ != NULL){
	// 		if(temp¨->id == id){
	// 			(*count)++;
	// 			return temp¨;
	// 		}
	// 	}
	// }

// Direction getDirection(int id, float x, float y){
// 	Direction direction;
// 	direction.id = id;
// 	direction.vector2.x = x;
// 	direction.vector2.y = y;
// 	return direction;
// }
// Velocity getVelocity(int id, float x, float y){
// 	Velocity velocity;
// 	velocity.id = id;
// 	velocity.vector2.x = x;
// 	velocity.vector2.y = y;
// 	return velocity;
// }
// Acceleration getAcceleration(int id, float x, float y){
// 	Acceleration acceleration;
// 	acceleration.id = id;
// 	acceleration.vector2.x = x;
// 	acceleration.vector2.y = y;
// 	return acceleration;
// }
