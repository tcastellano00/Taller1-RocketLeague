#include "ThreadClientBroadcaster.h"
#include "ThreadClientSender.h"
#include "../Common/Queue.h"

ThreadClientBroadcaster::ThreadClientBroadcaster(
    Queue<GameStatus>& newSenderQueue,
    std::list<ClientConnection>& newConnections)
    : senderQueue(newSenderQueue), 
      connections(newConnections), 
      open(true) { 

    }

void ThreadClientBroadcaster::run(){
    std::cout << "Broadcaster::run" << std::endl;
    std::list<ThreadClientSender> clientSenderThreads;
    
    //Instanciamos todos los hilos sender.
    for (auto connection = connections.begin(); 
              connection != connections.end(); 
              ++connection) {
        clientSenderThreads.emplace_back((*connection).getSocketReference());
        clientSenderThreads.back().start();
    }

    //Enviamos el estado del mundo a todos los clientes conectados.
    while (open) {
        GameStatus gameStatus = senderQueue.pop();

        for (auto sender = clientSenderThreads.begin(); 
                  sender != clientSenderThreads.end(); 
                  ++sender) {
            (*sender).push(gameStatus);
        }
    }
}

ThreadClientBroadcaster::~ThreadClientBroadcaster() {
    this->join();
}
