#ifndef BALLPHYSICS_H
#define BALLPHYSICS_H

#include "../Box2D/Box2D.h"

class BallPhysics {
private:
    b2Body* ballBody;
public:
    BallPhysics(b2Body* body);
    BallPhysics();
    b2Body* getBody();

};

#endif