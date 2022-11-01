#include "../Common/Thread.h"
#include "../Common/BlockingQueue.h"
#include "../Common/Command.h"

class ThreadCmdReader: public Thread {
private:
    BlockingQueue<Command>& queue;
public:
    void run() override;
    ThreadCmdReader(BlockingQueue<Command>& newQueue);
    ~ThreadCmdReader();
};