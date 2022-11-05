#include <string>

#include "LobbyCommand.h"
#include "LobbyCommandList.h"

LobbyCommandList::LobbyCommandList(
    const std::string &arguments) {
        this->arguments = arguments;
    }

std::string LobbyCommandList::execute(
    GameMonitor &game_monitor, ClientConnection& client) {
        std::string result = "OK";

        result += game_monitor.listGames();

        return result;
    }
