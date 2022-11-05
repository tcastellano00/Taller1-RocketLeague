#include "../Common/Thread.h"
#include "../Common/Socket.h"
#include "../Common/Queue.h"
#include "../Common/Command.h"
#include "ClientConnection.h"
#include "../Common/Thread.h"
#include <list>


class Gameloop : public Thread{

    // Queue <Command> recibingQueue;
    // Queue <Command> senderQueue;
    std::list <ThreadClientReceiver> clientThreadList;
    std::list <ClientConnection> connectionList;

    public:
    Gameloop(std::list <ClientConnection> connectionList);

    void run() override;

};