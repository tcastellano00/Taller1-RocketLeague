#include <string>
#include <sstream>
#include <iostream>

#include "LobbyCommand.h"
#include "LobbyCommandJoin.h"

CommandServerJoin::CommandServerJoin(
    const std::string &arguments) {
        this->arguments = arguments;
    }

std::string CommandServerJoin::execute(
    GameMonitor &game_monitor, ClientConnection& client) {
        std::stringstream args(arguments);

        std::string game_name;

        args >> game_name;

        bool result = game_monitor.addPlayerIfNotFull(game_name, client);

        return (result ? "OK" : "ERROR");
    }
