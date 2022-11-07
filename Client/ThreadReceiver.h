
#include "GameStatusMonitor.h"
#include "../Common/Socket.h"
#include "../Common/Thread.h"
#include "../Common/Protocol.h"


class ThreadReceiver: public Thread {
    GameStatusMonitor& gameStatusMonitor;
    Protocol protocol;

public:
    ThreadReceiver(Socket& cnct, GameStatusMonitor& gameStatusMonitor);

    void run() override;
    ~ThreadReceiver();
};
