#ifndef CLIENT_GAMESTATUSMONITOR_H
#define CLIENT_GAMESTATUSMONITOR_H

#include <mutex>
#include <string>
#include "../Common/GameStatus.h"
#include "../Common/Model/PlayerModel.h"

class GameStatusMonitor{
    std::mutex gameMutex;
    GameStatus gamestatus;

    public:
    GameStatusMonitor();

    bool gameIsClosed();
    
    GameStatus getGameStatus();

    void statusUpdate(GameStatus newGameStatus);
    
    void setClose();
};

#endif
