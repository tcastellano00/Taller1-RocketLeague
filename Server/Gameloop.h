#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "../Common/Thread.h"
#include "../Common/Socket.h"
#include "../Common/Queue.h"
#include "../Common/Command.h"
#include "ClientConnection.h"
#include "ThreadClientReceiver.h"

#include <list>
#include <chrono>
#include <unistd.h>
#define LIMITOFCOMANDS 10
#define DELTA 1000000.0f/25.0f
typedef std::chrono::high_resolution_clock Clock;


class Gameloop : public Thread {

private:
    Queue<GameStatus> senderQueue;
    Queue<std::shared_ptr<ActionsClient>> recibingQueue;
    std::list <ThreadClientReceiver> clientThreadReceiver;
    std::list <ClientConnection> connectionList;
    bool isRunning;

    void synchronizeFrameRate(
        std::chrono::_V2::system_clock::time_point timeStart,
        std::chrono::_V2::system_clock::time_point timeFinish
    );

public:
    Gameloop();

    void run() override;

    void init(std::list <ClientConnection>& connectionList);
    
    void stop();
    /*
    * Libera los recursos.
    * */
    ~Gameloop();
};

#endif