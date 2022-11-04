#include "../Common/Thread.h"
#include "../Common/Queue.h"
#include "../Common/Command.h"

class ThreadCmdReader: public Thread {
private:
    Queue<Command>& queue;
    bool handleEvents();
public:
    void run() override;
    ThreadCmdReader(Queue<Command>& newQueue);
    ~ThreadCmdReader();
};