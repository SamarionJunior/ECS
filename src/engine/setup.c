#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "setup.h"

#include "../architecture/components/components.h"
#include "../architecture/components/create.h"
#include "../architecture/components/initialize.h"

#include "../architecture/entities/entities.h"
#include "../architecture/systems/systems.h"

#include "../constants.h"

#include "../../dependencies/mycustom/myjson.h"

#include "../../dependencies/my/matrix/matrix.h"
#include "../../dependencies/my/matrix/add.h"
#include "../../dependencies/my/matrix/length.h"
#include "../../dependencies/my/matrix/get.h"

#include "../loader/json.h"
#include "../loader/map.h"

#include "../utilities/space.h"

void createScene(){
	addRow(&information, 0, NULL, 0);
	addRow(&position, 0, NULL, 0);
	addRow(&direction, 0, NULL, 0);
	addRow(&velocity, 0, NULL, 0);
	addRow(&acceleration, 0, NULL, 0);
	addRow(&size, 0, NULL, 0);
	addRow(&color, 0, NULL, 0);
	addRow(&collider, 0, NULL, 0);
	addRow(&layer, 0, NULL, 0);
	addRow(&entities, 0, NULL, 0);
}

void setup(void){

	score = 0;
	
	int id = 0;
	
	initializeComponents();

	initializeEntities();
	
	createScene();
	
	for (size_t i = 0; i < 12; i++){
		for (size_t j = 0; j < 12; j++){
			for (size_t k = 0; k < lengthtemporaryComponents; k++){

				if(mapMatrix[i][j] != temporaryComponents[k].index){
					continue;
				}

				addEntity(0, &id);
		
				for (size_t l = 0; l < temporaryComponents[k].lengtharrayComponentTypes; l++){
					
					Data auxData;

					switch (temporaryComponents[k].arrayComponentTypes[l]){
						case INFORMATION:
							auxData.data = malloc(sizeof(Information) * 1);
							(*((Information*)(auxData.data))) = *createInformation(
								id, 
								temporaryComponents[k].information.name,
								(strlen(temporaryComponents[k].information.name) + 1)
							);
							addCell(&information, 0, lengthRow(&information, 0), auxData);
							break;
						case POSITION:
							auxData.data = malloc(sizeof(Position) * 1);
							(*((Position*)(auxData.data))) = *createPosition(
								id, 
								(j*SPRITE) + (SPRITE * 1), 
								(i*SPRITE) + (SPRITE * 1), 
								temporaryComponents[k].position.old2.x,
								temporaryComponents[k].position.old2.y
							);
							addCell(&position, 0, lengthRow(&position, 0), auxData);
							break;

						case DIRECTION:
							auxData.data = malloc(sizeof(Direction) * 1);
							(*((Direction*)(auxData.data))) = *createDirection(
								id, 
								temporaryComponents[k].direction.vector2.x,
								temporaryComponents[k].direction.vector2.y
							);
							addCell(&direction, 0, lengthRow(&direction, 0), auxData);
							break;
						case VELOCITY:
							auxData.data = malloc(sizeof(Velocity) * 1);
							(*((Velocity*)(auxData.data))) = *createVelocity(
								id, 
								temporaryComponents[k].velocity.vector2.x,
								temporaryComponents[k].velocity.vector2.y
							);
							addCell(&velocity, 0, lengthRow(&velocity, 0), auxData);
							break;
						case ACCELERATION:
							auxData.data = malloc(sizeof(Acceleration) * 1);
							(*((Acceleration*)(auxData.data))) = *createAcceleration(
								id, 
								temporaryComponents[k].acceleration.vector2.x,
								temporaryComponents[k].acceleration.vector2.y
							);
							addCell(&acceleration, 0, lengthRow(&acceleration, 0), auxData);
							break;


						case SIZE:
							auxData.data = malloc(sizeof(Size) * 1);
							(*((Size*)(auxData.data))) = *createSize(
								id, 
								temporaryComponents[k].size.vector2.x,
								temporaryComponents[k].size.vector2.y
							);
							addCell(&size, 0, lengthRow(&size, 0), auxData);
							break;
						case COLOR:
							auxData.data = malloc(sizeof(Color) * 1);
							(*((Color*)(auxData.data))) = *createColor(
								id, 
								temporaryComponents[k].color.vector4.x,
								temporaryComponents[k].color.vector4.y,
								temporaryComponents[k].color.vector4.z,
								temporaryComponents[k].color.vector4.y
							);
							addCell(&color, 0, lengthRow(&color, 0), auxData);
							break;
						case COLLIDER:
							auxData.data = malloc(sizeof(Collider) * 1);
							(*((Collider*)(auxData.data))) = *createCollider(
								id, 
								temporaryComponents[k].collider.isItColliding,
								temporaryComponents[k].collider.collisionDirection,
								temporaryComponents[k].collider.isStatic
							);
							addCell(&collider, 0, lengthRow(&collider, 0), auxData);
							break;
						case LAYER:
							auxData.data = malloc(sizeof(Layer) * 1);
							(*((Layer*)(auxData.data))) = *createLayer(
								id, 
								temporaryComponents[k].layer.layer
							);
							addCell(&layer, 0, lengthRow(&layer, 0), auxData);
							break;
					}
				
				}
				
			}
			
		}
	}

	// // // // printf("entities: %d\n", lengthRow(&entities, 0));

	// // // // printf("information: %d\n", lengthRow(&information, 0));
	// // // // printf("position: %d\n", lengthRow(&position, 0));
	// // // // printf("direction: %d\n", lengthRow(&direction, 0));
	// // // // printf("velocity: %d\n", lengthRow(&velocity, 0));
	// // // // printf("acceleration: %d\n", lengthRow(&acceleration, 0));
	// // // // printf("size: %d\n", lengthRow(&size, 0));
	// // // // printf("color: %d\n", lengthRow(&color, 0));
	// // // // printf("collider: %d\n", lengthRow(&collider, 0));
	// // // // printf("layer %d\n", lengthRow(&layer, 0));

	// // // // printf("\n///////////////////\n");
	// // // // printf(  "/// END - SETUP ///\n");
	// // // // printf(  "///////////////////\n\n");

}