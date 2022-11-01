#include "../Common/common_thread.h"
#include "../Common/common_blockingqueue.h"
#include "../Common/common_command.h"
#include "../Common/common_socket.h"
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
