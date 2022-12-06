#include "SavingArea.h"
#include "EntityCategory.h"
#define mitadAltoParedesArco 8 //CAMBIAR ESTO




SavingArea::SavingArea(SavingAreaSide side, b2World& world) {
    this->side = side;
    this->goalBody = this->createBody(world);
    //this->goalBody = body;
    this->goalBody->SetUserData(this);
}

b2Body* SavingArea::createBody(b2World& world) {
    b2BodyDef goalBodyDef;
    goalBodyDef.type = b2_staticBody;
    goalBodyDef.position.Set(FIELDHALFWIDTH, 0);
    b2Body* body = world.CreateBody(&goalBodyDef);
    b2FixtureDef sensorFixture;
    b2PolygonShape polygonShapeSensor;
    sensorFixture.shape = &polygonShapeSensor;
    sensorFixture.isSensor = true;
    sensorFixture.filter.categoryBits = SAVING_AREA_SENSOR;
    sensorFixture.filter.maskBits = BALL;
    float areaSensorHalfWidht = GOALTOPHALFWIDTH;
    float areaSensorHalfHeight = GOALTOPHALFHEIGHT;
    if (side == LEFTAREA) {
        polygonShapeSensor.SetAsBox(areaSensorHalfWidht, areaSensorHalfHeight, b2Vec2(-FIELDHALFWIDTH + areaSensorHalfWidht*2,  FIELDHEIGHT/2), 0);
    } else if (side == RIGHTAREA) {
        polygonShapeSensor.SetAsBox(areaSensorHalfWidht, areaSensorHalfHeight, b2Vec2(FIELDHALFWIDTH - areaSensorHalfWidht*2, FIELDHEIGHT/2), 0);
    }
    body->CreateFixture(&sensorFixture);
    return body;
}

SavingAreaSide SavingArea::getSavingAreaSide() {
    return this->side;
}