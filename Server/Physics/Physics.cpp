#include "Physics.h"
#include "Car.h"
#include <iostream>
#include <string>

#include "../../libs/Box2D/Box2D.h"

#define MOVEMENTFORCE 500
#define CARFRICTION 1.5
#define GROUNDFRICTION 1.0
#define JUMPIMPULSE 40
#define GRAVITY -20
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



Physics::Physics(std::list<ClientConnection>& connections): world(b2Vec2(0.0f, GRAVITY)){

    numberOfPlayers = connections.size();
    timeStep = 1.0f / 10.0f;
    velocityIterations = 6;
    positionIterations = 2;

    int numberOfCar = 0;
    for (auto connection = connections.begin(); connection != connections.end(); ++connection) {
        int sktId = (*connection).getId();
        cars[sktId] = createCar(numberOfCar);
        numberOfCar++;
    }

    this->createBall();



    //this->createGround();
    this->createBox();
    //this->createCars();

    //CarPhisics car(b2World);
    this->leftGoal = this->createGoal(LEFT);
    this->rightGoal = this->createGoal(RIGHT);

    this->world.SetContactListener(&(this->contactListener));




}

void Physics::createBox(){
    b2BodyDef boxBodyDef;

    b2PolygonShape polygonShape;
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &polygonShape;
    myFixtureDef.density = 1;
    myFixtureDef.friction = GROUNDFRICTION;
    myFixtureDef.filter.categoryBits = BOUNDARY;
    myFixtureDef.filter.maskBits = CAR | BALL;

    boxBodyDef.type = b2_staticBody;
    boxBodyDef.position.Set(FIELDHALFWIDTH, 0);
    this->box = world.CreateBody(&boxBodyDef);

    //add four walls to the static body
    polygonShape.SetAsBox( FIELDHALFWIDTH, WALLWIDTH, b2Vec2(0, WALLWIDTH*(-1)), 0);//ground
    this->box->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( FIELDHALFWIDTH, WALLWIDTH, b2Vec2(0, FIELDHEIGTH + WALLWIDTH), 0);//ceiling
    this->box->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( WALLWIDTH, FIELDHALFWIDTH, b2Vec2((FIELDHALFWIDTH + WALLWIDTH)*(-1), FIELDHEIGTH/2), 0);//left wall
    this->box->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( WALLWIDTH, FIELDHALFWIDTH, b2Vec2(FIELDHALFWIDTH + WALLWIDTH, FIELDHEIGTH/2), 0);//right wall
    this->box->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( GOALTOPHALFWIDTH, GOALTOPHALFHEIGHT, b2Vec2(GOALTOPHALFWIDTH - FIELDHALFWIDTH, FIELDHEIGTH - GOALTOPHALFHEIGHT), 0);//left goal
    this->box->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( GOALTOPHALFWIDTH, GOALTOPHALFHEIGHT, b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH, FIELDHEIGTH - GOALTOPHALFHEIGHT), 0);//right goal
    this->box->CreateFixture(&myFixtureDef);



}

void Physics::simulateTimeStep(){
    world.Step(this->timeStep,this->velocityIterations,this->positionIterations);
}

b2Body* Physics::createCar(int numberOfCar) {
    b2BodyDef carBodyDef;
    carBodyDef.type = b2_dynamicBody;
    if (numberOfCar == 0) {carBodyDef.position.Set(FIELDHALFWIDTH/2, FIELDHEIGTH/2);}
    if (numberOfCar == 1) {carBodyDef.position.Set(3*FIELDHALFWIDTH/2, FIELDHEIGTH/2);}
    b2Body* car = world.CreateBody(&carBodyDef);

    //Textures
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(CARHALFWIDTH, CARHALFHEIGHT);
    b2FixtureDef fixtureDef;
    fixtureDef.filter.categoryBits = CAR;
    fixtureDef.filter.maskBits = BOUNDARY | BALL;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 0.15f;
    fixtureDef.friction = CARFRICTION;
    car->CreateFixture(&fixtureDef);
    return car;
}

void Physics::createGround() {
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);
    this->ground = world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);
    //No importa la densidad porque es un cuerpo estatico el piso
    this->ground->CreateFixture(&groundBox, 0.0f);
}

void Physics::moveCarRight(int socketId) {

    b2Body* car = (this->cars[socketId]);
    // car->SetTransform(
    //     b2Vec2(car->GetPosition().x + 1, car->GetPosition().y), car->GetAngle()
    // );
    b2Vec2 vel = car->GetLinearVelocity();
    float force = MOVEMENTFORCE;
    if ( vel.x ==  0 ) {
        car->ApplyLinearImpulse(b2Vec2(60, 0), car->GetWorldCenter(), true);
    }

    car->ApplyForceToCenter(b2Vec2(force,0), true);


}

void Physics::moveCarLeft(int socketId) {
    b2Body* car = (this->cars[socketId]);

    /*car->SetTransform(
        b2Vec2(car->GetPosition().x - 1, car->GetPosition().y), car->GetAngle()
    );*/
    float force = MOVEMENTFORCE*(-1);
    b2Vec2 vel = car->GetLinearVelocity();
    if ( vel.x ==  0 ) {
        car->ApplyLinearImpulse(b2Vec2(-60, 0), car->GetWorldCenter(), true);
    }
    car->ApplyForceToCenter(b2Vec2(force,0), true);
}

void Physics::carJump(int socketId) {
    b2Body* car = (this->cars[socketId]);

    b2Vec2 vel = car->GetLinearVelocity();
    float desiredVel = JUMPIMPULSE;
    float velChange = desiredVel - vel.y;
    float impulse = car->GetMass() * velChange; //disregard time factor
    car->ApplyLinearImpulse( b2Vec2(0, impulse), car->GetWorldCenter(), true);
}

void Physics::flipCarRight(int socketId) {
    b2Body* car = (this->cars[socketId]);
    car->ApplyAngularImpulse(TORQUEIMPULSE, true);
    //car->ApplyTorque(TORQUEFORCE, true);
}

void Physics::flipCarLeft(int socketId) {
    b2Body* car = (this->cars[socketId]);
    car->ApplyAngularImpulse(TORQUEIMPULSE*(-1), true);
    //car->ApplyTorque(TORQUEFORCE*(-1), true);
}


GameStatus Physics::getGameStus(){
    GameStatus newGameStatus;



    std::list<PlayerModel> playerModels;
    for (std::map<int, b2Body*>::iterator it = this->cars.begin(); it != this->cars.end(); ++it) {
        b2Vec2 carCoord = it->second->GetPosition();
        float angle = it->second->GetAngle();
        
        float xOriginal = -CARHALFWIDTH;
        float yOriginal = CARHALFHEIGHT;


        // float xPrime = xOriginal * std::cos(angle) - yOriginal * std::sin(angle);
        // float yPrime = xOriginal * std::sin(angle) + yOriginal * std::cos(angle);


        float xCar = carCoord.x + xOriginal;
        float yCar = carCoord.y + yOriginal;
        PlayerModel pm(xCar, yCar, angle, false);
        playerModels.push_back(pm);

    }
    newGameStatus.setPlayersModels(playerModels);
    b2Vec2 ballCoord = this->ball->GetPosition();
    float ballCoordX = ballCoord.x - BALLRADIUS;
    float ballCoordY = ballCoord.y + BALLRADIUS;
    BallModel bm(ballCoordX, ballCoordY, ball->GetAngle());
    newGameStatus.setBallModel(bm);

    std::cout << this->leftGoal->getGoals() << "    " << this->rightGoal->getGoals() << std::endl;

    


    return newGameStatus;
}

void Physics::createBall(){
    b2BodyDef ballBodyDef;
    ballBodyDef.type = b2_dynamicBody;
    ballBodyDef.position.Set(FIELDHALFWIDTH, FIELDHEIGTH/2);
    this->ball = world.CreateBody(&ballBodyDef);


    //Textures
    b2CircleShape circleBall;
    circleBall.m_radius = BALLRADIUS;
    b2FixtureDef fixtureDef;
    fixtureDef.filter.categoryBits = BALL;
    fixtureDef.filter.maskBits = BOUNDARY | CAR | GOALSENSOR;
    fixtureDef.shape = &circleBall;
    fixtureDef.density = 0.001f;
    fixtureDef.restitution = 0.9f;
    //fixtureDef.isSensor = true;
    fixtureDef.friction = CARFRICTION;
    this->ball->CreateFixture(&fixtureDef);
    //return ball;
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
    float sensorHalfHeight = (FIELDHEIGTH - GOALTOPHALFHEIGHT*2)/2;
    if (side == LEFT) {
        polygonShapeSensor.SetAsBox(sensorHalfWidht, sensorHalfHeight, b2Vec2(-FIELDHALFWIDTH + sensorHalfWidht, sensorHalfHeight), 0);
    } else if (side == RIGHT) {
        polygonShapeSensor.SetAsBox(sensorHalfWidht, sensorHalfHeight, b2Vec2(FIELDHALFWIDTH - sensorHalfWidht, sensorHalfHeight), 0);
    }
    body->CreateFixture(&sensorFixture);
    GoalSensor* goal = new GoalSensor(side, body);
    return goal;
}


Physics::~Physics() {
    delete leftGoal;
    delete rightGoal;
}