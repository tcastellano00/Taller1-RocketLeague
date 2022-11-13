// #include "Physics.h"
// #include "Car.h"

// Physics::Physics(int numberOfPlayers){

//     CarPhisics car(b2World);


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