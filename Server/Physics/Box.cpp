#include "Box.h"

// #define MOVEMENTFORCE 500


#define mitadAltoParedesArco 8 //CAMBIAR ESTO

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
    polygonShape.SetAsBox( FIELDHALFWIDTH, WALLWIDTH, b2Vec2(0, FIELDHEIGHT + WALLWIDTH), 0);//ceiling
    box->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( WALLWIDTH, FIELDHALFWIDTH, b2Vec2((FIELDHALFWIDTH + WALLWIDTH)*(-1), FIELDHEIGHT/2), 0);//left wall
    box->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( WALLWIDTH, FIELDHALFWIDTH, b2Vec2(FIELDHALFWIDTH + WALLWIDTH, FIELDHEIGHT/2), 0);//right wall
    box->CreateFixture(&myFixtureDef);



    polygonShape.SetAsBox( GOALTOPHALFWIDTH, mitadAltoParedesArco, b2Vec2(GOALTOPHALFWIDTH - FIELDHALFWIDTH,mitadAltoParedesArco), 0);//left goal down
    box->CreateFixture(&myFixtureDef);
    
    polygonShape.SetAsBox( GOALTOPHALFWIDTH, mitadAltoParedesArco, b2Vec2(GOALTOPHALFWIDTH - FIELDHALFWIDTH,FIELDHEIGHT - mitadAltoParedesArco), 0);//left goal down
    box->CreateFixture(&myFixtureDef);

    polygonShape.SetAsBox( GOALTOPHALFWIDTH, mitadAltoParedesArco, b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH, mitadAltoParedesArco), 0);//right goal down
    box->CreateFixture(&myFixtureDef);
    
    polygonShape.SetAsBox( GOALTOPHALFWIDTH, mitadAltoParedesArco, b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH, FIELDHEIGHT - mitadAltoParedesArco), 0);//right goal up
    box->CreateFixture(&myFixtureDef);


     //Rampas

    b2FixtureDef myFixtureDef2;

    //Rampa arco inferior izquierdo
    b2ChainShape chain;
    b2Vec2 surface[21];
    
    surface[0] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2     ,  mitadAltoParedesArco*2  );
    surface[1] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +0.2    ,  mitadAltoParedesArco*2 -1 );
    surface[2] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +0.5  ,  mitadAltoParedesArco*2 -2 );
    surface[3] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +1  ,  mitadAltoParedesArco*2 -4);
    surface[4] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +1.5  ,  mitadAltoParedesArco*2 -5 );
    surface[5] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +2.0  ,  mitadAltoParedesArco*2 -6 );
    surface[6] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +3  ,  mitadAltoParedesArco*2 -7.5 );
    surface[7] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +4  ,  mitadAltoParedesArco*2 -9.0 );
    surface[8] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +5  ,  mitadAltoParedesArco*2 -10.5 );
    surface[9] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +6  ,  mitadAltoParedesArco*2 -11.5 );
    surface[10] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +7  ,  mitadAltoParedesArco*2 -12.3 );
    surface[11] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +8.0  ,  mitadAltoParedesArco*2 -13.2 );
    surface[12] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +9.5 ,  mitadAltoParedesArco*2 -13.9 );
    surface[13] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +11 ,  mitadAltoParedesArco*2 -14.4 );
    surface[14] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +13 ,  mitadAltoParedesArco*2 -14.8 );
    surface[15] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +14 ,  mitadAltoParedesArco*2 -15.0 );
    surface[16] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +16  ,  mitadAltoParedesArco*2 - 15.3);
    surface[17] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +17  ,  mitadAltoParedesArco*2 - 15.5);
    surface[18] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +18  ,  mitadAltoParedesArco*2 - 15.7);
    surface[19] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +19  ,  mitadAltoParedesArco*2 - 15.9);
    surface[20] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +20  ,  mitadAltoParedesArco*2 - 16);
    
    chain.CreateChain(surface, 21);

    myFixtureDef2.shape = &chain;
    myFixtureDef2.filter.categoryBits = CORNER;
    myFixtureDef2.filter.maskBits = CAR | BALL;


    box->CreateFixture(&myFixtureDef2);



    //Rampa arco inferior derecho
    b2ChainShape chain2;
    b2Vec2 surface2[21];
    
    surface2[0] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2    ,  mitadAltoParedesArco*2  );
    surface2[1] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -0.2    ,  mitadAltoParedesArco*2 -1 );
    surface2[2] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -0.5  ,  mitadAltoParedesArco*2 -2 );
    surface2[3] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -1  ,  mitadAltoParedesArco*2 -4);
    surface2[4] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -1.5  ,  mitadAltoParedesArco*2 -5 );
    surface2[5] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -2.0  ,  mitadAltoParedesArco*2 -6 );
    surface2[6] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -3  ,  mitadAltoParedesArco*2 -7.5 );
    surface2[7] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -4  ,  mitadAltoParedesArco*2 -9.0 );
    surface2[8] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -5  ,  mitadAltoParedesArco*2 -10.5 );
    surface2[9] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -6  ,  mitadAltoParedesArco*2 -11.5 );
    surface2[10] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -7  ,  mitadAltoParedesArco*2 -12.3 );
    surface2[11] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -8.0  ,  mitadAltoParedesArco*2 -13.2 );
    surface2[12] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -9.5 ,  mitadAltoParedesArco*2 -13.9 );
    surface2[13] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -11 ,  mitadAltoParedesArco*2 -14.4 );
    surface2[14] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -13 ,  mitadAltoParedesArco*2 -14.8 );
    surface2[15] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -14 ,  mitadAltoParedesArco*2 -15.0 );
    surface2[16] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -16  ,  mitadAltoParedesArco*2 - 15.3);
    surface2[17] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -17  ,  mitadAltoParedesArco*2 - 15.5);
    surface2[18] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -18  ,  mitadAltoParedesArco*2 - 15.7);
    surface2[19] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -19  ,  mitadAltoParedesArco*2 - 15.9);
    surface2[20] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -20  ,  mitadAltoParedesArco*2 - 16);

    chain2.CreateChain(surface2, 21);

    myFixtureDef2.shape = &chain2;

    box->CreateFixture(&myFixtureDef2);

    //Rampa arco superior izquierdo
    b2ChainShape chain3;
    b2Vec2 surface3[21];
    
    surface3[0] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2   ,  FIELDHEIGHT - mitadAltoParedesArco*2  );
    surface3[1] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +0.2    , FIELDHEIGHT - mitadAltoParedesArco*2 + 1 );
    surface3[2] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +0.5  , FIELDHEIGHT - mitadAltoParedesArco*2 + 2 );
    surface3[3] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +1  , FIELDHEIGHT - mitadAltoParedesArco*2 + 4);
    surface3[4] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +1.5  , FIELDHEIGHT - mitadAltoParedesArco*2 + 5 );
    surface3[5] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +2.0  , FIELDHEIGHT - mitadAltoParedesArco*2 + 6 );
    surface3[6] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +3  , FIELDHEIGHT - mitadAltoParedesArco*2 + 7.5 );
    surface3[7] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +4  , FIELDHEIGHT - mitadAltoParedesArco*2 + 9.0 );
    surface3[8] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +5  , FIELDHEIGHT - mitadAltoParedesArco*2 + 10.5 );
    surface3[9] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +6  , FIELDHEIGHT - mitadAltoParedesArco*2 + 11.5 );
    surface3[10] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +7  , FIELDHEIGHT - mitadAltoParedesArco*2 + 12.3 );
    surface3[11] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +8.0  , FIELDHEIGHT - mitadAltoParedesArco*2 + 13.2 );
    surface3[12] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +9.5 , FIELDHEIGHT - mitadAltoParedesArco*2 + 13.9 );
    surface3[13] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +11 , FIELDHEIGHT - mitadAltoParedesArco*2 + 14.4 );
    surface3[14] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +13 , FIELDHEIGHT - mitadAltoParedesArco*2 + 14.8 );
    surface3[15] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +14 , FIELDHEIGHT - mitadAltoParedesArco*2 + 15.0 );
    surface3[16] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +16  , FIELDHEIGHT - mitadAltoParedesArco*2 +  15.3);
    surface3[17] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +17  , FIELDHEIGHT - mitadAltoParedesArco*2 +  15.5);
    surface3[18] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +18  , FIELDHEIGHT - mitadAltoParedesArco*2 +  15.7);
    surface3[19] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +19  , FIELDHEIGHT - mitadAltoParedesArco*2 +  15.9);
    surface3[20] = b2Vec2(-FIELDHALFWIDTH + GOALTOPHALFWIDTH*2 +20  , FIELDHEIGHT - mitadAltoParedesArco*2 +  16);
    
    chain3.CreateChain(surface3, 21);

    myFixtureDef2.shape = &chain3;
    box->CreateFixture(&myFixtureDef2);

    //Rampa arco superior derecho
    b2ChainShape chain4;
    b2Vec2 surface4[21];
    
    surface4[0] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2    ,  FIELDHEIGHT - mitadAltoParedesArco*2  );
    surface4[1] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -0.2    , FIELDHEIGHT - mitadAltoParedesArco*2 + 1 );
    surface4[2] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -0.5  , FIELDHEIGHT - mitadAltoParedesArco*2 + 2 );
    surface4[3] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -1  , FIELDHEIGHT - mitadAltoParedesArco*2 + 4);
    surface4[4] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -1.5  , FIELDHEIGHT - mitadAltoParedesArco*2 + 5 );
    surface4[5] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -2.0  , FIELDHEIGHT - mitadAltoParedesArco*2 + 6 );
    surface4[6] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -3  , FIELDHEIGHT - mitadAltoParedesArco*2 + 7.5 );
    surface4[7] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -4  , FIELDHEIGHT - mitadAltoParedesArco*2 + 9.0 );
    surface4[8] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -5  , FIELDHEIGHT - mitadAltoParedesArco*2 + 10.5 );
    surface4[9] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -6  , FIELDHEIGHT - mitadAltoParedesArco*2 + 11.5 );
    surface4[10] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -7  , FIELDHEIGHT - mitadAltoParedesArco*2 + 12.3 );
    surface4[11] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -8.0  , FIELDHEIGHT - mitadAltoParedesArco*2 + 13.2 );
    surface4[12] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -9.5 , FIELDHEIGHT - mitadAltoParedesArco*2 + 13.9 );
    surface4[13] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -11 , FIELDHEIGHT - mitadAltoParedesArco*2 + 14.4 );
    surface4[14] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -13 , FIELDHEIGHT - mitadAltoParedesArco*2 + 14.8 );
    surface4[15] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -14 , FIELDHEIGHT - mitadAltoParedesArco*2 + 15.0 );
    surface4[16] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -16  , FIELDHEIGHT - mitadAltoParedesArco*2 +  15.3);
    surface4[17] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -17  , FIELDHEIGHT - mitadAltoParedesArco*2 +  15.5);
    surface4[18] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -18  , FIELDHEIGHT - mitadAltoParedesArco*2 +  15.7);
    surface4[19] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -19  , FIELDHEIGHT - mitadAltoParedesArco*2 +  15.9);
    surface4[20] = b2Vec2(FIELDHALFWIDTH - GOALTOPHALFWIDTH*2 -20  , FIELDHEIGHT - mitadAltoParedesArco*2 +  16);
    
    chain4.CreateChain(surface4, 21);

    myFixtureDef2.shape = &chain4;
    box->CreateFixture(&myFixtureDef2);

}
