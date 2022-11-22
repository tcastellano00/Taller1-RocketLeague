#include "PlayerModel.h"

PlayerModel::PlayerModel() {}

PlayerModel::PlayerModel(float xCoord, float yCoord, float ang, bool nwturbo, std::string face) {
    this->x = xCoord;
    this->y = yCoord;
    this->angle = ang;
    this->turbo = nwturbo;
    this->facing = face;
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