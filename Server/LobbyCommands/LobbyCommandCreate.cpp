#include <string>
#include <sstream>

#include "LobbyCommand.h"
#include "LobbyCommandCreate.h"

CommandServerCreate::CommandServerCreate(
    const std::string &arguments) {
        this->arguments = arguments;
    }

std::string CommandServerCreate::execute(
    GameMonitor &game_monitor) {
        std::stringstream args(arguments);

        int max_players;
        std::string game_name;

        args >> max_players;
        args >> game_name;

        //bool result = game_monitor.create_game(game_name, max_players);

        //return (result ? "OK" : "ERROR");
    }
