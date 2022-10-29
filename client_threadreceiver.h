#include "client_thread.h"

class ThreadReceiver: public Thread {
public:
    void run() override;
    ~ThreadReceiver();
};
