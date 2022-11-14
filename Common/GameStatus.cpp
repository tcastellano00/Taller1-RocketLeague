#include "GameStatus.h"
#include <sstream>

GameStatus::GameStatus(){
    closed = false;
}

GameStatus::GameStatus(
    BallModel& ball,
    ScoreModel& score,
    std::list<PlayerModel>& players
) {
    this->ball = std::move(ball);
    this->score = std::move(score);
    this->players = std::move(players);
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

    float xCoordBall;
    float yCoordBall;
    float angleBoard;
    ss >> xCoordBall;
    ss >> yCoordBall;
    ss >> angleBoard;
    BallModel bm(xCoordBall, yCoordBall, angleBoard);
    this->ball = bm;


    for (int i = 0; i < numPlayers; ++i) {
        float xCoordPlayer;
        float yCoordPlayer;
        float anglePlayer;
        bool turbo;
        ss >> xCoordPlayer;
        ss >> yCoordPlayer;
        ss >> anglePlayer;
        ss >> turbo;
        this->players.emplace_back(xCoordPlayer, yCoordPlayer, anglePlayer, turbo);
    }
    //return false;
}

BallModel GameStatus::getBallModel() {
    return this->ball;
}
void GameStatus::setBallModel(BallModel ballModel) { }

ScoreModel GameStatus::getScoreModel(){
    return this->score;
}
void GameStatus::setScoreModel(ScoreModel scoreModel) { }

std::list<PlayerModel> GameStatus::getPlayersModels() {
    return this->players;
}
void GameStatus::setPlayersModels(std::list<PlayerModel> lstPlayersModels) { }

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

bool GameStatus::isClosed(){
    return closed;
}

void GameStatus::setPlayerModel(PlayerModel pm){
    this->player = pm;
}