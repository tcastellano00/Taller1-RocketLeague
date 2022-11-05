#include "../Common/Thread.h"
#include "../Common/Socket.h"
#include "../Common/Queue.h"
#include "../Common/Command.h"
#include "../Common/Protocol.h"

class ThreadClientReceiver : public Thread{

    Socket& sktConecction;
    Queue <Command>& recibingQueue;
    Protocol receiverProtocol;

    
    public:
    void run() override;

    ThreadClientReceiver(Socket& newSktConecction,Queue<Command>& newRecibingQueue);
    
    ~ThreadClientReceiver();
};
