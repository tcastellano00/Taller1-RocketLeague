#ifndef ACTIONCLIENTRIGHT_H
#define ACTIONCLIENTRIGHT_H
#include <string>

#include "ActionsClient.h"
#include "../GameMonitor.h"



class ActionClientRight : public ActionsClient {   
public:
    explicit ActionClientRight();

    //std::string execute(GameMonitor &game_monitor, ClientConnection& client) override;

    ~ActionClientRight() = default;
};

#endif
