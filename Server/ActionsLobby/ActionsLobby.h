#ifndef LOBBYCOMMAND_H
#define LOBBYCOMMAND_H

#include <string>
#include <memory>
#include <bits/unique_ptr.h>

#include "../Game/GameMonitor.h"
#include "../ClientConnection.h"

/*
Esta clase abstracta se heredada cuando se quiere representar 
alguna intencion del cliente durante su estadia en el lobby.
*/
class ActionsLobby {
protected:
    std::string arguments;
   
public:
    static std::unique_ptr<ActionsLobby> get_command_ptr(
        const std::string &name,
        const std::string &arguments);

    virtual std::string execute(GameMonitor &game_monitor, ClientConnection& client) = 0;

    ~ActionsLobby() = default;
};

#endif
