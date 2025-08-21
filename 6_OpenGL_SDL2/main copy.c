// On linux compile with:
// g++ -std=c++17 main.cpp glad/src/glad.c -I./glad/include -o prog -lSDL2 -ldl
// On windows compile with (if using mingw)
// g++ main.cpp ./glad/src/glad.c -I./glad/include -o prog.exe -lmingw32 -lSDL2main -lSDL2

// g++ -std=c++17 main.cpp glad/src/glad.c -I./glad/include -o prog -lSDL2 -ldl && ./prog 

// gcc main.c glad/src/glad.c -I./glad/include -o prog -lSDL2 -ldl && ./prog 

// gcc main.c glad/src/glad.c -I./glad/include -I./dep/ -o prog -lSDL2 -ldl && ./prog

// C++ Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <glad/glad.h>

#include <cglm/cglm.h>
#include <cglm/call.h>
#include <cglm/struct.h>

// #define GLM_ENABLE_EXPERIMENTAL
// // #define GLM_SWIZZLE
// #define GLM_FORCE_SWIZZLE
// #define GLM_SWIZZLE_XYZW
// #define GLM_SWIZZLE_STQP
// #define GLM_SWIZZLE_RGBA
// #include <glm/glm.hpp>
// // #include <glm/gtc/swizzle.hpp>
// // #include <glm/gtc/type_ptr.hpp>
// #include <glm/vec3.hpp> // glm::vec3
// #include <glm/vec4.hpp> // glm::vec4
// #include <glm/mat4x4.hpp> // glm::mat4
// #include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
// #include <glm/ext/matrix_clip_space.hpp> // glm::perspective
// #include <glm/ext/scalar_constants.hpp> // glm::pi
// #include <glm/gtx/string_cast.hpp>

int gScreenHeight = 480;
int gScreenWidth = 640;
SDL_Window*   gGraphicsApplicationWindow = NULL;
SDL_GLContext gOpenGLContext = NULL;

GLuint gVertexArrayObject = 0;
GLuint gVertexBufferObject = 0;
GLuint gIndexBufferObject = 0;
// GLuint gVertexBufferObject2 = 0;

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

float g_uOffsetX = 0.0f;
float g_uOffsetY = 0.0f;
float g_uOffsetZ = 0.0f;

void LoadShaderAsString(
  const char* filename,
  char* result
){
  // static char result[100];
  // for (size_t i = 0; i < 100; i++){
  //   result[i] = EOF;
  // }
  // char* line = "";
  char c;
  FILE* myFile = fopen(filename, "r");
  int i = 0;
  // printf("\n//////////////////////////\n");
  if(!(myFile == NULL)){
    while((c = fgetc(myFile)) != EOF){
      if(i == 1000){
        printf("file very large\n");
        exit(1);
        break;
      }
      result[i] = c;
      // printf("%c", result[i]);
      i++;
    }
    result[i] = '\0';
    fclose(myFile);
  }
  // printf("\n//////////////////////////\n");
  // return result;
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
  const GLfloat vertexData[] = {
    // x      y      z
    -0.5f, -0.5f,  0.0f, // left bottom
     1.0f,  0.0f,  0.0f, // color
     0.5f, -0.5f,  0.0f, // right bottom
     0.0f,  1.0f,  0.0f, // color
    -0.5f,  0.5f,  0.0f, // left top
     0.0f,  0.0f,  1.0f, // color
     0.5f,  0.5f,  0.0f, // right top
     0.0f,  0.0f,  1.0f, // color
  };
  const GLint indexBufferData[] = {
    0, 1, 2, 
    1, 2, 3
  };
  // const GLfloat vertexPositions[] = {
  //   // x      y      z
  //   -0.8f, -0.8f,  0.0f, // left
  //    0.8f, -0.8f,  0.0f, // right
  //    0.0f,  0.8f,  0.0f  // top
  // };
  // const GLfloat vertexColors[] = {
  //   // x      y      z
  //   1.0f, 0.0f, 0.0f, // color
  //   0.0f, 1.0f, 0.0f, // color
  //   0.0f, 0.0f, 1.0f  // color
  // };
  
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
    sizeof(GLfloat) * 3 * 2 * 4,
    vertexData,
    GL_STATIC_DRAW
  );

  // IBO or EBO
  glGenBuffers(1, &gIndexBufferObject);
  glBindBuffer(
    GL_ELEMENT_ARRAY_BUFFER, 
    gIndexBufferObject
  );
  glBufferData(
    GL_ELEMENT_ARRAY_BUFFER,
    sizeof(GLint) * 3 * 2,
    indexBufferData,
    GL_STATIC_DRAW
  );

  // position information
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(
    0,
    3,
    GL_FLOAT,
    GL_FALSE,
    sizeof(GLfloat) * 6,
    (void*)0
  );

  // color information
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(
    1,
    3,
    GL_FLOAT,
    GL_FALSE,
    sizeof(GLfloat) * 6,
    (GLfloat*)(sizeof(GLfloat) * 3)
  );

  glBindVertexArray(0);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);


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
  GLchar *vertexShaderSource = malloc(1000 * sizeof(GLchar));
  LoadShaderAsString(
    "./shaders/vert.glsl\0",
    vertexShaderSource
  );

  printf("\n//////////////////////////\n");
  printf("%s", vertexShaderSource);
  printf("\n//////////////////////////\n");

  GLchar *fragmentShaderSource = malloc(1000 * sizeof(GLchar));
  LoadShaderAsString(
    "./shaders/frag.glsl\0",
    fragmentShaderSource
  );

  printf("\n//////////////////////////\n");
  printf("%s", fragmentShaderSource);
  printf("\n//////////////////////////\n");

  gGraphicsPipelineShaderProgram = 
    CreateShaderProgram(
      vertexShaderSource, 
      fragmentShaderSource
    );
//   gGraphicsPipelineShaderProgram = 
//     CreateShaderProgram(
//       gVertexShaderSource, 
//       gFragmentShaderSource
//     );

  free(vertexShaderSource);
  free(fragmentShaderSource);
}

void Input(){
  SDL_Event e;
  while (SDL_PollEvent(&e) != 0){
    if(e.type == SDL_QUIT){
      gQuit = true;
    }
  }

  const Uint8 *state = SDL_GetKeyboardState(NULL);
  if(state[SDL_SCANCODE_UP]){
    g_uOffsetY+=0.01f;
    printf("g_uOffsetY: %f\n", g_uOffsetY);
  }
  if(state[SDL_SCANCODE_DOWN]){
    g_uOffsetY-=0.01f;
    printf("g_uOffsetY: %f\n", g_uOffsetY);
  }
  if(state[SDL_SCANCODE_RIGHT]){
    g_uOffsetX+=0.01f;
    printf("g_uOffsetX: %f\n", g_uOffsetX);
  }
  if(state[SDL_SCANCODE_LEFT]){
    g_uOffsetX-=0.01f;
    printf("g_uOffsetX: %f\n", g_uOffsetX);
  }
  if(state[SDL_SCANCODE_W]){
    g_uOffsetZ+=0.01f;
    printf("g_uOffsetZ: %f\n", g_uOffsetZ);
  }
  if(state[SDL_SCANCODE_S]){
    g_uOffsetZ-=0.01f;
    printf("g_uOffsetZ: %f\n", g_uOffsetZ);
  }
}
void PreDraw(){
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);

  glViewport(
    0 , 
    0, 
    gScreenWidth, 
    gScreenHeight
  );
  glClearColor(
    1.0f, 
    1.0f, 
    0.0f, 
    1.0f
  );

  glClear(
    GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT
  );

  glUseProgram(
    gGraphicsPipelineShaderProgram
  );

  GLint location = glGetUniformLocation(
    gGraphicsPipelineShaderProgram,
    "u_OffsetX"
  );

  if(location < 0){
    printf("Could not find u_Offset\n");
  }

  glUniform1f(
    location,
    g_uOffsetX
  );

  location = glGetUniformLocation(
    gGraphicsPipelineShaderProgram,
    "u_OffsetY"
  );

  glUniform1f(
    location,
    g_uOffsetY
  );

  location = glGetUniformLocation(
    gGraphicsPipelineShaderProgram,
    "u_OffsetZ"
  );

  glUniform1f(
    location,
    g_uOffsetZ
  );
}
void Draw(){
  // glBindVertexArray(gVertexArrayObject);
  // glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);

  // glDrawArrays(GL_TRIANGLES, 0, 3 * 2);
  
  glBindVertexArray(gVertexArrayObject);
  glBindBuffer(
    GL_ARRAY_BUFFER, 
    gVertexBufferObject
  );

  // glDrawArrays(GL_TRIANGLES, 0, 3 * 2);
  glDrawElements(
    GL_TRIANGLES, 
    6, 
    GL_UNSIGNED_INT,
    0
  );
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