#include "PlayerModel.h"

PlayerModel::PlayerModel() : x(100), y(400) {}

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