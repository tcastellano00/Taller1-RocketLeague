#include "../Common/Thread.h"
#include "../Common/Queue.h"
#include "../Common/Command.h"
#include "../Common/Socket.h"
#include "GameStatusMonitor.h"

class ThreadSender: public Thread {
private:
    Queue<Command>& queue;
    Socket& connection;
    GameStatusMonitor& gameStatusMonitor;
    
public:
    void run() override;
    ThreadSender(Queue<Command>& newQueue, Socket& cnct, GameStatusMonitor& gameStatusMonitor);
    ~ThreadSender();
};
