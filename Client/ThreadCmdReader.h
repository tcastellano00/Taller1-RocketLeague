#include "../Common/Thread.h"
#include "../Common/Queue.h"
#include "../Common/Command.h"
#include "GameStatusMonitor.h"

class ThreadCmdReader: public Thread {
private:
    Queue<Command>& queue;
    GameStatusMonitor& gameStatusMonitor;

    bool handleEvents();
public:
    void run() override;
    ThreadCmdReader(Queue<Command>& newQueue, GameStatusMonitor& gameStatusMonitor);
    ~ThreadCmdReader();
};