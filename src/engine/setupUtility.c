#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "setupUtility.h"

#include "../architecture/components/components.h"
#include "../architecture/components/create.h"

#include "../architecture/entities/entities.h"
#include "../architecture/entities/utility.h"

#include "../architecture/systems/systems.h"

#include "../constants.h"

#include "../../dependencies/mycustom/myjson.h"

#include "../loader/json.h"
#include "../loader/map.h"

#include "../utilities/space.h"

void addInformationinEntity(size_t k);
void addPositioninEntity(float x, float y, size_t k);
void addSizeinEntity(size_t k);
void addColorinEntity(size_t k);
void addColliderinEntity(size_t k);
void addLayerinEntity(size_t k);
void addPlayerinEntity(size_t k);
void addCollectibleinEntity(size_t k);
void addAnchorinEntity(int idParent, size_t k);
void addComponetsinEntity(float x, float y, int idParent, size_t k);
void createKindComponents(float x, float y, int idParent, size_t k);

////////////////////////////////////

void addInformationinEntity(size_t k){
	Information information = createInformation(
		getId(),
		temporaryComponents[k].information.name,
		(strlen(temporaryComponents[k].information.name) + 1)
	);
	addArray(
		informationArray, 
		lengthArray(informationArray), 
		&information
	);
}

void addPositioninEntity(float x, float y, size_t k){
	Position position = createPosition(
		getId(), 
		(x*SPRITE), 
		(y*SPRITE), 
		// (x*SPRITE) + (SPRITE * 1), 
		// (y*SPRITE) + (SPRITE * 1), 
		temporaryComponents[k].position.old2.x,
		temporaryComponents[k].position.old2.y
	);
	addArray(
		positionArray, 
		lengthArray(positionArray), 
		&position
	);
}

void addSizeinEntity(size_t k){
	Size size = createSize(
		getId(), 
		temporaryComponents[k].size.vector2.x,
		temporaryComponents[k].size.vector2.y
	);
	addArray(
		sizeArray, 
		lengthArray(sizeArray), 
		&size
	);
}

void addColorinEntity(size_t k){
	Color color = createColor(
		getId(), 
		temporaryComponents[k].color.vector4.x,
		temporaryComponents[k].color.vector4.y,
		temporaryComponents[k].color.vector4.z,
		temporaryComponents[k].color.vector4.y
	);
	addArray(
		colorArray, 
		lengthArray(colorArray), 
		&color
	);
}

void addColliderinEntity(size_t k){
	Collider collider = createCollider(
		getId(), 
		temporaryComponents[k].collider.isItColliding,
		temporaryComponents[k].collider.collisionDirection,
		temporaryComponents[k].collider.isStatic
	);
	addArray(
		colliderArray, 
		lengthArray(colliderArray), 
		&collider
	);
}

void addLayerinEntity(size_t k){
	Layer layer = createLayer(
		getId(), 
		temporaryComponents[k].layer.layer
	);
	addArray(
		layerArray, 
		lengthArray(layerArray), 
		&layer
	);
}

void addPlayerinEntity(size_t k){
	Player player = createPlayer(
		getId()
	);
	addArray(
		playerArray, 
		lengthArray(playerArray), 
		&player
	);
}

void addCollectibleinEntity(size_t k){
	Collectible collectible = createCollectible(
		getId()
	);
	addArray(
		collectibleArray, 
		lengthArray(collectibleArray), 
		&collectible
	);
}

void addAnchorinEntity(int idParent, size_t k){
	Anchor anchor = createAnchor(
		getId(),
		idParent
	);
	addArray(
		anchorArray, 
		lengthArray(anchorArray), 
		&anchor
	);
}

void addComponetsinEntity(float x, float y, int idParent, size_t k){
	for (size_t l = 0; l < temporaryComponents[k].lengtharrayComponentTypes; l++){
		switch (temporaryComponents[k].arrayComponentTypes[l]){
			case INFORMATION:
				addInformationinEntity(k);
				break;
			case POSITION:
				// printf("\n-AFTER-> lengthCollumnPosition: %ls\n", lengthCollumnPosition);
				addPositioninEntity(x, y, k);
				// printf("\n-BEFOR-> lengthCollumnPosition: %ls\n", lengthCollumnPosition);
				break;
			case SIZE:
				addSizeinEntity(k);
				break;
			case COLOR:
				addColorinEntity(k);
				break;
			case COLLIDER:
				addColliderinEntity(k);
				break;
			case LAYER:
				addLayerinEntity(k);
				break;
			case PLAYER:
				addPlayerinEntity(k);
				break;
			case COLLECTIBLE:
				addCollectibleinEntity(k);
				break;
			case ANCHOR:
				addAnchorinEntity(idParent, k);
				break;
		}
	}
}

void createKindComponents(float x, float y, int idParent, size_t k){
	setId(getId() + 1);
	addArray(
		entityArray,
		lengthArray(entityArray),
		&(Entity){
			.index = getId()
		}
	);
	addComponetsinEntity(x, y, idParent, k);
	// setId(getId() + 1);
}
