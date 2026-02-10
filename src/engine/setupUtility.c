#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "setupUtility.h"

#include "../architecture/components/components.h"

#include "../architecture/entities/entities.h"
#include "../architecture/entities/utility.h"

#include "../architecture/systems/systems.h"

#include "../constants.h"

#include "../../dependencies/mycustom/myjson.h"

#include "../loader/json.h"
#include "../loader/map.h"

#include "../utilities/space.h"
void addComponentsinEntity(TemporaryEntity te);
void createKindComponents(TemporaryEntity te);

////////////////////////////////////

void addComponentInEntity(void* component, Array* destino){

	((Id*)(component))->id = getId();

	// printf("Length: %d Address: %p\n", lengthArray(destino), destino);

	addArray(
		destino, 
		lengthArray(destino), 
		component
	);

}

void addComponentsinEntity(TemporaryEntity te){
	for (size_t l = 0; l < lengthArray(te.componentAndTypes); l++){
		ComponentAndType cap = *((ComponentAndType*)(getArray(te.componentAndTypes, l)));
		// printf("type: %s\n", namesOfCompenents[cap.type]);
		switch (cap.type){
			case INFORMATION:
				addComponentInEntity(
					cap.component, 
					arrayOfArrayComponents[INFORMATION]
				);
				break;
			case POSITION:
				// printf("\n-AFTER-> lengthCollumnPosition: %ls\n", lengthCollumnPosition);
				// printf("%.0f %.0f\n", (*(Position*)cap.component).current2.x, (*(Position*)cap.component).current2.y);
				// printf("Address: %p\n", arrayOfArrayComponents[POSITION]);
				addComponentInEntity(
					cap.component, 
					arrayOfArrayComponents[POSITION]
				);
				// printf("\n-BEFOR-> lengthCollumnPosition: %ls\n", lengthCollumnPosition);
				break;
			case SIZE:
				addComponentInEntity(
					cap.component, 
					arrayOfArrayComponents[SIZE]
				);
				break;
			case COLOR:
				addComponentInEntity(
					cap.component, 
					arrayOfArrayComponents[COLOR]
				);
				break;
			case COLLIDER:
				addComponentInEntity(
					cap.component, 
					arrayOfArrayComponents[COLLIDER]
				);
				break;
			case LAYER:
				// printf("layer: %d\n", (*(Layer*)cap.component).layer);
				addComponentInEntity(
					cap.component, 
					arrayOfArrayComponents[LAYER]
				);
				break;
			case PLAYER:
				addComponentInEntity(
					cap.component, 
					arrayOfArrayComponents[PLAYER]
				);
				break;
			case COLLECTIBLE:
				addComponentInEntity(
					cap.component, 
					arrayOfArrayComponents[COLLECTIBLE]
				);
				break;
			case ANCHOR:
				addComponentInEntity(
					cap.component, 
					arrayOfArrayComponents[ANCHOR]
				);
				break;
		}
	}
}

void createKindComponents(TemporaryEntity te){
	addEntity();
	addComponentsinEntity(te);
	// setId(getId() + 1);
}
