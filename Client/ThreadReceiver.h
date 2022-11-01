#include "../Common/Thread.h"
#include "GameStatusMonitor.h"
#include "../Common/Socket.h"


class ThreadReceiver: public Thread {
    GameStatusMonitor& gameStatusMonitor;
    Socket& connection;

public:
    ThreadReceiver(Socket& cnct, GameStatusMonitor& gameStatusMonitor);

    void run() override;
    ~ThreadReceiver();
};
