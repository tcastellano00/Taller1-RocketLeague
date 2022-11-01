#include "ThreadSender.h"
#include <iostream>
#include "../Common/Protocol.h"

void ThreadSender::run() {
    std::cout << "Im running sender thread" << std::endl;
    Protocol protocol(connection);

    while (playing) {
        Command command = queue.pop();

        if (protocol.isClosed()) {
            break;
        }

        protocol.sendMessage(command.getType());

        playing = gameStatusMonitor.gameIsClosed();
    }
}

ThreadSender::ThreadSender(BlockingQueue<Command>& newQueue, Socket& cnct,GameStatusMonitor& newGameStatusMonitor):
    queue(newQueue),connection(cnct),gameStatusMonitor(newGameStatusMonitor) {
        this->playing = true;
    }


ThreadSender::~ThreadSender() {
    this->join();
}