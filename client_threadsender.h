#include "common_thread.h"

class ThreadSender: public Thread {
public:
    void run() override;
    ~ThreadSender();
};
