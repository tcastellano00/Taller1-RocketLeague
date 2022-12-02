#include "Physics.h"
#include "Car.h"
#include "Box.h"
#include <iostream>
#include <string>

#include "../../libs/Box2D/Box2D.h"

#define MOVEMENTFORCE 500
#define CARFRICTION 1.5
#define GROUNDFRICTION 1.0
#define JUMPIMPULSE 40
#define GRAVITY -10
#define TORQUEFORCE 5000
#define TORQUEIMPULSE 200
#define FIELDHALFWIDTH 90
#define FIELDHEIGTH 60
#define WALLWIDTH 1
#define CARHALFWIDTH 7.5
#define CARHALFHEIGHT 2
#define BALLRADIUS 5
#define GOALTOPHALFWIDTH 10
#define GOALTOPHALFHEIGHT 22
#define TURBOFORCE MOVEMENTFORCE*8
#define FRONTSENSORHALFWIDTH 5.0
#define BOTTOMSENSORHALFHEIGTH 5.0
#define ROTATIONANGULARVELOCITY 3


#define mitadAltoParedesArco 8 //CAMBIAR ESTO
#define CHAINSTARTHEIGHT 11


Physics::Physics(std::list<ClientConnection>& connections): world(b2Vec2(0.0f, GRAVITY)){

    numberOfPlayers = connections.size();
    timeStep = 1.0f / 10.0f;
    velocityIterations = 6;
    positionIterations = 2;

    int numberOfCar = 0;
    for (auto connection = connections.begin(); connection != connections.end(); ++connection) {
        int sktId = (*connection).getId();
        cars[sktId] = new CarPhysics(world, numberOfCar);
        numberOfCar++;
    }
    BoxPhysics box(this->world);
    this->createBall();

    //this->createGround();
    //this->createBox();
    //this->createCars();

    //CarPhisics car(b2World);
    this->leftGoal = this->createGoal(LEFT);
    this->rightGoal = this->createGoal(RIGHT);

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

CarPhysics* Physics::createCar(int numberOfCar) {
    CarPhysics* carPhysics = new CarPhysics(world, numberOfCar);
    return carPhysics;



}

void Physics::moveCarRight(int socketId) {
    CarPhysics* car = this->cars[socketId];
    b2Body* carBody = car->getCarBody();
    // car->SetTransform(
    //     b2Vec2(car->GetPosition().x + 1, car->GetPosition().y), car->GetAngle()
    // );
    //b2Vec2 vel = carBody->GetLinearVelocity();
    float force = MOVEMENTFORCE;


    // if ( vel.x ==  0 ) {
    //     carBody->ApplyLinearImpulse(b2Vec2(60, 0), carBody->GetWorldCenter(), true);
    // }


    if (car->getAirStatus() != GROUND) {
        force /= 10;
    }

    carBody->ApplyForceToCenter(b2Vec2(force,0), true);
    if (car->getSide() == LEFTPLAYER) {
        if (car->getFacingStatus() == FACINGBACK) {
            car->swapFrontBackSensor();
        }
        car->setFacingStatus(FACINGFRONT);
    } else {
        if (car->getFacingStatus() == FACINGFRONT) {
            car->swapFrontBackSensor();
        }
        car->setFacingStatus(FACINGBACK);
    }
    car->setAcceleratingStatus(ACCELERATINGRIGHT);
}

void Physics::moveCarLeft(int socketId) {
    CarPhysics* car = this->cars[socketId];
    b2Body* carBody = car->getCarBody();

    /*car->SetTransform(
        b2Vec2(car->GetPosition().x - 1, car->GetPosition().y), car->GetAngle()
    );*/
    float force = MOVEMENTFORCE*(-1);
    //b2Vec2 vel = carBody->GetLinearVelocity();



    // if ( vel.x ==  0 ) {
    //     carBody->ApplyLinearImpulse(b2Vec2(-60, 0), carBody->GetWorldCenter(), true);
    // }

    if (car->getAirStatus() !=  GROUND) {
        force /= 10;
    }
    carBody->ApplyForceToCenter(b2Vec2(force,0), true);
    if (car->getSide() == LEFTPLAYER) {
        if (car->getFacingStatus() == FACINGFRONT) {
            car->swapFrontBackSensor();
        }
        car->setFacingStatus(FACINGBACK);
    } else {
        if (car->getFacingStatus() == FACINGBACK) {
            car->swapFrontBackSensor();
        }
        car->setFacingStatus(FACINGFRONT);
    }
    car->setAcceleratingStatus(ACCELERATINGLEFT);
}

void Physics::carStopAccelerating(int socketId) {
    CarPhysics* car = this->cars[socketId];
    car->setAcceleratingStatus(NOTACCELERATING);
}

void Physics::carJump(int socketId) {
    CarPhysics* car = this->cars[socketId];
    AirStatus airStatus = car->getAirStatus();

    if (airStatus == AIRAFTERFLIP){
        return;
    }

    if (car->getSensorStatus() == BALLINBACKSENSOR && airStatus == AIR && car->getAcceleratingStatus() != NOTACCELERATING) {
        ball->goldShot(car->getSide());
        car->flipJump();
    } else if (car->getSensorStatus() == BALLINFRONTSENSOR && airStatus == AIR && car->getAcceleratingStatus() != NOTACCELERATING) {
        ball->redShot(car->getSide());
        car->flipJump();
    } else if (car->getSensorStatus() == BALLINBOTTOMSENSOR) {
        ball->purpleShot(car->getSide());
        if(car->getSide() == LEFTPLAYER){ car->getCarBody()->ApplyLinearImpulse(b2Vec2(-3000,0),car->getCarBody()->GetWorldCenter(), true);}
        else{car->getCarBody()->ApplyLinearImpulse(b2Vec2(3000,0), car->getCarBody()->GetWorldCenter(), true);}
    } else if (car->getAcceleratingStatus() != NOTACCELERATING && car->getAirStatus() == AIR ){
        car->flipJump();
    } else {
        b2Body* carBody = car->getCarBody();
        b2Vec2 vel = carBody->GetLinearVelocity();
        float desiredVel = JUMPIMPULSE;
        float velChange = desiredVel - vel.y;
        float impulse = carBody->GetMass() * velChange; //disregard time factor
        carBody->ApplyLinearImpulse( b2Vec2(0, impulse), carBody->GetWorldCenter(), true);
    }
    
    if (airStatus == AIR) {
        car->setAirStatus(AIRAFTERFLIP);
    }
    
}

void Physics::flipCarRight(int socketId) {
    b2Body* carBody = this->cars[socketId]->getCarBody();
    carBody->SetAngularVelocity(ROTATIONANGULARVELOCITY);
}

void Physics::flipCarLeft(int socketId) {
    b2Body* carBody = this->cars[socketId]->getCarBody();
    carBody->SetAngularVelocity(ROTATIONANGULARVELOCITY * (-1));
}

void Physics::carStopFlip(int socketId) {
    b2Body* carBody = this->cars[socketId]->getCarBody();
    carBody->SetAngularVelocity(0);
}

void Physics::carTurbo(int socketId){
    // if(this->liquidNitrogen != 0){

    // }

    CarPhysics* car = this->cars[socketId];

    if (!car->canUseTurbo()) {
        car->setDoingTurbo(false);
        return;
    }

    car->loseTurbo();

    b2Body* carBody = car->getCarBody();
    float angle = carBody->GetAngle();
    float x = std::cos(angle)*TURBOFORCE;
    float y = std::sin(angle)*TURBOFORCE;

    if ((car->getSide() == LEFTPLAYER && car->getFacingStatus() == FACINGBACK) ||
        (car->getSide() == RIGHTPLAYER && car->getFacingStatus() == FACINGFRONT)){
        x *= -1;
        y *= -1;
    }
    carBody->ApplyForceToCenter(b2Vec2(x, y),true);
    car->setDoingTurbo(true);
    //this->liquidNitrogen -= 1;
    
}

void Physics::carStopTurbo(int socketId) {
    CarPhysics* car = this->cars[socketId];
    car->setDoingTurbo(false);
}


void Physics::createBall(){
    b2BodyDef ballBodyDef;
    ballBodyDef.type = b2_dynamicBody;
    ballBodyDef.position.Set(FIELDHALFWIDTH, FIELDHEIGTH/2);
    b2Body* ballBody = world.CreateBody(&ballBodyDef);

    //Textures
    b2CircleShape circleBall;
    circleBall.m_radius = BALLRADIUS;
    b2FixtureDef fixtureDef;
    fixtureDef.filter.categoryBits = BALL;
    fixtureDef.filter.maskBits = BOUNDARY | CAR | GOALSENSOR | CAR_FRONT_SENSOR | CAR_BOTTOM_SENSOR;
    fixtureDef.shape = &circleBall;
    fixtureDef.density = 0.001f;
    fixtureDef.restitution = 0.9f;
    //fixtureDef.isSensor = true;
    fixtureDef.friction = CARFRICTION;
    ballBody->CreateFixture(&fixtureDef);
    //return ball;
    this->ball = new BallPhysics(ballBody);
}

GoalSensor* Physics::createGoal(SideOfGoal side) {
    b2BodyDef goalBodyDef;
    goalBodyDef.type = b2_staticBody;
    goalBodyDef.position.Set(FIELDHALFWIDTH, 0);
    b2Body* body = world.CreateBody(&goalBodyDef);
    b2FixtureDef sensorFixture;
    b2PolygonShape polygonShapeSensor;
    sensorFixture.shape = &polygonShapeSensor;
    sensorFixture.isSensor = true;
    sensorFixture.filter.categoryBits = GOALSENSOR;
    sensorFixture.filter.maskBits = BALL;
    float sensorHalfWidht = GOALTOPHALFWIDTH - BALLRADIUS;
    float sensorHalfHeight = (FIELDHEIGTH - mitadAltoParedesArco*2)/2;
    if (side == LEFT) {
        polygonShapeSensor.SetAsBox(sensorHalfWidht, sensorHalfHeight, b2Vec2(-FIELDHALFWIDTH + sensorHalfWidht,  FIELDHEIGTH/2), 0);
    } else if (side == RIGHT) {
        polygonShapeSensor.SetAsBox(sensorHalfWidht, sensorHalfHeight, b2Vec2(FIELDHALFWIDTH - sensorHalfWidht, FIELDHEIGTH/2), 0);
    }
    body->CreateFixture(&sensorFixture);
    GoalSensor* goal = new GoalSensor(side, body);
    return goal;
}


GameStatus Physics::getGameStatus(){
    GameStatus newGameStatus;



    std::list<PlayerModel> playerModels;
    for (std::map<int, CarPhysics*>::iterator it = this->cars.begin(); it != this->cars.end(); ++it) {
        b2Vec2 carCoord = it->second->getCarBody()->GetPosition();
        float angle = it->second->getCarBody()->GetAngle() * (-1);
        
        float xOriginal = -CARHALFWIDTH;
        float yOriginal = CARHALFHEIGHT;


        //float xPrime = xOriginal * std::cos(angle*(-1)) - yOriginal * std::sin(angle*(-1));
        //float yPrime = xOriginal * std::sin(angle*(-1)) + yOriginal * std::cos(angle*(-1));


        float xCar = carCoord.x + xOriginal;
        float yCar = carCoord.y + yOriginal;
        
        std::string facing;

        if (it->second->getSide() == LEFTPLAYER) {
            if (it->second->getFacingStatus() == FACINGBACK) {
                facing = "left";
            } else {
                facing = "right";
            }
        } else{
            if (it->second->getFacingStatus() == FACINGFRONT) {
                facing = "left";
            } else {
                facing = "right";
            }
        }

        bool turbo = it->second->getDoingTurbo();
        int turboRem = it->second->getTurbo();

        /*if (it->second->getSensorStatus() == BALLINBACKSENSOR) {
            std::cout << "SENSOR: BACK" << std::endl;
        } else if (it->second->getSensorStatus() == BALLINBOTTOMSENSOR) {
            std::cout << "SENSOR: BOTTOM" << std::endl;
        } else if (it->second->getSensorStatus() == BALLINFRONTSENSOR) {
            std::cout << "SENSOR: FRONT" << std::endl;
        } else if (it->second->getSensorStatus() == NOTSENSOR) {
            std::cout << "SENSOR: NOT" << std::endl;
        }*/


        PlayerModel pm(xCar, yCar, angle, turbo, facing, turboRem);
        playerModels.push_back(pm);


    }
    newGameStatus.setPlayersModels(playerModels);
    b2Vec2 ballCoord = this->ball->getBody()->GetPosition();
    float ballCoordX = ballCoord.x - BALLRADIUS;
    float ballCoordY = ballCoord.y + BALLRADIUS;
    std::string colour;
    switch(ball->getShotType()) {
        case NONE: {
            colour = "normal";
            break;
        }
        case REDSHOT: {
            colour = "red";
            break;
        }
        case GOLDSHOT: {
            colour = "gold";
            break;
        }
        case PURPLESHOT: {
            colour = "purple";
            break;
        }
    }

    BallModel bm(ballCoordX, ballCoordY, ball->getBody()->GetAngle() * (-1), colour);

    newGameStatus.setBallModel(bm);

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
            it->second->getCarBody()->SetTransform(b2Vec2(FIELDHALFWIDTH/2, FIELDHEIGTH/2), 0); 
        } else if (i == 1) {
            it->second->getCarBody()->SetTransform(b2Vec2(3*FIELDHALFWIDTH/2, FIELDHEIGTH/2), 0);
        } else if (i == 2) {
            it->second->getCarBody()->SetTransform(b2Vec2(FIELDHALFWIDTH/3, FIELDHEIGTH/2), 0);
        } else if (i == 3) {
            it->second->getCarBody()->SetTransform(b2Vec2(5*FIELDHALFWIDTH/3, FIELDHEIGTH/2), 0);
        }
        it->second->getCarBody()->ApplyForceToCenter(b2Vec2(0,-1), true);
        ++i;
    }
    ball->getBody()->SetTransform(b2Vec2(FIELDHALFWIDTH, FIELDHEIGTH/2), 0);
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

Physics::~Physics() {
    delete leftGoal;
    delete rightGoal;
    for (std::map<int, CarPhysics*>::iterator it = this->cars.begin(); it != this->cars.end(); ++it) {
        delete it->second;
    }
    delete ball;

}
