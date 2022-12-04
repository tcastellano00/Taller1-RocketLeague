#include "ThreadClientBroadcaster.h"
#include "ThreadClientSender.h"
#include "../../Common/BlockingQueue.h"
#include "../../Common/LibError.h"

ThreadClientBroadcaster::ThreadClientBroadcaster(
    BlockingQueue<GameStatus>& newSenderQueue,
    std::list<ClientConnection>& newConnections)
    : senderQueue(newSenderQueue), 
      connections(newConnections), 
      open(true) { }

void ThreadClientBroadcaster::run(){
    std::cout << "Broadcaster::run" << std::endl;
    std::list<ThreadClientSender> clientSenderThreads;
    
    try
    {
        //Instanciamos todos los hilos sender.
        for (auto &connection : connections){
            clientSenderThreads.emplace_back(connection.getSocketReference());
            clientSenderThreads.back().start();
        }

        //Enviamos el estado del mundo a todos los clientes conectados.
        while (open) {
            GameStatus gameStatus = senderQueue.pop();

            for (auto &senderThread : clientSenderThreads)
                senderThread.push(gameStatus);
            
            open = (not gameStatus.isClosed());
        }
    }
    catch(const LibError &e) { }
}

ThreadClientBroadcaster::~ThreadClientBroadcaster() {
    this->join();
}
