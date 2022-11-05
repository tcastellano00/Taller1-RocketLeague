#include <string>
#include <sstream>

#include "LobbyCommand.h"
#include "LobbyCommandCreate.h"

CommandServerCreate::CommandServerCreate(
    const std::string &arguments) {
        this->arguments = arguments;
    }

std::string CommandServerCreate::execute(
    GameMonitor &game_monitor, ClientConnection& client) {
        std::stringstream args(arguments);

        int max_players;
        std::string game_name;

        args >> max_players;
        args >> game_name;

        bool result = game_monitor.createGame(game_name, max_players, client);

        return (result ? "OK" : "ERROR");
    }
