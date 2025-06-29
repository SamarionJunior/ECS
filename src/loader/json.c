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

void initializeTemporaryComponent();
void printComponetTemporary();
void printJSONScene();

cJSON* getItemArray(const cJSON *array, int index);
bool verify(cJSON *object, typeOBjectJson type);
int getArraySize(const cJSON *array);
void printTypeAndLength(TemporaryComponent* temporaryComponents, int i);
void setTypeAndLength(TemporaryComponent* temporaryComponents, int i, TypesOfComponents type);
cJSON* getObject(const cJSON *const object, const char *const string);

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

cJSON* getItemArray(const cJSON *array, int index){
	// printf("array: %p\n", array);
	return cJSON_GetArrayItem(array, index);
}

bool verify(cJSON *object, typeOBjectJson type){
	return verifyTypeAndLength(object, type);
}

int getArraySize(const cJSON *array){
	return cJSON_GetArraySize(array);
}

void printTypeAndLength(TemporaryComponent* temporaryComponents, int i){
	printf(
		"\nType: %d - Length: %d\n", 
		temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes-1], 
		temporaryComponents[i].lengtharrayComponentTypes
	);
}

void setTypeAndLength(TemporaryComponent* temporaryComponents, int i, TypesOfComponents type){
	temporaryComponents[i].arrayComponentTypes[temporaryComponents[i].lengtharrayComponentTypes] = type;
	temporaryComponents[i].lengtharrayComponentTypes++;
}

cJSON * getObject(const cJSON * const object, const char * const string){
	return cJSON_GetObjectItemCaseSensitive(object, string);
}

// bool getObjectAndVerify(const cJSON *const parent, const char *const string, cJSON** child, typeOBjectJson type){
// 	*child = getObject(parent, (char*){"entities"}); 
// 	return verify(child, type);
// }

void printJSONScene(){

	initializeTemporaryComponent();

	cJSON *ents = getObject(json, (char*){"entities"}); 
	if(!verify(ents, ARRAY)) return;

	// cJSON *ents = NULL;
	// if(!getObjectAndVerify(json, (char*){"entities"}, &ents, ARRAY)) return;

	// printf("entities\n");

	for (size_t i = 0 ; i < getArraySize(ents) ; i++){

		// printf("i: %d\n", i);

		// printf("type: %p\n", ents);

		cJSON * ent = getItemArray(ents, i);

		// printf("type: %p\n", ent);

		if(!verify(ent, OBJECT)) continue;

		printf("i: %d\n", i);
		
		cJSON * index = getObject(ent, (char*){"index"});
		if(verify(index, NUMBER)){
			temporaryComponents[i].index = index->valueint;
		}
		// // // // printf("index json: %d\n", index->valueint);
		// // // // printf("temporaryComponents[i].index: %d\n", temporaryComponents[i].index);

		cJSON * comps = getObject(ent, (char*){"components"});
		if(!verify(comps, OBJECT)) continue;
			
		cJSON * infor = getObject(comps, (char*){"information"});
		if(verify(infor, OBJECT)){

			setTypeAndLength(temporaryComponents, i, INFORMATION);
			// printTypeAndLength(temporaryComponents, i);

			cJSON * name = getObject(infor, (char*){"name"});
			if(verify(name, STRING)){
				// printf("\n%s\n", name->valuestring);
				strcpy(temporaryComponents[i].information.name, name->valuestring);
			}

			temporaryComponents[i].isThereInformation = true;

		}
		
		cJSON * pos = getObject(comps, (char*){"position"});
		if(verify(pos, OBJECT)){

			setTypeAndLength(temporaryComponents, i, POSITION);
			// printTypeAndLength(temporaryComponents, i);

			cJSON * x = getObject(pos, (char*){"x"});
			if(verify(x, NUMBER)){
				// printf("\n%f\n", x->valuedouble);
				temporaryComponents[i].position.current2.x = x->valuedouble;
			}

			cJSON * y = getObject(pos, (char*){"y"});
			if(verify(y, NUMBER)){
				// printf("\n%f\n", y->valuedouble);
				temporaryComponents[i].position.current2.y = y->valuedouble;
			}

			cJSON * oldX = getObject(pos, (char*){"oldX"});
			if(verify(oldX, NUMBER)){
				// printf("\n%f\n", x->valuedouble);
				temporaryComponents[i].position.old2.x = oldX->valuedouble;
			}

			cJSON * oldY = getObject(pos, (char*){"oldY"});
			if(verify(oldY, NUMBER)){
				// printf("\n%f\n", y->valuedouble);
				temporaryComponents[i].position.old2.y = oldY->valuedouble;
			}

			temporaryComponents[i].isTherePosition = true;

		}
		
		cJSON * dir = getObject(comps, (char*){"direction"});
		if(verify(dir, OBJECT)){

			setTypeAndLength(temporaryComponents, i, DIRECTION);
			// printTypeAndLength(temporaryComponents, i);

			cJSON * x = getObject(dir, (char*){"x"});
			if(verify(x, NUMBER)){
				// printf("\n%f\n", x->valuedouble);
				temporaryComponents[i].direction.vector2.x = x->valuedouble;
			}

			cJSON * y = getObject(dir, (char*){"y"});
			if(verify(y, NUMBER)){
				// printf("\n%f\n", y->valuedouble);
				temporaryComponents[i].direction.vector2.y = y->valuedouble;
			}

			temporaryComponents[i].isThereDirection = true;

		}
		
		cJSON * vel = getObject(comps, (char*){"velocity"});
		if(verify(vel, OBJECT)){

			setTypeAndLength(temporaryComponents, i, VELOCITY);
			// printTypeAndLength(temporaryComponents, i);

			cJSON * x = getObject(vel, (char*){"x"});
			if(verify(x, NUMBER)){
				// printf("\n%f\n", x->valuedouble);
				temporaryComponents[i].velocity.vector2.x = x->valuedouble;
			}

			cJSON * y = getObject(vel, (char*){"y"});
			if(verify(y, NUMBER)){
				// printf("\n%f\n", y->valuedouble);
				temporaryComponents[i].velocity.vector2.y = y->valuedouble;
			}

			temporaryComponents[i].isThereVelocity = true;

		}
		
		cJSON * acc = getObject(comps, (char*){"acceleration"});
		if(verify(acc, OBJECT)){

			setTypeAndLength(temporaryComponents, i, ACCELERATION);
			// printTypeAndLength(temporaryComponents, i);

			cJSON * x = getObject(acc, (char*){"x"});
			if(verify(x, NUMBER)){
				// printf("\n%f\n", x->valuedouble);
				temporaryComponents[i].acceleration.vector2.x = x->valuedouble;
			}

			cJSON * y = getObject(acc, (char*){"y"});
			if(verify(y, NUMBER)){
				// printf("\n%f\n", y->valuedouble);
				temporaryComponents[i].acceleration.vector2.y = y->valuedouble;
			}

			temporaryComponents[i].isThereAcceleration = true;

		}
		
		cJSON * siz = getObject(comps, (char*){"size"});
		if(verify(siz, OBJECT)){

			setTypeAndLength(temporaryComponents, i, SIZE);
			// printTypeAndLength(temporaryComponents, i);

			cJSON * width = getObject(siz, (char*){"width"});
			if(verify(width, NUMBER)){
				// printf("\n%f\n", width->valuedouble);
				temporaryComponents[i].size.vector2.x = (width->valuedouble == -1.0) ? WINDOW_WIDTH : width->valuedouble;
				// printf("\nwidth: %f\n", temporaryComponents[i].size.width);
			}

			cJSON * height = getObject(siz, (char*){"height"});
			if(verify(height, NUMBER)){
				// printf("\n%f\n", height->valuedouble);
				temporaryComponents[i].size.vector2.y = height->valuedouble;
			}

			temporaryComponents[i].isThereSize = true;

		}
		
		cJSON * col = getObject(comps, (char*){"color"});
		if(verify(col, OBJECT)){

			setTypeAndLength(temporaryComponents, i, COLOR);
			// printTypeAndLength(temporaryComponents, i);

			cJSON * red = getObject(col, (char*){"red"});
			if(verify(red, NUMBER)){
				// printf("\n%d\n", red->valueint);
				temporaryComponents[i].color.vector4.x = red->valueint;
			}

			cJSON * green = getObject(col, (char*){"green"});
			if(verify(green, NUMBER)){
				// printf("\n%d\n", green->valueint);
				temporaryComponents[i].color.vector4.y = green->valueint;
			}

			cJSON * blue = getObject(col, (char*){"blue"});
			if(verify(blue, NUMBER)){
				// printf("\n%d\n", blue->valueint);
				temporaryComponents[i].color.vector4.z = blue->valueint;
			}

			cJSON * alpha = getObject(col, (char*){"alpha"});
			if(verify(alpha, NUMBER)){
				// printf("\n%d\n", alpha->valueint);
				temporaryComponents[i].color.vector4.w = alpha->valueint;
			}

			temporaryComponents[i].isThereColor = true;

		}
		
		cJSON * coll = getObject(comps, (char*){"collider"});
		if(verify(coll, OBJECT)){

			setTypeAndLength(temporaryComponents, i, COLLIDER);
			// printTypeAndLength(temporaryComponents, i);

			cJSON * isItColliding = getObject(coll, (char*){"isItColliding"});
			if(verify(isItColliding, STRING)){
				// printf("\n%s\n", isItColliding->valuestring);
				temporaryComponents[i].collider.isItColliding = (strcmp(isItColliding->valuestring, "true") == 0) ? true : false;
			}

			cJSON * collDir = getObject(coll, (char*){"collisionDirection"});
			if(verify(collDir, STRING)){
				// printf("\n%s\n", direc->valuestring);
				// (direc->string == "NULL") ? NULL : NULL
				temporaryComponents[i].collider.collisionDirection[0] = NULL;
				temporaryComponents[i].collider.collisionDirection[0] = NULL;
				temporaryComponents[i].collider.collisionDirection[0] = NULL;
				temporaryComponents[i].collider.collisionDirection[0] = NULL;
			}

			cJSON * isStatic = getObject(coll, (char*){"isStatic"});
			// if(verify(isStatic, STRING)){
			// 	// // // // printf("\n%s\n", isStatic->valuestring);
			// 	temporaryComponents[i].collider.isStatic = (strcmp(isStatic->valuestring, "true") == 0) ? true : false;
			// 	// // // // printf("\n%d\n", temporaryComponents[i].collider.isStatic);
			// }

			temporaryComponents[i].isThereCollider = true;

		}
		
		cJSON * laye = getObject(comps, (char*){"layer"});
		if(verify(laye, OBJECT)){

			setTypeAndLength(temporaryComponents, i, LAYER);
			// printTypeAndLength(temporaryComponents, i);

			cJSON * lay = getObject(laye, (char*){"layer"});
			if(verify(lay, NUMBER)){
				// printf("\n%d\n", lay->valueint);
				temporaryComponents[i].layer.layer = lay->valueint;
			}

			temporaryComponents[i].isThereLayer = true;

		}
		
		cJSON * play = getObject(comps, (char*){"player"});
		if(verify(play, OBJECT)){

			setTypeAndLength(temporaryComponents, i, PLAYER);

			// printTypeAndLength(temporaryComponents, i);

			// cJSON * lay = getObject(laye, "id");
			// if(verify(lay, NUMBER)){
			// 	// printf("\n%d\n", lay->valueint);
			// 	temporaryComponents[i].layer.layer = lay->valueint;
			// }

			temporaryComponents[i].isTherePlayer = true;

		}
		
		cJSON * collectib = getObject(comps, (char*){"collectible"});
		if(verify(collectib, OBJECT)){

			setTypeAndLength(temporaryComponents, i, COLLECTIBLE);

			// printTypeAndLength(temporaryComponents, i);

			// cJSON * lay = getObject(laye, "id");
			// if(verify(lay, NUMBER)){
			// 	// printf("\n%d\n", lay->valueint);
			// 	temporaryComponents[i].layer.layer = lay->valueint;
			// }

			temporaryComponents[i].isThereCollectible= true;

		}
	
		// cJSON * systs = getObject(ent, "systems");
		// if(!verify(systs, ARRAY)) return;
		// for (size_t j = 0 ; j < cJSON_GetArraySize(systs) ; j++){
		// 	cJSON * syst = cJSON_GetArrayItem(systs, j);
		// 	if(verify(syst, NUMBER)){
		// 		// printf("\nSystem: %d\n", syst->valueint);
		// 		temporaryComponents[i].arraySystems[j] = syst->valueint;
		// 		temporaryComponents[i].lengthArraySystems++;
		// 	}

		// }

		lengthtemporaryComponents++;

	}

}

void initializeTemporaryComponent(){

	lengthtemporaryComponents = 0;

	for (size_t i = 0; i < 10; i++){
		temporaryComponents[i].index = -1;
		// temporaryComponents[i].lengthArraySystems = 0;
		temporaryComponents[i].lengtharrayComponentTypes = 0;
		for (size_t j = 0; j < TOTALCOMPONENTS; j++){
			temporaryComponents[i].arrayComponentTypes[j] = -1;
		}
		// for (size_t j = 0; j < MAX_SYSTEMS; j++){
		// 	temporaryComponents[i].arraySystems[j] = 0;
		// }

		temporaryComponents[i].isThereInformation = false;
		temporaryComponents[i].information.id = -1;
		temporaryComponents[i].information.name = malloc(sizeof(char)*10);

		temporaryComponents[i].isTherePosition = false;
		temporaryComponents[i].position.id = -1;
		temporaryComponents[i].position.current2.x = 0;
		temporaryComponents[i].position.current2.y = 0;
		temporaryComponents[i].position.old2.x = 0;
		temporaryComponents[i].position.old2.y = 0;

		temporaryComponents[i].isThereDirection = false;
		temporaryComponents[i].direction.id = -1;
		temporaryComponents[i].direction.vector2.x = 0;
		temporaryComponents[i].direction.vector2.y = 0;

		temporaryComponents[i].isThereVelocity = false;
		temporaryComponents[i].velocity.id = -1;
		temporaryComponents[i].velocity.vector2.x = 0;
		temporaryComponents[i].velocity.vector2.y = 0;

		temporaryComponents[i].isThereAcceleration = false;
		temporaryComponents[i].acceleration.id = -1;
		temporaryComponents[i].acceleration.vector2.x = 0;
		temporaryComponents[i].acceleration.vector2.y = 0;

		temporaryComponents[i].isThereSize = false;
		temporaryComponents[i].size.id = -1;
		temporaryComponents[i].size.vector2.x = 0;
		temporaryComponents[i].size.vector2.y = 0;

		temporaryComponents[i].isThereColor = false;
		temporaryComponents[i].color.id = -1;
		temporaryComponents[i].color.vector4.x = 0;
		temporaryComponents[i].color.vector4.y = 0;
		temporaryComponents[i].color.vector4.z = 0;
		temporaryComponents[i].color.vector4.w = 0;

		temporaryComponents[i].isThereCollider = false;
		temporaryComponents[i].collider.id = -1;
		temporaryComponents[i].collider.isItColliding = false;
		for (size_t j = 0; j < TOTALCOORDENATE; j++){
			temporaryComponents[i].collider.collisionDirection[j] = 0;
		}
		temporaryComponents[i].collider.isStatic = true;

		temporaryComponents[i].isThereLayer = false;
		temporaryComponents[i].layer.id = -1;
		temporaryComponents[i].layer.layer = 0;

		temporaryComponents[i].isTherePlayer = false;
		temporaryComponents[i].player.id = -1;

		temporaryComponents[i].isThereCollectible = false;
		temporaryComponents[i].collectible.id = -1;

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
