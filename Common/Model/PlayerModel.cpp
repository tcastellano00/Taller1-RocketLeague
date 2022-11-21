#include "PlayerModel.h"

PlayerModel::PlayerModel() {}

PlayerModel::PlayerModel(float xCoord, float yCoord, float ang, bool turbo) {
    x = xCoord;
    y = yCoord;
    angle = ang;
    turbo = turbo;
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