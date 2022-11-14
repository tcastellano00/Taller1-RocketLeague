#include "Physics.h"
#include "Car.h"

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


}

void Physics::moveCarLeft() {
    
}

GameStatus Physics::getGameStus(){
    GameStatus newGameStatus;

    b2Vec2 carCoord = car->GetPosition();
    float xCar = carCoord.x;
    float yCar = carCoord.y;


    PlayerModel pm(xCar, yCar, car->GetAngle(), false);
    newGameStatus.setPlayerModel(pm);

    return newGameStatus;

}








































//     // iterar hasta el numero de jugadores e instanciar X jugadores?
//     b2BodyDef player1;
//     player1.type = b2_dynamicBody; //this will be a dynamic body
//     player1.position.Set(0, 20); //set the starting position
//     player1.angle = 0; //set the starting angle


//     b2BodyDef player2;
//     player2.type = b2_dynamicBody; //this will be a dynamic body
//     player2.position.Set(0, 20); //set the starting position
//     player2.angle = 0; //set the starting angle


//     b2BodyDef bow1;
//     bow1.type = b2_staticBody; //this will be a dynamic body
//     bow1.position.Set(0, 20); //set the starting position
//     bow1.angle = 0; //set the starting angle


//     b2BodyDef bow2;
//     bow2.type = b2_staticBody; //this will be a dynamic body
//     bow2.position.Set(0, 20); //set the starting position
//     bow2.angle = 0; //set the starting angle

//     b2Body* bodyPlayer1 = m_world->CreateBody(&player1);
//     b2Body* bodyPlayer2 = m_world->CreateBody(&player2);
//     b2Body* bodyBow1 = m_world->CreateBody(&bow1);
//     b2Body* bodyBow2 = m_world->CreateBody(&bow2);


//     b2PolygonShape boxShape;
//     boxShape.SetAsBox(1,1);

//     b2FixtureDef boxFixtureDef;                     //La forma que tiene cada objeto
//     boxFixtureDef.shape = &boxShape;
//     boxFixtureDef.density = 1;
//     bodyPlayer1->CreateFixture(&boxFixtureDef);


//     //Piso donde se appoyan los jugadores

//     b2PolygonShape polygonShape;
//     b2FixtureDef myFixtureDef;
//     b2BodyDef myBodyDef;
//     myBodyDef.type = b2_staticBody;
//     myBodyDef.position.Set(0,0);

//     b2EdgeShape edgeShape;
//     edgeShape.Set( b2Vec2(-15,0), b2Vec2(15,0) );
//     myFixtureDef.shape = &edgeShape;

//     b2Body* staticBody = m_world->CreateBody(&myBodyDef);
//     staticBody->CreateFixture(&myFixtureDef);

// }