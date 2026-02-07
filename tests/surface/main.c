#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <sys/time.h>

#include <SDL3/SDL.h>

void SetPixel(SDL_Surface* surface, int x, int y, uint8_t r, uint8_t g, uint8_t b){ 
  SDL_LockSurface(surface);
  uint8_t* pixelArray = (uint8_t*)surface->pixels;
  pixelArray[(y * surface->pitch) + (x * SDL_GetPixelFormatDetails(surface->format)->bytes_per_pixel) + 0] = g;
  pixelArray[(y * surface->pitch) + (x * SDL_GetPixelFormatDetails(surface->format)->bytes_per_pixel) + 1] = b;
  pixelArray[(y * surface->pitch) + (x * SDL_GetPixelFormatDetails(surface->format)->bytes_per_pixel) + 2] = r;
  SDL_UnlockSurface(surface);
}

int main(int argc, char* argv[]){

  SDL_Window* window = NULL;

  SDL_Surface* screen;

  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    printf("SDL could not be initialized: ");
    SDL_GetError();
  }else{
    printf("SDL video system is ready to go\n");
  }

  window = SDL_CreateWindow(
    "C++ SDL2 Window",
    640,
    480,
    0
  );

  screen = SDL_GetWindowSurface(window);

  bool gameIsRunning = true;

  while(gameIsRunning){
    SDL_Event event;

    float x,y;
    Uint32 buttons;
    buttons = SDL_GetMouseState(&x,&y);

    while(SDL_PollEvent(&event)){
      if(event.type == SDL_EVENT_QUIT){
        gameIsRunning= false;
      }
      if(event.button.button == SDL_BUTTON_LEFT){
        // printf("left mouse was pressed (%f, %f)\n", x, y);
        for (size_t i = 0; i < 32; i++){
          for (size_t j = 0; j < 32; j++){
            SetPixel(screen, (int) j + (int) x, (int) i + (int) y, 255, 0, 0);
          }
        }
      }
      if(event.button.button == SDL_BUTTON_RIGHT){
        // printf("rightmouse was pressed (%f, %f)\n", x, y);
        // SetPixel(screen, (int) x, (int) y, 0, 0, 255);
        for (size_t i = 0; i < 32; i++){
          for (size_t j = 0; j < 32; j++){
            SetPixel(screen, (int) j + (int) x, (int) i + (int) y, 0, 0, 255);
          }
        }
      }
    }

    SDL_UpdateWindowSurface(window);
  }

	SDL_DestroySurface(screen);

  SDL_DestroyWindow(window);
  
  SDL_Quit();

  return 0;

}