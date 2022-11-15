#ifndef PHYSICS_H
#define PHYSICS_H

#include "../../libs/Box2D/Box2D.h"
#include "../../Common/GameStatus.h"
#include <map>
#include <list>
#include "../ClientConnection.h"

class Physics{
    private:
    int numberOfPlayers;
    float timeStep;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    
    std::map<int, b2Body*> cars;
    //b2Body* car;
    b2Body* ground;

    b2Body* createCar(int numberOfCar);
    void createGround();
    
    

    protected:
    b2World world;
    //b2Body * m_groundBody ;

    public:
    Physics(std::list<ClientConnection>& connections);

    void moveCarRight(int socketId);

    void moveCarLeft(int socketId);

    GameStatus getGameStus();

    void simulateTimeStep();

    ~Physics() = default;
};
#endif