#include "../Common/common_thread.h"
#include "../Common/common_blockingqueue.h"
#include "../Common/common_command.h"

class ThreadCmdReader: public Thread {
private:
    BlockingQueue<Command>& queue;
public:
    void run() override;
    ThreadCmdReader(BlockingQueue<Command>& newQueue);
    ~ThreadCmdReader();
};