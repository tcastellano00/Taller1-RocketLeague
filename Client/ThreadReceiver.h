#include "../Common/common_thread.h"
#include "GameStatusMonitor.h"


class ThreadReceiver: public Thread {
    GameStatusMonitor& gameStatusMonitor;

public:
    ThreadReceiver(GameStatusMonitor& gameStatusMonitor);

    void run() override;
    ~ThreadReceiver();
};
