#ifndef SERVER_THREAD_CLIENT_BROADCASTER_H
#define SERVER_THREAD_CLIENT_BROADCASTER_H

#include <list>
#include <string>
#include "../../Common/Thread.h"
#include "../../Common/Socket.h"
#include "../../Common/BlockingQueue.h"
#include "../../Common/GameStatus.h"
#include "../ClientConnection.h"


/*
Hilo encargado de recibir el estado actual del mundo desde una unica queue
(en la que pushea los estados actuales el GameLoop) y enviarlo a los distintos hilos
Senders.
*/
class ThreadClientBroadcaster : public Thread{

    BlockingQueue<GameStatus>& senderQueue;
    std::list<ClientConnection>& connections;
    bool open;

    public:
    ThreadClientBroadcaster(
        BlockingQueue<GameStatus>& newSenderQueue,
        std::list<ClientConnection>& newConnections
    );

    void run() override;

    ~ThreadClientBroadcaster();
};

#endif