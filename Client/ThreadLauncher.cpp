#include "ThreadLauncher.h"
#include <iostream>
#include "ThreadCmdreader.h"
#include "ThreadReceiver.h"
#include "ThreadSender.h"
#include "../Common/common_blockingqueue.h"
#include "../Common/common_command.h"


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