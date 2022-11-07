#include "PlayerModel.h"

PlayerModel::PlayerModel() : x(300), y(300) {}

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