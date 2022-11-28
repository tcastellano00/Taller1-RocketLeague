#include "GameStatus.h"
#include <sstream>

GameStatus::GameStatus() {
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
    this->closed = false;
    this->replay = false;
}

BallModel GameStatus::getBallModel() {
    return this->ball;
}

void GameStatus::setBallModel(BallModel ballModel) {
    this->ball = ballModel;
}

ScoreModel GameStatus::getScoreModel(){
    return this->score;
}

void GameStatus::setScoreModel(ScoreModel scoreModel) {
    this->score = scoreModel;
}

std::list<PlayerModel> GameStatus::getPlayersModels() {
    return this->players;
}

void GameStatus::setPlayersModels(std::list<PlayerModel> lstPlayersModels) {
    this->players = lstPlayersModels;
}

std::string GameStatus::status(){
    return actualStatus;
}

void GameStatus::setClose() {
    closed = true;
}

bool GameStatus::isClosed(){
    return closed;
}

bool GameStatus::isInReplay() {
    return this->replay;
}

void GameStatus::setReplay(bool rep) {
    this->replay = rep;
}