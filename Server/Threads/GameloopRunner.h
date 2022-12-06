#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "../../Common/Thread.h"
#include "../../Common/Socket.h"
#include "../../Common/BlockingQueue.h"
#include "../../Common/NonBlockingQueue.h"
#include "../../Common/Command.h"
#include "../../Common/Config/CommonConfig.h"
#include "../ClientConnection.h"
#include "ThreadClientReceiver.h"

#include <list>





class GameloopRunner : public Thread {

private:
    BlockingQueue<GameStatus> senderQueue;
    NonBlockingQueue<std::shared_ptr<ActionsClient>> recibingQueue;
    std::list <ThreadClientReceiver> clientThreadReceiver;
    std::list <ClientConnection> connectionList;
    bool isRunning;
    bool isThreadRunning;


public:
    GameloopRunner();

    void run() override;

    void init(std::list <ClientConnection>& connectionList);
    
    void stop();
    /*
    * Libera los recursos.
    * */
    ~GameloopRunner();
};

#endif