#include "Box.h"

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

BoxPhysics::BoxPhysics(b2World &world){
    b2Body* box;
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
    box = world.CreateBody(&boxBodyDef);

    //add four walls to the static body
    polygonShape.SetAsBox( FIELDHALFWIDTH, WALLWIDTH, b2Vec2(0, WALLWIDTH*(-1)), 0);//ground
    box->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( FIELDHALFWIDTH, WALLWIDTH, b2Vec2(0, FIELDHEIGTH + WALLWIDTH), 0);//ceiling
    box->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( WALLWIDTH, FIELDHALFWIDTH, b2Vec2((FIELDHALFWIDTH + WALLWIDTH)*(-1), FIELDHEIGTH/2), 0);//left wall
    box->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( WALLWIDTH, FIELDHALFWIDTH, b2Vec2(FIELDHALFWIDTH + WALLWIDTH, FIELDHEIGTH/2), 0);//right wall
    box->CreateFixture(&myFixtureDef);



    polygonShape.SetAsBox( GOALTOPHALFWIDTH, mitadAltoParedesArco, b2Vec2(GOALTOPHALFWIDTH - FIELDHALFWIDTH,mitadAltoParedesArco), 0);//left goal down
    box->CreateFixture(&myFixtureDef);
    
    polygonShape.SetAsBox( GOALTOPHALFWIDTH, mitadAltoParedesArco, b2Vec2(GOALTOPHALFWIDTH - FIELDHALFWIDTH,FIELDHEIGTH - mitadAltoParedesArco), 0);//left goal down
    box->CreateFixture(&myFixtureDef);

    polygonShape.SetAsBox( GOALTOPHALFWIDTH, mitadAltoParedesArco, b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH, mitadAltoParedesArco), 0);//right goal down
    box->CreateFixture(&myFixtureDef);
    
    polygonShape.SetAsBox( GOALTOPHALFWIDTH, mitadAltoParedesArco, b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH, FIELDHEIGTH - mitadAltoParedesArco), 0);//right goal up
    box->CreateFixture(&myFixtureDef);


     //Rampas
    b2ChainShape chain;

    //Rampa arco inferior izquierdo
    b2Vec2 surface[17];
    
    surface[0] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2     ,  CHAINSTARTHEIGHT  );
    surface[1] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +0.5,  CHAINSTARTHEIGHT -1.7 );
    surface[2] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +1  ,  CHAINSTARTHEIGHT -2.8 );
    surface[3] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +2  ,  CHAINSTARTHEIGHT -3.9);
    surface[4] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +3  ,  CHAINSTARTHEIGHT -4.9 );
    surface[5] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +4  ,  CHAINSTARTHEIGHT -5.7 );
    surface[6] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +5  ,  CHAINSTARTHEIGHT -6.5 );
    surface[7] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +6  ,  CHAINSTARTHEIGHT -7.3 );
    surface[8] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +7  ,  CHAINSTARTHEIGHT -7.9 );
    surface[9] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +8  ,  CHAINSTARTHEIGHT -8.5 );
    surface[10] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +9  ,  CHAINSTARTHEIGHT -9.0 );
    surface[11] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +10  ,  CHAINSTARTHEIGHT -9.4 );
    surface[12] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +11 ,  CHAINSTARTHEIGHT -9.8 );
    surface[13] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +12 ,  CHAINSTARTHEIGHT -10.2 );
    surface[14] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +13 ,  CHAINSTARTHEIGHT -10.6 );
    surface[15] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +14 ,  CHAINSTARTHEIGHT -10.9 );
    surface[16] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +15  ,  CHAINSTARTHEIGHT - 11);
    
    chain.CreateChain(surface, 17);
    box->CreateFixture(&chain,1);
}