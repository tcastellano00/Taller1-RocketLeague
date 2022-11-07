#include "BallModel.h"

BallModel::BallModel() : x(370), y(400) {}

BallModel::~BallModel(){}

int BallModel::getCoordX() {
    return this->x;
}
int BallModel::getCoordY() {
    return this->y;
}