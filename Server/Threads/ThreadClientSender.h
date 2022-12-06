#ifndef SERVER_THREAD_CLIENT_SENDER_H
#define SERVER_THREAD_CLIENT_SENDER_H

#include <list>
#include <string>
#include "../../Common/Thread.h"
#include "../../Common/Socket.h"
#include "../../Common/BlockingQueue.h"
#include "../../Common/Protocol.h"
#include "../../Common/GameStatus.h"
#include "../ClientConnection.h"

/*
Hilo encargado de recibir el estado actual del mundo por parte del hilo Broadcaster
y enviarlo al cliente correspondiente.
*/
class ThreadClientSender : public Thread{
    BlockingQueue<GameStatus> queue;
    Protocol protocol;
    bool open;

    public:
    ThreadClientSender(Socket& socket);

    void run() override;

    void push(GameStatus gameStatus);

    ~ThreadClientSender();
};

#endif