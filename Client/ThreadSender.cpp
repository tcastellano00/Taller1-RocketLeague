#include "ThreadSender.h"
#include <iostream>
#include "../Common/LibError.h"
#include "../Common/Protocol.h"

ThreadSender::ThreadSender(
    BlockingQueue<Command>& newQueue, 
    Socket& cnct, 
    GameStatusMonitor& newGameStatusMonitor)
    : queue(newQueue),
      connection(cnct),
      gameStatusMonitor(newGameStatusMonitor) { }

void ThreadSender::run() {
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
    this->join();
}