#include "BallModel.h"

BallModel::BallModel() : x(370), y(400), angle(0), colour("") {}

BallModel::BallModel(float xCoord, float yCoord, float ang, std::string col) {
    x = xCoord;
    y = yCoord;
    angle = ang;
    colour = col;
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

std::string BallModel::getColour() {
    return colour;
}