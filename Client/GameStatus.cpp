
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

void GameStatus::movePlayerRight() {
    this->player.moveRight();
}

void GameStatus::movePlayerLeft(){
    this->player.moveLeft();
}

void GameStatus::setClose() {
    closed = true;
}

PlayerModel GameStatus::getPlayer() {
    return player;
}