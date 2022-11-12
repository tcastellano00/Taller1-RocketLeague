#include "BallModel.h"

BallModel::BallModel() : x(370), y(400), angle(0) {}

BallModel::BallModel(int xCoord, int yCoord, int ang) {
    x = xCoord;
    y = yCoord;
    angle = ang;
}

BallModel::~BallModel(){}

int BallModel::getCoordX() {
    return this->x;
}
int BallModel::getCoordY() {
    return this->y;
}

int BallModel::getAngle() {
    return angle;
}