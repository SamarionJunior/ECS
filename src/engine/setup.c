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
	addRow(&componentsForCollision, 0, NULL, 0);
	addRow(&componentsForGravity, 0, NULL, 0);
	addRow(&componentsForLayer, 0, NULL, 0);
	addRow(&componentsForMove, 0, NULL, 0);
	addRow(&componentsForScore, 0, NULL, 0);
}

void setup(void){

	score = 0;

	// // // // printf("\n/////////////\n");
	// // // // printf(  "/// SETUP ///\n");
	// // // // printf(  "/////////////\n\n");
	
	int id = 0;
	
	initializeComponents();

	initializeEntities();
	
	initializeSystems();
	
	createScene();
	
	for (size_t i = 0; i < 12; i++){
		for (size_t j = 0; j < 12; j++){

			// printf("%d", mapMatrix[i][j]);
			
			for (size_t k = 0; k < lengthtemporaryComponents; k++){
				// printf("%d - %d\n", temporaryComponents[0].index, temporaryComponents[1].index);

				if(mapMatrix[i][j] != temporaryComponents[k].index){
					continue;
				}

				// printf("%d - %d\n", mapMatrix[i][j], temporaryComponents[k].index);
		
					
				// printf("\n");
				// printf("------------\n");
				// printf("------------\n");
				addEntity(0, &id);
				// printf("id: %d\n", id);
				// printf("------------\n");
				// printf("------------\n");

				// printf("\n");
		
	// 			// printf("\n%d\n", temporaryComponents[i].lengtharrayComponentTypes);
		
				for (size_t l = 0; l < temporaryComponents[k].lengtharrayComponentTypes; l++){
					// printf("\n%d\n", temporaryComponents[i].arrayComponentTypes[j]);
					
					Data auxData;

					// printf("%d\n", temporaryComponents[k].arrayComponentTypes[l]);

					// printf("------------\n");

					// printf("id: %d\n", id);

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
								// temporaryComponents[k].position.current2.x,
								// temporaryComponents[k].position.current2.y,
								temporaryComponents[k].position.old2.x,
								temporaryComponents[k].position.old2.y
							);
							addCell(&position, 0, lengthRow(&position, 0), auxData);
							// add(POSITION, 		createPosition(
							// 	entity, 
							// 	temporaryComponents[k].position.x, 
							// 	temporaryComponents[k].position.y, 
							// 	temporaryComponents[k].position.oldX, 
							// 	temporaryComponents[k].position.oldY
							// ));
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
							// printf("\nIs Static: %d\n", ((Collision *)readComponentByIdAndReturnReferenc(COLLISION, entity))->isStatic);
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
				
					// printf("------------\n");
				}
				
				for (size_t l = 0; l < temporaryComponents[k].lengthArraySystems; l++){
					// printf(
					// 	"\ntemporaryComponents[k].arraySystems[%d] %d\n\n", 
					// 	temporaryComponents[k].lengthArraySystems, 
					// 	temporaryComponents[k].arraySystems[l]
					// );
					
					switch (temporaryComponents[k].arraySystems[l]){
						case GRAVITY:
							
							Information *data91 = getCell(&information, 0, lengthRow(&information, 0) - 1)->data;
							
							// printf("\nlengthRow(&position, 0) %d\n", lengthRow(&position, 0));
							Position *data0 = getCell(&position, 0, lengthRow(&position, 0) - 1)->data;
							// printf("\nlengthRow(&direction, 0) %d\n", lengthRow(&direction, 0));
							Direction *data1 = getCell(&direction, 0, lengthRow(&direction, 0) - 1)->data;
							// printf("\nlengthRow(&velocity, 0) %d\n", lengthRow(&velocity, 0));
							Velocity *data2 = getCell(&velocity, 0, lengthRow(&velocity, 0) - 1)->data;
							// printf("\nlengthRow(&acceleration, 0) %d\n", lengthRow(&acceleration, 0));
							Acceleration *data3 = getCell(&acceleration, 0, lengthRow(&acceleration, 0) - 1)->data;
							// printf("\nlengthRow(&collider, 0) %d\n", lengthRow(&collider, 0));
							Collider *data4 = getCell(&collider, 0, lengthRow(&collider, 0) - 1)->data;
							// printf("\n(*((Position*)data[0])).id %d\n", data0->id);
							if(
								data91->id == id &&
								data0->id == id &&
								data1->id == id &&
								data2->id == id &&
								data3->id == id &&
								data4->id == id
							){
								Data auxData;
								auxData.data = malloc(sizeof(ComponentsForGravity) * 1);
								(*((ComponentsForGravity*)(auxData.data))) = (ComponentsForGravity){
									.information = data91,
									.position = data0,
									.direction = data1,
									.velocity = data2,
									.acceleration = data3,
									.collider = data4
								};

								// printf("Matrix - Address: %p\n", &componentsForGravity);
								// printf("maximumRow - value: %d\n", componentsForGravity.maximumRow);
								// printf("maximumCollum - value: %d\n", componentsForGravity.maximumCollum);
								// printf("row - value: %d\n", 0);
								// printf("collum - value: %d\n", lengthMatrix(&componentsForGravity) - 1);
								// printf("matrix->row - value: %d\n", componentsForGravity.row);
								// printf("matrix->collum[row] - value: %d\n", componentsForGravity.collum[0]);

								addSystem(&componentsForGravity, 0, lengthMatrix(&componentsForGravity) - 1, auxData);
							}
							break;
						case COLLISION:
							
							Information *data99 = getCell(&information, 0, lengthRow(&information, 0) - 1)->data;
							Position *data01 = getCell(&position, 0, lengthRow(&position, 0) - 1)->data;
							Direction *data11 = getCell(&direction, 0, lengthRow(&direction, 0) - 1)->data;
							Velocity *data21 = getCell(&velocity, 0, lengthRow(&velocity, 0) - 1)->data;
							Acceleration *data31 = getCell(&acceleration, 0, lengthRow(&acceleration, 0) - 1)->data;
							Size *data41 = getCell(&size, 0, lengthRow(&size, 0) - 1)->data;
							Collider *data51 = getCell(&collider, 0, lengthRow(&collider, 0) - 1)->data;

							if(
								data99->id == id &&
								data01->id == id &&
								data11->id == id &&
								data21->id == id &&
								data31->id == id &&
								data41->id == id &&
								data51->id == id
							){
								Data auxData;
								auxData.data = malloc(sizeof(ComponentsForCollision) * 1);
								(*((ComponentsForCollision*)(auxData.data))) = (ComponentsForCollision){
									.information = data99,
									.position = data01,
									.direction = data11,
									.velocity = data21,
									.acceleration = data31,
									.size = data41,
									.collider = data51
								};

								addSystem(&componentsForCollision, 0, lengthMatrix(&componentsForCollision) - 1, auxData);
							}
							break;
						case LAYERS:
							
							Information *data92 = getCell(&information, 0, lengthRow(&information, 0) - 1)->data;
							
							Position *data00 = getCell(&position, 0, lengthRow(&position, 0) - 1)->data;
							Size *data10 = getCell(&size, 0, lengthRow(&size, 0) - 1)->data;
							Color *data20 = getCell(&color, 0, lengthRow(&color, 0) - 1)->data;
							Layer *data30 = getCell(&layer, 0, lengthRow(&layer, 0) - 1)->data;

							if(
								data92->id == id &&
								data00->id == id &&
								data10->id == id &&
								data20->id == id &&
								data30->id == id
							){

								Data auxData;
								auxData.data = malloc(sizeof(ComponentsForLayer) * 1);
								(*((ComponentsForLayer*)(auxData.data))) = (ComponentsForLayer){
									.information = data92,
									.position = data00,
									.size = data10,
									.color = data20,
									.layer = data30
								};
								addSystem(&componentsForLayer, 0, lengthMatrix(&componentsForLayer) - 1, auxData);
							
							}
							// addLayers(entity);
							break;
						case MOVE:
							
							Information *data93 = getCell(&information, 0, lengthRow(&information, 0) - 1)->data;
							
							Position *data02 = getCell(&position, 0, lengthRow(&position, 0) - 1)->data;
							Direction *data12 = getCell(&direction, 0, lengthRow(&direction, 0) - 1)->data;
							Velocity *data22 = getCell(&velocity, 0, lengthRow(&velocity, 0) - 1)->data;
							Acceleration *data32 = getCell(&acceleration, 0, lengthRow(&acceleration, 0) - 1)->data;
							Size *data42 = getCell(&size, 0, lengthRow(&size, 0) - 1)->data;
							Collider *data52 = getCell(&collider, 0, lengthRow(&collider, 0) - 1)->data;

							if(
								data93->id == id &&
								data02->id == id &&
								data12->id == id &&
								data22->id == id &&
								data32->id == id &&
								data42->id == id &&
								data52->id == id
							){
								Data auxData;
								auxData.data = malloc(sizeof(ComponentsForCollision) * 1);
								(*((ComponentsForCollision*)(auxData.data))) = (ComponentsForCollision){
									.information = data93,
									.position = data02,
									.direction = data12,
									.velocity = data22,
									.acceleration = data32,
									.size = data42,
									.collider = data52
								};

								addSystem(&componentsForMove, 0, lengthMatrix(&componentsForMove) - 1, auxData);
							}

							break;
						case SCORE:
							
							Information *data95 = getCell(&information, 0, lengthRow(&information, 0) - 1)->data;
							
							Position *data04 = getCell(&position, 0, lengthRow(&position, 0) - 1)->data;
							Direction *data14 = getCell(&direction, 0, lengthRow(&direction, 0) - 1)->data;
							Velocity *data24 = getCell(&velocity, 0, lengthRow(&velocity, 0) - 1)->data;
							Acceleration *data34 = getCell(&acceleration, 0, lengthRow(&acceleration, 0) - 1)->data;
							Size *data44 = getCell(&size, 0, lengthRow(&size, 0) - 1)->data;
							Collider *data54 = getCell(&collider, 0, lengthRow(&collider, 0) - 1)->data;

							if(
								data95->id == id &&
								data04->id == id &&
								data14->id == id &&
								data24->id == id &&
								data34->id == id &&
								data44->id == id &&
								data54->id == id
							){
								Data auxData;
								auxData.data = malloc(sizeof(ComponentsForScore) * 1);
								(*((ComponentsForScore*)(auxData.data))) = (ComponentsForScore){
									.information = data95,
									.position = data04,
									.direction = data14,
									.velocity = data24,
									.acceleration = data34,
									.size = data44,
									.collider = data54
								};

								addSystem(&componentsForScore, 0, lengthMatrix(&componentsForScore) - 1, auxData);
							}

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

	// // // // printf("componentsForGravity %d\n", lengthRow(&componentsForGravity, 0));
	// // // // printf("componentsForCollision %d\n", lengthRow(&componentsForCollision, 0));
	// // // // printf("componentsForLayer %d\n", lengthRow(&componentsForLayer, 0));
	// // // // printf("componentsForMove %d\n", lengthRow(&componentsForMove, 0));

	// // // // printf("\n///////////////////\n");
	// // // // printf(  "/// END - SETUP ///\n");
	// // // // printf(  "///////////////////\n\n");

}

	// printf("\n%d - Setup\n", rand()%100);

	// printf("\n");

	// for (size_t i = 0; i < 12; i++){
	// 	for (size_t j = 0; j < 12; j++){
	// 		// // // // printf("%d", mapMatrix[i][j]);
	// 	}
	// 	// // // // printf("\n");
	// }
	// printf("\n");