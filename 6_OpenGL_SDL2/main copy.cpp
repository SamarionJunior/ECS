// On linux compile with:
// g++ -std=c++17 main.cpp glad/src/glad.c -I./glad/include -o prog -lSDL2 -ldl
// On windows compile with (if using mingw)
// g++ main.cpp ./glad/src/glad.c -I./glad/include -o prog.exe -lmingw32 -lSDL2main -lSDL2

// C++ Standard Libraries
#include <iostream>

// Third-party library
#include <SDL2/SDL.h>
// Include GLAD
#include <glad/glad.h>

#include <time.h>
#include <sys/time.h>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

int main(int argc, char* argv[]){

    // Create a window data type
    // This pointer will point to the 
    // window that is allocated from SDL_CreateWindow
    SDL_Window* window=nullptr;

    // Initialize the video subsystem.
    // If it returns less than 1, then an
    // error code will be received.
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL could not be initialized: " <<
                  SDL_GetError();
    }else{
        std::cout << "SDL video system is ready to go\n";
    }
    // Before we create our window, specify OpenGL version
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,24);

    // Request a window to be created for our platform
    // The parameters are for the title, x and y position,
    // and the width and height of the window.
    window = SDL_CreateWindow("C++ SDL2 Window",
            20,
            20,
            1920,
            1280,
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    // OpenGL setup the graphics context
    SDL_GLContext context;
    context = SDL_GL_CreateContext(window);

    // Setup our function pointers
    gladLoadGLLoader(SDL_GL_GetProcAddress);

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    int success;
    char infoLog[512];
    unsigned int shaderProgram = glCreateProgram();
    unsigned int VBO, VAO, EBO;


    // Infinite loop for our application
    bool gameIsRunning = true;

	long int count = 0;

	long int media = 0;

	long int secunds = 0;

	long int countSecunds = 0.0;

	struct timeval stop, start, a1, a2, a3;

    while(gameIsRunning){

		    gettimeofday(&start, NULL);

        glViewport(0,0,1920,1280);

        SDL_Event event;
        // Start our event loop
        while(SDL_PollEvent(&event)){
            // Handle each specific event
            if(event.type == SDL_QUIT){
                gameIsRunning= false;
            }
            // if(event.type == SDL_MOUSEMOTION){
            //     std::cout << "mouse has been moved\n";
            // }
            // if(event.type == SDL_KEYDOWN){
            //     std::cout << "a key has been pressed\n";
            //     if(event.key.keysym.sym == SDLK_0){
            //         std::cout << "0 was pressed\n";
            //     }else{
            //         std::cout << "0 was not pressed\n";
            //     }
            // }
            // Retrieve the state of all of the keys
            // Then we can query the scan code of one or more
            // keys at a time
            // const Uint8* state = SDL_GetKeyboardState(NULL);
            // if(state[SDL_SCANCODE_RIGHT]){
            //     std::cout << "right arrow key is pressed\n";
            // }
        }

        // for (size_t i = 0; i < 1000; i++){
          glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
          glCompileShader(vertexShader);
          glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
          if (!success){
              glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
              std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
          }
          glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
          glCompileShader(fragmentShader);
          glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
          if (!success){
              glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
              std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
          }
          glAttachShader(shaderProgram, vertexShader);
          glAttachShader(shaderProgram, fragmentShader);
          glLinkProgram(shaderProgram);
          glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
          if (!success) {
              glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
              std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
          }
          glDeleteShader(vertexShader);
          glDeleteShader(fragmentShader);
          float vertices[] = {
              500.0f,  500.0f, 0.0f,  // top right
              500.0f, -500.0f, 0.0f,  // bottom right
              -500.0f, -500.0f, 0.0f,  // bottom left
              -500.0f,  500.0f, 0.0f   // top left 
          };
          unsigned int indices[] = {
              0, 1, 3,  // first Triangle
              1, 2, 3   // second Triangle
          };
          glGenVertexArrays(1, &VAO);
          glGenBuffers(1, &VBO);
          glGenBuffers(1, &EBO);
          glBindVertexArray(VAO);
          glBindBuffer(GL_ARRAY_BUFFER, VBO);
          glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
          glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
          glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
          glEnableVertexAttribArray(0);
          glBindBuffer(GL_ARRAY_BUFFER, 0); 
          glBindVertexArray(0); 
        // }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        SDL_GL_SwapWindow(window);

        

        gettimeofday(&stop, NULL);

        if(stop.tv_usec < start.tv_usec){
          long int q = 999999 - start.tv_usec;
          long int w = stop.tv_usec + q;
          countSecunds += w;
        }else{
          countSecunds += (stop.tv_usec - start.tv_usec);
        }

        count++;

        if (countSecunds > 999999){
          
          secunds++;

          media += count;

          // printf("secunds: %lu | microsecunds: %lu | FPS: %lu | media: %lu\n", secunds, countSecunds, count, (media / secunds));
          printf("FPS: %lu | media: %lu\n", count, (media / secunds));
          // printf("start\t %lu us\n", start.tv_usec);
          // printf("stop\t %lu us\n", stop.tv_usec);
          countSecunds = 0.0;
          count = 0;
        }
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);

    SDL_DestroyWindow(window);
    SDL_Delay(3000);
    SDL_Delay(3000);
    SDL_Delay(3000);
    SDL_Delay(3000);
    SDL_Delay(3000);
    SDL_Quit();
    return 0;
}