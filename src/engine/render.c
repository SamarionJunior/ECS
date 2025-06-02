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

#include "../../dependencies/my/matrix/matrix.h"
#include "../../dependencies/my/matrix/length.h"
#include "../../dependencies/my/matrix/get.h"

// void fillauxRect(SDL_FRect* auxRect, int id);
// void setColor(Color color);
// void clearWindow(Color color);
// void draw(SDL_FRect* auxRect, int id);

void render();
void fillAuxRect(SDL_FRect* auxRect, ComponentsForLayer *componentsForSystem);
void setColor(Color color);
void clearWindow(Color color);
void draw(SDL_FRect* auxRect, ComponentsForLayer *componentsForSystem);

void render() {

	// printf("\n//////////////\n");
	// printf(  "/// RENDER ///\n");
	// printf(  "//////////////\n\n");

	// printf("\n%d - render\n", rand()%100);

	if(lengthRow(&entities, 0) == 0){
		return;
	}

	SDL_FRect auxRect;

	clearWindow(*createColor(ID_INIT, 0, 0, 0, 255));

	for(size_t layerOrder = 0; layerOrder < MAX_LAYER ; layerOrder++){

		for(int i = 0 ; i < lengthRow(&componentsForLayer, 0); i++){
			ComponentsForLayer *componentsForSystem = (ComponentsForLayer*)getCell(&componentsForLayer, 0, i)->data;
	
			if(
				// existEntities(*(int *)getIdInSystem(LAYERS, i)) && 
				componentsForSystem->layer->layer == layerOrder
			){
				// printf("\n%d - draw 0\n", rand()%100);
				draw(&auxRect, componentsForSystem);
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

void fillAuxRect(SDL_FRect* auxRect, ComponentsForLayer *componentsForSystem){
	auxRect->x = componentsForSystem->position->current2.x;
	auxRect->y = componentsForSystem->position->current2.y;
	auxRect->w = componentsForSystem->size->vector2.x;
	auxRect->h = componentsForSystem->size->vector2.y;
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

void draw(SDL_FRect* auxRect, ComponentsForLayer *componentsForSystem){

	fillAuxRect(auxRect, componentsForSystem);

	setColor(*(componentsForSystem->color));

	if (!SDL_RenderFillRect(renderer, auxRect)) {
		// // // // printf("SDL_RenderFillRect\n");
		// fprintf(stderr, "| Erro %s |", ((Information *)readComponentByIdAndReturnReferenc(INFORMATION, id))->name);
	}
}