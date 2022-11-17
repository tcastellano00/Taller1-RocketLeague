#include "ThreadCmdReader.h"
#include <iostream>
#include <unistd.h>
#include <SDL2/SDL.h>

void ThreadCmdReader::run() {
    usleep(5000000); //reemplazar por una CV.

    std::cout << "Im running cmd reader thread" << std::endl;

    bool running = true;

    while (running) {
        running = handleEvents();
    }
}

bool ThreadCmdReader::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_KEYDOWN: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_UP: {
                        Command cmd("right");
                        queue.push(cmd);
                        break;
                    }
                    case SDLK_DOWN: {
                        Command cmd("left");
                        queue.push(cmd);
                        break;
                    }
                    case SDLK_SPACE: {
                        Command cmd("jump");
                        queue.push(cmd);
                        break;
                    }
                    case SDLK_RIGHT: {
                        Command cmd("flip right");
                        queue.push(cmd);
                        break;
                    }
                    case SDLK_LEFT: {
                        Command cmd("flip left");
                        queue.push(cmd);
                        break;
                    }
                }
                break;
            }
            case SDL_KEYUP: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_RIGHT: {
                        Command cmd("stop right");
                        queue.push(cmd);
                        break;
                    }
                    case SDLK_LEFT: {
                        Command cmd("stop left");
                        queue.push(cmd);
                        break;
                    }
                }
                break;
            }
            case SDL_QUIT: {
                std::cout << "Quit :(" << std::endl;
                Command cmd("close");
                Command cmdQueue("close queue");
                queue.push(cmd);
                queue.push(cmdQueue);
                return false;
            }
            
        }

    }

    return true;

}

ThreadCmdReader::ThreadCmdReader(Queue<Command>& newQueue): queue(newQueue) {}

ThreadCmdReader::~ThreadCmdReader() {
    std::cout << "Cerramos cmd reader" << std::endl;
    this->join();
}