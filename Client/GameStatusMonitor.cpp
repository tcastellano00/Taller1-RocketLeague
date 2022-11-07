
#include "GameStatusMonitor.h"
#include <iostream>

GameStatusMonitor::GameStatusMonitor(){
}

bool GameStatusMonitor::gameIsClosed(){
    std::lock_guard<std::mutex> lock(gameMutex);
    return gamestatus.isClosed();
}

std::string GameStatusMonitor::gameStatus(){
    std::lock_guard<std::mutex> lock(gameMutex);
    return gamestatus.status();
}

void GameStatusMonitor::statusUpdate(std::string newState){
    std::lock_guard<std::mutex> lock(gameMutex);
    gamestatus.statusUpdate(newState);
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
    gamestatus.setClose();
}

int GameStatusMonitor::getPlayerCoordX() {
    return gamestatus.getPlayerCoordX();
}
int GameStatusMonitor::getPlayerCoordY() {
    return gamestatus.getPlayerCoordY();
}