#include "ThreadLauncher.h"
#include <iostream>
#include "ThreadCmdReader.h"
#include "ThreadReceiver.h"
#include "ThreadSender.h"
#include "Renderer.h"
#include "../Common/BlockingQueue.h"
#include "../Common/Command.h"


ThreadLauncher::ThreadLauncher() {}

void ThreadLauncher::start(Socket& connection,GameStatusMonitor& gameStatusMonitor) {
    std::cout << "Im launching the threads" << std::endl;
    BlockingQueue<Command> queue;

    ThreadCmdReader cmdReader(queue);
    cmdReader.start();

    ThreadSender sender(queue, connection, gameStatusMonitor);
    sender.start();
    
    ThreadReceiver receiver(connection, gameStatusMonitor);
    receiver.start();

    Renderer renderer;
    renderer.launch();
    //renderer.render(gameStatusMonitor);
}