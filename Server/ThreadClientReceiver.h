#ifndef SERVER_THREAD_CLIENT_RECEIVER_H
#define SERVER_THREAD_CLIENT_RECEIVER_H

#include "../Common/Thread.h"
#include "../Common/Socket.h"
#include "../Common/NonBlockingQueue.h"
#include "../Common/Protocol.h"
#include "ActionsClient/ActionsClient.h"

class ThreadClientReceiver : public Thread{

    Socket& sktConecction;
    NonBlockingQueue<std::shared_ptr<ActionsClient>>& recibingQueue;
    Protocol receiverProtocol;

    public:
    void run() override;

    ThreadClientReceiver(
        Socket& newSktConecction, 
        NonBlockingQueue<std::shared_ptr<ActionsClient>>& newRecibingQueue);
    
    ~ThreadClientReceiver();
};

#endif
