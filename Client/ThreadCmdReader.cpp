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
    keyBoardMapper()
    {}

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
}

void ThreadCmdReader::handleEventOnKeyUp(SDL_Event event) {
    SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;

    std::string command = keyBoardMapper.getActionByKeyCodeOnKeyUp(keyEvent.keysym.sym);

    pushCommand(command);
}

void ThreadCmdReader::handleEventOnQuit() {
    pushCommand(QUIT);
}

void ThreadCmdReader::pushCommand(const std::string command) {
    if (command == "") return;

    if (command == "pause music"){
        std::cout << "comando M" << std::endl; 
        gameStatusMonitor.toggleMusic();
    }

    if (command == "next music"){
        std::cout << "comando N" << std::endl;
    }
    
    Command cmd(command);
    queue.push(cmd);
}

ThreadCmdReader::~ThreadCmdReader() {
    std::cout << "Cerramos cmd reader" << std::endl;
    this->join();
}