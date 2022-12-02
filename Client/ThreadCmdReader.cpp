#include <iostream>
#include <unistd.h>
#include <SDL2/SDL.h>

#include "ThreadCmdReader.h"
#include "../Common/Constants/ActionsClient.h"

ThreadCmdReader::ThreadCmdReader(
    BlockingQueue<Command>& newQueue, 
    GameStatusMonitor& newGameStatusMonitor) : 
    queue(newQueue), 
    gameStatusMonitor(newGameStatusMonitor),
    keyBoardMapper() {}

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

    std::string command = keyBoardMapper.getActionByKeyCodeOnKeyDown(keyEvent.keysym.sym);

    pushCommand(command);
    /*
    switch (keyEvent.keysym.sym) {
        case SDLK_UP: pushCommand(START_FLIPING_RIGHT); break;
        case SDLK_DOWN: pushCommand(START_FLIPING_LEFT); break;
        case SDLK_SPACE: pushCommand(START_JUMPING); break;
        case SDLK_RIGHT: pushCommand(START_MOVING_RIGHT); break;
        case SDLK_LEFT: pushCommand(START_MOVING_LEFT); break;
        case SDLK_t: pushCommand(START_DOING_TURBO); break;
        default: break;
    } */
}

void ThreadCmdReader::handleEventOnKeyUp(SDL_Event event) {
    SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;

    std::string command = keyBoardMapper.getActionByKeyCodeOnKeyUp(keyEvent.keysym.sym);

    pushCommand(command);
    /*
    switch (keyEvent.keysym.sym) {
        case SDLK_UP: pushCommand(STOP_FLIPING_RIGHT); break;
        case SDLK_DOWN: pushCommand(STOP_FLIPING_LEFT); break;
        case SDLK_SPACE: pushCommand(STOP_JUMPING); break;
        case SDLK_RIGHT: pushCommand(STOP_MOVING_RIGHT); break;
        case SDLK_LEFT: pushCommand(STOP_MOVING_LEFT); break;
        case SDLK_t: pushCommand(STOP_DOING_TURBO); break;
        default: break;
    } */
}

void ThreadCmdReader::handleEventOnQuit() {
    pushCommand(QUIT);
}

void ThreadCmdReader::pushCommand(const std::string command) {
    if (command == "") return;
    
    Command cmd(command);
    queue.push(cmd);
}

ThreadCmdReader::~ThreadCmdReader() {
    std::cout << "Cerramos cmd reader" << std::endl;
    this->join();
}