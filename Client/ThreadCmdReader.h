#ifndef CLIENT_THREAD_CMDREADER_H
#define CLIENT_THREAD_CMDREADER_H

#include "../Common/Thread.h"
#include "../Common/BlockingQueue.h"
#include "../Common/Command.h"
#include "GameStatusMonitor.h"
#include "BackGroundMusic.h"

#include <SDL2/SDL.h>
#include "SDL/KeyboardEvent/KeyBoardMapper.h"

/*
Clase que registra todos los comandos ingresados por el usuario
para luego ingresarlos a una cola de eventos.
*/
class ThreadCmdReader: public Thread {
private:
    BlockingQueue<Command>& queue;
    GameStatusMonitor& gameStatusMonitor;
    KeyBoardMapper keyBoardMapper;

    bool handleEvents();
    bool handleEvent(SDL_Event event);
    void handleEventOnKeyDown(SDL_Event event);
    void handleEventOnKeyUp(SDL_Event event);
    void handleEventOnQuit();
    void pushCommand(const std::string command);

public:
    void run() override;
    ThreadCmdReader(
        BlockingQueue<Command>& newQueue, 
        GameStatusMonitor& gameStatusMonitor);
    ~ThreadCmdReader();
};

#endif