#include "client_threadlauncher.h"
#include <iostream>
#include "client_threadcmdreader.h"
#include "client_threadreceiver.h"
#include "client_threadsender.h"

ThreadLauncher::ThreadLauncher() {}

void ThreadLauncher::start() {
    std::cout << "Im launching the threads" << std::endl;
    ThreadCmdReader cmdReader;
    cmdReader.start();
    ThreadReceiver receiver;
    receiver.start();
    ThreadSender sender;
    sender.start();
}