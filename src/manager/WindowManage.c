#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
// #include <SDL3/SDL_video.h>
#include "WindowManage.h"
#include "../constants.h"

SDL_Window* window;
SDL_Renderer* renderer;
TTF_Font *font = NULL;
// SDL_Texture *texture = NULL;

typedef signed long sint32;

sint32 SDL_TICKS_PASSED(sint32 a, sint32 b) {
	return ((sint32)((b)-(a)) <= 0);
}

bool initialize_window() {

	// // // // printf("\n/////////////////////////\n");
	// // // // printf(  "/// INITIALIZE WINDOW ///\n");
	// // // // printf(  "/////////////////////////\n\n");

	if (!SDL_Init(0)) {
		fprintf(stderr, "\nError initializing SDL.\n");
		return false;
	}

	window = SDL_CreateWindow(
		NULL,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		0
	);

	if (!window) {
		fprintf(stderr, "\nError creating SDL Window.\n");
		return false;
	}

	renderer = SDL_CreateRenderer(
		window, 
		NULL
	);

	if (!renderer) {
		fprintf(stderr, "\nError creating SDL Renderer.\n");
		return false;
	}

	if (TTF_Init() == false) {
		return false;
	}

	if ((font = TTF_OpenFont("./Jersey10-Regular.ttf", 18.0f)) == NULL) {
		return false;
	}

	return true;

	// // // // printf("\n///////////////////////////////\n");
	// // // // printf(  "/// END - INITIALIZE WINDOW ///\n");
	// // // // printf(  "///////////////////////////////\n\n");
}

void destroy_window() {

	if(font != NULL) {
    TTF_CloseFont(font);
  }
  TTF_Quit();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

}