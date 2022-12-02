#include "LobbyCommand.h"
#include "LobbyCommandCreate.h"
#include "LobbyCommandJoin.h"
#include "LobbyCommandList.h"

#include "../../Common/Constants/ActionsLobby.h"

std::unique_ptr<LobbyCommand> LobbyCommand::get_command_ptr(
    const std::string &name, const std::string &arguments) {

    if (name == JOIN_GAME)
        return std::unique_ptr<LobbyCommandJoin>(new LobbyCommandJoin(arguments));
    else if (name == LIST_GAMES)
        return std::unique_ptr<LobbyCommandList>(new LobbyCommandList(arguments));
    else if (name == CREATE_GAME)
        return std::unique_ptr<LobbyCommandCreate>(new LobbyCommandCreate(arguments));

    return NULL;
}
