#ifndef CLIENT_THREAD_CMDREADER_H
#define CLIENT_THREAD_CMDREADER_H

#include "../Common/Thread.h"
#include "../Common/BlockingQueue.h"
#include "../Common/Command.h"
#include "GameStatusMonitor.h"

class ThreadCmdReader: public Thread {
private:
    BlockingQueue<Command>& queue;
    GameStatusMonitor& gameStatusMonitor;

    bool handleEvents();
public:
    void run() override;
    ThreadCmdReader(
        BlockingQueue<Command>& newQueue, 
        GameStatusMonitor& gameStatusMonitor);
    ~ThreadCmdReader();
};

#endif