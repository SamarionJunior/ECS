#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "components.h"
#include "create.h"
#include "../../constants.h"
#include "initialize.h"

#include "../../../dependencies/my/matrix/matrix.h"
#include "../../../dependencies/my/matrix/initialize.h"

#include "../../../dependencies/my/dynamicvectors/components/information.h"
#include "../../../dependencies/my/dynamicvectors/components/position.h"
#include "../../../dependencies/my/dynamicvectors/components/size.h"
#include "../../../dependencies/my/dynamicvectors/components/color.h"
#include "../../../dependencies/my/dynamicvectors/components/collider.h"
#include "../../../dependencies/my/dynamicvectors/components/layer.h"
#include "../../../dependencies/my/dynamicvectors/components/player.h"
#include "../../../dependencies/my/dynamicvectors/components/collectible.h"
#include "../../../dependencies/my/dynamicvectors/components/anchor.h"

Information defualtInformation = (Information){
	.id = ID_INIT,
	.name = "",
	.lengthName = 0
};
Position defualtPosition = (Position){
	.id = ID_INIT,
	.current2.x = 0,
	.current2.y = 0,
	.old2.x = 0,
	.old2.y = 0
};
Direction defualtDirection = (Direction){
	.id = ID_INIT,
	.vector2.x = 0,
	.vector2.y = 0
};
Velocity defualtVelocity = (Velocity){
	.id = ID_INIT,
	.vector2.x = 0,
	.vector2.y = 0
};
Acceleration defualtAcceleration = (Acceleration){
	.id = ID_INIT,
	.vector2.x = 0,
	.vector2.y = 0
};
Size defualtSize = (Size){
	.id = ID_INIT,
	.vector2.x = 0,
	.vector2.y = 0
};
Color defualtColor = (Color){
	.id = ID_INIT,
	.vector4.x = 0,
	.vector4.y = 0,
	.vector4.z = 0,
	.vector4.w = 0
};
Collider defualtCollider = (Collider){
	.id = ID_INIT,
	.isItColliding = false,
	.collisionDirection = {0,0,0,0},
	.isStatic = true
};
Layer defualtLayer = (Layer){
	.id = ID_INIT,
	.layer = 0
};
Player defualtPlayer = (Player){
	.id = ID_INIT
};
Collectible defualtCollectible = (Collectible){
	.id = ID_INIT
};
Anchor defualtAnchor = (Anchor){
	.id = ID_INIT,
	.idParent = ID_INIT
};

void initializeComponents();

void initializeComponents(){

	initializeVectorInformation(&vectorInformation, MAX_COMPONENTS);
	initializeVectorPosition(&vectorPosition, MAX_COMPONENTS);
	initializeVectorSize(&vectorSize, MAX_COMPONENTS);
	initializeVectorColor(&vectorColor, MAX_COMPONENTS);
	initializeVectorCollider(&vectorCollider, MAX_COMPONENTS);
	initializeVectorLayer(&vectorLayer, MAX_COMPONENTS);

	initializeVectorPlayer(&vectorPlayer, MAX_COMPONENTS);
	initializeVectorCollectible(&vectorCollectible, MAX_COMPONENTS);
	initializeVectorAnchor(&vectorAnchor, MAX_COMPONENTS);
}