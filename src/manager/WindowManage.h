#ifndef WINDOWMANAGE_H_
#define WINDOWMANAGE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL3_ttf/SDL_ttf.h>

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern TTF_Font *font;
// extern SDL_Texture *texture;

typedef signed long sint32;

sint32 SDL_TICKS_PASSED(sint32 a, sint32 b);

bool initialize_window();

void destroy_window();

#endif