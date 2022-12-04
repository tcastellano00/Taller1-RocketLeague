#include <string>
#include <sstream>
#include <iostream>

#include "ActionsLobby.h"
#include "ActionLobbyJoin.h"

ActionLobbyJoin::ActionLobbyJoin(
    const std::string &arguments) {
        this->arguments = arguments;
    }

std::string ActionLobbyJoin::execute(
    GameMonitor &game_monitor, ClientConnection& client) {
        std::stringstream args(arguments);

        std::string game_name;

        args >> game_name;

        bool result = game_monitor.addPlayerIfNotFull(game_name, client);

        return (result ? "OK" : "ERROR");
    }
