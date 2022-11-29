
#include "GameStatusMonitor.h"
#include <iostream>
#include <utility>

GameStatusMonitor::GameStatusMonitor() {
    // Member initialization list
    this->clientClosedGame = false;
}

bool GameStatusMonitor::gameIsClosed(){
    std::lock_guard<std::mutex> lock(gameMutex);
    return this->clientClosedGame;
}

GameStatus GameStatusMonitor::getGameStatus(){
    std::lock_guard<std::mutex> lock(gameMutex);
    return gamestatus;
}

void GameStatusMonitor::statusUpdate(GameStatus newGameStatus){
    std::lock_guard<std::mutex> lock(gameMutex);
    gamestatus = newGameStatus;
}

void GameStatusMonitor::setClose() {
    std::lock_guard<std::mutex> lock(gameMutex);
    gamestatus.setClose();

    this->clientClosedGame = true;
}