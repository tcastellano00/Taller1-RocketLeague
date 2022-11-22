#include "Car.h"
#include <cmath>
#define FLIPIMPULSE 3000
#define PI  3.14159265358979323846
#define FLIPANGULARVEL PI*2


CarPhysics::CarPhysics(b2Body* body, PlayerSide side){
    body->SetUserData(this);
    this->carBody = body;
    this->facingStatus = FACINGFRONT;
    this->side = side;
    this->airStatus = AIR;
    this->isDoingTurbo = false;
    this->acceleratingStatus = NOTACCELERATING;
    this->sensorStatus = NOTSENSOR;
    this->isFliping = false;
    this->flipStartAngle = 0;
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

void CarPhysics::setSensorStatus(SensorStatus status) {
    this->sensorStatus = status;
}

SensorStatus CarPhysics::getSensorStatus() {
    return this->sensorStatus;
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

void CarPhysics::setAcceleratingStatus(AcceleratingStatus status) {
    this->acceleratingStatus = status;
}

AcceleratingStatus CarPhysics::getAcceleratingStatus() {
    return this->acceleratingStatus;
}

void CarPhysics::flipJump() {
    if (this->acceleratingStatus == ACCELERATINGRIGHT) {
        this->carBody->ApplyLinearImpulse(b2Vec2(FLIPIMPULSE, 0), this->carBody->GetWorldCenter(), true);
        this->carBody->SetAngularVelocity(FLIPANGULARVEL);

    } else {
        this->carBody->ApplyLinearImpulse(b2Vec2(FLIPIMPULSE*(-1), 0), this->carBody->GetWorldCenter(), true);
        this->carBody->SetAngularVelocity(FLIPANGULARVEL* (-1));
    }
    this->isFliping = true;
    this->flipStartAngle = carBody->GetAngle(); 
    
}

void CarPhysics::swapFrontBackSensor() {
    if (this->sensorStatus == BALLINBACKSENSOR){
        this->sensorStatus = BALLINFRONTSENSOR;
    } else if (this->sensorStatus == BALLINFRONTSENSOR) {
        this->sensorStatus = BALLINBACKSENSOR;
    }
}

void CarPhysics::updateFlipStatus() {
    if (this->isFliping && abs(this->carBody->GetAngle() - this->flipStartAngle) >= 2*PI) {
        this->isFliping = false;
        this->flipStartAngle = 0;
        this->carBody->SetAngularVelocity(0);
    }
}