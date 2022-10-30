#include "common_thread.h"
#include "common_blockingqueue.h"
#include "common_command.h"
#include "common_socket.h"
#include "client_gamestatusmonitor.h"

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
