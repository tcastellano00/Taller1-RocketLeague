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
    this->inExplosion = false;
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

bool GameStatus::isInExplosion() {
    return this->inExplosion;
}

void GameStatus::setInExplosion(bool expl) {
    this->inExplosion = expl;
}

void GameStatus::setCarJump(bool jump){
    this->carJump = jump;
}

bool GameStatus::isJumping(){
    return this->carJump;
}

bool GameStatus::isACarDoingTurbo() {
    bool doingTurbo = false;
    for (auto player = players.begin(); player != players.end(); ++player) {
        doingTurbo = doingTurbo || player->isDoingTurbo();
    }
    return doingTurbo;
}