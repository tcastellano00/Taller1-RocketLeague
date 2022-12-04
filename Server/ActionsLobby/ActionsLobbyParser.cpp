#include "ActionsLobbyParser.h"
#include <sstream>

std::unique_ptr<ActionsLobby> ActionsLobbyParser::getCommand(std::string line) {
    std::stringstream command_stream(line);

    std::string command_name;
    std::string command_args;
    
    command_stream >> command_name;
    getline(command_stream, command_args);
    
    return ActionsLobby::get_command_ptr(command_name, command_args);
}
