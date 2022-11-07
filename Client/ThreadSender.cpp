#include "ThreadSender.h"
#include <iostream>
#include "../Common/Protocol.h"

void ThreadSender::run() {
    std::cout << "Im running sender thread" << std::endl;
    Protocol protocol(connection);

    while (playing) {

        Command command = queue.pop();

        /*
        if (protocol.isClosed()) {
            break;
        }

        protocol.sendMessage(command.getType());
        */

        if (command.getType() == "right")
            gameStatusMonitor.movePlayerRight();
        else if (command.getType() == "left")
            gameStatusMonitor.movePlayerLeft();
        else if (command.getType() == "close")
            gameStatusMonitor.setClose();

        playing = (not gameStatusMonitor.gameIsClosed());
    }
}

ThreadSender::ThreadSender(Queue<Command>& newQueue, Socket& cnct, GameStatusMonitor& newGameStatusMonitor):
    queue(newQueue),connection(cnct),gameStatusMonitor(newGameStatusMonitor) {
        this->playing = true;
    }


ThreadSender::~ThreadSender() {
    std::cout << "Cerramos sender" << std::endl;
    this->join();
}