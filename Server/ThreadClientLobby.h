#include "../Common/Thread.h"
#include "../Common/Socket.h"
#include "ClientConnection.h"
#include "GameMonitor.h"

class ThreadClientLobby: public Thread {
private:
    ClientConnection client;
    GameMonitor& gameMonitor;

protected:
    void run() override;

public:
    ThreadClientLobby(ClientConnection& client, GameMonitor& gameMonitor);
    void stop();
    ~ThreadClientLobby();
};
