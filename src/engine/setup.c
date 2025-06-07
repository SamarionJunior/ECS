#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "setup.h"

#include "../architecture/components/components.h"
#include "../architecture/components/create.h"
// #include "../architecture/components/initialize.h"

#include "../architecture/entities/entities.h"
#include "../architecture/entities/utility.h"

#include "../architecture/systems/systems.h"

#include "../constants.h"

#include "../../dependencies/mycustom/myjson.h"

#include "../../dependencies/my/dynamicvectors/vector.h"

#include "../../dependencies/my/dynamicvectors/entities/entity.h"

#include "../../dependencies/my/dynamicvectors/components/information.h"
#include "../../dependencies/my/dynamicvectors/components/position.h"
#include "../../dependencies/my/dynamicvectors/components/size.h"
#include "../../dependencies/my/dynamicvectors/components/color.h"
#include "../../dependencies/my/dynamicvectors/components/collider.h"
#include "../../dependencies/my/dynamicvectors/components/layer.h"
#include "../../dependencies/my/dynamicvectors/components/player.h"
#include "../../dependencies/my/dynamicvectors/components/collectible.h"

#include "../loader/json.h"
#include "../loader/map.h"

#include "../utilities/space.h"

// void createScene(){
// 	addRow(&information, 0, NULL, 0);
// 	addRow(&position, 0, NULL, 0);
// 	addRow(&direction, 0, NULL, 0);
// 	addRow(&velocity, 0, NULL, 0);
// 	addRow(&acceleration, 0, NULL, 0);
// 	addRow(&size, 0, NULL, 0);
// 	addRow(&color, 0, NULL, 0);
// 	addRow(&collider, 0, NULL, 0);
// 	addRow(&layer, 0, NULL, 0);
// 	addRow(&entities, 0, NULL, 0);
// }

void setup(void){

	score = 0;
	
	int id = 0;
	
	initializeComponents();

	initializeEntities();
	
	// createScene();
	
	for (size_t i = 0; i < 12; i++){
		for (size_t j = 0; j < 12; j++){
			for (size_t k = 0; k < lengthtemporaryComponents; k++){

				if(mapMatrix[i][j] != temporaryComponents[k].index){
					continue;
				}

				// addEntity(&vectorEntity, lengthCollumnEntity(&vectorEntity), &id);
				addCellEntity(
					&vectorEntity,
					lengthCollumnEntity(&vectorEntity),
					(Entity){
						.index = id
					}
				);

				// printVectorEntity(&vectorEntity);
		
				for (size_t l = 0; l < temporaryComponents[k].lengtharrayComponentTypes; l++){
					
					// Data auxData;

					switch (temporaryComponents[k].arrayComponentTypes[l]){
						case INFORMATION:
							addCellInformation(
								&vectorInformation, 
								lengthCollumnInformation(&vectorInformation), 
								createInformation(
									id,
									temporaryComponents[k].information.name,
									(strlen(temporaryComponents[k].information.name) + 1)
								)
							);
							break;
						case POSITION:
							addCellPosition(
								&vectorPosition, 
								lengthCollumnInformation(&vectorPosition), 
								createPosition(
									id, 
									(j*SPRITE) + (SPRITE * 1), 
									(i*SPRITE) + (SPRITE * 1), 
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
									id, 
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
									id, 
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
									id, 
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
									id, 
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
									id
								)
							);
							break;
						case COLLECTIBLE:
							// printf("\noi\n");
							addCellCollectible(
								&vectorCollectible, 
								lengthCollumnCollectible(&vectorCollectible), 
								createCollectible(
									id
								)
							);
							break;
					}
				
				}
				
				id++;

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

// case DIRECTION:
// 	auxData.data = malloc(sizeof(Direction) * 1);
// 	(*((Direction*)(auxData.data))) = *createDirection(
// 		id, 
// 		temporaryComponents[k].direction.vector2.x,
// 		temporaryComponents[k].direction.vector2.y
// 	);
// 	addCell(&direction, 0, lengthRow(&direction, 0), auxData);
// 	addCell(
// 		&vector, 
// 		lengthCollumn(&vector), 
// 		create(
// 			id, 
// 			(j*SPRITE) + (SPRITE * 1), 
// 			(i*SPRITE) + (SPRITE * 1), 
// 			temporaryComponents[k].position.old2.x,
// 			temporaryComponents[k].position.old2.y
// 		)
// 	);
// 	break;
// case VELOCITY:
// 	auxData.data = malloc(sizeof(Velocity) * 1);
// 	(*((Velocity*)(auxData.data))) = *createVelocity(
// 		id, 
// 		temporaryComponents[k].velocity.vector2.x,
// 		temporaryComponents[k].velocity.vector2.y
// 	);
// 	addCell(&velocity, 0, lengthRow(&velocity, 0), auxData);
// 	break;
// case ACCELERATION:
// 	auxData.data = malloc(sizeof(Acceleration) * 1);
// 	(*((Acceleration*)(auxData.data))) = *createAcceleration(
// 		id, 
// 		temporaryComponents[k].acceleration.vector2.x,
// 		temporaryComponents[k].acceleration.vector2.y
// 	);
// 	addCell(&acceleration, 0, lengthRow(&acceleration, 0), auxData);
// 	break;