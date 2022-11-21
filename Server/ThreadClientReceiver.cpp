#include "ThreadClientReceiver.h"
#include "../Common/Queue.h"
#include "ActionsClient/ActionsClient.h"


ThreadClientReceiver::ThreadClientReceiver(
    Socket& newSktConecction, 
    Queue<std::shared_ptr<ActionsClient>>& newRecibingQueue
)
    :   sktConecction(newSktConecction),
        recibingQueue(newRecibingQueue), 
        receiverProtocol(sktConecction){
}

void ThreadClientReceiver::run(){
    std::cout << "ThreadClientReceiver::run" << std::endl;

    while (not receiverProtocol.isClosed()) {
        std::string message = receiverProtocol.reciveMessage();

        std::shared_ptr<ActionsClient> actionClient = ActionsClient::get_command_ptr(
            message, 
            sktConecction.getIdentifier()
        );

        recibingQueue.push(actionClient);
    }
}

ThreadClientReceiver::~ThreadClientReceiver(){
    this->join();
}