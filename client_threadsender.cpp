#include "client_threadsender.h"
#include <iostream>
#include "common_protocol.h"

void ThreadSender::run() {
    std::cout << "Im running sender thread" << std::endl;
    Protocol protocol(connection);

    while (playing) {
        Command command(queue.pop());

        if (protocol.isClosed()) {
            break;
        }

        protocol.sendMessage(command.getType());
        //playing = monitorGameStatus.stillPlaying();
    }
}

ThreadSender::ThreadSender(BlockingQueue<Command>& newQueue, Socket& cnct): queue(newQueue), connection(cnct) {}


ThreadSender::~ThreadSender() {
    this->join();
}