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
bool getObjectAndVerify(const cJSON *const parent, const char *const string, cJSON** child, typeOBjectJson type);
bool getArrayAndVerify(const cJSON *const parent, int i, cJSON** child, typeOBjectJson type);

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

void printJSONScene(){
	initializeTemporaryComponent();
	cJSON* ents = NULL;
	cJSON* ent = NULL;
	cJSON* ind = NULL;
	cJSON* aux = NULL;
	cJSON* aux2 = NULL;
	if(!getObjectAndVerify(json, (char*){"entities"}, &ents, ARRAY)) return;
	// printf("entities type: %p\n", ents->type);
	for (size_t i = 0 ; i < getArraySize(ents) ; i++){
		if(!getArrayAndVerify(ents, i, &ent, OBJECT)) continue;
		// printf("item type: %p\n", ent->type);
		if(getObjectAndVerify(ent, (char*){"index"}, &ind, NUMBER)){
			// printf("index type: %p\n", aux->type);
			temporaryComponents[i].index = ind->valueint;
			// printf("%d - %d\n", temporaryComponents[i].index, ind->valueint);
		}
		if(!getObjectAndVerify(ent, (char*){"components"}, &ind, OBJECT)) continue;
		// printf("components type: %p\n", aux->type);
		if(getObjectAndVerify(ind, (char*){"information"}, &aux, OBJECT)){
			// printf("information type: %p\n", aux->type);
			setTypeAndLength(temporaryComponents, i, INFORMATION);
			if(getObjectAndVerify(aux, (char*){"name"}, &aux2, STRING)){
				strcpy(temporaryComponents[i].information.name, aux2->valuestring);
			}
			temporaryComponents[i].isThereInformation = true;
		}
		if(getObjectAndVerify(ind, (char*){"position"}, &aux, OBJECT)){
			// printf("position type: %p\n", aux->type);
			setTypeAndLength(temporaryComponents, i, POSITION);
			if(getObjectAndVerify(aux, (char*){"x"}, &aux2, NUMBER)){
				temporaryComponents[i].position.current2.x = aux2->valuedouble;
			}
			if(getObjectAndVerify(aux, (char*){"y"}, &aux2, NUMBER)){
				temporaryComponents[i].position.current2.y = aux2->valuedouble;
			}
			if(getObjectAndVerify(aux, (char*){"oldX"}, &aux2, NUMBER)){
				temporaryComponents[i].position.old2.x = aux2->valuedouble;
			}
			if(getObjectAndVerify(aux, (char*){"oldY"}, &aux2, NUMBER)){
				temporaryComponents[i].position.old2.y = aux2->valuedouble;
			}
			temporaryComponents[i].isTherePosition = true;
		}
		if(getObjectAndVerify(ind, (char*){"direction"}, &aux, OBJECT)){
			// printf("direction type: %p\n", aux->type);
			setTypeAndLength(temporaryComponents, i, DIRECTION);
			if(getObjectAndVerify(aux, (char*){"x"}, &aux2, NUMBER)){
				temporaryComponents[i].direction.vector2.x = aux2->valuedouble;
			}
			if(getObjectAndVerify(aux, (char*){"y"}, &aux2, NUMBER)){
				temporaryComponents[i].direction.vector2.y = aux2->valuedouble;
			}
			temporaryComponents[i].isThereDirection = true;
		}
		if(getObjectAndVerify(ind, (char*){"velocity"}, &aux, OBJECT)){
			// printf("velocity type: %p\n", aux->type);
			setTypeAndLength(temporaryComponents, i, VELOCITY);
			if(getObjectAndVerify(aux, (char*){"x"}, &aux2, NUMBER)){
				temporaryComponents[i].velocity.vector2.x = aux2->valuedouble;
			}
			if(getObjectAndVerify(aux, (char*){"y"}, &aux2, NUMBER)){
				temporaryComponents[i].velocity.vector2.y = aux2->valuedouble;
			}
			temporaryComponents[i].isThereVelocity = true;
		}
		if(getObjectAndVerify(ind, (char*){"acceleration"}, &aux, OBJECT)){
			// printf("acceleration type: %p\n", aux->type);
			setTypeAndLength(temporaryComponents, i, ACCELERATION);
			if(getObjectAndVerify(aux, (char*){"x"}, &aux2, NUMBER)){
				temporaryComponents[i].acceleration.vector2.x = aux2->valuedouble;
			}
			if(getObjectAndVerify(aux, (char*){"y"}, &aux2, NUMBER)){
				temporaryComponents[i].acceleration.vector2.y = aux2->valuedouble;
			}
			temporaryComponents[i].isThereAcceleration = true;
		}	
		if(getObjectAndVerify(ind, (char*){"size"}, &aux, OBJECT)){
			// printf("size type: %p\n", aux->type);
			setTypeAndLength(temporaryComponents, i, SIZE);
			if(getObjectAndVerify(aux, (char*){"width"}, &aux2, NUMBER)){
				temporaryComponents[i].size.vector2.x = (aux2->valuedouble == -1.0) ? WINDOW_WIDTH : aux2->valuedouble;
			}
			if(getObjectAndVerify(aux, (char*){"height"}, &aux2, NUMBER)){
				temporaryComponents[i].size.vector2.y = aux2->valuedouble;
			}
			temporaryComponents[i].isThereSize = true;
		}
		if(getObjectAndVerify(ind, (char*){"color"}, &aux, OBJECT)){
			// printf("color type: %p\n", aux->type);
			setTypeAndLength(temporaryComponents, i, COLOR);
			if(getObjectAndVerify(aux, (char*){"red"}, &aux2, NUMBER)){
				temporaryComponents[i].color.vector4.x = aux2->valueint;
			}
			if(getObjectAndVerify(aux, (char*){"green"}, &aux2, NUMBER)){
				temporaryComponents[i].color.vector4.y = aux2->valueint;
			}
			if(getObjectAndVerify(aux, (char*){"blue"}, &aux2, NUMBER)){
				temporaryComponents[i].color.vector4.z = aux2->valueint;
			}
			if(getObjectAndVerify(aux, (char*){"alpha"}, &aux2, NUMBER)){
				temporaryComponents[i].color.vector4.w = aux2->valueint;
			}
			temporaryComponents[i].isThereColor = true;
		}
		if(getObjectAndVerify(ind, (char*){"collider"}, &aux, OBJECT)){
			// printf("collider type: %p\n", aux->type);
			setTypeAndLength(temporaryComponents, i, COLLIDER);
			if(getObjectAndVerify(aux, (char*){"isItColliding"}, &aux2, NUMBER)){
				temporaryComponents[i].collider.isItColliding = (strcmp(aux2->valuestring, "true") == 0) ? true : false;
			}
			if(getObjectAndVerify(aux, (char*){"collisionDirection"}, &aux2, NUMBER)){
				temporaryComponents[i].collider.collisionDirection[0] = NULL;
				temporaryComponents[i].collider.collisionDirection[0] = NULL;
				temporaryComponents[i].collider.collisionDirection[0] = NULL;
				temporaryComponents[i].collider.collisionDirection[0] = NULL;
			}
			if(getObjectAndVerify(aux, (char*){"isStatic"}, &aux2, NUMBER)){

			}
			temporaryComponents[i].isThereCollider = true;
		}
		if(getObjectAndVerify(ind, (char*){"layer"}, &aux, OBJECT)){
			// printf("layer type: %p\n", aux->type);
			setTypeAndLength(temporaryComponents, i, LAYER);
			if(getObjectAndVerify(aux, (char*){"layer"}, &aux2, NUMBER)){
				temporaryComponents[i].layer.layer = aux2->valueint;
			}
			temporaryComponents[i].isThereLayer = true;
		}
		if(getObjectAndVerify(ind, (char*){"player"}, &aux, OBJECT)){
			// printf("player type: %p\n", aux->type);
			setTypeAndLength(temporaryComponents, i, PLAYER);
			temporaryComponents[i].isTherePlayer = true;
		}	
		if(getObjectAndVerify(ind, (char*){"collectible"}, &aux, OBJECT)){
			// printf("collectible type: %p\n", aux->type);
			setTypeAndLength(temporaryComponents, i, COLLECTIBLE);
			temporaryComponents[i].isThereCollectible= true;
		}
		if(getObjectAndVerify(ind, (char*){"anchor"}, &aux, OBJECT)){
			// printf("collectible type: %p\n", aux->type);
			setTypeAndLength(temporaryComponents, i, ANCHOR);
			temporaryComponents[i].isThereAnchor= true;
		}
		lengthtemporaryComponents++;
	}
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

bool getObjectAndVerify(const cJSON *const parent, const char *const string, cJSON** child, typeOBjectJson type){
	// printf("//////////////////////////\n");
	// printf("%st\n", string);
	// printf("//////////////////////////\n");
	*child = getObject(parent, string); 
	if(*child != NULL){
		// printf("%p\n", *child);
		// printf("%s\n", cJSON_Print(*child));
		return verify(*child, type);
	}
	// printf("NULL\n");
	return false;
}

bool getArrayAndVerify(const cJSON *const parent, int i, cJSON** child, typeOBjectJson type){
	// printf("//////////////////////////\n");
	// printf("%d\n", i);
	// printf("//////////////////////////\n");
	*child = getItemArray(parent, i); 
	if(*child != NULL){
		// printf("%p\n", *child);
		// printf("%s\n", cJSON_Print(*child));
		return verify(*child, type);
	}
	// printf("NULL\n");
	return false;
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

		temporaryComponents[i].isThereAnchor = false;
		temporaryComponents[i].anchor.id = -1;
		temporaryComponents[i].anchor.idParent = -1;

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
