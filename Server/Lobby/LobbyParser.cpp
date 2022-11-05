#include "LobbyParser.h"
#include <sstream>

std::unique_ptr<LobbyCommand> LobbyParser::getCommand(std::string line) {
    std::stringstream command_stream(line);

    std::string command_name;
    std::string command_args;
    
    command_stream >> command_name;
    getline(command_stream, command_args);
    
    return LobbyCommand::get_command_ptr(
        command_name, 
        command_args);
}
