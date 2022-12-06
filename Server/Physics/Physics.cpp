#include "Physics.h"
#include "Car.h"
#include "Box.h"
#include <iostream>
#include <string>

#include "../../libs/Box2D/Box2D.h"
#include "QueryCallback.h"
#include "../../Common/Config/CommonConfig.h"

Physics::Physics(std::list<ClientConnection>& connections): world(b2Vec2(0.0f, GRAVITY)){

    numberOfPlayers = connections.size();
    timeStep = 1.0f / 10.0f;
    velocityIterations = 6;
    positionIterations = 2;
    gameTime = GAMETIME;

    int numberOfCar = 0;
    for (auto connection = connections.begin(); connection != connections.end(); ++connection) {
        int clientId = (*connection).getId();
        cars[clientId] = new CarPhysics(clientId, (*connection).getName(), world, numberOfCar);
        numberOfCar++;
    }
    BoxPhysics box(this->world);

    this->ball = new BallPhysics(this->world);

    //this->createBall();
    this->leftGoal = new GoalSensor(LEFT, world);
    this->rightGoal = new GoalSensor(RIGHT, world);
    

    SavingArea* leftSavingArea = new SavingArea(LEFTAREA,world);
    SavingArea* rightSavingArea = new SavingArea(RIGHTAREA,world);

    leftSavingArea->getSavingAreaSide();
    rightSavingArea->getSavingAreaSide();//pq sino

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

void Physics::carStopAccelerating(int clientId) {
    CarPhysics* car = this->cars[clientId];
    car->stopAccelerating();
}

void Physics::carJump(int clientId) {

    CarPhysics* car = this->cars[clientId];
    MakeShot makeShot = DONTMAKESHOT;
    carJumping = car->jump(makeShot);

    int sideMultiplicator = (car->getSide() == LEFTPLAYER) ? 1 : -1;

    if (makeShot == MAKEGOLDSHOT) {
        ball->goldShot(sideMultiplicator);
    } else if (makeShot == MAKEREDSHOT) {
        ball->redShot(sideMultiplicator);
    } else if (makeShot == MAKEPURPLESHOT) {
        ball->purpleShot(sideMultiplicator);
    }
}

void Physics::flipCarRight(int clientId) {
    CarPhysics* car = this->cars[clientId];
    car->rotate(1);
}

void Physics::flipCarLeft(int clientId) {
    CarPhysics* car = this->cars[clientId];
    car->rotate(-1);
}

void Physics::carStopFlip(int clientId) {
    CarPhysics* car = this->cars[clientId];
    car->stopRotate();
}

void Physics::startDoingTurbo(int clientId) {
    CarPhysics* car = this->cars[clientId];
    car->startDoingTurbo();
} 

void Physics::carStopTurbo(int clientId) {
    CarPhysics* car = this->cars[clientId];
    car->stopDoingTurbo();
}

GameStatus Physics::getGameStatus(){
    GameStatus newGameStatus;

    std::list<PlayerModel> playerModels;

    bool skip = true;

    for (std::map<int, CarPhysics*>::iterator it = this->cars.begin(); it != this->cars.end(); ++it) {
        PlayerModel pm = it->second->getPlayerModel();
        playerModels.push_back(pm);


        skip = skip && it->second->getSkipReplay();


    }

    this->skipRep = skip;

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


    

    newGameStatus.setReplay(this->isInReplay && !this->skipRep);
    newGameStatus.setInExplosion(this->isInExplosion);
    newGameStatus.setCarJump(this->carJumping);

    this->carJumping = false;
    this->ball->setContactWithBox(false);

    return newGameStatus;
}


// void Physics::applyBlastImpulse(b2Body* body, b2Vec2 blastCenter, b2Vec2 applyPoint, float blastPower)
//     {
//         //ignore the grenade itself, and any non-dynamic bodies
//         if ( body == this->ball->getBody() || body->GetType() != b2_dynamicBody )
//             return;
//         b2Vec2 blastDir = applyPoint - blastCenter;
//         float distance = blastDir.Normalize();
//         //ignore bodies exactly at the blast point - blast direction is undefined
//         if ( distance == 0 )
//             return;
//         float invDistance = 1 / distance;
//         float impulseMag = blastPower * invDistance * invDistance;
//         impulseMag = b2Min( impulseMag, 500.0f );
//         body->ApplyLinearImpulse( impulseMag * blastDir, applyPoint,true);
// }

// void Physics::applyExplosion(){
//     //if (isInExplosion){return;}
    
//     b2Vec2 center = ball->getBody()->GetPosition();

//     //find all fixtures within blast radius AABB
//     QueryCallback queryCallback;
//     b2AABB aabb;
//     aabb.lowerBound = center - b2Vec2( FIELDHALFWIDTH*2,FIELDHEIGHT );
//     aabb.upperBound = center + b2Vec2( FIELDHALFWIDTH*2,FIELDHEIGHT  );
//     world.QueryAABB( &queryCallback, aabb );

//     //check which of these have their center of mass within the blast radius
//     for (long unsigned int i = 0; i < queryCallback.foundBodies.size(); i++) {
//         b2Body* body = queryCallback.foundBodies[i];
//         b2Vec2 bodyCom = body->GetWorldCenter();
//         //ignore bodies outside the blast range
//         if ( (bodyCom - center).Length() >= BALLRADIUS )
//             continue;
//         applyBlastImpulse(body, center, bodyCom, blastPower );//scale blast power to roughly match results of other methods at 32 rays
//     }
// }



void Physics::applyExplosion(int sign){
    if (isInExplosion){return;}

    isInExplosion = true;

    for (b2Body* body = world.GetBodyList(); body; body = body->GetNext())
    {
        if (body == this->ball->getBody()){continue;}
        body->ApplyLinearImpulse( b2Vec2(1000000*sign,0), body->GetWorldCenter(),true ); //Cambiar esto
    }
}

void Physics::resetPositionsIfGoal(){
    if(!leftGoal->getGoalScored() && !rightGoal->getGoalScored()){
        return;
    }

    if(leftGoal->getGoalScored()){
        this->applyExplosion(1);
    } else {
       this->applyExplosion(-1); 
    }
    if(isInExplosion){this->world.SetGravity(b2Vec2(0,0));}
    if (timeExplosion > 1){
        timeExplosion -= 1;
        return; }
    timeExplosion = 60;
    isInExplosion = false;
    this->world.SetGravity(b2Vec2(0.0f, GRAVITY));


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
    
    //Tiempo en milisegundos que demora un frame.
    this->currentTimeOfReplay += 1000.0f / CommonConfig::getFrameRate();

    if (this->currentTimeOfReplay >= REPLAYTIME || this->skipRep) {
        this->currentTimeOfReplay = 0;
        this->setIsInReplay(false);
        this->skipRep = false;
        for (std::map<int, CarPhysics*>::iterator it = this->cars.begin(); it != this->cars.end(); ++it) {
            it->second->setSkipReplay(false);
        }
        
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

void Physics::startAcceleratingCarForward(int clientId) {
    CarPhysics* car = this->cars[clientId];
    car->startAcceleratingForward();
}

void Physics::startAcceleratingCarBackwards(int clientId){
    CarPhysics* car = this->cars[clientId];
    car->startAcceleratingBackwards();
}

void Physics::stopAcceleratingCar(int clientId){
    CarPhysics* car = this->cars[clientId];
    car->stopAccelerating();
}

void Physics::turnCar(int clientId) {
    CarPhysics* car = this->cars[clientId];
    car->turn();
}

void Physics::doRedShot(int clientId) {
    CarPhysics* car = this->cars[clientId];
    if (car->getSide() == LEFTPLAYER) {
        ball->redShot(1);
    } else {
        ball->redShot(-1);
    }
}

void Physics::doGoldenShot(int clientId) {
    CarPhysics* car = this->cars[clientId];
    if (car->getSide() == LEFTPLAYER) {
        ball->goldShot(1);
    } else {
        ball->goldShot(-1);
    }
}

void Physics::doPurpleShot(int clientId) {
    CarPhysics* car = this->cars[clientId];
    if (car->getSide() == LEFTPLAYER) {
        ball->purpleShot(1);
    } else {
        ball->purpleShot(-1);
    }
}

void Physics::playerSetSkipReplay(int clientId) {
    CarPhysics* car = this->cars[clientId];
    car->setSkipReplay(true);
}

Physics::~Physics() {
    delete leftGoal;
    delete rightGoal;

    delete leftSavingArea;
    delete rightSavingArea;
    for (std::map<int, CarPhysics*>::iterator it = this->cars.begin(); it != this->cars.end(); ++it) {
        delete it->second;
    }
    delete ball;

}

