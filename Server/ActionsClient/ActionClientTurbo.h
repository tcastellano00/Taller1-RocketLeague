#ifndef ACTIONCLIENTTURBO_H
#define ACTIONCLIENTTURBO_H

#include <string>

#include "ActionsClient.h"
#include "../GameMonitor.h"



class ActionClientTurbo : public ActionsClient {   
public:
    explicit ActionClientTurbo();

    //std::string execute(GameMonitor &game_monitor, ClientConnection& client) override;

    ~ActionClientTurbo() = default;
};

#endif