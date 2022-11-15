
#include "GameStatusMonitor.h"
#include <iostream>
#include <utility>

GameStatusMonitor::GameStatusMonitor(){
}

bool GameStatusMonitor::gameIsClosed(){
    std::lock_guard<std::mutex> lock(gameMutex);
    return gamestatus.isClosed();
}

GameStatus GameStatusMonitor::getGameStatus(){
    std::lock_guard<std::mutex> lock(gameMutex);
    return gamestatus;
}

void GameStatusMonitor::statusUpdate(GameStatus newGameStatus){
    std::lock_guard<std::mutex> lock(gameMutex);
    gamestatus = newGameStatus;
}

void GameStatusMonitor::movePlayerRight() {
    std::lock_guard<std::mutex> lock(gameMutex);
    gamestatus.movePlayerRight();
}

void GameStatusMonitor::movePlayerLeft(){
    std::lock_guard<std::mutex> lock(gameMutex);
    gamestatus.movePlayerLeft();
}

void GameStatusMonitor::setClose() {
    std::lock_guard<std::mutex> lock(gameMutex);
    gamestatus.setClose();
}

PlayerModel GameStatusMonitor::getPlayer() {
    std::lock_guard<std::mutex> lock(gameMutex);
    return gamestatus.getPlayer();
}