#ifndef LOBBYCOMMANDCREATE_H
#define LOBBYCOMMANDCREATE_H

#include <string>

#include "ActionsLobby.h"
#include "../Game/GameMonitor.h"

class ActionLobbyCreate : public ActionsLobby {   
public:
    explicit ActionLobbyCreate(const std::string &arguments);

    std::string execute(GameMonitor &game_monitor, ClientConnection& client) override;

    ~ActionLobbyCreate() = default;
};

#endif
