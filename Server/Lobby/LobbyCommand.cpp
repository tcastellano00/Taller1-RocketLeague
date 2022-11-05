#include "LobbyCommand.h"
#include "LobbyCommandCreate.h"
#include "LobbyCommandJoin.h"
#include "LobbyCommandList.h"

std::unique_ptr<LobbyCommand> LobbyCommand::get_command_ptr(
    const std::string &name,
    const std::string &arguments) {
    if (name == "UNIR")
        return std::unique_ptr<LobbyCommandJoin>(
            new LobbyCommandJoin(arguments));
    else if (name == "LISTAR")
        return std::unique_ptr<LobbyCommandList>(
            new LobbyCommandList(arguments));
    else
        return std::unique_ptr<LobbyCommandCreate>(
            new LobbyCommandCreate(arguments));
}
