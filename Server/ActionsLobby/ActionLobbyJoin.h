#ifndef LOBBYCOMMANDJOIN_H
#define LOBBYCOMMANDJOIN_H

#include <string>

#include "ActionsLobby.h"
#include "../Game/GameMonitor.h"

class ActionLobbyJoin : public ActionsLobby {
public:
    explicit ActionLobbyJoin(const std::string &arguments);

    std::string execute(GameMonitor &game_monitor, ClientConnection& client) override;

    ~ActionLobbyJoin() = default;
};

#endif
