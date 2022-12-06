#include <string>
#include <sstream>

#include "ActionsLobby.h"
#include "ActionLobbyCreate.h"

ActionLobbyCreate::ActionLobbyCreate(
    const std::string &arguments) {
        this->arguments = arguments;
    }

std::string ActionLobbyCreate::execute(
    GameMonitor &game_monitor, ClientConnection& client) {
        std::stringstream args(arguments);

        int max_players;
        std::string game_name;
        std::string game_name_word;

        args >> max_players;
        args >> game_name;

        while(args >> game_name_word)
            game_name += " " + game_name_word;

        bool result = game_monitor.createGame(game_name, max_players, client);

        return (result ? "OK" : "ERROR");
    }
