#include <string>
#include <sstream>
#include <iostream>

#include "LobbyCommand.h"
#include "LobbyCommandJoin.h"

LobbyCommandJoin::LobbyCommandJoin(
    const std::string &arguments) {
        this->arguments = arguments;
    }

std::string LobbyCommandJoin::execute(
    GameMonitor &game_monitor, ClientConnection& client) {
        std::stringstream args(arguments);

        std::string game_name;

        args >> game_name;

        bool result = game_monitor.addPlayerIfNotFull(game_name, client);

        return (result ? "OK" : "ERROR");
    }
