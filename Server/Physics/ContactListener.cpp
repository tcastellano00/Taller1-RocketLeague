#include "ContactListener.h"
#include <iostream>
#include "Physics.h"


bool ContactListener::getGoalContactWithBall(b2Contact* contact, GoalSensor*& goal, BallPhysics*& ball) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    //make sure only one of the fixtures was a sensor
    bool sensorA = fixtureA->IsSensor();
    bool sensorB = fixtureB->IsSensor();

    if ( ! (sensorA ^ sensorB) ) {
        return false;
    }


    //if none of them is a goal, return false
    b2Filter filterA = fixtureA->GetFilterData();
    b2Filter filterB = fixtureB->GetFilterData();
    if (filterA.categoryBits != GOALSENSOR && filterB.categoryBits != GOALSENSOR) {
        return false;
    }

    GoalSensor* goalEntity;
    BallPhysics* ballEntity;

    if (sensorA) {//fixtureA is the goal
        goalEntity = static_cast<GoalSensor*>(fixtureA->GetBody()->GetUserData());
        ballEntity = static_cast<BallPhysics*>(fixtureB->GetBody()->GetUserData());
    } else {//fixtureB is the goal
        goalEntity = static_cast<GoalSensor*>(fixtureB->GetBody()->GetUserData());
        ballEntity = static_cast<BallPhysics*>(fixtureA->GetBody()->GetUserData());
    }

    goal = goalEntity;
    ball = ballEntity;

    return true;
}

bool ContactListener::getCarContactWithBox(b2Contact* contact, CarPhysics*& car){
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    bool match1 =  fixtureA->GetFilterData().categoryBits == CAR && fixtureB->GetFilterData().categoryBits == BOUNDARY;
    bool match2 = fixtureA->GetFilterData().categoryBits == BOUNDARY && fixtureB->GetFilterData().categoryBits == CAR;
    
    if (!(match1 || match2)){
        return false;
    }

    CarPhysics* carEntity;
    if (fixtureA->GetFilterData().categoryBits == CAR) {
        carEntity = static_cast<CarPhysics*>(fixtureA->GetBody()->GetUserData());
    } else { //fixtureB is the car
        carEntity = static_cast<CarPhysics*>(fixtureB->GetBody()->GetUserData());
    }

    car = carEntity;
    return true;

}

bool ContactListener::getBallContactWithBox(b2Contact* contact, BallPhysics*& ball){
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    bool match1 =  fixtureA->GetFilterData().categoryBits == BALL && fixtureB->GetFilterData().categoryBits == BOUNDARY;
    bool match2 = fixtureA->GetFilterData().categoryBits == BOUNDARY && fixtureB->GetFilterData().categoryBits == BALL;
    
    if (!(match1 || match2)){
        return false;
    }

    BallPhysics* ballEntity;
    if (fixtureA->GetFilterData().categoryBits == BALL) {//fixtureA is the ball
        ballEntity = static_cast<BallPhysics*>(fixtureA->GetBody()->GetUserData());
    } else { //fixtureB is the ball
        ballEntity = static_cast<BallPhysics*>(fixtureB->GetBody()->GetUserData());
    }

    ball = ballEntity;
    return true;
}

bool ContactListener::getCarSensorContactWithBall(b2Contact* contact, CarPhysics*& car, bool& isFrontSensor){
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    bool match1 =  fixtureA->GetFilterData().categoryBits == BALL && fixtureB->GetFilterData().categoryBits == CAR_FRONT_SENSOR;
    bool match2 = fixtureA->GetFilterData().categoryBits == BALL && fixtureB->GetFilterData().categoryBits == CAR_BOTTOM_SENSOR;
    bool match3 =  fixtureA->GetFilterData().categoryBits == CAR_FRONT_SENSOR && fixtureB->GetFilterData().categoryBits == BALL;
    bool match4 = fixtureA->GetFilterData().categoryBits == CAR_BOTTOM_SENSOR && fixtureB->GetFilterData().categoryBits == BALL;

    if (!(match1 || match2 || match3 || match4)){
        return false;
    }


    CarPhysics* carEntity;
    
    if (fixtureA->GetFilterData().categoryBits == BALL) {
        carEntity = static_cast<CarPhysics*>(fixtureB->GetBody()->GetUserData());
        if (fixtureB->GetFilterData().categoryBits == CAR_FRONT_SENSOR) {
            isFrontSensor = true;
        }
    } else { //fixtureB is the ball, fixtureA is the sensor of the car
        carEntity = static_cast<CarPhysics*>(fixtureA->GetBody()->GetUserData());
        if (fixtureA->GetFilterData().categoryBits == CAR_FRONT_SENSOR) {
            isFrontSensor = true;
        }
    }

    car = carEntity;

    return true;
}

bool ContactListener::getCarContactWithBall(b2Contact* contact, CarPhysics*& car, BallPhysics*& ball) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    bool match1 =  fixtureA->GetFilterData().categoryBits == CAR && fixtureB->GetFilterData().categoryBits == BALL;
    bool match2 = fixtureA->GetFilterData().categoryBits == BALL && fixtureB->GetFilterData().categoryBits == CAR;

    if (!(match1 || match2)){
        return false;
    }
    CarPhysics* carEntity;
    BallPhysics* ballEntity;

    if (fixtureA->GetFilterData().categoryBits == BALL) {
        ballEntity = static_cast<BallPhysics*>(fixtureA->GetBody()->GetUserData());
        carEntity = static_cast<CarPhysics*>(fixtureB->GetBody()->GetUserData());
    } else { //fixtureB is the ball, fixtureA is the car
        ballEntity = static_cast<BallPhysics*>(fixtureB->GetBody()->GetUserData());
        carEntity = static_cast<CarPhysics*>(fixtureA->GetBody()->GetUserData());
    }

    car = carEntity;
    ball = ballEntity;
    return true;
}

void ContactListener::BeginContact(b2Contact* contact) {
    GoalSensor* goal;
    BallPhysics* ball;
    if ( this->getGoalContactWithBall(contact, goal, ball) ) {
        goal->scoreGoal();
        CarPhysics* scorer = ball->getLastPlayerContact();
        CarPhysics* assister = ball->getPenultimatePlayerContact();

        //Chequeo por si el puntero es nulo
        if (!scorer) {return;}

        bool ownGoal = true; 

        if ((scorer->getSide() == LEFTPLAYER && goal->getSideOfGoal() == RIGHT) ||
            (scorer->getSide() == RIGHTPLAYER && goal->getSideOfGoal() == LEFT)) {
            scorer->scoreAGoal();
            ownGoal = false;
        }

        //Chequeo por si el puntero es nulo
        if (!assister) {return;}

        if(!ownGoal && assister->getSide() == scorer->getSide() && (assister != scorer)){
            assister->assistAGoal();
        }
        
        return;
    }
    if (this->getBallContactWithBox(contact,ball)){
        ball->setContactWithBox(true);
    }
    CarPhysics* car;
    if (this->getCarContactWithBox(contact, car)) {
        car->landed();
        return;
    }

    bool isFrontSensor = false;
    if (this->getCarSensorContactWithBall(contact, car, isFrontSensor)) {
        if (isFrontSensor){
            if (car->getFacingStatus() == FACINGFRONT) {
                car->setSensorStatus(BALLINFRONTSENSOR);
            } else {
                car->setSensorStatus(BALLINBACKSENSOR);
            }
            
        } else {
        car->setSensorStatus(BALLINBOTTOMSENSOR);
        }
        return;
    }

    if (this->getCarContactWithBall(contact, car, ball)) {
        ball->setContactWithBox(true);//para el sonido
        if (ball->getLastPlayerContact() == car) {
            return;
        }

        ball->updateLastPlayerContact(car);

    }

}

void ContactListener::EndContact(b2Contact* contact) {
    
    GoalSensor* goal;
    BallPhysics* ball;
    if ( this->getGoalContactWithBall(contact, goal, ball) ) {
        //modelar termina el contacto
    }

    if(this->getBallContactWithBox(contact,ball)){
        ball->setContactWithBox(false);
    }
    CarPhysics* car;
    if (this->getCarContactWithBox(contact, car)) {
        car->jumpedFromTheFloor();
        return;
    }

    bool isFrontSensor = false;
    if (this->getCarSensorContactWithBall(contact, car, isFrontSensor)) {
        car->setSensorStatus(NOTSENSOR);
        return;
    }
    }