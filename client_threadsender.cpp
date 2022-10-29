#include "client_threadsender.h"
#include <iostream>

void ThreadSender::run() {
    std::cout << "Im running sender thread" << std::endl;
}

ThreadSender::~ThreadSender() {
    this->join();
}