#include "Renderer.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include "SDL/Player.h"
#include "SDL/Animation.h" 
#include <exception>
#include <unistd.h>


Renderer::Renderer() {}

// void Renderer::render(GameStatusMonitor& gameStatusMonitor) {
//     std::cout << "Im rendering" << std::endl;

//     SDL_Window *window;                    // Declare a pointer

//     SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

//     // Create an application window with the following settings:
//     window = SDL_CreateWindow(
//         "An SDL2 window",                  // window title
//         SDL_WINDOWPOS_UNDEFINED,           // initial x position
//         SDL_WINDOWPOS_UNDEFINED,           // initial y position
//         640,                               // width, in pixels
//         480,                               // height, in pixels
//         SDL_WINDOW_OPENGL                  // flags - see below
//     );

//     // Check that the window was successfully created
//     if (window == NULL) {
//         // In the case that the window could not be made...
//         printf("Could not create window: %s\n", SDL_GetError());
//         return;
//     }

//     // The window is open: could enter program loop here (see SDL_PollEvent())
    
//     std::string lastState("");

//     while (!gameStatusMonitor.gameIsClosed()) {
//         std::string actualStatus = gameStatusMonitor.gameStatus();
//         if (actualStatus == lastState) {
//             continue;
//         }
//         lastState = actualStatus;
//         std::cout<< actualStatus << std::endl;
//         SDL_Delay(1000);
//     }

//     // Close and destroy the window
//     SDL_DestroyWindow(window);

//     // Clean up
//     SDL_Quit();
// }


static bool handleEvents(Player &player);
static void render(SDL2pp::Renderer &renderer, Player &player);
static void update(Player &player, float dt);

void Renderer::launch(){
    try {
        // Inicializo biblioteca de SDL
        SDL2pp::SDL sdl(SDL_INIT_VIDEO);
        // Creo una ventana dinamica con titulo "Hello world"
        SDL2pp::Window window("Hello world", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            800, 600, SDL_WINDOW_RESIZABLE);

        // Creo renderer
        SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

        // Usar factory
        SDL2pp::Texture im(renderer, 
            SDL2pp::Surface("assets/autoderecha.png").SetColorKey(true, 0));

        Player player(im);
        bool running = true;
        // Gameloop, notar como tenemos desacoplado el procesamiento de los inputs (handleEvents)
        // del update del modelo.
        while (running) {
            running = handleEvents(player);
            update(player, FRAME_RATE);
            render(renderer, player);
            // la cantidad de segundos que debo dormir se debe ajustar en función
            // de la cantidad de tiempo que demoró el handleEvents y el render
            usleep(FRAME_RATE);
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        //return 1;
    }
    //return 0;
}

/**
 * Va a tomar un evento de teclado, y actualizará el modelo en función de los eventos que lleguen.
 * En un juego real no se tomará de a un evento por vuelta del gameloop, sino que se deberán tomar TODOS
 * o N eventos por vuelta
 */
static bool handleEvents(Player &player) {
    SDL_Event event;
    // Para el alumno: Buscar diferencia entre waitEvent y pollEvent
    while(SDL_PollEvent(&event)){
        switch(event.type) {
            case SDL_KEYDOWN: {
                // ¿Qué pasa si mantengo presionada la tecla?    
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_LEFT:
                        player.moveLeft();
                        break;
                    case SDLK_RIGHT:
                        player.moveRigth();
                        break;
                    }
                } // Fin KEY_DOWN
                break;
            case SDL_KEYUP: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_LEFT:
                        player.stopMoving();
                        break;
                    case SDLK_RIGHT:
                        player.stopMoving();
                        break;
                    } 
                }// Fin KEY_UP
                break;
            case SDL_MOUSEMOTION:
                std::cout << "Oh! Mouse" << std::endl;
                break;
            case SDL_QUIT:
                std::cout << "Quit :(" << std::endl;
                return false;
        } // fin switch(event)
    } // fin while(SDL_PollEvents)
    return true;
}

static void render(SDL2pp::Renderer &renderer, Player &player) {
    renderer.Clear();
    player.render(renderer);
    renderer.Present();
}

static void update(Player &player, float dt) {
    player.update(dt);
}