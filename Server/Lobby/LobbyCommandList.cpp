#include <string>

#include "LobbyCommand.h"
#include "LobbyCommandList.h"

CommandServerList::CommandServerList(
    const std::string &arguments) {
        this->arguments = arguments;
    }

std::string CommandServerList::execute(
    GameMonitor &game_monitor, ClientConnection& client) {
        std::string result = "OK";

        result += game_monitor.listGames();

        return result;
    }
