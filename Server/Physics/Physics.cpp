#include "Physics.h"
#include "Car.h"
#include <iostream>
#include <string>

#include "../../libs/Box2D/Box2D.h"

Physics::Physics(int numPlayers): world(b2Vec2(0.0f, -10.0f)){

    numberOfPlayers = numPlayers;
    timeStep = 1.0f / 60.0f;
    velocityIterations = 6;
    positionIterations = 2;

    this->createGround();
    this->createCars();


    

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

void Physics::simulateTimeStep(){
    world.Step(this->timeStep,this->velocityIterations,this->positionIterations);
}

void Physics::createCars() {
    b2BodyDef carBodyDef;
    carBodyDef.type = b2_dynamicBody;
    carBodyDef.position.Set(0.0f, 4.0f);
    this->car = world.CreateBody(&carBodyDef);
    
    //Textures
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    this->car->CreateFixture(&fixtureDef);
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

void Physics::moveCarRight() {
    //std::cout << "Physics::moveRight" << std::endl;
    //std::cout << "x: " << std::to_string(car->GetPosition().x) << " y: " << std::to_string(car->GetPosition().y)  << std::endl;

    car->SetTransform(
        b2Vec2(car->GetPosition().x + 1, car->GetPosition().y), car->GetAngle()
    );
    
    //b2Vec2 vel = car->GetLinearVelocity();
    //float force = 0;
    //if ( vel.x <  5 ) force =  50;
    //car->ApplyForce(b2Vec2(force,0), car->GetWorldCenter(), false);

    
    //std::cout << "x: " << std::to_string(car->GetPosition().x) << " y: " << std::to_string(car->GetPosition().y)  << std::endl; 
}

void Physics::moveCarLeft() {
    car->SetTransform(
        b2Vec2(car->GetPosition().x - 1, car->GetPosition().y), car->GetAngle()
    );
}

GameStatus Physics::getGameStus(){
    GameStatus newGameStatus;

    //std::cout << "Physics: getNameStatus" <<std::endl;

    b2Vec2 carCoord = car->GetPosition();
    float xCar = carCoord.x;
    float yCar = carCoord.y;

    PlayerModel pm(xCar, yCar, car->GetAngle(), false);
    newGameStatus.setPlayerModel(pm);

    //std::cout << "GetGameStatus x:" << std::to_string(newGameStatus.getPlayer().getCoordX()) << std::endl;
    //std::cout << "GetGameStatus y:"  << std::to_string(newGameStatus.getPlayer().getCoordY()) << std::endl;

    newGameStatus.identificador = "NASHEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE";
    
    return newGameStatus;
}