#include "../Common/common_thread.h"
#include "client_gamestatusmonitor.h"


class ThreadReceiver: public Thread {
    GameStatusMonitor& gameStatusMonitor;

public:
    ThreadReceiver(GameStatusMonitor& gameStatusMonitor);

    void run() override;
    ~ThreadReceiver();
};
