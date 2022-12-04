#include <string>

#include "ActionLobbyList.h"

ActionLobbyList::ActionLobbyList(
    const std::string &arguments) {
        this->arguments = arguments;
    }

std::string ActionLobbyList::execute(
    GameMonitor &game_monitor, ClientConnection& client) {
        std::string result = "OK";

        result += game_monitor.listGames();

        return result;
    }
