#ifndef PHYSICS_H
#define PHYSICS_H

#include "../../libs/Box2D/Box2D.h"
#include "../../Common/GameStatus.h"
#include <map>
#include <list>
#include "../ClientConnection.h"
#include "GoalSensor.h"
#include "ContactListener.h"

enum _entityCategory {
    BOUNDARY = 0x0001,
    CAR  = 0x0002,
    BALL = 0x0004,
    GOALSENSOR = 0x0008,
  };

class Physics{
    private:
    int numberOfPlayers;
    float timeStep;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;
    GoalSensor* leftGoal;
    GoalSensor* rightGoal;
    ContactListener contactListener;


    
    std::map<int, b2Body*> cars;
    //b2Body* car;
    b2Body* ball;
    b2Body* ground;
    b2Body* box;

    b2Body* createCar(int numberOfCar);
    void createGround();
   GoalSensor* createGoal(SideOfGoal side);
    
    

    protected:
    b2World world;
    //b2Body * m_groundBody ;

    public:
    Physics(std::list<ClientConnection>& connections);

    void moveCarRight(int socketId);

    void moveCarLeft(int socketId);

    void flipCarRight(int socketId);

    void flipCarLeft(int socketId);

    void carJump(int socketId);

    GameStatus getGameStus();

    void simulateTimeStep();

    void createBox();

    void createBall();

    ~Physics();
};
#endif