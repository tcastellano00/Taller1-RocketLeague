#include "../../Common/LibError.h"
#include "../../Common/NonBlockingQueue.h"

#include "ThreadClientReceiver.h"
#include "../ActionsClient/ActionsClient.h"

ThreadClientReceiver::ThreadClientReceiver(
    int clientId,
    Socket& newSktConecction, 
    NonBlockingQueue<std::shared_ptr<ActionsClient>>& newRecibingQueue
)
    :   clientId(clientId),
        sktConecction(newSktConecction),
        recibingQueue(newRecibingQueue), 
        receiverProtocol(sktConecction){
}

void ThreadClientReceiver::run(){

    try {
        while (not receiverProtocol.isClosed()) {
            std::string message = receiverProtocol.reciveMessage();

            std::shared_ptr<ActionsClient> actionClient = ActionsClient::get_command_ptr(
                message, 
                this->clientId
            );

            recibingQueue.push(actionClient);
        }
    } catch(const LibError &e) { }
}

ThreadClientReceiver::~ThreadClientReceiver(){
    this->join();
}