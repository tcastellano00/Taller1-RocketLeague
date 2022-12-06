#ifndef LOBBYCOMMANDSETNAME_H
#define LOBBYCOMMANDSETNAME_H

#include <string>

#include "ActionsLobby.h"
#include "../Game/GameMonitor.h"

class ActionLobbySetName : public ActionsLobby {
public:
    explicit ActionLobbySetName(const std::string &arguments);

    std::string execute(GameMonitor &game_monitor, ClientConnection& client) override;

    ~ActionLobbySetName() = default;
};

#endif
