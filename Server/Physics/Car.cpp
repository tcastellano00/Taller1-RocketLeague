#include "Car.h"
#include <cmath>
#include "EntityCategory.h"
#include <iostream>


CarPhysics::CarPhysics(int cltId,b2World& world, int numberOfCar){
    this->clientId = cltId;
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
    if (numberOfCar == 0) {carBodyDef.position.Set(FIELDHALFWIDTH/2, FIELDHEIGHT/2);}
    if (numberOfCar == 1) {carBodyDef.position.Set(3*FIELDHALFWIDTH/2, FIELDHEIGHT/2);}
    if (numberOfCar == 2) {carBodyDef.position.Set(FIELDHALFWIDTH/3, FIELDHEIGHT/2);}
    if (numberOfCar == 3) {carBodyDef.position.Set(5*FIELDHALFWIDTH/3, FIELDHEIGHT/2);}
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

void CarPhysics::jumpFromGround() {
    b2Body* carBody = this->getCarBody();
    b2Vec2 vel = carBody->GetLinearVelocity();
    float desiredVel = JUMPIMPULSE;
    float velChange = desiredVel - vel.y;
    float impulse = carBody->GetMass() * velChange; //disregard time factor
    carBody->ApplyLinearImpulse( b2Vec2(0, impulse), carBody->GetWorldCenter(), true);
}

void CarPhysics::swapFrontBackSensor() {
    if (this->sensorStatus == BALLINBACKSENSOR){
        this->sensorStatus = BALLINFRONTSENSOR;
    } else if (this->sensorStatus == BALLINFRONTSENSOR) {
        this->sensorStatus = BALLINBACKSENSOR;
    }
}

void CarPhysics::swapFacingStatus() {
    if (this->facingStatus == FACINGFRONT) {
        this->facingStatus = FACINGBACK;
    } else {
        this->facingStatus = FACINGFRONT;
    }
}

void CarPhysics::swapAcceleratingStatus() {
    if (this->acceleratingStatus == ACCELERATINGLEFT) {
        this->acceleratingStatus = ACCELERATINGRIGHT;
    } else if (this->acceleratingStatus == ACCELERATINGRIGHT) {
        this->acceleratingStatus = ACCELERATINGLEFT;
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

void CarPhysics::startAcceleratingForward() {
    if ((this->side == LEFTPLAYER && this->facingStatus == FACINGFRONT) ||
        (this->side == RIGHTPLAYER && this->facingStatus == FACINGBACK) ) {
        this->acceleratingStatus = ACCELERATINGRIGHT;
    } else {
        this->acceleratingStatus = ACCELERATINGLEFT;
    }
}

void CarPhysics::startAcceleratingBackwards() {
    if ((this->side == LEFTPLAYER && this->facingStatus == FACINGFRONT) ||
        (this->side == RIGHTPLAYER && this->facingStatus == FACINGBACK) ) {
        this->acceleratingStatus = ACCELERATINGLEFT;
    } else {
        this->acceleratingStatus = ACCELERATINGRIGHT;
    }
}

void CarPhysics::stopAccelerating() {
    this->acceleratingStatus = NOTACCELERATING;
}

void CarPhysics::applyAcceleration() {
    if (this->acceleratingStatus == NOTACCELERATING) {
        return;
    }
    float32 xForce;
    float32 yForce;
    float force = MOVEMENTFORCE;

    /*if (this->airStatus != GROUND) {
        force /= 10;
    }*/

    float angle = this->carBody->GetAngle();
    xForce = std::cos(angle)*force;
    yForce = std::sin(angle)*force;

    if (this->acceleratingStatus == ACCELERATINGLEFT) {
        xForce *= -1;
        yForce *= -1;
    }
    carBody->ApplyForceToCenter(b2Vec2(xForce, yForce), true);
}

void CarPhysics::turn() {
    this->swapFrontBackSensor();
    this->swapFacingStatus();
    this->swapAcceleratingStatus();
}

bool CarPhysics::jump(BallPhysics* ball) {

    if (airStatus == AIRAFTERFLIP){
        return false;
    }
    int sideMultiplicator = (this->side == LEFTPLAYER) ? 1 : -1;


    if (sensorStatus == BALLINBACKSENSOR && airStatus == AIR && acceleratingStatus != NOTACCELERATING) {
        ball->goldShot(sideMultiplicator);
        this->flipJump();
    } else if (sensorStatus == BALLINFRONTSENSOR && airStatus == AIR && acceleratingStatus != NOTACCELERATING) {
        ball->redShot(sideMultiplicator);
        this->flipJump();
    } else if (sensorStatus == BALLINBOTTOMSENSOR) {
        ball->purpleShot(sideMultiplicator);
        this->getCarBody()->ApplyLinearImpulse(b2Vec2(-3000*sideMultiplicator,0),this->getCarBody()->GetWorldCenter(), true);
    } else if (acceleratingStatus != NOTACCELERATING && airStatus == AIR ){
        this->flipJump();
    } else {
        this->jumpFromGround();
    }
    
    if (airStatus == AIR) {
        this->setAirStatus(AIRAFTERFLIP);
    }
    return true;
}

 void CarPhysics::rotate(int sideMultiplicator) {
    this->carBody->SetAngularVelocity(ROTATIONANGULARVELOCITY*sideMultiplicator);
 }

  void CarPhysics::stopRotate() {
    this->carBody->SetAngularVelocity(0);
 }

 void CarPhysics::startDoingTurbo(){
    this->isDoingTurbo = true;
 }

 void CarPhysics::stopDoingTurbo(){
    this->isDoingTurbo = false;
 }

 void CarPhysics::applyTurbo(){

    if (!this->isDoingTurbo) {
        return;
    }

    if (!this->canUseTurbo()) {
        this->setDoingTurbo(false);
        return;
    }
    this->loseTurbo();
    b2Body* carBody = this->getCarBody();
    float angle = carBody->GetAngle();


    float x = std::cos(angle)*TURBOFORCE;
    float y = std::sin(angle)*TURBOFORCE;

    if ((this->side == LEFTPLAYER && this->facingStatus == FACINGBACK) ||
        (this->side == RIGHTPLAYER && this->facingStatus == FACINGFRONT)){
        x *= -1;
        y *= -1;
    }
    //carBody->ApplyForceToCenter(b2Vec2(x, y),true);
    carBody->ApplyLinearImpulse(b2Vec2(x, y), carBody->GetWorldCenter(), true);
}

PlayerModel CarPhysics::getPlayerModel() {
    b2Vec2 carCoord = carBody->GetPosition();
    float angle = carBody->GetAngle() * (-1);
    
    float xOriginal = -CARHALFWIDTH;
    float yOriginal = CARHALFHEIGHT;


    //float xPrime = xOriginal * std::cos(angle*(-1)) - yOriginal * std::sin(angle*(-1));
    //float yPrime = xOriginal * std::sin(angle*(-1)) + yOriginal * std::cos(angle*(-1));


    float xCar = carCoord.x + xOriginal;
    float yCar = carCoord.y + yOriginal;
    
    std::string facing;

    if (side == LEFTPLAYER) {
        if (facingStatus == FACINGBACK) {
            facing = "left";
        } else {
            facing = "right";
        }
    } else{
        if (facingStatus == FACINGFRONT) {
            facing = "left";
        } else {
            facing = "right";
        }
    }

    bool turbo = this->isDoingTurbo;
    int turboRem = this->turboRemaining;

    /*if (it->second->getSensorStatus() == BALLINBACKSENSOR) {
        std::cout << "SENSOR: BACK" << std::endl;
    } else if (it->second->getSensorStatus() == BALLINBOTTOMSENSOR) {
        std::cout << "SENSOR: BOTTOM" << std::endl;
    } else if (it->second->getSensorStatus() == BALLINFRONTSENSOR) {
        std::cout << "SENSOR: FRONT" << std::endl;
    } else if (it->second->getSensorStatus() == NOTSENSOR) {
        std::cout << "SENSOR: NOT" << std::endl;
    }*/


    PlayerModel pm(this->clientId , xCar, yCar, angle, turbo, facing, turboRem);
    return pm;
}