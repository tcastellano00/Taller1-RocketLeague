#include "common_thread.h"

class ThreadCmdReader: public Thread {
public:
    void run() override;
    ~ThreadCmdReader();
};