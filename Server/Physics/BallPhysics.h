#ifndef BALLPHYSICS_H
#define BALLPHYSICS_H

#include "../Box2D/Box2D.h"
#include "Car.h"
#include <string>

enum SpecialShot {
    REDSHOT,
    GOLDSHOT,
    PURPLESHOT,  
    NONE,

};

class BallPhysics {
private:
    b2Body* ballBody;
    void generateImpulse(float impulse);
    SpecialShot shotType;
    int specialShotTimer;
    

public:
    BallPhysics(b2Body* body);
    BallPhysics();
    b2Body* getBody();
    


    void redShot(PlayerSide side);
    void goldShot(PlayerSide side);
    void purpleShot(PlayerSide side);

    SpecialShot getShotType();
    void setShotType(SpecialShot type);

    void updateShotStatus();

};

#endif