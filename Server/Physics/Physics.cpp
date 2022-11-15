#include "Physics.h"
#include "Car.h"
#include <iostream>
#include <string>

#include "../../libs/Box2D/Box2D.h"

Physics::Physics(std::list<ClientConnection>& connections): world(b2Vec2(0.0f, -10.0f)){

    numberOfPlayers = connections.size();
    timeStep = 1.0f / 60.0f;
    velocityIterations = 6;
    positionIterations = 2;

    int numberOfCar = 0;
    for (auto connection = connections.begin(); connection != connections.end(); ++connection) {
        int sktId = (*connection).getId();
        cars[sktId] = createCar(numberOfCar);
        numberOfCar++;
    }



    this->createGround();
    //this->createBox();
    //this->createCars();


    

    //CarPhisics car(b2World);


    //Simulado del tiempo:

    //float timeStep = 1.0f / 60.0f;
    //int32 velocityIterations = 6;
    //int32 positionIterations = 2;
    //b2World::Step 
    //Abajo como esta definido 
    // void b2World::Step 	( 	float  	timeStep,
	// 	int32  	velocityIterations,
	// 	int32  	positionIterations 
	// ) 	


}

void Physics::createBox(){
    b2BodyDef boxBodyDef;

    b2PolygonShape polygonShape;
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &polygonShape;
    myFixtureDef.density = 1;

    boxBodyDef.type = b2_staticBody;
    boxBodyDef.position.Set(25, 25);
    this->box = world.CreateBody(&boxBodyDef);
    
    //add four walls to the static body
    polygonShape.SetAsBox( 25, 1, b2Vec2(25, 50), 0);//ground
    this->box->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( 25, 1, b2Vec2(0, 50), 0);//ceiling
    this->box->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( 1, 25, b2Vec2(0, 25), 0);//left wall
    this->box->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( 1, 25, b2Vec2(50, 25), 0);//right wall
    this->box->CreateFixture(&myFixtureDef);
}

void Physics::simulateTimeStep(){
    world.Step(this->timeStep,this->velocityIterations,this->positionIterations);
}

b2Body* Physics::createCar(int numberOfCar) {
    b2BodyDef carBodyDef;
    carBodyDef.type = b2_dynamicBody;
    if (numberOfCar == 0) {carBodyDef.position.Set(2.0f, 4.0f);}
    if (numberOfCar == 1) {carBodyDef.position.Set(48.0f, 4.0f);}
    b2Body* car = world.CreateBody(&carBodyDef);
    
    //Textures
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
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
    //std::cout << "Physics::moveRight" << std::endl;
    //std::cout << "x: " << std::to_string(car->GetPosition().x) << " y: " << std::to_string(car->GetPosition().y)  << std::endl;

    b2Body* car = (this->cars[socketId]);
    car->SetTransform(
        b2Vec2(car->GetPosition().x + 1, car->GetPosition().y), car->GetAngle()
    );
    
    //b2Vec2 vel = car->GetLinearVelocity();
    //float force = 0;
    //if ( vel.x <  5 ) force =  50;
    //car->ApplyForce(b2Vec2(force,0), car->GetWorldCenter(), false);

    
    //std::cout << "x: " << std::to_string(car->GetPosition().x) << " y: " << std::to_string(car->GetPosition().y)  << std::endl; 
}

void Physics::moveCarLeft(int socketId) {
    b2Body* car = (this->cars[socketId]);
    car->SetTransform(
        b2Vec2(car->GetPosition().x - 1, car->GetPosition().y), car->GetAngle()
    );
}

GameStatus Physics::getGameStus(){
    GameStatus newGameStatus;

    //std::cout << "Physics: getNameStatus" <<std::endl;

    /*b2Vec2 carCoord = car->GetPosition();
    float xCar = carCoord.x;
    float yCar = carCoord.y;

    PlayerModel pm(xCar, yCar, car->GetAngle(), false);
    newGameStatus.setPlayerModel(pm);
    */

    std::list<PlayerModel> playerModels;
    for (std::map<int, b2Body*>::iterator it = this->cars.begin(); it != this->cars.end(); ++it) {
        b2Vec2 carCoord = it->second->GetPosition();
        float xCar = carCoord.x;
        float yCar = carCoord.y;
        PlayerModel pm(xCar, yCar, it->second->GetAngle(), false);
        playerModels.push_back(pm);
    }
    newGameStatus.setPlayersModels(playerModels);


    //std::cout << "GetGameStatus x:" << std::to_string(newGameStatus.getPlayer().getCoordX()) << std::endl;
    //std::cout << "GetGameStatus y:"  << std::to_string(newGameStatus.getPlayer().getCoordY()) << std::endl;

    //newGameStatus.identificador = "NASHEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE";
    
    return newGameStatus;
}