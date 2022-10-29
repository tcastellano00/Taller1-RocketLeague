#include "client_threadreceiver.h"
#include <iostream>

void ThreadReceiver::run() {
    std::cout << "Im running receiver thread" << std::endl;
}

ThreadReceiver::~ThreadReceiver() {
    this->join();
}