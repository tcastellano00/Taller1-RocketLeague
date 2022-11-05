#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "../Common/Thread.h"
#include "../Common/Socket.h"
#include "../Common/Queue.h"
#include "../Common/Command.h"
#include "ClientConnection.h"
#include "ThreadClientReceiver.h"

#include <list>


class Gameloop : public Thread{

    // Queue <Command> recibingQueue;
    // Queue <Command> senderQueue;
    std::list <ThreadClientReceiver> clientThreadList;
    std::list <ClientConnection> connectionList;

    public:
    Gameloop();

    void run() override;

    void init(std::list <ClientConnection>& connectionList);

    /*
    * Libera los recursos.
    * */
    ~Gameloop();
};

#endif