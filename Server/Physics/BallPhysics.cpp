#include "BallPhysics.h"
#define REDSHOTIMPULSE 100000.0
#define GOLDSHOTIMPULSE 100000.0
#define PURPLESHOTIMPULSE 100000.0
#define SPECIALSHOTTIME 25

BallPhysics::BallPhysics(b2Body* body) {
    body->SetUserData(this);
    this->ballBody = body;
    this->shotType = NONE;
    this->specialShotTimer = 0;
}

BallPhysics::BallPhysics() {}

b2Body* BallPhysics::getBody() {
    return this->ballBody;
}

void BallPhysics::redShot(PlayerSide side) {
    
    shotType = REDSHOT;
    if (side == LEFTPLAYER) {
        generateImpulse(REDSHOTIMPULSE);
    } else {
        generateImpulse(REDSHOTIMPULSE*(-1));
    }
}
void BallPhysics::goldShot(PlayerSide side) {
    shotType = GOLDSHOT;
    if (side == LEFTPLAYER) {
        generateImpulse(GOLDSHOTIMPULSE);
    } else {
        generateImpulse(GOLDSHOTIMPULSE*(-1));
    }
}
void BallPhysics::purpleShot(PlayerSide side) {
    shotType = PURPLESHOT;
    if (side == LEFTPLAYER) {
        generateImpulse(PURPLESHOTIMPULSE);
    } else {
        generateImpulse(PURPLESHOTIMPULSE*(-1));
    }
}

void BallPhysics::generateImpulse(float impulse) {
    this->ballBody->ApplyForceToCenter(b2Vec2(impulse,0),true);
    //this->ballBody->SetLinearVelocity(b2Vec2(impulse,0));
    //this->ballBody->ApplyLinearImpulse(b2Vec2(impulse, 0), this->ballBody->GetWorldCenter(), true);
}

SpecialShot BallPhysics::getShotType(){
    return this->shotType;
}

void BallPhysics::setShotType(SpecialShot type){
    this->shotType = type;
}

void BallPhysics::updateShotStatus() {
    if (this->shotType != NONE) {
        this->specialShotTimer += 1;
    }
    
    if (this->specialShotTimer > SPECIALSHOTTIME){
        this->shotType = NONE;
        this->specialShotTimer = 0;
    }
}