#include "PlayerModel.h"

PlayerModel::PlayerModel() {}

PlayerModel::PlayerModel(int cltId,float xCoord, float yCoord, float ang, bool nwturbo, std::string face, int turboRem,
    std::string newName,int newGoals,int newAssists, int newSaves) {
    this->clientId = cltId;
    this->x = xCoord;
    this->y = yCoord;
    this->angle = ang;
    this->turbo = nwturbo;
    this->facing = face;
    this->turboRemaining = turboRem;
    this->name = newName;
    this->goals = newGoals;
    this->assists = newAssists;
    this->saves = newSaves;

}

PlayerModel::~PlayerModel(){}

float PlayerModel::getCoordX() {
    return this->x;
}

float PlayerModel::getCoordY() {
    return this->y;
}

float PlayerModel::getAngle() {
    return this->angle;
}

bool PlayerModel::isDoingTurbo() {
    return this->turbo;
}

std::string PlayerModel::getFacing(){
    return this->facing;
}

int PlayerModel::getTurboRemaining() {
    return this->turboRemaining;
}

int PlayerModel::getClientId(){
    return this->clientId;
}


std::string PlayerModel::getName(){
    return this->name;
}

int PlayerModel::getGoals(){
    return this->goals;
}

int PlayerModel::getAssists(){
    return this->assists;
}

int PlayerModel::getSaves() {
    return this->saves;
}
