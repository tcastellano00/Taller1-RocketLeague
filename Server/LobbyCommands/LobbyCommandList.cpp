#include <string>

#include "LobbyCommand.h"
#include "LobbyCommandList.h"

CommandServerList::CommandServerList(
    const std::string &arguments) {
        this->arguments = arguments;
    }

std::string CommandServerList::execute(
    GameMonitor &game_monitor) {
        std::string result = "OK";

       // result += game_monitor.list_games();

       // return result;
    }
