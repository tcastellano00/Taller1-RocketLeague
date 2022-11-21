#include "Car.h"


CarPhysics::CarPhysics(b2Body* body, FacingStatus facing){
    body->SetUserData(this);
    this->carBody = body;
    this->facingStatus = facing;
    this->airStatus = AIR;
}

CarPhysics::CarPhysics() {}

b2Body* CarPhysics::getCarBody() {
    return this->carBody;
}
