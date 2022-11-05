#ifndef LOBBYCOMMANDLIST_H
#define LOBBYCOMMANDLIST_H

#include <string>

#include "LobbyCommand.h"
#include "../GameMonitor.h"

class CommandServerList : public CommandServer {
public:
    explicit CommandServerList(const std::string &arguments);

    std::string execute(GameMonitor &game_monitor) override;

    ~CommandServerList() = default;
};

#endif
