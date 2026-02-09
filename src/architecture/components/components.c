#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "components.h"
#include "../../constants.h"

// // #include "../../../dependencies/my/dynamicvectors/vector.h"
// // #include "../../../dependencies/my/dynamicvectors/components/information.h"
// // #include "../../../dependencies/my/dynamicvectors/components/position.h"
// // #include "../../../dependencies/my/dynamicvectors/components/size.h"
// // #include "../../../dependencies/my/dynamicvectors/components/color.h"
// // #include "../../../dependencies/my/dynamicvectors/components/collider.h"
// // #include "../../../dependencies/my/dynamicvectors/components/layer.h"
// // #include "../../../dependencies/my/dynamicvectors/components/collectible.h"
// // #include "../../../dependencies/my/dynamicvectors/components/anchor.h"

// #include "dynamicvectors/vector.h"

Color black = {0, 0, 0, 255};

Array* informationArray;
Array* positionArray;

// Array* directionArray;
// Array* velocityArray;
// Array* accelerationArray;

Array* sizeArray;
Array* colorArray;
Array* colliderArray;
Array* layerArray;

Array* playerArray;
Array* collectibleArray;
Array* anchorArray;

Array* arrayOfArrayComponents[TOTALCOMPONENTS];

char *namesOfCompenents[TOTALCOMPONENTS] = {
	"Information",
	"Position",
	// "Direction",
	// "Velocity",
	// "Acceleration",
	"Size",
	"Color",
	"Collider",
	"Layer",
	"Player",
	"Anchor",
	"Collectible"
};

// void destroyComponents();
// int getDirectionCollision(int scene, int index, Coordenate direction);

// int getDirectionCollision(int scene, int index, Coordenate direction){
// 	return (*(Collider*)(getCell(&collider, scene, index))).collisionDirection[direction];
// }

void destroyComponents(){

	destroyArray(informationArray);
	destroyArray(positionArray);

	// destroyArray(directionArray);
	// destroyArray(velocityArray);
	// destroyArray(accelerationArray);

	destroyArray(sizeArray);
	destroyArray(colorArray);
	destroyArray(colliderArray);
	destroyArray(layerArray);

	destroyArray(playerArray);
	destroyArray(collectibleArray);
	destroyArray(anchorArray);

	// destroyVectorInformation(&vectorInformation);
	// destroyVectorPosition(&vectorPosition);
	// destroyVectorSize(&vectorSize);
	// destroyVectorColor(&vectorColor);
	// destroyVectorCollider(&vectorCollider);
	// destroyVectorLayer(&vectorLayer);
	// destroyVectorCollectible(&vectorCollectible);
	// destroyVectorAnchor(&vectorAnchor);
}