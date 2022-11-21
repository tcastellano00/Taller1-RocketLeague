#include "BallPhysics.h"

BallPhysics::BallPhysics(b2Body* body) {
    body->SetUserData(this);
    this->ballBody = body;
}

BallPhysics::BallPhysics() {}

b2Body* BallPhysics::getBody() {
    return this->ballBody;
}