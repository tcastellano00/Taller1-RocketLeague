
#include "GameStatusMonitor.h"
#include <iostream>
#include <utility>

GameStatusMonitor::GameStatusMonitor() : clientClosedGame(false),isPlayingMusic(true) { }

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

void GameStatusMonitor::toggleMusic(){
    isPlayingMusic = !isPlayingMusic;
}

void GameStatusMonitor::toggleNext(){
    callNext = !callNext;
}

bool GameStatusMonitor::getIsPlayingMusic(){
    return isPlayingMusic;
}

bool GameStatusMonitor::getCallNext(){
    return callNext;
}