#include "ScoreModel.h"

ScoreModel::ScoreModel(int minutes, int seconds, int milisec, int goalsFirst, int goalsSecond) {
    minutesLeft = minutes;
    secondsLeft = seconds;
    miliSecondsLeft = milisec;
    goalsFirstTeam = goalsFirst;
    goalsSecondTeam = goalsSecond;
}

ScoreModel::ScoreModel() {}

int ScoreModel::getMinutesLeft() {
    return minutesLeft;
}

int ScoreModel::getSecondsLeft(){
    return secondsLeft;
}

int ScoreModel::getMiliSecondsLeft() {
    return miliSecondsLeft;
}

int ScoreModel::getGoalsFirstTeam() {
    return goalsFirstTeam;
}

int ScoreModel::getGoalsSecondTeam() {
    return goalsSecondTeam;
}