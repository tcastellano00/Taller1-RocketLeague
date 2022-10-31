#ifndef CLIENT_GAMESTATUS_H
#define CLIENT_GAMESTATUS_H

#include <iostream>
#include <string>

class GameStatus{
    bool closed;
    std::string actualStatus;

    public:
    GameStatus();

    bool isClosed();

    void statusUpdate(std::string newState);

    std::string status();
};
#endif