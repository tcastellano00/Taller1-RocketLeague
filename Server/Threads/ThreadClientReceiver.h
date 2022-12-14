#ifndef SERVER_THREAD_CLIENT_RECEIVER_H
#define SERVER_THREAD_CLIENT_RECEIVER_H

#include "../../Common/Thread.h"
#include "../../Common/Socket.h"
#include "../../Common/NonBlockingQueue.h"
#include "../../Common/Protocol.h"
#include "../ActionsClient/ActionsClient.h"


/*
Hilo encargado de recibir la ActionClient actual del cliente correspondiente y pushearlo
a la unica receivingQueue, de donde el GameLoop los lee.
*/
class ThreadClientReceiver : public Thread{
    int clientId;
    Socket& sktConecction;
    NonBlockingQueue<std::shared_ptr<ActionsClient>>& recibingQueue;
    Protocol receiverProtocol;

    public:
    void run() override;

    ThreadClientReceiver(
        int clientId,
        Socket& newSktConecction, 
        NonBlockingQueue<std::shared_ptr<ActionsClient>>& newRecibingQueue);
    
    ~ThreadClientReceiver();
};

#endif
