#ifndef SERVER_THREAD_CLIENT_BROADCASTER_H
#define SERVER_THREAD_CLIENT_BROADCASTER_H

#include <list>
#include <string>
#include "../Common/Thread.h"
#include "../Common/Socket.h"
#include "../Common/Queue.h"
#include "../Common/Command.h"
#include "ClientConnection.h"

class Broadcaster : public Thread{

    Queue <Command>& senderQueue;
    std::list<ClientConnection>& connections;
    //crear lista de queues
    
    public:
    Broadcaster(std::list<ClientConnection>& newConnections, Queue<Command>& newSenderQueue);

    void run() override;

    ~Broadcaster() = default;
};

#endif