// On linux compile with:
// g++ -std=c++17 main.cpp -o prog -lSDL2 -lSDL2_image -ldl
// gcc main.c -o main.exe -lSDL3 -lSDL3_image -ldl && ./main.exe

// C++ Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>
// Third Party
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_hints.h>

#define SDL_HINT_FRAMEBUFFER_ACCELERATION

void startFrameCount();
void endFrameCount();
void calculateFramesNumber();
void resertFrameVariables();

static long int count = 0;

static long int media = 0;

static long int secunds = 0;

static long int countSecunds = 0.0;

static struct timeval end, start;

void resertFrameVariables(){
	count = 0;
	media = 0;
	secunds = 0;
	countSecunds = 0.0;
}

void startFrameCount(){
	gettimeofday(&start, NULL);
}

void endFrameCount(){
	gettimeofday(&end, NULL);
}

void calculateFramesNumber(){

	if(end.tv_usec < start.tv_usec){
		long int q = 999999 - start.tv_usec;
		long int w = end.tv_usec + q;
		countSecunds += w;
	}else{
		countSecunds += (end.tv_usec - start.tv_usec);
	}

	count++;

	if (countSecunds > 999999){
		
		secunds++;

		media += count;

		// printf("secunds: %lu | microsecunds: %lu | FPS: %lu | media: %lu\n", secunds, countSecunds, count, (media / secunds));
		printf("%d - FPS: %lu | media: %lu\n", rand()%10, count, (media / secunds));
		// printf("Entities: %d\n", lengthArray(entityArray));
		// if(vectorPosition.data != NULL){
			// printf("\n--> lengthCollumnPosition: %d\n", vectorPosition.columnLength);
		// }
		// printf("start\t %lu us\n", start.tv_usec);
		// printf("stop\t %lu us\n", stop.tv_usec);
		countSecunds = 0.0;
		count = 0;
	}

}

int main(int argc, char* argv[]){
  srand(time(NULL));
  // Create a window data type
  // This pointer will point to the 
  // window that is allocated from SDL_CreateWindow
  SDL_Window* window=NULL;

  // Initialize the video subsystem.
  // iF it returns less than 1, then an
  // error code will be received.
  if(SDL_Init(SDL_INIT_VIDEO) < 0){
      printf("SDL could not be initialized: %s\n", SDL_GetError());
  }else{
      printf("SDL video system is ready to go\n");
  }
  // Request a window to be created for our platform
  // The parameters are for the title, x and y position,
  // and the width and height of the window.

  window = SDL_CreateWindow(
    "C++ SDL2 Window",
    1920,
    1280,
    SDL_WINDOW_RESIZABLE
  );

  SDL_Renderer* renderer = NULL;
  renderer = SDL_CreateRenderer(window, NULL);

  // Setup and initialize the SDL2_Image library
  // with our supported formats
  // int flags = IMG_INIT_PNG;
  // int initStatus = IMG_Init(flags);
  // if((initStatus & flags) != flags){
  //     std::cout << "SDL2_Image format not available" << std::endl;
  // }

  SDL_Surface* image;
  image = IMG_Load("/home/learn/Área de trabalho/ECS/tests/build/a.jpg");
  // printf("Image loaded\n");
  if(!image){
      printf("Image not loaded... %s\n", SDL_GetError());
  }

  SDL_Texture* ourPNG = SDL_CreateTextureFromSurface(renderer, image);

  // Infinite loop for our application
  bool gameIsRunning = true;
  // Main application loop

  int count = 0;

  resertFrameVariables();
  startFrameCount();

  while(gameIsRunning){
    SDL_Event event;

    // (1) Handle Input
    // Start our event loop
    while(SDL_PollEvent(&event)){
      if(event.type == SDL_EVENT_QUIT){
        gameIsRunning= false;
      }

    }
    // (2) Handle Updates
    
    // (3) Clear and Draw the Screen
    // Gives us a clear "canvas"
    SDL_SetRenderDrawColor(renderer,0,0,0xFF,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_RenderTexture(renderer,ourPNG,NULL,NULL);

    // Finally show what we've drawn
    SDL_RenderPresent(renderer);
    // printf("\n%d", rand());
    endFrameCount();
    calculateFramesNumber();

    
  }

  // We destroy our window. We are passing in the pointer
  // that points to the memory allocated by the 
  // 'SDL_CreateWindow' function. Remember, this is
  // a 'C-style' API, we don't have destructors.
  SDL_DestroyWindow(window);
  
  // Free our png image surface
  SDL_DestroySurface(image);
  // And destroy our texture
  SDL_DestroyTexture(ourPNG);

  // IMG_Quit();

  // Quit our program.
  SDL_Quit();
  return 0;
}