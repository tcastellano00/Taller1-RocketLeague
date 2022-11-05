#ifndef LOBBYCOMMANDLIST_H
#define LOBBYCOMMANDLIST_H

#include <string>

#include "LobbyCommand.h"
#include "../GameMonitor.h"

class LobbyCommandList : public LobbyCommand {
public:
    explicit LobbyCommandList(const std::string &arguments);

    std::string execute(GameMonitor &game_monitor, ClientConnection& client) override;

    ~LobbyCommandList() = default;
};

#endif
