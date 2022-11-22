#include "ThreadSender.h"
#include <iostream>
#include "../Common/LibError.h"
#include "../Common/Protocol.h"

ThreadSender::ThreadSender(
    Queue<Command>& newQueue, 
    Socket& cnct, 
    GameStatusMonitor& newGameStatusMonitor)
    : queue(newQueue),
      connection(cnct),
      gameStatusMonitor(newGameStatusMonitor) { }

void ThreadSender::run() {
    std::cout << "Im running sender thread" << std::endl;
    Protocol protocol(connection);

    try {
        while (not gameStatusMonitor.gameIsClosed()) {

            Command command = queue.pop();

            if (command.getType() == "quit") {
                break;
            }
            
            if (protocol.isClosed()) {
                gameStatusMonitor.setClose();
                break;
            }

            protocol.sendMessage(command.getType());        
        }
    }
    catch(const LibError& e)
    {
        gameStatusMonitor.setClose();
    }
}

ThreadSender::~ThreadSender() {
    std::cout << "Cerramos sender" << std::endl;
    this->join();
}