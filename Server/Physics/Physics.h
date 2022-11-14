#ifndef PHYSICS_H
#define PHYSICS_H

#include "../../libs/Box2D/Box2D.h"
#include "../../Common/GameStatus.h"

class Physics{
    private:
    int numberOfPlayers;
    float timeStep;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    b2Body* car;
    b2Body* ground;

    void createCars();
    void createGround();
    
    

    protected:
    b2World world;
    //b2Body * m_groundBody ;

    public:
    Physics(int numberOfPlayers);

    void moveCarRight();

    void moveCarLeft();

    GameStatus getGameStus();

    void simulateTimeStep();

    ~Physics() = default;
};
#endif