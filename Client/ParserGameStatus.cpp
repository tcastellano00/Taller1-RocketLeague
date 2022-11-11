#include "ParserGameStatus.h"
#include <utility>
#include <sstream>

ParserGameStatus::ParserGameStatus(std::string reply) {
    std::stringstream sstring(reply);
    //int numPl;
    /*numPl << reply;
    this->numberOfPlayers = numPl;

    int mins;
    mins << reply;
    int sec;
    sec << reply;
    int mili;
    mili << reply;
    int goalsFirst;
    goalsFirst << reply;
    int goalsSecond;
    goalsSecond << reply;
    //Score sc(mins, sec, mili, goalsFirst, goalsSecond);
    //this->score = sc;*/

}

int ParserGameStatus::getNumberOfPlayers() {
    return numberOfPlayers;
}

BallModel ParserGameStatus::getBall() {
    return std::move(ball);
}

ScoreModel ParserGameStatus::getScore() {
    return std::move(score);
}

std::list<PlayerModel> ParserGameStatus::getPlayers() {
    return std::move(players);
}

