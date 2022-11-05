#ifndef LOBBYCOMMANDJOIN_H
#define LOBBYCOMMANDJOIN_H

#include <string>

#include "LobbyCommand.h"
#include "../GameMonitor.h"

class LobbyCommandJoin : public LobbyCommand {
public:
    explicit LobbyCommandJoin(const std::string &arguments);

    std::string execute(GameMonitor &game_monitor, ClientConnection& client) override;

    ~LobbyCommandJoin() = default;
};

#endif
