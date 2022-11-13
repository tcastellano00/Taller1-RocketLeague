// #include "Car.h"

// CarPhisics::CarPhisics(b2World * &m_world): m_world(m_world){

//     b2BodyDef car;
//     car.type = b2_dynamicBody; //this will be a dynamic body
//     car.position.Set(0, 20); //set the starting position
//     car.angle = 0; //set the starting angle

//     b2Body* dynamicBody = m_world->CreateBody(&car);
    
//     //prepare a shape definition
//     b2PolygonShape polygonShape;
//     b2FixtureDef myFixtureDef;
//     b2CircleShape circleShape;
//     myFixtureDef.shape = &polygonShape;
//     myFixtureDef.density = 1;
    
//     //add four square shaped fixtures around the body center
//     polygonShape.SetAsBox(2, 1, {0,0}, 0 ); //a 2x2 rectangle
//     dynamicBody->CreateFixture(&myFixtureDef); //add a fixture to the body

//     myFixtureDef.shape = &circleShape;
//     myFixtureDef.density = 1;

//     //No supe como ubicar el circulo.
//     dynamicBody->CreateFixture(&myFixtureDef); //add a fixture to the body
// }