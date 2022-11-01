#include "Renderer.h"
#include <iostream>

#include <SDL2/SDL.h>
#include <string>

Renderer::Renderer() {}

void Renderer::render(GameStatusMonitor& gameStatusMonitor) {
    std::cout << "Im rendering" << std::endl;

    SDL_Window *window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return;
    }

    // The window is open: could enter program loop here (see SDL_PollEvent())
    
    std::string lastState("");

    while (!gameStatusMonitor.gameIsClosed()) {
        std::string actualStatus = gameStatusMonitor.gameStatus();
        if (actualStatus == lastState) {
            continue;
        }
        lastState = actualStatus;
        std::cout<< actualStatus << std::endl;
        SDL_Delay(1000);
    }

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
}