// On linux compile with:
// g++ -std=c++17 main.cpp glad/src/glad.c -I./glad/include -o prog -lSDL2 -ldl
// On windows compile with (if using mingw)
// g++ main.cpp ./glad/src/glad.c -I./glad/include -o prog.exe -lmingw32 -lSDL2main -lSDL2

// g++ -std=c++17 main.cpp glad/src/glad.c -I./glad/include -o prog -lSDL2 -ldl && ./prog 

// gcc main.c glad/src/glad.c -I./glad/include -o prog -lSDL2 -ldl && ./prog 

// C++ Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <glad/glad.h>

int gScreenHeight = 480;
int gScreenWidth = 640;
SDL_Window*   gGraphicsApplicationWindow = NULL;
SDL_GLContext gOpenGLContext = NULL;

GLuint gVertexArrayObject = 0;
GLuint gVertexBufferObject = 0;

bool gQuit = false;

GLuint gGraphicsPipelineShaderProgram = 0;

const GLchar* gVertexShaderSource = 
  "#version 410 core\n"
  "in vec4 position;\n"
  "void main(){\n"
  "  gl_Position = vec4(position.x, position.y, position.z, position.w);\n"
  "}\n"
;
const GLchar* gFragmentShaderSource = 
  "#version 410 core\n"
  "out vec4 color;\n"
  "void main(){\n"
  "  color = vec4(1.0f, 0.5f, 0.0f, 1.0f);\n"
  "}\n"
;

const GLchar* LoadShaderAsString(
  const char* filename
){
  char* resulte = "";
  char* line = "";
  
}

void GetOpenGLVersionInfor(){
  printf(
    "Vendor: %s\n",
    glGetString(GL_VENDOR)
  );
  printf(
    "Renderer: %s\n",
    glGetString(GL_RENDERER)
  );
  printf(
    "Version: %s\n",
    glGetString(GL_VERSION)
  );
  printf(
    "Shading Language: %s\n", 
    glGetString(GL_SHADING_LANGUAGE_VERSION)
  );
}

void InitializeProgram(){

  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    printf("SDL2 could not initialize video subsystem\n");
    exit(1);
  }

  SDL_GL_SetAttribute(
    SDL_GL_CONTEXT_MAJOR_VERSION, 4
  );
  SDL_GL_SetAttribute(
    SDL_GL_CONTEXT_MINOR_VERSION, 1
  );
  SDL_GL_SetAttribute(
    SDL_GL_CONTEXT_PROFILE_MASK,
    SDL_GL_CONTEXT_PROFILE_CORE
  );
  SDL_GL_SetAttribute(
    SDL_GL_DOUBLEBUFFER, 1
  );
  SDL_GL_SetAttribute(
    SDL_GL_DEPTH_SIZE, 24
  );

  gGraphicsApplicationWindow = SDL_CreateWindow(
    "OpenGL Window",
    0,
    0,
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

  if(!gladLoadGLLoader(SDL_GL_GetProcAddress)){
    printf("glad was not available\n");
    exit(1);
  }

  GetOpenGLVersionInfor();

}

void VertexSpecification(){
  // on cpu
  const GLfloat vertexPosition[] = {
    // x      y      z
    -0.8f, -0.8f,  0.0f, // 1
     0.8f, -0.8f,  0.0f, // 2
     0.0f,  0.8f,  0.0f  // 3
  };
  // on gpu
  glGenVertexArrays(1, &gVertexArrayObject);
  glBindVertexArray(gVertexArrayObject);

  glGenBuffers(1, &gVertexBufferObject);
  glBindBuffer(
    GL_ARRAY_BUFFER,
    gVertexBufferObject
  );
  glBufferData(
    GL_ARRAY_BUFFER,
    sizeof(GLfloat) * 9,
    vertexPosition,
    GL_STATIC_DRAW
  );

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(
    0,
    3,
    GL_FLOAT,
    GL_FALSE,
    0,
    (void*)0
  );

  glBindVertexArray(0);
  glDisableVertexAttribArray(0);
}

GLuint CompileShader(
  GLuint type, 
  const GLchar* source
){
  GLuint shaderObject;

  if(type == GL_VERTEX_SHADER){
    shaderObject = glCreateShader(GL_VERTEX_SHADER);
  }else if(type == GL_FRAGMENT_SHADER){
    shaderObject = glCreateShader(GL_FRAGMENT_SHADER);
  }

  glShaderSource(shaderObject, 1, &source, NULL);
  glCompileShader(shaderObject);

  return shaderObject;
}
GLuint CreateShaderProgram(
  const GLchar* vertexshadersource,
  const GLchar* fragmentshadersource
){
  GLuint programObject = glCreateProgram();

  GLuint myVertexShader = CompileShader(
    GL_VERTEX_SHADER,
    vertexshadersource
  );
  GLuint myFragmentShader = CompileShader(
    GL_FRAGMENT_SHADER,
    fragmentshadersource
  );

  glAttachShader(programObject, myVertexShader);
  glAttachShader(programObject, myFragmentShader);
  glLinkProgram(programObject);

  glValidateProgram(programObject);

  return programObject;
}
void CreateGraphicsPipeline(){
  gGraphicsPipelineShaderProgram = 
    CreateShaderProgram(
      gVertexShaderSource, 
      gFragmentShaderSource
    );
}

void Input(){
  SDL_Event e;
  while (SDL_PollEvent(&e) != 0){
    if(e.type == SDL_QUIT){
      gQuit = true;
    }
  }
  
}
void PreDraw(){
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);

  glViewport(0 , 0, gScreenWidth, gScreenHeight);
  glClearColor(1.0f, 1.0f, 0.0f, 1.0f);

  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

  glUseProgram(gGraphicsPipelineShaderProgram);
}
void Draw(){
  glBindVertexArray(gVertexArrayObject);
  glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);

  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void MainLoop(){
  while (!gQuit){
    Input();
    PreDraw();
    Draw();



    SDL_GL_SwapWindow(gGraphicsApplicationWindow);
  }
  
}
void CleanUp(){
  SDL_DestroyWindow(gGraphicsApplicationWindow);
  SDL_Quit();
}

int main(int argc, char* argv[]) {
  InitializeProgram();
  VertexSpecification();
  CreateGraphicsPipeline();
  MainLoop();
  CleanUp();
  return 0;
}