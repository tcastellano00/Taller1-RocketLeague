#include <iostream>
#include <unistd.h>
#include <SDL2/SDL.h>

#include "ThreadCmdReader.h"

ThreadCmdReader::ThreadCmdReader(
    BlockingQueue<Command>& newQueue, 
    GameStatusMonitor& newGameStatusMonitor) : 
    queue(newQueue), gameStatusMonitor(newGameStatusMonitor) {}

void ThreadCmdReader::run() {
    bool running = (not gameStatusMonitor.gameIsClosed());

    while (running)
        running = handleEvents();
    
    gameStatusMonitor.setClose();
}

bool ThreadCmdReader::handleEvents() {
    SDL_Event event;
    bool running = true;
    while (SDL_WaitEvent(&event) && running) {
        running = handleEvent(event);
    }

    return running;
}

bool ThreadCmdReader::handleEvent(SDL_Event event) {
    switch(event.type) {
        case SDL_KEYDOWN: handleEventOnKeyDown(event); break;
        case SDL_KEYUP: handleEventOnKeyUp(event); break;
        case SDL_QUIT: handleEventOnQuit(); return false;
        default: break;
    }

    return true;
}

void ThreadCmdReader::handleEventOnKeyDown(SDL_Event event) {
    SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;

    switch (keyEvent.keysym.sym) {
        case SDLK_UP: pushCommand("flip right"); break;
        case SDLK_DOWN: pushCommand("flip left"); break;
        case SDLK_SPACE: pushCommand("jump"); break;
        case SDLK_RIGHT: pushCommand("right"); break;
        case SDLK_LEFT: pushCommand("left"); break;
        case SDLK_t: pushCommand("turbo"); break;
        default: break;
    }
}

void ThreadCmdReader::handleEventOnKeyUp(SDL_Event event) {
    SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;

    switch (keyEvent.keysym.sym) {
        case SDLK_UP: pushCommand("stop right"); break;
        case SDLK_DOWN: pushCommand("stop left"); break;
        //case SDLK_SPACE: pushCommand("stop jumping"); break;
        case SDLK_RIGHT: pushCommand("stop accelerating"); break;
        case SDLK_LEFT: pushCommand("stop accelerating"); break;
        case SDLK_t: pushCommand("stop turbo"); break;
        default: break;
    }
}

void ThreadCmdReader::handleEventOnQuit() {
    pushCommand("quit");
}

void ThreadCmdReader::pushCommand(const std::string command) {
    Command cmd(command);
    queue.push(cmd);
}

ThreadCmdReader::~ThreadCmdReader() {
    std::cout << "Cerramos cmd reader" << std::endl;
    this->join();
}