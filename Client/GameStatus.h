#ifndef CLIENT_GAMESTATUS_H
#define CLIENT_GAMESTATUS_H

#include <iostream>
#include <string>
#include "Model/PlayerModel.h"

class GameStatus{
    bool closed;
    std::string actualStatus;
    //std::list <PlayerModel> players;
    PlayerModel player;

    public:
    GameStatus();

    bool isClosed();

    void statusUpdate(std::string newState);

    std::string status();

    void movePlayerRight();

    void movePlayerLeft();

    void setClose();

    PlayerModel getPlayer();
};
#endif