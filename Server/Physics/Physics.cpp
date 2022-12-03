#include "Physics.h"
#include "Car.h"
#include "Box.h"
#include <iostream>
#include <string>


#include "../../libs/Box2D/Box2D.h"

// #define MOVEMENTFORCE 500
// #define CARFRICTION 1.5
// #define GROUNDFRICTION 1.0
// #define JUMPIMPULSE 40
// #define GRAVITY -10
// #define TORQUEFORCE 5000
// #define TORQUEIMPULSE 200
// #define FIELDHALFWIDTH 90
// #define FIELDHEIGTH 60
// #define WALLWIDTH 1
// #define CARHALFWIDTH 7.5
// #define CARHALFHEIGHT 2
// #define BALLRADIUS 5
// #define GOALTOPHALFWIDTH 10
// #define GOALTOPHALFHEIGHT 22
// #define TURBOFORCE MOVEMENTFORCE*8
// #define FRONTSENSORHALFWIDTH 5.0
// #define BOTTOMSENSORHALFHEIGTH 5.0
// #define ROTATIONANGULARVELOCITY 3

float FIELDHALFWIDTH = ServerConfig::getFieldHalfWidth();
float FIELDHEIGHT = ServerConfig::getFieldHeight();
float GRAVITY = ServerConfig::getGravity();
float GAMETIME = ServerConfig::getGameTime();
float EXTRATIME = ServerConfig::getExtraTime();
float REPLAYTIME = ServerConfig::getReplayTime();



Physics::Physics(std::list<ClientConnection>& connections): world(b2Vec2(0.0f, GRAVITY)){

    numberOfPlayers = connections.size();
    timeStep = 1.0f / 10.0f;
    velocityIterations = 6;
    positionIterations = 2;
    gameTime = GAMETIME;

    int numberOfCar = 0;
    for (auto connection = connections.begin(); connection != connections.end(); ++connection) {
        int sktId = (*connection).getId();
        cars[sktId] = new CarPhysics(world, numberOfCar);
        numberOfCar++;
    }
    BoxPhysics box(this->world);

    this->ball = new BallPhysics(this->world);

    //this->createBall();
    this->leftGoal = new GoalSensor(LEFT, world);
    this->rightGoal = new GoalSensor(RIGHT, world);

    this->world.SetContactListener(&(this->contactListener));
}

void Physics::createBox(){
    BoxPhysics box(this->world);
}

void Physics::simulateTimeStep(){
    world.Step(this->timeStep,this->velocityIterations,this->positionIterations);
    ball->updateShotStatus();
    for (std::map<int, CarPhysics*>::iterator it = this->cars.begin(); it != this->cars.end(); ++it) {
        it->second->updateFlipStatus();
    }

}

void Physics::carStopAccelerating(int socketId) {
    CarPhysics* car = this->cars[socketId];
    car->stopAccelerating();
}

void Physics::carJump(int socketId) {
    CarPhysics* car = this->cars[socketId];
    car->jump(this->ball); 
}

void Physics::flipCarRight(int socketId) {
    CarPhysics* car = this->cars[socketId];
    car->rotate(1);
}

void Physics::flipCarLeft(int socketId) {
    CarPhysics* car = this->cars[socketId];
    car->rotate(-1);
}

void Physics::carStopFlip(int socketId) {
    CarPhysics* car = this->cars[socketId];
    car->stopRotate();
}

void Physics::startDoingTurbo(int socketId) {
    CarPhysics* car = this->cars[socketId];
    car->startDoingTurbo();
} 


void Physics::carStopTurbo(int socketId) {
    CarPhysics* car = this->cars[socketId];
    car->stopDoingTurbo();
}

GameStatus Physics::getGameStatus(){
    GameStatus newGameStatus;

    std::list<PlayerModel> playerModels;
    for (std::map<int, CarPhysics*>::iterator it = this->cars.begin(); it != this->cars.end(); ++it) {
        PlayerModel pm = it->second->getPlayerModel();
        playerModels.push_back(pm);


    }
    newGameStatus.setPlayersModels(playerModels);
    newGameStatus.setBallModel(this->ball->getModel());

    //The goals of the left team are the ones scored in the right goal, and viceversa
    int goalsLeft = this->rightGoal->getGoals();
    int goalsRight = this->leftGoal->getGoals();



    //float segGame = (gameTime - timer.GetMilliseconds()) / 1000 ;  No funciona el getMIllisenconds()
    if(!isInReplay){
        gameTime -= 40;
    } 
    int segGame = (gameTime) / 1000 ; //Restamos a mano el tiempo correspondiente a un frame.
    int minGame = segGame / 60;
    segGame = segGame - minGame*60;
    

    ScoreModel scm(minGame, segGame, 0, goalsLeft, goalsRight);
    newGameStatus.setScoreModel(scm);

    if (gameTime <= 0) {
        if (goalsLeft == goalsRight) {
            gameTime = EXTRATIME;
        } else {
            newGameStatus.setClose();
        }
    }

    if (this->isInReplay) {
        newGameStatus.setReplay(true);
    } else {
        newGameStatus.setReplay(false);
    }

    return newGameStatus;
}

void Physics::resetPositionsIfGoal(){
    if(!leftGoal->getGoalScored() && !rightGoal->getGoalScored()){
        return;
    }
    leftGoal->setGoalScored(false);
    rightGoal->setGoalScored(false);
    int i = 0;
    for (std::map<int, CarPhysics*>::iterator it = this->cars.begin(); it != this->cars.end(); ++it) {
        if (i == 0) {
            it->second->getCarBody()->SetTransform(b2Vec2(FIELDHALFWIDTH/2, FIELDHEIGHT/2), 0); 
        } else if (i == 1) {
            it->second->getCarBody()->SetTransform(b2Vec2(3*FIELDHALFWIDTH/2, FIELDHEIGHT/2), 0);
        } else if (i == 2) {
            it->second->getCarBody()->SetTransform(b2Vec2(FIELDHALFWIDTH/3, FIELDHEIGHT/2), 0);
        } else if (i == 3) {
            it->second->getCarBody()->SetTransform(b2Vec2(5*FIELDHALFWIDTH/3, FIELDHEIGHT/2), 0);
        }
        it->second->getCarBody()->ApplyForceToCenter(b2Vec2(0,-1), true);
        ++i;
    }
    ball->getBody()->SetTransform(b2Vec2(FIELDHALFWIDTH, FIELDHEIGHT/2), 0);
    ball->getBody()->SetLinearVelocity(b2Vec2(0,-1));
    ball->getBody()->SetAngularVelocity(0);

    this->setIsInReplay(true);
}

bool Physics::getIsInReplay() {
    return this->isInReplay;
}

void Physics::setIsInReplay(bool replay) {
    this->isInReplay = replay;
}

void Physics::updateReplayStaus() {
    if (!this->isInReplay) {
        return;
    }
    this->currentTimeOfReplay += 40; //equivalente a un frame
    if (this->currentTimeOfReplay >= REPLAYTIME) {
        this->currentTimeOfReplay = 0;
        this->setIsInReplay(false);
    }
}

void Physics::fillTurbos() {
    for (std::map<int, CarPhysics*>::iterator it = this->cars.begin(); it != this->cars.end(); ++it) {
        if (!it->second->getDoingTurbo() && it->second->getAirStatus() == GROUND ) {
            it->second->fillTurbo();
        }
    }
}

void Physics::accelerateCars() {
    for (std::map<int, CarPhysics*>::iterator it = this->cars.begin(); it != this->cars.end(); ++it) {
        it->second->applyAcceleration();
    }
}

void Physics::applyTurboToCars() {
    for (std::map<int, CarPhysics*>::iterator it = this->cars.begin(); it != this->cars.end(); ++it) {
        it->second->applyTurbo();
    }
}

void Physics::startAcceleratingCarForward(int socketId) {
    CarPhysics* car = this->cars[socketId];
    car->startAcceleratingForward();
}

void Physics::startAcceleratingCarBackwards(int socketId){
    CarPhysics* car = this->cars[socketId];
    car->startAcceleratingBackwards();
}

void Physics::stopAcceleratingCar(int socketId){
    CarPhysics* car = this->cars[socketId];
    car->stopAccelerating();
}

void Physics::turnCar(int socketId) {
    CarPhysics* car = this->cars[socketId];
    car->turn();
}

void Physics::doRedShot(int socketId) {
    CarPhysics* car = this->cars[socketId];
    if (car->getSide() == LEFTPLAYER) {
        ball->redShot(1);
    } else {
        ball->redShot(-1);
    }
}

void Physics::doGoldenShot(int socketId) {
    CarPhysics* car = this->cars[socketId];
    if (car->getSide() == LEFTPLAYER) {
        ball->goldShot(1);
    } else {
        ball->goldShot(-1);
    }
}

void Physics::doPurpleShot(int socketId) {
    CarPhysics* car = this->cars[socketId];
    if (car->getSide() == LEFTPLAYER) {
        ball->purpleShot(1);
    } else {
        ball->purpleShot(-1);
    }
}

Physics::~Physics() {
    delete leftGoal;
    delete rightGoal;
    for (std::map<int, CarPhysics*>::iterator it = this->cars.begin(); it != this->cars.end(); ++it) {
        delete it->second;
    }
    delete ball;

}
