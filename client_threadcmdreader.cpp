#include "client_threadcmdreader.h"
#include <iostream>

void ThreadCmdReader::run() {
    std::cout << "Im running cmd reader thread" << std::endl;
}

ThreadCmdReader::~ThreadCmdReader() {
    this->join();
}