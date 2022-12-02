#include "Car.h"
#include <cmath>
#include "EntityCategory.h"
#define FLIPIMPULSE 3000
#define PI  3.14159265358979323846
#define FLIPANGULARVEL PI*2
#define MAXTURBO 50 //dos segundos de turbo

#define FIELDHALFWIDTH 90
#define FIELDHEIGTH 60
#define CARHALFWIDTH 7.5
#define CARHALFHEIGHT 2
#define FRONTSENSORHALFWIDTH 5.0
#define BOTTOMSENSORHALFHEIGTH 5.0
#define CARFRICTION 1.5


CarPhysics::CarPhysics(b2World& world, int numberOfCar){

    if (numberOfCar == 0 || numberOfCar == 2) {
        this->side = LEFTPLAYER;
    } else {
        this->side = RIGHTPLAYER;
    }

    this->carBody = this->createBody(world, numberOfCar);
    this->carBody->SetUserData(this);
    this->facingStatus = FACINGFRONT;
    this->airStatus = AIR;
    this->isDoingTurbo = false;
    this->acceleratingStatus = NOTACCELERATING;
    this->sensorStatus = NOTSENSOR;
    this->isFliping = false;
    this->flipStartAngle = 0;
    this->turboRemaining = MAXTURBO;

    
}

b2Body* CarPhysics::createBody(b2World& world, int numberOfCar) {
    b2BodyDef carBodyDef;
    carBodyDef.type = b2_dynamicBody;
    if (numberOfCar == 0) {carBodyDef.position.Set(FIELDHALFWIDTH/2, FIELDHEIGTH/2);}
    if (numberOfCar == 1) {carBodyDef.position.Set(3*FIELDHALFWIDTH/2, FIELDHEIGTH/2);}
    if (numberOfCar == 2) {carBodyDef.position.Set(FIELDHALFWIDTH/3, FIELDHEIGTH/2);}
    if (numberOfCar == 3) {carBodyDef.position.Set(5*FIELDHALFWIDTH/3, FIELDHEIGTH/2);}
    b2Body* car = world.CreateBody(&carBodyDef);

    //Textures
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(CARHALFWIDTH, CARHALFHEIGHT);
    b2FixtureDef fixtureDef;
    fixtureDef.filter.categoryBits = CAR;
    fixtureDef.filter.maskBits = BOUNDARY | BALL;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 0.15f;
    fixtureDef.friction = CARFRICTION;
    car->CreateFixture(&fixtureDef);
    
    
    //Sensor de la trompa del auto
    b2FixtureDef sensorCarFront;
    b2PolygonShape polygonShapeSensor;
    sensorCarFront.shape = &polygonShapeSensor;
    sensorCarFront.isSensor = true;
    sensorCarFront.filter.categoryBits = CAR_FRONT_SENSOR;
    sensorCarFront.filter.maskBits = BALL;
    float frontSensorHalfHeight = CARHALFHEIGHT;
    float frontSensorHalfWidth = FRONTSENSORHALFWIDTH;

    if (numberOfCar == 0 || numberOfCar == 2) {
        polygonShapeSensor.SetAsBox(frontSensorHalfWidth, frontSensorHalfHeight, b2Vec2(CARHALFWIDTH + frontSensorHalfWidth, 0), 0);

    }else{
        polygonShapeSensor.SetAsBox(frontSensorHalfWidth, frontSensorHalfHeight, b2Vec2((-1)*CARHALFWIDTH + frontSensorHalfWidth*(-1), 0), 0);
    }

    car->CreateFixture(&sensorCarFront);

     //Sensor de la parte de abajo del auto
    b2FixtureDef sensorBottomFront;
    b2PolygonShape polygonShapeSensor1;
    sensorBottomFront.shape = &polygonShapeSensor1;
    sensorBottomFront.isSensor = true;
    sensorBottomFront.filter.categoryBits = CAR_BOTTOM_SENSOR;
    sensorBottomFront.filter.maskBits = BALL;
    float bottomsensorHalfWidht = CARHALFWIDTH;
    float bottomsensorHalfHeight = BOTTOMSENSORHALFHEIGTH;

    polygonShapeSensor1.SetAsBox(bottomsensorHalfWidht, bottomsensorHalfHeight,
     b2Vec2(0,CARHALFHEIGHT*(-1) + bottomsensorHalfHeight * (-1)), 0);

    car->CreateFixture(&sensorBottomFront);

    return car;
}

CarPhysics::CarPhysics() {}

b2Body* CarPhysics::getCarBody() {
    return this->carBody;
}

void CarPhysics::landed() {
    this->airStatus = GROUND;
}

void CarPhysics::jumpedFromTheFloor() {
    this->airStatus = AIR;
}

AirStatus CarPhysics::getAirStatus() {
    return this->airStatus;
}

void CarPhysics::setAirStatus(AirStatus status) {
    this->airStatus = status;
}

FacingStatus CarPhysics::getFacingStatus() {
    return this->facingStatus;
}

void CarPhysics::setSensorStatus(SensorStatus status) {
    this->sensorStatus = status;
}

SensorStatus CarPhysics::getSensorStatus() {
    return this->sensorStatus;
}

PlayerSide CarPhysics::getSide() {
    return side;
}

void CarPhysics::setFacingStatus(FacingStatus status) {
    this->facingStatus = status;
}

void CarPhysics::setDoingTurbo(bool doing) {
    this->isDoingTurbo = doing;
}

bool CarPhysics::getDoingTurbo() {
    return this->isDoingTurbo;
}

void CarPhysics::setAcceleratingStatus(AcceleratingStatus status) {
    this->acceleratingStatus = status;
}

AcceleratingStatus CarPhysics::getAcceleratingStatus() {
    return this->acceleratingStatus;
}

void CarPhysics::flipJump() {
    if (this->acceleratingStatus == ACCELERATINGRIGHT) {
        this->carBody->ApplyLinearImpulse(b2Vec2(FLIPIMPULSE, 0), this->carBody->GetWorldCenter(), true);
        this->carBody->SetAngularVelocity(FLIPANGULARVEL * (-1));

    } else {
        this->carBody->ApplyLinearImpulse(b2Vec2(FLIPIMPULSE*(-1), 0), this->carBody->GetWorldCenter(), true);
        this->carBody->SetAngularVelocity(FLIPANGULARVEL);
    }
    this->isFliping = true;
    this->flipStartAngle = carBody->GetAngle(); 
    
}

void CarPhysics::swapFrontBackSensor() {
    if (this->sensorStatus == BALLINBACKSENSOR){
        this->sensorStatus = BALLINFRONTSENSOR;
    } else if (this->sensorStatus == BALLINFRONTSENSOR) {
        this->sensorStatus = BALLINBACKSENSOR;
    }
}

void CarPhysics::updateFlipStatus() {
    if (this->isFliping && abs(this->carBody->GetAngle() - this->flipStartAngle) >= 2*PI) {
        this->isFliping = false;
        this->flipStartAngle = 0;
        this->carBody->SetAngularVelocity(0);
    }
}

void CarPhysics::loseTurbo() {
    if (this->turboRemaining > 0) {
        this->turboRemaining -= 1;
    }
}

void CarPhysics::fillTurbo() {
    if (this->turboRemaining < MAXTURBO) {
        this->turboRemaining += 1;
    }
}

bool CarPhysics::canUseTurbo() {
    return this->turboRemaining != 0;
}

int CarPhysics::getTurbo() {
    return this->turboRemaining;
}