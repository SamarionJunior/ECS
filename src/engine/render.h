#ifndef RENDER_H_
#define RENDER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../architecture/components/components.h"

#include "../architecture/entities/entities.h"

#include "../architecture/systems/systems.h"

void render();
void fillAuxRect(SDL_FRect* auxRect, Position position, Size size);
void setColor(Color color);
void clearWindow(Color color);
void draw(SDL_FRect* auxRect, Position position, Size size, Color color);

 #endif