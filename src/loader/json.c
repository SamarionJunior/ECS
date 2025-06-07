#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../architecture/components/components.h"

#include "../architecture/entities/entities.h"
#include "../architecture/systems/systems.h"

#include "../constants.h"

#include "../../dependencies/mycustom/myjson.h"

#include "json.h"

int lengthtemporaryComponents = 0;

TemporaryComponent temporaryComponents[10];

void printJSONScene(){

	lengthtemporaryComponents = 0;

	for (size_t i = 0; i < 10; i++){
		temporaryComponents[i].index = -1;
		temporaryComponents[i].lengthArraySystems = 0;
		temporaryComponents[i].lengtharrayComponentTypes = 0;
		for (size_t j = 0; j < TOTALCOMPONENTS; j++){
			temporaryComponents[i].arrayComponentTypes[j] = -1;
		}
		for (size_t j = 0; j < MAX_SYSTEMS; j++){
			temporaryComponents[i].arraySystems[j] = 0;
		}

		temporaryComponents[i].information.id = -1;
		temporaryComponents[i].information.name = malloc(sizeof(char)*10);
		temporaryComponents[i].position.id = -1;
		temporaryComponents[i].position.current2.x = 0;
		temporaryComponents[i].position.current2.y = 0;
		temporaryComponents[i].position.old2.x = 0;
		temporaryComponents[i].position.old2.y = 0;
		temporaryComponents[i].direction.id = -1;
		temporaryComponents[i].direction.vector2.x = 0;
		temporaryComponents[i].direction.vector2.y = 0;
		temporaryComponents[i].velocity.id = -1;
		temporaryComponents[i].velocity.vector2.x = 0;
		temporaryComponents[i].velocity.vector2.y = 0;
		temporaryComponents[i].acceleration.id = -1;
		temporaryComponents[i].acceleration.vector2.x = 0;
		temporaryComponents[i].acceleration.vector2.y = 0;
		temporaryComponents[i].size.id = -1;
		temporaryComponents[i].size.vector2.x = 0;
		temporaryComponents[i].size.vector2.y = 0;
		temporaryComponents[i].color.id = -1;
		temporaryComponents[i].color.vector4.x = 0;
		temporaryComponents[i].color.vector4.y = 0;
		temporaryComponents[i].color.vector4.z = 0;
		temporaryComponents[i].color.vector4.w = 0;
		temporaryComponents[i].collider.id = -1;
		temporaryComponents[i].collider.isItColliding = false;

		for (size_t j = 0; j < TOTALCOORDENATE; j++){
			temporaryComponents[i].collider.collisionDirection[j] = 0;
		}

		temporaryComponents[i].collider.isStatic = true;
		temporaryComponents[i].layer.id = -1;
		temporaryComponents[i].layer.layer = 0;
		temporaryComponents[i].player.id = -1;
		temporaryComponents[i].collectible.id = -1;
	}

    cJSON *ents = cJSON_GetObjectItemCaseSensitive(json, "entities"); 
    if(!verifyTypeAndLength(ents, ARRAY)) return;

    for (size_t i = 0 ; i < cJSON_GetArraySize(ents) ; i++){

        cJSON * ent = cJSON_GetArrayItem(ents, i);
        if(verifyTypeAndLength(ent, OBJECT)){
			
			cJSON * index = cJSON_GetObjectItemCaseSensitive(ent, "index");
			// // // // printf("index json: %d\n", index->valueint);

			temporaryComponents[i].index = index->valueint;
			// // // // printf("temporaryComponents[i].index: %d\n", temporaryComponents[i].index);

			cJSON * comps = cJSON_GetObjectItemCaseSensitive(ent, "components");
			if(verifyTypeAndLength(comps, OBJECT)){
				
				cJSON * infor = cJSON_GetObjectItemCaseSensitive(comps, "information");
				if(verifyTypeAndLength(infor, OBJECT)){

					temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes] = INFORMATION;
					temporaryComponents[i].lengtharrayComponentTypes++;

					// printf(
					// 	"\nType: %d - Length: %d\n", 
					// 	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
					// 	temporaryComponents[i].lengtharrayComponentTypes
					// );

					cJSON * name = cJSON_GetObjectItemCaseSensitive(infor, "name");
					if(verifyTypeAndLength(name, STRING)){
						// printf("\n%s\n", name->valuestring);
						strcpy(temporaryComponents[i].information.name, name->valuestring);
					}

					// printf(
					// 	"\nType: %d - Length: %d\n", 
					// 	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
					// 	temporaryComponents[i].lengtharrayComponentTypes
					// );

				}
				
				cJSON * pos = cJSON_GetObjectItemCaseSensitive(comps, "position");
				if(verifyTypeAndLength(pos, OBJECT)){

					temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes] = POSITION;
					temporaryComponents[i].lengtharrayComponentTypes++;

					// printf(
					// 	"\nType: %d - Length: %d\n", 
					// 	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
					// 	temporaryComponents[i].lengtharrayComponentTypes
					// );

					cJSON * x = cJSON_GetObjectItemCaseSensitive(pos, "x");
					if(verifyTypeAndLength(x, NUMBER)){
						// printf("\n%f\n", x->valuedouble);
						temporaryComponents[i].position.current2.x = x->valuedouble;
					}

					cJSON * y = cJSON_GetObjectItemCaseSensitive(pos, "y");
					if(verifyTypeAndLength(y, NUMBER)){
						// printf("\n%f\n", y->valuedouble);
						temporaryComponents[i].position.current2.y = y->valuedouble;
					}

					cJSON * oldX = cJSON_GetObjectItemCaseSensitive(pos, "oldX");
					if(verifyTypeAndLength(oldX, NUMBER)){
						// printf("\n%f\n", x->valuedouble);
						temporaryComponents[i].position.old2.x = oldX->valuedouble;
					}

					cJSON * oldY = cJSON_GetObjectItemCaseSensitive(pos, "oldY");
					if(verifyTypeAndLength(oldY, NUMBER)){
						// printf("\n%f\n", y->valuedouble);
						temporaryComponents[i].position.old2.y = oldY->valuedouble;
					}

					// printf(
					// 	"\nType: %d - Length: %d\n", 
					// 	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
					// 	temporaryComponents[i].lengtharrayComponentTypes
					// );

				}
				
				cJSON * dir = cJSON_GetObjectItemCaseSensitive(comps, "direction");
				if(verifyTypeAndLength(dir, OBJECT)){

					temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes] = DIRECTION;
					temporaryComponents[i].lengtharrayComponentTypes++;

					cJSON * x = cJSON_GetObjectItemCaseSensitive(dir, "x");
					if(verifyTypeAndLength(x, NUMBER)){
						// printf("\n%f\n", x->valuedouble);
						temporaryComponents[i].direction.vector2.x = x->valuedouble;
					}

					cJSON * y = cJSON_GetObjectItemCaseSensitive(dir, "y");
					if(verifyTypeAndLength(y, NUMBER)){
						// printf("\n%f\n", y->valuedouble);
						temporaryComponents[i].direction.vector2.y = y->valuedouble;
					}

				}
				
				cJSON * vel = cJSON_GetObjectItemCaseSensitive(comps, "velocity");
				if(verifyTypeAndLength(vel, OBJECT)){

					temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes] = VELOCITY;
					temporaryComponents[i].lengtharrayComponentTypes++;

					cJSON * x = cJSON_GetObjectItemCaseSensitive(vel, "x");
					if(verifyTypeAndLength(x, NUMBER)){
						// printf("\n%f\n", x->valuedouble);
						temporaryComponents[i].velocity.vector2.x = x->valuedouble;
					}

					cJSON * y = cJSON_GetObjectItemCaseSensitive(vel, "y");
					if(verifyTypeAndLength(y, NUMBER)){
						// printf("\n%f\n", y->valuedouble);
						temporaryComponents[i].velocity.vector2.y = y->valuedouble;
					}

				}
				
				cJSON * acc = cJSON_GetObjectItemCaseSensitive(comps, "acceleration");
				if(verifyTypeAndLength(acc, OBJECT)){

					temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes] = ACCELERATION;
					temporaryComponents[i].lengtharrayComponentTypes++;

					cJSON * x = cJSON_GetObjectItemCaseSensitive(acc, "x");
					if(verifyTypeAndLength(x, NUMBER)){
						// printf("\n%f\n", x->valuedouble);
						temporaryComponents[i].acceleration.vector2.x = x->valuedouble;
					}

					cJSON * y = cJSON_GetObjectItemCaseSensitive(acc, "y");
					if(verifyTypeAndLength(y, NUMBER)){
						// printf("\n%f\n", y->valuedouble);
						temporaryComponents[i].acceleration.vector2.y = y->valuedouble;
					}

				}
				
				cJSON * siz = cJSON_GetObjectItemCaseSensitive(comps, "size");
				if(verifyTypeAndLength(siz, OBJECT)){

					temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes] = SIZE;
					temporaryComponents[i].lengtharrayComponentTypes++;

					// printf(
					// 	"\nType: %d - Length: %d\n", 
					// 	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
					// 	temporaryComponents[i].lengtharrayComponentTypes
					// );

					cJSON * width = cJSON_GetObjectItemCaseSensitive(siz, "width");
					if(verifyTypeAndLength(width, NUMBER)){
						// printf("\n%f\n", width->valuedouble);
						temporaryComponents[i].size.vector2.x = (width->valuedouble == -1.0) ? WINDOW_WIDTH : width->valuedouble;
						// printf("\nwidth: %f\n", temporaryComponents[i].size.width);
					}

					cJSON * height = cJSON_GetObjectItemCaseSensitive(siz, "height");
					if(verifyTypeAndLength(height, NUMBER)){
						// printf("\n%f\n", height->valuedouble);
						temporaryComponents[i].size.vector2.y = height->valuedouble;
					}

					// printf(
					// 	"\nType: %d - Length: %d\n", 
					// 	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
					// 	temporaryComponents[i].lengtharrayComponentTypes
					// );

				}
				
				cJSON * col = cJSON_GetObjectItemCaseSensitive(comps, "color");
				if(verifyTypeAndLength(col, OBJECT)){

					temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes] = COLOR;
					temporaryComponents[i].lengtharrayComponentTypes++;

					// printf(
					// 	"\nType: %d - Length: %d\n", 
					// 	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
					// 	temporaryComponents[i].lengtharrayComponentTypes
					// );

					cJSON * red = cJSON_GetObjectItemCaseSensitive(col, "red");
					if(verifyTypeAndLength(red, NUMBER)){
						// printf("\n%d\n", red->valueint);
						temporaryComponents[i].color.vector4.x = red->valueint;
					}

					cJSON * green = cJSON_GetObjectItemCaseSensitive(col, "green");
					if(verifyTypeAndLength(green, NUMBER)){
						// printf("\n%d\n", green->valueint);
						temporaryComponents[i].color.vector4.y = green->valueint;
					}

					cJSON * blue = cJSON_GetObjectItemCaseSensitive(col, "blue");
					if(verifyTypeAndLength(blue, NUMBER)){
						// printf("\n%d\n", blue->valueint);
						temporaryComponents[i].color.vector4.z = blue->valueint;
					}

					cJSON * alpha = cJSON_GetObjectItemCaseSensitive(col, "alpha");
					if(verifyTypeAndLength(alpha, NUMBER)){
						// printf("\n%d\n", alpha->valueint);
						temporaryComponents[i].color.vector4.w = alpha->valueint;
					}

					// printf(
					// 	"\nType: %d - Length: %d\n", 
					// 	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
					// 	temporaryComponents[i].lengtharrayComponentTypes
					// );

				}
				
				cJSON * coll = cJSON_GetObjectItemCaseSensitive(comps, "collider");
				if(verifyTypeAndLength(coll, OBJECT)){

					temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes] = COLLIDER;
					temporaryComponents[i].lengtharrayComponentTypes++;

					// printf(
					// 	"\nType: %d - Length: %d\n", 
					// 	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
					// 	temporaryComponents[i].lengtharrayComponentTypes
					// );

					cJSON * isItColliding = cJSON_GetObjectItemCaseSensitive(coll, "isItColliding");
					if(verifyTypeAndLength(isItColliding, STRING)){
						// printf("\n%s\n", isItColliding->valuestring);
						temporaryComponents[i].collider.isItColliding = (strcmp(isItColliding->valuestring, "true") == 0) ? true : false;
					}

					cJSON * collDir = cJSON_GetObjectItemCaseSensitive(coll, "collisionDirection");
					if(verifyTypeAndLength(collDir, STRING)){
						// printf("\n%s\n", direc->valuestring);
						// (direc->string == "NULL") ? NULL : NULL
						temporaryComponents[i].collider.collisionDirection[0] = NULL;
						temporaryComponents[i].collider.collisionDirection[0] = NULL;
						temporaryComponents[i].collider.collisionDirection[0] = NULL;
						temporaryComponents[i].collider.collisionDirection[0] = NULL;
					}

					cJSON * isStatic = cJSON_GetObjectItemCaseSensitive(coll, "isStatic");
					// if(verifyTypeAndLength(isStatic, STRING)){
					// 	// // // // printf("\n%s\n", isStatic->valuestring);
					// 	temporaryComponents[i].collider.isStatic = (strcmp(isStatic->valuestring, "true") == 0) ? true : false;
					// 	// // // // printf("\n%d\n", temporaryComponents[i].collider.isStatic);
					// }

					// printf(
					// 	"\nType: %d - Length: %d\n", 
					// 	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
					// 	temporaryComponents[i].lengtharrayComponentTypes
					// );

				}
				
				cJSON * laye = cJSON_GetObjectItemCaseSensitive(comps, "layer");
				if(verifyTypeAndLength(laye, OBJECT)){

					temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes] = LAYER;
					temporaryComponents[i].lengtharrayComponentTypes++;

					// printf(
					// 	"\nType: %d - Length: %d\n", 
					// 	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
					// 	temporaryComponents[i].lengtharrayComponentTypes
					// );

					cJSON * lay = cJSON_GetObjectItemCaseSensitive(laye, "layer");
					if(verifyTypeAndLength(lay, NUMBER)){
						// printf("\n%d\n", lay->valueint);
						temporaryComponents[i].layer.layer = lay->valueint;
					}

					// printf(
					// 	"\nType: %d - Length: %d\n", 
					// 	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
					// 	temporaryComponents[i].lengtharrayComponentTypes
					// );

				}
				
				cJSON * play = cJSON_GetObjectItemCaseSensitive(comps, "player");
				if(verifyTypeAndLength(play, OBJECT)){

					temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes] = PLAYER;
					temporaryComponents[i].lengtharrayComponentTypes++;

					// printf(
					// 	"\nType: %d - Length: %d\n", 
					// 	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
					// 	temporaryComponents[i].lengtharrayComponentTypes
					// );

					// cJSON * lay = cJSON_GetObjectItemCaseSensitive(laye, "id");
					// if(verifyTypeAndLength(lay, NUMBER)){
					// 	// printf("\n%d\n", lay->valueint);
					// 	temporaryComponents[i].layer.layer = lay->valueint;
					// }

					// printf(
					// 	"\nType: %d - Length: %d\n", 
					// 	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
					// 	temporaryComponents[i].lengtharrayComponentTypes
					// );

				}
				cJSON * collectib = cJSON_GetObjectItemCaseSensitive(comps, "collectible");
				if(verifyTypeAndLength(collectib, OBJECT)){

					temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes] = COLLECTIBLE;
					temporaryComponents[i].lengtharrayComponentTypes++;

					// printf(
					// 	"\nType: %d - Length: %d\n", 
					// 	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
					// 	temporaryComponents[i].lengtharrayComponentTypes
					// );

					// cJSON * lay = cJSON_GetObjectItemCaseSensitive(laye, "id");
					// if(verifyTypeAndLength(lay, NUMBER)){
					// 	// printf("\n%d\n", lay->valueint);
					// 	temporaryComponents[i].layer.layer = lay->valueint;
					// }

					// printf(
					// 	"\nType: %d - Length: %d\n", 
					// 	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
					// 	temporaryComponents[i].lengtharrayComponentTypes
					// );

				}
			}
			
			cJSON * systs = cJSON_GetObjectItemCaseSensitive(ent, "systems");
			if(!verifyTypeAndLength(systs, ARRAY)) return;
			for (size_t j = 0 ; j < cJSON_GetArraySize(systs) ; j++){
				cJSON * syst = cJSON_GetArrayItem(systs, j);
				if(verifyTypeAndLength(syst, NUMBER)){
					// printf("\nSystem: %d\n", syst->valueint);
					temporaryComponents[i].arraySystems[j] = syst->valueint;
					temporaryComponents[i].lengthArraySystems++;
				}

			}
		
		}
		lengthtemporaryComponents++;
    }

}

void printComponetTemporary(){
	
	// // // // printf("\n");

	for (size_t i = 0; i < lengthtemporaryComponents; i++){

	// 	// // // // printf("\n[%d]\n\n", i);

	// 	// // // // printf("temporaryComponents[i].index = %d\n", temporaryComponents[i].index);
	// 	// // // // printf("temporaryComponents[i].lengthArraySystems = %d\n", temporaryComponents[i].lengthArraySystems);
	// 	// // // // printf("temporaryComponents[i].lengtharrayComponentTypes = %d\n", temporaryComponents[i].lengtharrayComponentTypes);
		
	// 	for (size_t j = 0; j < QTD_TYPE_COMPONENTS; j++){
	// 		// // // // printf("temporaryComponents[i].arrayComponentTypes[j] = %d\n", temporaryComponents[i].arrayComponentTypes[j]);
	// 	}
	// 	for (size_t j = 0; j < MAX_SYSTEMS; j++){
	// 		// // // // printf("temporaryComponents[i].arraySystems[j] = %d\n", temporaryComponents[i].arraySystems[j]);
	// 	}

	// 	// // // // printf("temporaryComponents[i].information.id = %d\n", temporaryComponents[i].information.id);
		// // // // printf("temporaryComponents[i].information.name = %s\n", temporaryComponents[i].information.name);
	// 	// // // // printf("temporaryComponents[i].position.id = %d\n", temporaryComponents[i].position.id);
	// 	// // // // printf("temporaryComponents[i].position.current2.x = %f\n", temporaryComponents[i].position.current2.x);
	// 	// // // // printf("temporaryComponents[i].position.current2.y = %f\n", temporaryComponents[i].position.current2.y);
	// 	// // // // printf("temporaryComponents[i].position.old2.x = %f\n", temporaryComponents[i].position.old2.x);
	// 	// // // // printf("temporaryComponents[i].position.old2.y = %f\n", temporaryComponents[i].position.old2.y);
	// 	// // // // printf("temporaryComponents[i].direction.id = %d\n", temporaryComponents[i].direction.id);
	// 	// // // // printf("temporaryComponents[i].direction.vector2.x = %f\n", temporaryComponents[i].direction.vector2.x);
	// 	// // // // printf("temporaryComponents[i].direction.vector2. = %f\n", temporaryComponents[i].direction.vector2.y);
	// 	// // // // printf("temporaryComponents[i].velocity.id = %d\n", temporaryComponents[i].velocity.id);
	// 	// // // // printf("temporaryComponents[i].velocity.vector2.x = %f\n", temporaryComponents[i].velocity.vector2.x);
	// 	// // // // printf("temporaryComponents[i].velocity.vector2.y = %f\n", temporaryComponents[i].velocity.vector2.y);
	// 	// // // // printf("temporaryComponents[i].acceleration.id = %d\n", temporaryComponents[i].acceleration.id);
	// 	// // // // printf("temporaryComponents[i].acceleration.vector2.x = %f\n", temporaryComponents[i].acceleration.vector2.x);
	// 	// // // // printf("temporaryComponents[i].acceleration.vector2.y = %f\n", temporaryComponents[i].acceleration.vector2.y);
	// 	// // // // printf("temporaryComponents[i].size.id = %d\n", temporaryComponents[i].size.id);
	// 	// // // // printf("temporaryComponents[i].size.vector2.x = %f\n", temporaryComponents[i].size.vector2.x);
	// 	// // // // printf("temporaryComponents[i].size.vector2.y = %f\n", temporaryComponents[i].size.vector2.y);
	// 	// // // // printf("temporaryComponents[i].color.id = %d\n", temporaryComponents[i].color.id);
	// 	// // // // printf("temporaryComponents[i].color.vector4.x = %f\n", temporaryComponents[i].color.vector4.x);
	// 	// // // // printf("temporaryComponents[i].color.vector4.y = %f\n", temporaryComponents[i].color.vector4.y);
	// 	// // // // printf("temporaryComponents[i].color.vector4.z = %f\n", temporaryComponents[i].color.vector4.z);
	// 	// // // // printf("temporaryComponents[i].color.vector4.w = %f\n", temporaryComponents[i].color.vector4.w);
	// 	// // // // printf("temporaryComponents[i].collider.id = %d\n", temporaryComponents[i].collider.id);
	// 	// // // // printf("temporaryComponents[i].collider.isItColliding = %d\n", temporaryComponents[i].collider.isItColliding);
	// 	// // // // printf("temporaryComponents[i].collider.collisionDirection[0] = %d\n", temporaryComponents[i].collider.collisionDirection[0]);
	// 	// // // // printf("temporaryComponents[i].collider.collisionDirection[1] = %d\n", temporaryComponents[i].collider.collisionDirection[1]);
	// 	// // // // printf("temporaryComponents[i].collider.collisionDirection[2] = %d\n", temporaryComponents[i].collider.collisionDirection[2]);
	// 	// // // // printf("temporaryComponents[i].collider.collisionDirection[3] = %d\n", temporaryComponents[i].collider.collisionDirection[3]);
	// 	// // // // printf("temporaryComponents[i].collider.isStatic = %d\n", temporaryComponents[i].collider.isStatic);
	// 	// // // // printf("temporaryComponents[i].layer.layer = %d\n", temporaryComponents[i].layer.layer);
		
	}
	
}

void loadJSON(){

	// // // // printf("\n/////////////////\n");
	// // // // printf(  "/// LOAD JSON ///\n");
	// // // // printf(  "/////////////////\n\n");

	nameFileJson = "data/scene.json";
	readJSON(&printJSONScene);
	printComponetTemporary();

	// // // // printf("\n///////////////////////\n");
	// // // // printf(  "/// END - LOAD JSON ///\n");
	// // // // printf(  "///////////////////////\n\n");
}