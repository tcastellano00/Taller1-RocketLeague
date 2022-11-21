#ifndef LOBBYCOMMANDCREATE_H
#define LOBBYCOMMANDCREATE_H

#include <string>

#include "LobbyCommand.h"
#include "../GameMonitor.h"

class LobbyCommandCreate : public LobbyCommand {   
public:
    explicit LobbyCommandCreate(const std::string &arguments);

    std::string execute(GameMonitor &game_monitor, ClientConnection& client) override;

    ~LobbyCommandCreate() = default;
};

#endif
