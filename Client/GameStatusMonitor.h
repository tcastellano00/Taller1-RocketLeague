#ifndef CLIENT_GAMESTATUSMONITOR_H
#define CLIENT_GAMESTATUSMONITOR_H

#include <mutex>
#include <string>
#include "GameStatus.h"

class GameStatusMonitor{
    std::mutex gameMutex;
    GameStatus gamestatus;

    public:
    GameStatusMonitor();

    bool gameIsClosed();
    
    std::string gameStatus();

    void statusUpdate(std::string newState);
    void setClose();

};

#endif
