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
#include "../../Common/Config/ServerConfig.h"



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
    int gameTime; //milisegundos
    ContactListener contactListener;
    std::map<int, CarPhysics*> cars;
    //b2Body* car;
    BallPhysics* ball;
    b2Body* ground;
    b2Body* box;
    void createGround();
    GoalSensor* createGoal(SideOfGoal side);

    bool isInReplay = false;
    bool isInExplosion = false;
    bool carJumping = false;
    int currentTimeOfReplay = 0;
    int timeExplosion = 50; //frames, 2 segundos.

    float FIELDHALFWIDTH = ServerConfig::getFieldHalfWidth();
    float FIELDHEIGHT = ServerConfig::getFieldHeight();
    float GRAVITY = ServerConfig::getGravity();
    float GAMETIME = ServerConfig::getGameTime();
    float EXTRATIME = ServerConfig::getExtraTime();
    float REPLAYTIME = ServerConfig::getReplayTime();
    float BALLRADIUS = ServerConfig::getBallRadius();

  protected:
    
    //b2Body * m_groundBody;

  public:

    b2World world;
    Physics(std::list<ClientConnection>& connections);

    void flipCarRight(int clientId);

    void flipCarLeft(int clientId);

    void carJump(int clientId);

    GameStatus getGameStatus();

    void simulateTimeStep();

    void createBox();

    void createBall();

    void carStopTurbo(int clientId);

    void carStopAccelerating(int clientId);

    void carStopFlip(int clientId);

    void resetPositionsIfGoal();

    bool getIsInReplay();

    void setIsInReplay(bool replay);

    void updateReplayStaus();

    void fillTurbos();

    void startAcceleratingCarForward(int clientId);
    void startAcceleratingCarBackwards(int clientId);
    void stopAcceleratingCar(int clientId);

    void accelerateCars();

    void startDoingTurbo(int clientId);
    void applyTurboToCars();

    void turnCar(int clientId);

    void doRedShot(int clientId);
    void doGoldenShot(int clientId);
    void doPurpleShot(int clientId);

    void applyExplosion();
    void applyBlastImpulse(b2Body* body, b2Vec2 blastCenter, b2Vec2 applyPoint, float blastPower);

    void playerSetSkipReplay(int clientId);



    ~Physics();
};
#endif