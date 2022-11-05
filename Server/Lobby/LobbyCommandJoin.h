#ifndef LOBBYCOMMANDJOIN_H
#define LOBBYCOMMANDJOIN_H

#include <string>

#include "LobbyCommand.h"
#include "../GameMonitor.h"

class CommandServerJoin : public CommandServer {
public:
    explicit CommandServerJoin(const std::string &arguments);

    std::string execute(GameMonitor &game_monitor, ClientConnection& client) override;

    ~CommandServerJoin() = default;
};

#endif
