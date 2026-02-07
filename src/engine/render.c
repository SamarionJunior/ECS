#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL3/SDL.h>
// #include <SDL3_image/SDL_image.h>

#include "render.h"

#include "../architecture/components/components.h"
#include "../architecture/components/create.h"
#include "../architecture/components/get.h"

#include "../architecture/entities/entities.h"

#include "../architecture/systems/systems.h"

#include "../constants.h"
#include "../manager/WindowManage.h"

// #include "../../dependencies/my/dynamicvectors/vector.h"

// #include "../../dependencies/my/dynamicvectors/components/layer.h"
// #include "../../dependencies/my/dynamicvectors/components/position.h"
// #include "../../dependencies/my/dynamicvectors/components/size.h"
// #include "../../dependencies/my/dynamicvectors/components/color.h"

// #include "../../dependencies/my/dynamicvectors/entities/entity.h"

void render();
void fillAuxRect(SDL_FRect* auxRect, Position position, Size size);
void setColor(Color color);
void clearWindow(Color color);
void draw(SDL_FRect* auxRect, Position position, Size size, Color color);

static Occurrence occurrencesPosition;
static Occurrence occurrencesSize;
static Occurrence occurrencesColor;

// static Position* temporaryPointerPosition;
// static Size* temporaryPointerSize;
// static Color* temporaryPointerColor;

static Position temporaryPosition;
static Size temporarySize;
static Color temporaryColor;

static SDL_FRect auxRect;

static Id* temporaryId;
static int temporaryIndex;

void render() {

	// printf("\n//////////////\n");
	// printf(  "/// RENDER ///\n");
	// printf(  "//////////////\n\n");

	// printf("\n%d - render\n", rand()%100);

	if(lengthArray(layerArray) == 0){
		return;
	}

	clearWindow(createColor(ID_INIT, 0, 0, 0, 255));

	// for(size_t layerOrder = 0; layerOrder < MAX_LAYER ; layerOrder++){

		for(int i = 0 ; i < lengthArray(layerArray); i++){

			if((temporaryId = (Id*)getArray(layerArray, i)) == NULL){
				continue;
			}

			temporaryIndex = temporaryId->id;

			if(getOccurrenceById(positionArray, temporaryIndex, &occurrencesPosition) == false){
				continue;
			}
			if(getOccurrenceById(sizeArray, temporaryIndex, &occurrencesSize) == false){
				continue;
			}
			if(getOccurrenceById(colorArray, temporaryIndex, &occurrencesColor) == false){
				continue;
			}

			temporaryPosition = (*((Position*)occurrencesPosition.component));
			temporarySize = (*((Size*)occurrencesSize.component));
			temporaryColor = (*((Color*)occurrencesColor.component));

			// printf(
			// 	"%d: x %f y %f\n", 
			// 	rand(),
			// 	temporaryPosition.current2.x, 
			// 	temporaryPosition.current2.y
			// );
	
			// if(count != 4){
			// 	break;
			// }

			// if(auxLayer->layer == layerOrder){
				// printf("\n%d - draw 0\n", rand()%100);
				draw(
					&auxRect, 
					temporaryPosition, 
					temporarySize, 
					temporaryColor
				);
			// }

		}

	// }

	SDL_RenderPresent(renderer);

	// printf("\n////////////////////\n");
	// printf(  "/// END - RENDER ///\n");
	// printf(  "////////////////////\n\n");

}

void fillAuxRect(SDL_FRect* auxRect, Position position, Size size){
	auxRect->x = position.current2.x;
	auxRect->y = position.current2.y;
	auxRect->w = size.vector2.x;
	auxRect->h = size.vector2.y;
}

void setColor(Color color){
	SDL_SetRenderDrawColor(
		renderer, 
		color.vector4.x, 
		color.vector4.y, 
		color.vector4.z, 
		color.vector4.w
	);
}

void clearWindow(Color color){
	setColor(color);
	SDL_RenderClear(renderer);
}

void draw(SDL_FRect* auxRect, Position position, Size size, Color color){

	fillAuxRect(auxRect, position, size);

	setColor(color);

	if (!SDL_RenderFillRect(renderer, auxRect)) {
		// // // // printf("SDL_RenderFillRect\n");
		// fprintf(stderr, "| Erro %s |", ((Information *)readComponentByIdAndReturnReferenc(INFORMATION, id))->name);
	}
}