#ifndef PHYSICS_H
#define PHYSICS_H

#include "../../libs/Box2D/Box2D.h"
#include "../../Common/GameStatus.h"
#include <map>
#include <list>
#include "../ClientConnection.h"
#include "GoalSensor.h"
#include "ContactListener.h"
#include "Car.h"
#include "BallPhysics.h"

enum _entityCategory {
  BOUNDARY = 0x0001,
  CAR  = 0x0002,
  BALL = 0x0004,
  GOALSENSOR = 0x0008,
  CAR_FRONT_SENSOR = 0x0010,
  CAR_BOTTOM_SENSOR = 0x0020,
};

class Physics{
	private:
    int numberOfPlayers;
    float timeStep;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;
    GoalSensor* leftGoal;
    GoalSensor* rightGoal;
    b2Timer timer;
    int liquidNitrogen = 50; //Cantidad de combustible para el Turbo
    int gameTime = 180000; //milisegundos
    ContactListener contactListener;
    std::map<int, CarPhysics*> cars;
    //b2Body* car;
    BallPhysics* ball;
    b2Body* ground;
    b2Body* box;
    CarPhysics* createCar(int numberOfCar);
    void createGround();
    GoalSensor* createGoal(SideOfGoal side);

  protected:
    b2World world;
    //b2Body * m_groundBody;

  public:
    Physics(std::list<ClientConnection>& connections);

    void moveCarRight(int socketId);

    void moveCarLeft(int socketId);

    void flipCarRight(int socketId);

    void flipCarLeft(int socketId);

    void carJump(int socketId);

    void carTurbo(int socketId);

    GameStatus getGameStatus();

    void simulateTimeStep();

    void createBox();

    void createBall();

    void carStopTurbo(int socketId);

    void carStopAccelerating(int socketId);

    void carStopFlip(int socketId);

    ~Physics();
};
#endif