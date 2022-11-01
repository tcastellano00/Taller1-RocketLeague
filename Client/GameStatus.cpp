
#include "GameStatus.h"

GameStatus::GameStatus(){
    closed = false;
}

bool GameStatus::isClosed(){
    return closed;
    //return false;
}

std::string GameStatus::status(){
    return actualStatus;
}

void GameStatus::statusUpdate(std::string newState){
    actualStatus = newState;
}

void GameStatus::setClose() {
    closed = true;
}