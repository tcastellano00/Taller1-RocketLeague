#ifndef SERVER_THREAD_CLIENT_SENDER_H
#define SERVER_THREAD_CLIENT_SENDER_H

#include <list>
#include <string>
#include "../Common/Thread.h"
#include "../Common/Socket.h"
#include "../Common/Queue.h"
#include "../Common/Protocol.h"
#include "../Common/GameStatus.h"
#include "ClientConnection.h"


class ThreadClientSender : public Thread{
    Queue<GameStatus> queue;
    Protocol protocol;
    bool open;

    public:
    ThreadClientSender(Socket& socket);

    void run() override;

    void push(GameStatus gameStatus);

    ~ThreadClientSender();
};

#endif