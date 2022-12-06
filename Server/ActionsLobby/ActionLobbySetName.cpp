#include <string>
#include <sstream>
#include <iostream>

#include "ActionsLobby.h"
#include "ActionLobbySetName.h"

ActionLobbySetName::ActionLobbySetName(
    const std::string &arguments) {
        this->arguments = arguments;
    }

std::string ActionLobbySetName::execute(
    GameMonitor &game_monitor, ClientConnection& client) {
        std::stringstream args(arguments);

        std::string clientName;

        args >> clientName;

        
        client.setName(clientName);

        return "";
    }
