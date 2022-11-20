#ifndef SERVER_THREAD_CLIENT_LOBBY_H
#define SERVER_THREAD_CLIENT_LOBBY_H

#include "../Common/Thread.h"
#include "../Common/Socket.h"
#include "ClientConnection.h"
#include "GameMonitor.h"

class ThreadClientLobby: public Thread {
private:
    ClientConnection client;
    GameMonitor& gameMonitor;
    Protocol protocol;

protected:
    void run() override;

public:
    ThreadClientLobby(ClientConnection& client, GameMonitor& gameMonitor);
    void stop();
    ~ThreadClientLobby();
};

#endif