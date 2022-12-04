#include "GoalSensor.h"
#include "EntityCategory.h"
#define FIELDHALFWIDTH 90
#define FIELDHEIGHT 60
#define GOALTOPHALFWIDTH 10
#define BALLRADIUS 5
#define mitadAltoParedesArco 8 //CAMBIAR ESTO


// float FIELDHALFWIDTH = ServerConfig::getFieldHalfWidth();
// float FIELDHEIGTH = ServerConfig::getFieldHeight();
// float GOALTOPHALFWIDTH = ServerConfig::getGoalTopHalfWidth();
// float BALLRADIUS = ServerConfig::getBallRadius();


GoalSensor::GoalSensor(SideOfGoal side, b2World& world) {
    this->side = side;
    this->goalBody = this->createBody(world);
    //this->goalBody = body;
    this->goalBody->SetUserData(this);
    this->goals = 0;
    this->goalScored = false;
}

b2Body* GoalSensor::createBody(b2World& world) {
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
    float sensorHalfHeight = (FIELDHEIGHT - mitadAltoParedesArco*2)/2;
    if (side == LEFT) {
        polygonShapeSensor.SetAsBox(sensorHalfWidht, sensorHalfHeight, b2Vec2(-FIELDHALFWIDTH + sensorHalfWidht,  FIELDHEIGHT/2), 0);
    } else if (side == RIGHT) {
        polygonShapeSensor.SetAsBox(sensorHalfWidht, sensorHalfHeight, b2Vec2(FIELDHALFWIDTH - sensorHalfWidht, FIELDHEIGHT/2), 0);
    }
    body->CreateFixture(&sensorFixture);
    return body;
}

GoalSensor::GoalSensor() {
}

SideOfGoal GoalSensor::getSideOfGoal() {
    return side;
}

b2Body* GoalSensor::getGoalBody() {
    return goalBody;
}

int GoalSensor::getGoals() {
    return goals;
}

void GoalSensor::scoreGoal() {
    goalScored = true;
    goals++;
}

bool GoalSensor::getGoalScored(){
    return this->goalScored;
}

void GoalSensor::setGoalScored(bool set) {
    this->goalScored = set;
}