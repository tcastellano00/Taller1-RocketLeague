#include "BallModel.h"

BallModel::BallModel() : x(370), y(400), angle(0) {}

BallModel::BallModel(float xCoord, float yCoord, float ang) {
    x = xCoord;
    y = yCoord;
    angle = ang;
}

BallModel::~BallModel(){}

float BallModel::getCoordX() {
    return this->x;
}
float BallModel::getCoordY() {
    return this->y;
}

float BallModel::getAngle() {
    return angle;
}