#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h> // Or use GLAD/GLEW for modern OpenGL

// ... (Shader source code, vertex data) ...

int main(int argc, char* argv[]) {
  // 1. Initialize SDL and create window/context
  SDL_Init(SDL_INIT_VIDEO);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_Window* window = SDL_CreateWindow("OpenGL Square", 800, 600, SDL_WINDOW_OPENGL);
  SDL_GLContext context = SDL_GL_CreateContext(window);
  SDL_GL_MakeCurrent(window, context);

  // ... (Initialize GLAD/GLEW if used) ...

  // 2. Define Vertex Data and VBO
  float vertices[] = {
    // Position         // Color (optional)
    -0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // Top-left
     0.5f,  0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // Top-right
     0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f, // Bottom-right
    -0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 0.0f  // Bottom-left
  };
  unsigned int indices[] = {
    0, 1, 2, // First triangle
    2, 3, 0  // Second triangle
  };
  // ... (Create VBO, EBO, VAO, buffer data) ...

  // 3. Create Shaders and Shader Program
  // ... (Compile and link shaders) ...

  // Rendering loop
  bool quit = false;
  SDL_Event e;
  while(!quit) {
    while(SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT) {
        quit = true;
      }
    }

    // 5. Rendering
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // ... (Use shader program, bind VAO, draw elements) ...

    SDL_GL_SwapWindow(window);
  }

  printf("dsdsd\n");

  // 6. Cleanup
  // ... (Delete OpenGL objects, destroy window/context, quit SDL) ...

  return 0;
}