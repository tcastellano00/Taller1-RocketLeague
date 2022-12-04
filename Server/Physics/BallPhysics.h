#ifndef BALLPHYSICS_H
#define BALLPHYSICS_H

#include "../Box2D/Box2D.h"
#include "EntityCategory.h"
#include <string>
#include "../Config/ServerConfig.h"
#include "../../Common/Model/BallModel.h"

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
    BallPhysics(b2World &world);
    BallPhysics();
    b2Body* getBody();

    b2Body* createBody(b2World& world);
    


    void redShot(int sideMultiplicator);
    void goldShot(int sideMultiplicator);
    void purpleShot(int sideMultiplicator);

    SpecialShot getShotType();
    void setShotType(SpecialShot type);

    void updateShotStatus();

    BallModel getModel();

};

#endif