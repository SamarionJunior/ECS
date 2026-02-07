#include <SDL2/SDL.h>
// #include <SDL2/SDL_opengl.h>
#include "glad.h"

int gScreenHeight = 640;
int gScreenWidth = 480;
SDL_Window*   gGraphicsApplicationWindow = NULL;
SDL_GLContext gOpenGLContext = NULL;

void InitializeProgram(){

  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    printf("SDL2 could not initialize video subsystem\n");
    exit(1);
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(
    SDL_GL_CONTEXT_PROFILE_MASK,
    SDL_GL_CONTEXT_PROFILE_CORE
  );
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  gGraphicsApplicationWindow = (
    "OpenGL Window",
    gScreenWidth,
    gScreenHeight,
    SDL_WINDOW_OPENGL
  );

  if(gGraphicsApplicationWindow == NULL){
    printf("SDL Window was not able to be created\n");
    printf("%s\n", SDL_GetError());
    printf("%u\n", glGetError());
    exit(1);
  }

  gOpenGLContext = SDL_GL_CreateContext(gGraphicsApplicationWindow);

  if(gOpenGLContext == NULL){
    printf("OpenGL context not available\n");
    exit(1);
  }

}
void MainLoop(){

}
void CleanUp(){
  SDL_DestroyWindow(gGraphicsApplicationWindow);
  SDL_Quit();
}

int main(int argc, char* argv[]) {
  InitializeProgram();
  MainLoop();
  CleanUp();
  return 0;
}