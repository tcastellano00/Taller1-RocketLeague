#include "ThreadCmdReader.h"
#include <iostream>
#include <SDL2/SDL.h>

void ThreadCmdReader::run() {
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
                    case SDLK_RIGHT: {
                        Command cmd("accelerate right");
                        queue.push(cmd);
                        break;
                    }
                    case SDLK_LEFT: {
                        Command cmd("accelerate left");
                        queue.push(cmd);
                        break;
                    }
                    case SDLK_SPACE: {
                        Command cmd("jump");
                        queue.push(cmd);
                        break;
                    }
                }
            }
            case SDL_KEYUP: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_RIGHT: {
                        std::cout << "stop" << std::endl;
                        Command cmd("stop accelerate right");
                        queue.push(cmd);
                        break;
                    }
                    case SDLK_LEFT: {
                        std::cout << "stop" << std::endl;
                        Command cmd("stop accelerate left");
                        queue.push(cmd);
                        break;
                    }
                }
            }
            case SDL_QUIT: {
                std::cout << "Quit :(" << std::endl;
                Command cmd("close");
                queue.push(cmd);
                return false;
            }
            
        }

    }

    return true;

}

ThreadCmdReader::ThreadCmdReader(BlockingQueue<Command>& newQueue): queue(newQueue) {}

ThreadCmdReader::~ThreadCmdReader() {
    this->join();
}