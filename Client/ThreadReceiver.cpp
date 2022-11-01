#include "ThreadReceiver.h"
#include <iostream>

ThreadReceiver::ThreadReceiver(GameStatusMonitor& newGameStatusMonitor):gameStatusMonitor(newGameStatusMonitor){}

void ThreadReceiver::run() {
    std::cout << "Im running receiver thread" << std::endl;
}

ThreadReceiver::~ThreadReceiver() {
    this->join();
}