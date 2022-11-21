#ifndef CARPHYSICS_H
#define CARPHYSICS_H

#include "../Box2D/Box2D.h"

// class CarPhisics{
//     b2World * &m_world;
    
//     public:
//     CarPhisics(b2World * &m_world);
// };

enum FacingStatus {
    FACINGLEFT,
    FACINGRIGHT,
};

enum AirStatus {
    AIR,
    GROUND,
};

class CarPhysics {
private:
    b2Body* carBody;
    FacingStatus facingStatus;
    AirStatus airStatus;

public:
    CarPhysics(b2Body* body, FacingStatus facing);
    CarPhysics();
    b2Body* getCarBody();
};

#endif