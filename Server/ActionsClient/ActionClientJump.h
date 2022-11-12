#ifndef ACTIONCLIENTJUMP_H
#define ACTIONCLIENTJUMP_H

#include <string>

#include "ActionsClient.h"
#include "../GameMonitor.h"



class ActionClientJump : public ActionsClient {   
public:
    explicit ActionClientJump();

    //std::string execute(GameMonitor &game_monitor, ClientConnection& client) override;

    ~ActionClientJump() = default;
};

#endif