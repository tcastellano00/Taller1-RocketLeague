#ifndef SERVER_THREAD_CLIENT_LOBBY_H
#define SERVER_THREAD_CLIENT_LOBBY_H

#include "../../Common/Thread.h"
#include "../../Common/Socket.h"
#include "../Game/GameMonitor.h"
#include "../ClientConnection.h"

/*
Hilo que se ejecuta mientras el cliente se encuentra en el Lobby. Se encarga de
comunicarse con el cliente mediante el Protocol, crear nuevas partidas o unir 
al cliente a una partida ya existente.
*/
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