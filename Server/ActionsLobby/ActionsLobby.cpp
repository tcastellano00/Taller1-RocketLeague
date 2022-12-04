#include "ActionsLobby.h"
#include "ActionLobbyCreate.h"
#include "ActionLobbyJoin.h"
#include "ActionLobbyList.h"

#include "../../Common/Constants/ActionsLobby.h"

std::unique_ptr<ActionsLobby> ActionsLobby::get_command_ptr(
    const std::string &name, const std::string &arguments) {

    if (name == JOIN_GAME)
        return std::unique_ptr<ActionsLobby>(new ActionLobbyJoin(arguments));
    else if (name == LIST_GAMES)
        return std::unique_ptr<ActionsLobby>(new ActionLobbyList(arguments));
    else if (name == CREATE_GAME)
        return std::unique_ptr<ActionsLobby>(new ActionLobbyCreate(arguments));

    return NULL;
}
