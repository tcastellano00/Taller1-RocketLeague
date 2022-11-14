#include "PlayerModel.h"

PlayerModel::PlayerModel() : x(100), y(400) {}

PlayerModel::PlayerModel(float xCoord, float yCoord, float ang, bool turbo) {
    x = xCoord;
    y = yCoord;
    angle = ang;
    isDoingTurbo = turbo;
}

void PlayerModel::moveRight() {
    x += 3;
}

void PlayerModel::moveLeft() {
    x -= 3;
}

PlayerModel::~PlayerModel(){}

float PlayerModel::getCoordX() {
    return this->x;
}
float PlayerModel::getCoordY() {
    return this->y;
}

float PlayerModel::getAngle() {
    return angle;
}