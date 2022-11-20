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
    this->player.x = pm.x;
    this->player.y = pm.y;
    this->player.angle = pm.angle;
    this->player.isDoingTurbo = pm.isDoingTurbo;
}