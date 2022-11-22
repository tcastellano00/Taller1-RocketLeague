#include "PlayerModel.h"

PlayerModel::PlayerModel() {}

PlayerModel::PlayerModel(float xCoord, float yCoord, float ang, bool turbo, std::string face) {
    x = xCoord;
    y = yCoord;
    angle = ang;
    turbo = turbo;
    facing = face;
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