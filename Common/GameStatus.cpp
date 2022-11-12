#include "GameStatus.h"
#include <sstream>

GameStatus::GameStatus(){
    closed = false;
    
}

void GameStatus::statusUpdate(std::string newState) {
    std::stringstream ss(newState);
    int numPlayers;
    ss >> numPlayers;

    int min;
    int sec;
    int milisec;
    int goalsFirst;
    int goalsSecond;
    ss >> min;
    ss >> sec; 
    ss >> milisec;
    ss >> goalsFirst;
    ss >> goalsSecond;
    ScoreModel sc(min, sec, milisec, goalsFirst, goalsSecond);
    this->score = sc;

    int xCoordBall;
    int yCoordBall;
    int angleBoard;
    ss >> xCoordBall;
    ss >> yCoordBall;
    ss >> angleBoard;
    BallModel bm(xCoordBall, yCoordBall, angleBoard);
    this->ball = bm;

    /*for (int i = 0; i < numPlayers; ++i) {
        int xCoordPlayer;
        int yCoordPlayer;
        int anglePlayer;
        bool
    }*/
}

bool GameStatus::isClosed(){
    return closed;
    //return false;
}

std::string GameStatus::status(){
    return actualStatus;
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