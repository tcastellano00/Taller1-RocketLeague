
#include "client_gamestatus.h"

GameStatus::GameStatus(){}

bool GameStatus::isClosed(){
    return closed;
}

std::string GameStatus::status(){
    return actualStatus;
}

void GameStatus::statusUpdate(std::string newState){
    actualStatus = newState;
}