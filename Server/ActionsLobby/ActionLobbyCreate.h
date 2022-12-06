#ifndef LOBBYCOMMANDCREATE_H
#define LOBBYCOMMANDCREATE_H

#include <string>

#include "ActionsLobby.h"
#include "../Game/GameMonitor.h"

/*
Esta clase representa la accion de que un cliente esta
queriendo crear una nueva partida en el lobby. 
*/
class ActionLobbyCreate : public ActionsLobby {   
public:
    explicit ActionLobbyCreate(const std::string &arguments);

    std::string execute(GameMonitor &game_monitor, ClientConnection& client) override;

    ~ActionLobbyCreate() = default;
};

#endif
