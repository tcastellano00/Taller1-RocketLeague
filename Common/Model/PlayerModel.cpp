#include "PlayerModel.h"

PlayerModel::PlayerModel() : x(100), y(400) {}

PlayerModel::PlayerModel(int xCoord, int yCoord, int ang, bool turbo) {
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

int PlayerModel::getCoordX() {
    return this->x;
}
int PlayerModel::getCoordY() {
    return this->y;
}

int PlayerModel::getAngle() {
    return angle;
}