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

static Occurrence occurrencePosition;
static Occurrence occurrenceSize;
static Occurrence occurrenceColor;

// static Position* temporaryPointerPosition;
// static Size* temporaryPointerSize;
// static Color* temporaryPointerColor;

static Position temporaryPosition;
static Size temporarySize;
static Color temporaryColor;

static SDL_FRect auxRect;

static Id* temporaryId;
static int temporaryIndex;

SDL_Color color = { 255, 255, 255, 255};

SDL_Texture *texture1 = NULL;
SDL_Surface *suface1 = NULL;

SDL_Texture *texture2 = NULL;
SDL_Surface *suface2 = NULL;

void render() {

	// printf("\n//////////////\n");
	// printf(  "/// RENDER ///\n");
	// printf(  "//////////////\n\n");

	// printf("\n%d - render\n", rand()%100);

	if(lengthArray(layerArray) == 0){
		return;
	}

	texture1 = NULL;
	char s1[6+1+21] = "Score: ";
	char s2[21] = "";
	snprintf(s2, 21, "%d", score);
	const char* texto1 = strcat(s1, s2);
	// congratulations
	if((suface1 = TTF_RenderText_Solid(font, texto1, 0, color)) == NULL) {
		return false;
	}
	texture1 = SDL_CreateTextureFromSurface(renderer, suface1);
	SDL_DestroySurface(suface1);
	if (texture1 == NULL) {
		return false;
	}

	texture2 = NULL;
	char normal[] = " ";
	char win[] = "Congratulations!";
	char loss[] = "Game Over!";
	const char* texto2 = 
	(game_is_running == WIN || game_is_running == LOSS) ? 
		((game_is_running == WIN) ? 
			win : 
			loss
		) : 
		normal;
	if((suface2 = TTF_RenderText_Solid(font, texto2, 0, color)) == NULL) {
		printf("dafdadf\n");
		return false;
	}
	texture2 = SDL_CreateTextureFromSurface(renderer, suface2);
	SDL_DestroySurface(suface2);
	if (texture2 == NULL) {
		printf("adfdfadsfasdfasd\n");
		return false;
	}

	clearWindow(createColor(ID_INIT, 0, 0, 0, 255));

	// for(size_t layerOrder = 0; layerOrder < MAX_LAYER ; layerOrder++){

		for(int i = 0 ; i < lengthArray(layerArray); i++){

			if((temporaryId = (Id*)getArray(layerArray, i)) == NULL){
				continue;
			}

			temporaryIndex = temporaryId->id;

			if(getOccurrenceById(positionArray, temporaryIndex, &occurrencePosition) == false){
				continue;
			}
			if(getOccurrenceById(sizeArray, temporaryIndex, &occurrenceSize) == false){
				continue;
			}
			if(getOccurrenceById(colorArray, temporaryIndex, &occurrenceColor) == false){
				continue;
			}

			temporaryPosition = (*((Position*)occurrencePosition.component));
			temporarySize = (*((Size*)occurrenceSize.component));
			temporaryColor = (*((Color*)occurrenceColor.component));


			// printf("%.0f %.0f\n", (*((Position*)(occurrencePosition.component))).current2.x, (*((Position*)(occurrencePosition.component))).current2.y);

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

	SDL_FRect aux1;
  SDL_GetTextureSize(texture1, &aux1.w, &aux1.h);
	aux1.x = 10;
	aux1.y = 7 + getROW() * SPRITE;
  SDL_RenderTexture(renderer, texture1, NULL, &aux1);

	SDL_FRect aux2;
  SDL_GetTextureSize(texture2, &aux2.w, &aux2.h);
	aux2.x = 10;
	// aux2.y = 7 + getROW() * SPRITE;
	aux2.y = aux1.y + aux1.h + 7;
  SDL_RenderTexture(renderer, texture2, NULL, &aux2);

	SDL_RenderPresent(renderer);

	SDL_DestroyTexture(texture1);
	SDL_DestroyTexture(texture2);

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