#include "client_threadlauncher.h"
#include <iostream>
#include "client_threadcmdreader.h"
#include "client_threadreceiver.h"
#include "client_threadsender.h"
#include "common_blockingqueue.h"
#include "common_command.h"


ThreadLauncher::ThreadLauncher() {}

void ThreadLauncher::start(Socket& connection,GameStatusMonitor& gameStatusMonitor) {
    std::cout << "Im launching the threads" << std::endl;
    BlockingQueue<Command> queue;
    ThreadCmdReader cmdReader(queue);
    cmdReader.start();
    ThreadSender sender(queue, connection,gameStatusMonitor);
    sender.start();
    ThreadReceiver receiver(gameStatusMonitor);
    receiver.start();
}