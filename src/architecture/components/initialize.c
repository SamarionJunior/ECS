#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "components.h"
#include "create.h"
#include "../../constants.h"
#include "initialize.h"

#include "../../../dependencies/my/matrix/matrix.h"
#include "../../../dependencies/my/matrix/initialize.h"

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

void initializeComponents();

void initializeComponents(){
	initializeMatrix(&information, SUBCOMPONENTS, MAX_COMPONENTS);
	initializeMatrix(&position, SUBCOMPONENTS, MAX_COMPONENTS);
	initializeMatrix(&direction, SUBCOMPONENTS, MAX_COMPONENTS);
	initializeMatrix(&velocity, SUBCOMPONENTS, MAX_COMPONENTS);
	initializeMatrix(&acceleration, SUBCOMPONENTS, MAX_COMPONENTS);
	initializeMatrix(&size, SUBCOMPONENTS, MAX_COMPONENTS);
	initializeMatrix(&color, SUBCOMPONENTS, MAX_COMPONENTS);
	initializeMatrix(&collider, SUBCOMPONENTS, MAX_COMPONENTS);
	initializeMatrix(&layer, SUBCOMPONENTS, MAX_COMPONENTS);

	// for (size_t i = 0; i < SUBCOMPONENTS; i++){
	// 	for (size_t j = 0; j < MAX_ENTITIES; j++){
			
	// 		/////////////////
	// 		/// SET METOD ///
	// 		/////////////////

	// 		*((Information*)(information.matrix[i][j].data)) = defualtInformation;
	// 		*((Position*)(position.matrix[i][j].data)) = defualtPosition;
	// 		*((Size*)(size.matrix[i][j].data)) = defualtSize;
	// 		*((Color*)(color.matrix[i][j].data)) = defualtColor;
	// 		*((Collider*)(Collider.matrix[i][j].data)) = defualtCollider;
	// 		*((Layer*)(layer.matrix[i][j].data)) = defualtLayer;
	// 		// printf("\n%f\n", components[i].position[j].x);
	// 	}
	// 	for (size_t j = 0; j < QTD_TYPE_COMPONENTS; j++){
	// 		// components[i].length[j]	= 0;
	// 	}
	// }
}

// defualtInformation 	= *createInformation(ID_INIT, "");
// defualtPosition 	= *createPosition(ID_INIT, 0, 0, 0, 0);
// defualtSize 		= *createSize(ID_INIT, 0, 0);
// defualtColor 		= *createColor(ID_INIT, 0, 0, 0, 0);
// defualtCollider 	= *createCollider(ID_INIT, false, NULL, true);
// defualtLayer 		= *createLayer(ID_INIT, 0);