#include "../Common/Thread.h"

class ThreadClienteReceiver : public Thread{

    public:
    void run() override;

    ~ThreadClienteReceiver();
};
