#ifndef LOBBYCOMMANDCREATE_H
#define LOBBYCOMMANDCREATE_H

#include <string>

#include "LobbyCommand.h"
#include "../GameMonitor.h"



class CommandServerCreate : public CommandServer {   
public:
    explicit CommandServerCreate(const std::string &arguments);

    std::string execute(GameMonitor &game_monitor) override;

    ~CommandServerCreate() = default;
};

#endif
