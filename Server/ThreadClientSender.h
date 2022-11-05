#include <list>
#include <string>
#include "../Common/Thread.h"
#include "../Common/Socket.h"
#include "../Common/Queue.h"
#include "../Common/Command.h"
#include "ClientConnection.h"

class ThreadClientSender : public Thread{
    Queue <Command>& senderQueue;
    Socket& socketSender;
    public:
    ThreadClientSender(Queue <Command>& newSenderQueue,Socket& newSocketSender);

    void run() override;

    ~ThreadClientSender();
};