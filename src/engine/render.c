#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL3/SDL.h>
#include "render.h"

#include "../architecture/components/components.h"
#include "../architecture/components/create.h"

#include "../architecture/entities/entities.h"

#include "../architecture/systems/systems.h"

#include "../constants.h"
#include "../manager/WindowManage.h"

#include "../../dependencies/my/dynamicvectors/vector.h"

#include "../../dependencies/my/dynamicvectors/components/layer.h"
#include "../../dependencies/my/dynamicvectors/components/position.h"
#include "../../dependencies/my/dynamicvectors/components/size.h"
#include "../../dependencies/my/dynamicvectors/components/color.h"

#include "../../dependencies/my/dynamicvectors/entities/entity.h"

// void fillauxRect(SDL_FRect* auxRect, int id);
// void setColor(Color color);
// void clearWindow(Color color);
// void draw(SDL_FRect* auxRect, int id);

void render();
void fillAuxRect(SDL_FRect* auxRect, Position position, Size size);
void setColor(Color color);
void clearWindow(Color color);
void draw(SDL_FRect* auxRect, Position position, Size size, Color color);

void render() {

	// printf("\n//////////////\n");
	// printf(  "/// RENDER ///\n");
	// printf(  "//////////////\n\n");

	// printf("\n%d - render\n", rand()%100);

	if(lengthCollumnLayer(&vectorLayer) == 0){
		return;
	}

	SDL_FRect auxRect;

	clearWindow(createColor(ID_INIT, 0, 0, 0, 255));

	for(size_t layerOrder = 0; layerOrder < MAX_LAYER ; layerOrder++){

		for(int i = 0 ; i < lengthCollumnEntity(&vectorEntity); i++){

			Entity* id = getCellEntity(&vectorEntity, i);

			// printf("\n%p\n", id);

			if(id == NULL){
				break;
			}

			// printf("\n%d\n", id->index);

			// if(id->index == NULL){
			// 	break;
			// }

			int index = id->index;

			// printf("\n%d\n", index);

			int count = 0;

			Position* auxPosition = NULL;
			Size* auxSize = NULL;
			Color* auxColor = NULL;
			Layer* auxLayer = NULL;

			for (size_t j = 0; j < lengthCollumnPosition(&vectorPosition); j++){
				Position* tempPosition = getCellPosition(&vectorPosition, j);
				if(tempPosition != NULL){
					if(tempPosition->id == index){
						auxPosition = tempPosition;
						count++;
						break;
					}
				}
			}
			for (size_t j = 0; j < lengthCollumnSize(&vectorSize); j++){
				Size* tempSize = getCellSize(&vectorSize, j);
				if(tempSize != NULL){
					if(tempSize->id == index){
						auxSize = tempSize;
						count++;
						break;
					}
				}
			}
			for (size_t j = 0; j < lengthCollumnColor(&vectorColor); j++){
				Color* tempColor = getCellColor(&vectorColor, j);
				if(tempColor != NULL){
					if(tempColor->id == index){
						auxColor = tempColor;
						count++;
						break;
					}
				}
			}
			for (size_t j = 0; j < lengthCollumnLayer(&vectorLayer); j++){
				Layer* tempLayer = getCellLayer(&vectorLayer, j);
				if(tempLayer != NULL){
					if(tempLayer->id == index){
						auxLayer = tempLayer;
						count++;
						break;
					}
				}
			}
	
			if(count != 4){
				break;
			}

			if(auxLayer->layer == layerOrder){
				// printf("\n%d - draw 0\n", rand()%100);
				draw(&auxRect, *auxPosition, *auxSize, *auxColor);
			}
		}
	
		// for(int i = 0 ; i < lengthRow(&componentsForLayer, 0); i++){
		// 	ComponentsForLayer *componentsForSystem = (ComponentsForLayer*)getCell(&componentsForLayer, 0, i)->data;
		// 	if(
		// 		// existEntities(*(int *)getIdInSystem(LAYERS, i)) && 
		// 		// ((Layer *)(getCell(&layer, 0, i)->data))->layer == 1
		// 		componentsForSystem->layer->layer == 1
		// 	){
		// 		// draw(&auxRect, *(int *)getIdInSystem(LAYERS, i));
		// 		draw(&auxRect, componentsForSystem);
		// 	}
		// }

	}

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