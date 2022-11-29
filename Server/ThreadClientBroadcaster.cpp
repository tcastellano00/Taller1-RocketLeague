#include "ThreadClientBroadcaster.h"
#include "ThreadClientSender.h"
#include "../Common/Queue.h"
#include "../Common/LibError.h"

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
    
    try
    {
        //Instanciamos todos los hilos sender.
        for (auto connection = connections.begin(); 
                connection != connections.end(); 
                ++connection) {
            clientSenderThreads.emplace_back((*connection).getSocketReference());
            clientSenderThreads.back().start();
        }

        //Enviamos el estado del mundo a todos los clientes conectados.
        // while (not gameStatus.isClosed()), y ya no hace falta el bool
        while (open) {
            GameStatus gameStatus = senderQueue.pop();

            for (auto sender = clientSenderThreads.begin(); 
                    sender != clientSenderThreads.end(); 
                    ++sender) {
                (*sender).push(gameStatus);
            }
            
            open = (not gameStatus.isClosed());
        }
    }
    catch(const LibError &e) {
        // Por qué ignorar esta exception? Es esperada? Si ignoran una exception, pongan
        // un comentario de por qué lo hacen.
    }
}

ThreadClientBroadcaster::~ThreadClientBroadcaster() {
    this->join();
}
