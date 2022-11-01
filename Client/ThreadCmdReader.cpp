#include "ThreadCmdReader.h"
#include <iostream>

void ThreadCmdReader::run() {
    std::cout << "Im running cmd reader thread" << std::endl;
}

ThreadCmdReader::ThreadCmdReader(BlockingQueue<Command>& newQueue): queue(newQueue) {}

ThreadCmdReader::~ThreadCmdReader() {
    this->join();
}