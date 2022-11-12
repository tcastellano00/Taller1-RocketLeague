#include "ThreadClientBroadcaster.h"
#include "ThreadClientSender.h"
#include "../Common/Queue.h"


ThreadClientBroadcaster::ThreadClientBroadcaster(std::list<ClientConnection>& newConnections, Queue<Command>& newSenderQueue)
    :senderQueue(newSenderQueue), connections(newConnections) , open(true){
}

void ThreadClientBroadcaster::run(){
    std::cout << "Broadcaster::run" << std::endl;
    std::list<ThreadClientSender> clientSenderThreads;
    
    //Instanciamos todos los hilos sender.
    for (auto connection = connections.begin(); connection != connections.end(); ++connection) {
        std::cout << "ThreadClientSender::run in for" << std::endl;
        clientSenderThreads.emplace_back((*connection).getSocketReference());
        clientSenderThreads.back().start();
    }

    //Enviamos el estado del mundo a todos los clientes conectados.
    while (open) {
        Command command = senderQueue.pop();
        
        for (auto sender = clientSenderThreads.begin(); 
                  sender != clientSenderThreads.end(); 
                  ++sender) {
            (*sender).push(command);
        }
    }
}

ThreadClientBroadcaster::~ThreadClientBroadcaster() {
    this->join();
}
