#include "BallPhysics.h"
#define REDSHOTIMPULSE 100000.0
#define GOLDSHOTIMPULSE 100000.0
#define PURPLESHOTIMPULSE 100000.0
#define FIELDHALFWIDTH 90
#define FIELDHEIGTH 60
#define CARFRICTION 1.5
#define SPECIALSHOTTIME 25
#define BALLRADIUS 5


// float REDSHOTIMPULSE = ServerConfig::getRedShotImpulse();
// float GOLDSHOTIMPULSE = ServerConfig::getGoldShotImpulse();
// float PURPLESHOTIMPULSE = ServerConfig::getPurpleShotImpulse();
// float FIELDHALFWIDTH = ServerConfig::getFieldHalfWidth();
// float FIELDHEIGTH = ServerConfig::getFieldHeight();
// float CARFRICTION = ServerConfig::getCarFriction();
// float SPECIALSHOTTIME = ServerConfig::getSpecialShotTime();
// float BALLRADIUS = ServerConfig::getBallRadius();


BallPhysics::BallPhysics(b2World &world) {
    
    this->ballBody = this->createBody(world);
    this->ballBody->SetUserData(this);
    //this->ballBody = body;
    this->shotType = NONE;
    this->specialShotTimer = 0;
}

 b2Body* BallPhysics::createBody(b2World& world){
    b2BodyDef ballBodyDef;
    ballBodyDef.type = b2_dynamicBody;
    ballBodyDef.position.Set(FIELDHALFWIDTH, FIELDHEIGTH/2);
    b2Body* ballBody = world.CreateBody(&ballBodyDef);

    //Textures
    b2CircleShape circleBall;
    circleBall.m_radius = BALLRADIUS;
    b2FixtureDef fixtureDef;
    fixtureDef.filter.categoryBits = BALL;
    fixtureDef.filter.maskBits = BOUNDARY | CAR | GOALSENSOR | CAR_FRONT_SENSOR | CAR_BOTTOM_SENSOR;
    fixtureDef.shape = &circleBall;
    fixtureDef.density = 0.000001f;
    fixtureDef.restitution = 0.9f;
    fixtureDef.friction = CARFRICTION;
    ballBody->CreateFixture(&fixtureDef);
    return ballBody;
 }


BallPhysics::BallPhysics() {}

b2Body* BallPhysics::getBody() {
    return this->ballBody;
}

void BallPhysics::redShot(int sideMultiplicator) {
    shotType = REDSHOT;
    generateImpulse(REDSHOTIMPULSE*sideMultiplicator);
}

void BallPhysics::goldShot(int sideMultiplicator) {
    shotType = GOLDSHOT;
    generateImpulse(GOLDSHOTIMPULSE*sideMultiplicator);
}

void BallPhysics::purpleShot(int sideMultiplicator) {
    shotType = PURPLESHOT;
    generateImpulse(PURPLESHOTIMPULSE*sideMultiplicator);
}

void BallPhysics::generateImpulse(float impulse) {
    this->ballBody->ApplyForceToCenter(b2Vec2(impulse,0),true);
    //this->ballBody->SetLinearVelocity(b2Vec2(impulse,0));
    //this->ballBody->ApplyLinearImpulse(b2Vec2(impulse, 0), this->ballBody->GetWorldCenter(), true);
}

SpecialShot BallPhysics::getShotType(){
    return this->shotType;
}

void BallPhysics::setShotType(SpecialShot type){
    this->shotType = type;
}

void BallPhysics::updateShotStatus() {
    if (this->shotType != NONE) {
        this->specialShotTimer += 1;
    }
    
    if (this->specialShotTimer > SPECIALSHOTTIME){
        this->shotType = NONE;
        this->specialShotTimer = 0;
    }
}

BallModel BallPhysics::getModel(){
    b2Vec2 ballCoord = this->ballBody->GetPosition();
    float ballCoordX = ballCoord.x - BALLRADIUS;
    float ballCoordY = ballCoord.y + BALLRADIUS;
    std::string colour;
    switch(this->getShotType()) {
        case NONE: {
            colour = "normal";
            break;
        }
        case REDSHOT: {
            colour = "red";
            break;
        }
        case GOLDSHOT: {
            colour = "gold";
            break;
        }
        case PURPLESHOT: {
            colour = "purple";
            break;
        }
    }

    BallModel bm(ballCoordX, ballCoordY, this->ballBody->GetAngle() * (-1), colour);
    return bm;

}