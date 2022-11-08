#ifndef SERVER_THREAD_CLIENT_SENDER_H
#define SERVER_THREAD_CLIENT_SENDER_H

#include <list>
#include <string>
#include "../Common/Thread.h"
#include "../Common/Socket.h"
#include "../Common/Queue.h"
#include "../Common/Command.h"
#include "../Common/Protocol.h"
#include "ClientConnection.h"


class ThreadClientSender : public Thread{
    Queue <Command>& senderQueue;
    //Socket& socketSender;
    Protocol senderProtocol;
    bool senderOpen;

    public:
    ThreadClientSender(Queue <Command>& newSenderQueue,Socket& newSocketSender);

    void run() override;

    ~ThreadClientSender();
};

#endif