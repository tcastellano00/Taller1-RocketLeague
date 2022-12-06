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
        std::string game_name_word;

        args >> game_name;

        while(args >> game_name_word)
            game_name += " " + game_name_word;

        bool result = game_monitor.addPlayerIfNotFull(game_name, client);

        return (result ? "OK" : "ERROR");
    }
