#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
// #include <SDL3_image/SDL_image.h>

#include "render.h"

#include "../architecture/components/components.h"
#include "../architecture/components/create.h"
#include "../architecture/components/get.h"

#include "../architecture/entities/entities.h"

// #include "../architecture/systems/systems.h"
#include "../architecture/systems/collision.h"

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

// static Occurrence occurrencePosition;
// static Occurrence occurrenceSize;
// static Occurrence occurrenceColor;

// static Position* temporaryPointerPosition;
// static Size* temporaryPointerSize;
// static Color* temporaryPointerColor;

static Position* temporaryPosition;
static Size* temporarySize;
static Color* temporaryColor;
static Layer* temporaryLayer;

static SDL_FRect auxRect;

static Id temporaryId;
// static int temporaryIndex;

SDL_Color color = { 255, 255, 255, 255};

SDL_Texture *texture1 = NULL;
SDL_Surface *suface1 = NULL;

SDL_Texture *texture2 = NULL;
SDL_Surface *suface2 = NULL;

static Layer* auxLayer = NULL;

static float offSetX = 0;
static float lastPlayerPositionX = 0;

static const float marginScreen = 300.0f;
static const float marginScreenLeft = (float)WINDOW_WIDTH - marginScreen;
static const float marginScreenRight = marginScreen;

void updateCamera(){

	if(lengthArray(playerArray) <= 0){
		return;
	}

	Position* playerPosition = NULL;

	getComponentById(
		positionArray, 
		(*(Player*)getArray(playerArray, 0)).id, 
		&playerPosition
	);

	// printf("%f\n",
	// 	(playerPosition->current2.x >= playerPosition->old2.x) ? 
	// 		playerPosition->current2.x - playerPosition->old2.x :
	// 		playerPosition->old2.x - playerPosition->current2.x
	// );

	if(lastPlayerPositionX == playerPosition->current2.x){
		return;
	}

	const float playerRelativePositionX = playerPosition->current2.x + offSetX;

	if(
		playerRelativePositionX < marginScreenLeft
		&& playerRelativePositionX > marginScreenRight
	){
		return;
	}

	lastPlayerPositionX = playerPosition->current2.x;

	offSetX += (playerPosition->current2.x >= playerPosition->old2.x) ? 
		-(playerPosition->current2.x - playerPosition->old2.x) :
		playerPosition->old2.x - playerPosition->current2.x;

}

void render() {

	// printf("\n//////////////\n");
	// printf(  "/// RENDER ///\n");
	// printf(  "//////////////\n\n");

	// printf("\n%d - render\n", rand()%100);

	Array layerCurrent[] = {
		layer0Array,
		layer1Array,
		layer2Array
	};

	// printf("layer0Array: %d\n", lengthArray(layer0Array));
	// printf("layer1Array: %d\n", lengthArray(layer1Array));
	// printf("layer2Array: %d\n", lengthArray(layer2Array));

	bool isThereLayer = false;
	for (size_t layerOrder = 0; layerOrder < 3; layerOrder++){
		if(lengthArray(layerCurrent[layerOrder]) > 0){
			isThereLayer = true;
			break;
		}
	}
	if(isThereLayer == false){
		return;
	}

	updateCamera();

	// texture1 = NULL;
	// char s1[6+1+21] = "Score: ";
	// char s2[21] = "";
	// snprintf(s2, 21, "%d", score);
	// const char* texto1 = strcat(s1, s2);
	// // congratulations
	// if((suface1 = TTF_RenderText_Solid(font, texto1, 0, color)) == NULL) {
	// 	return false;
	// }
	// texture1 = SDL_CreateTextureFromSurface(renderer, suface1);
	// SDL_DestroySurface(suface1);
	// if (texture1 == NULL) {
	// 	return false;
	// }

	// texture2 = NULL;
	// char normal[] = " ";
	// char win[] = "Congratulations!";
	// char loss[] = "Game Over!";
	// const char* texto2 = 
	// (game_is_running == WIN || game_is_running == LOSS) ? 
	// 	((game_is_running == WIN) ? 
	// 		win : 
	// 		loss
	// 	) : 
	// 	normal;
	// if((suface2 = TTF_RenderText_Solid(font, texto2, 0, color)) == NULL) {
	// 	printf("dafdadf\n");
	// 	return false;
	// }
	// texture2 = SDL_CreateTextureFromSurface(renderer, suface2);
	// SDL_DestroySurface(suface2);
	// if (texture2 == NULL) {
	// 	printf("adfdfadsfasdfasd\n");
	// 	return false;
	// }

	clearWindow(createColor(ID_INIT, 0, 0, 0, 255));

	// int count = 0;

	for(size_t layerOrder = 0; layerOrder < 3 ; layerOrder++){ // IMPLENET SETUP FOR LAYER LENGHT

		for(int i = 0 ; i < lengthArray(layerCurrent[layerOrder]); i++){
			// printf("%d %d\n", layerOrder, i);

			// if(getComponentsByIndex(layerArray, i, 6, positionArray, &temporaryPosition, sizeArray, &temporarySize, colorArray, &temporaryColor) == false){
			// 	continue;
			// }

			if(getComponentByIndex(layerCurrent[layerOrder], i, &temporaryLayer) == false){
				continue;
			}

			// if(temporaryLayer->layer != layerOrder){
			// 	continue;
			// }

			if(getComponentsById(temporaryLayer->id, 6, positionArray, &temporaryPosition, sizeArray, &temporarySize, colorArray, &temporaryColor) == false){
				continue;
			}

			// Position aux = *temporaryPosition;
			// aux.current2.x += offSetX;

			// if(collisionBetweenAendB(
			// 	aux, 
			// 	*temporarySize, 
			// 	(Position){
			// 		.current2.x = 0,
			// 	},
			// 	(Size){
			// 		.vector2.x = WINDOW_WIDTH,
			// 		.vector2.y = WINDOW_HEIGHT
			// 	}
			// ) == false){
			// 	// printf("%d\n", i);
			// 	continue;
			// }

			// count++;

			draw(
				&auxRect, 
				*temporaryPosition, 
				*temporarySize, 
				*temporaryColor
			);

		}

	}
	// printf("%d\n", count);

	// SDL_FRect aux1;
  // SDL_GetTextureSize(texture1, &aux1.w, &aux1.h);
	// aux1.x = 10;
	// aux1.y = 7 + getROW() * SPRITE;
  // SDL_RenderTexture(renderer, texture1, NULL, &aux1);

	// SDL_FRect aux2;
  // SDL_GetTextureSize(texture2, &aux2.w, &aux2.h);
	// aux2.x = 10;
	// // aux2.y = 7 + getROW() * SPRITE;
	// aux2.y = aux1.y + aux1.h + 7;
  // SDL_RenderTexture(renderer, texture2, NULL, &aux2);

	SDL_RenderPresent(renderer);

	// SDL_DestroyTexture(texture1);
	// SDL_DestroyTexture(texture2);

	// printf("\n////////////////////\n");
	// printf(  "/// END - RENDER ///\n");
	// printf(  "////////////////////\n\n");

}

void fillAuxRect(SDL_FRect* auxRect, Position position, Size size){
	auxRect->x = position.current2.x + offSetX;
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