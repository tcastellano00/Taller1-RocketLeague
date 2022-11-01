#include "../Common/Thread.h"
#include "../Common/BlockingQueue.h"
#include "../Common/Command.h"
#include "../Common/Socket.h"
#include "GameStatusMonitor.h"

class ThreadSender: public Thread {
private:
    BlockingQueue<Command>& queue;
    bool playing;
    Socket& connection;
    GameStatusMonitor& gameStatusMonitor;
public:
    void run() override;
    ThreadSender(BlockingQueue<Command>& newQueue, Socket& cnct,GameStatusMonitor& gameStatusMonitor);
    ~ThreadSender();
};
