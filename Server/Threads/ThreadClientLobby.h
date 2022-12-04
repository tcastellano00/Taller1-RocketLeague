#ifndef SERVER_THREAD_CLIENT_LOBBY_H
#define SERVER_THREAD_CLIENT_LOBBY_H

#include "../../Common/Thread.h"
#include "../../Common/Socket.h"
#include "../Game/GameMonitor.h"
#include "../ClientConnection.h"

class ThreadClientLobby: public Thread {
private:
    ClientConnection client;
    GameMonitor& gameMonitor;
    Protocol protocol;
    bool inLobby;

protected:
    void run() override;

public:
    ThreadClientLobby(ClientConnection& client, GameMonitor& gameMonitor);
    void stop();
    ~ThreadClientLobby();
};

#endif