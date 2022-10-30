#include "common_thread.h"
#include "common_blockingqueue.h"
#include "common_command.h"
#include "common_socket.h"

class ThreadSender: public Thread {
private:
    BlockingQueue<Command>& queue;
    bool playing;
    Socket& connection;
public:
    void run() override;
    ThreadSender(BlockingQueue<Command>& newQueue, Socket& cnct);
    ~ThreadSender();
};
