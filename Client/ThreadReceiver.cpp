#include "ThreadReceiver.h"
#include <iostream>
#include "../Common/Protocol.h"

ThreadReceiver::ThreadReceiver(Socket& cnct, GameStatusMonitor& newGameStatusMonitor): gameStatusMonitor(newGameStatusMonitor), connection(cnct){}

void ThreadReceiver::run() {
    std::cout << "Im running receiver thread" << std::endl;
    Protocol protocol(connection);
    while (!gameStatusMonitor.gameIsClosed()) {
        std::string response = protocol.reciveMessage();
        gameStatusMonitor.statusUpdate(response);
        if (response == "close") {
            gameStatusMonitor.setClose();
        }
    }

}

ThreadReceiver::~ThreadReceiver() {
    this->join();
}