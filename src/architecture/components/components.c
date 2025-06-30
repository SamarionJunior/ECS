#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "components.h"
#include "../../constants.h"
#include "../../../dependencies/my/dynamicvectors/vector.h"
#include "../../../dependencies/my/dynamicvectors/components/information.h"
#include "../../../dependencies/my/dynamicvectors/components/position.h"
#include "../../../dependencies/my/dynamicvectors/components/size.h"
#include "../../../dependencies/my/dynamicvectors/components/color.h"
#include "../../../dependencies/my/dynamicvectors/components/collider.h"
#include "../../../dependencies/my/dynamicvectors/components/layer.h"
#include "../../../dependencies/my/dynamicvectors/components/collectible.h"
#include "../../../dependencies/my/dynamicvectors/components/anchor.h"

// #include "dynamicvectors/vector.h"

Color black = {0, 0, 0, 255};

char *namesOfCompenents[QTD_TYPE_COMPONENTS] = {
	"Information",
	"Position",
	"Direction",
	"Velocity",
	"Acceleration",
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
	destroyVectorInformation(&vectorInformation);
	destroyVectorPosition(&vectorPosition);
	destroyVectorSize(&vectorSize);
	destroyVectorColor(&vectorColor);
	destroyVectorCollider(&vectorCollider);
	destroyVectorLayer(&vectorLayer);
	destroyVectorCollectible(&vectorCollectible);
	destroyVectorAnchor(&vectorAnchor);
}