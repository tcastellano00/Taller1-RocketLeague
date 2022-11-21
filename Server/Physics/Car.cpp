#include "Car.h"


CarPhysics::CarPhysics(b2Body* body, PlayerSide side){
    body->SetUserData(this);
    this->carBody = body;
    this->facingStatus = FACINGFRONT;
    this->side = side;
    this->airStatus = AIR;
    this->isDoingTurbo = false;
}

CarPhysics::CarPhysics() {}

b2Body* CarPhysics::getCarBody() {
    return this->carBody;
}

void CarPhysics::landed() {
    this->airStatus = GROUND;
}

void CarPhysics::jumpedFromTheFloor() {
    this->airStatus = AIR;
}

AirStatus CarPhysics::getAirStatus() {
    return this->airStatus;
}

void CarPhysics::setAirStatus(AirStatus status) {
    this->airStatus = status;
}

FacingStatus CarPhysics::getFacingStatus() {
    return this->facingStatus;
}

void CarPhysics::setBallInFrontSensor(bool cond) {
    ballInFrontSensor = cond;
}
void CarPhysics::setBallInBackSensor(bool cond) {
    ballInBackSensor = cond;
}
void CarPhysics::setBallInBottomSensor(bool cond) {
    ballInBottomSensor = cond;
}

bool CarPhysics::getBallInFrontSensor() {
    return ballInFrontSensor;
}
bool CarPhysics::getBallInBackSensor() {
    return ballInBackSensor;
}
bool CarPhysics::getBallInBottomSensor() {
    return ballInBottomSensor;
}

PlayerSide CarPhysics::getSide() {
    return side;
}

void CarPhysics::setFacingStatus(FacingStatus status) {
    this->facingStatus = status;
}

void CarPhysics::setDoingTurbo(bool doing) {
    this->isDoingTurbo = doing;
}

bool CarPhysics::getDoingTurbo() {
    return this->isDoingTurbo;
}