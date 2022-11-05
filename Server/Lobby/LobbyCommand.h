#ifndef LOBBYCOMMAND_H
#define LOBBYCOMMAND_H

#include <string>
#include <memory>
#include <bits/unique_ptr.h>

#include "../GameMonitor.h"
#include "../ClientConnection.h"

class LobbyCommand {
protected:
    std::string arguments;
   
public:
    static std::unique_ptr<LobbyCommand> get_command_ptr(
        const std::string &name,
        const std::string &arguments);

    virtual std::string execute(GameMonitor &game_monitor, ClientConnection& client) = 0;

    ~LobbyCommand() = default;
};

#endif
