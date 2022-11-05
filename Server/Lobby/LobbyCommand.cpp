#include "LobbyCommand.h"
#include "LobbyCommandCreate.h"
#include "LobbyCommandJoin.h"
#include "LobbyCommandList.h"

std::unique_ptr<CommandServer> CommandServer::get_command_ptr(
    const std::string &name,
    const std::string &arguments) {
    if (name == "UNIR")
        return std::unique_ptr<CommandServerJoin>(
            new CommandServerJoin(arguments));
    else if (name == "LISTAR")
        return std::unique_ptr<CommandServerList>(
            new CommandServerList(arguments));
    else
        return std::unique_ptr<CommandServerCreate>(
            new CommandServerCreate(arguments));
}
