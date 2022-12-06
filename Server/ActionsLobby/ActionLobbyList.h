#ifndef LOBBYCOMMANDLIST_H
#define LOBBYCOMMANDLIST_H

#include <string>

#include "ActionsLobby.h"
#include "../Game/GameMonitor.h"

/*
Esta clase representa la accion de que un cliente esta
queriendo ver todas las partidas creadas en el servidor. 
*/
class ActionLobbyList : public ActionsLobby {
public:
    explicit ActionLobbyList(const std::string &arguments);

    std::string execute(GameMonitor &game_monitor, ClientConnection& client) override;

    ~ActionLobbyList() = default;
};

#endif
