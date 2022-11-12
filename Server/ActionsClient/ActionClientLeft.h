#ifndef ACTIONCLIENTLEFT_H
#define ACTIONCLIENTLEFT_H

#include <string>

#include "ActionsClient.h"
#include "../GameMonitor.h"



class ActionClientLeft : public ActionsClient {   
public:
    explicit ActionClientLeft();

    //std::string execute(GameMonitor &game_monitor, ClientConnection& client) override;

    ~ActionClientLeft() = default;
};

#endif