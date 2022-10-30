#include "common_thread.h"
#include "common_blockingqueue.h"
#include "common_command.h"

class ThreadCmdReader: public Thread {
private:
    BlockingQueue<Command>& queue;
public:
    void run() override;
    ThreadCmdReader(BlockingQueue<Command>& newQueue);
    ~ThreadCmdReader();
};