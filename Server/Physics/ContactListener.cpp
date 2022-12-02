#include "ContactListener.h"
#include <iostream>
#include "Physics.h"


bool ContactListener::getGoal(b2Contact* contact, GoalSensor*& goal) {
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

    if (sensorA) {//fixtureA is the goal
        goalEntity = static_cast<GoalSensor*>(fixtureA->GetBody()->GetUserData());
    } else {//fixtureB is the goal
        goalEntity = static_cast<GoalSensor*>(fixtureB->GetBody()->GetUserData());
    }

    goal = goalEntity;

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

void ContactListener::BeginContact(b2Contact* contact) {
    GoalSensor* goal;
    if ( this->getGoal(contact, goal) ) {
        goal->scoreGoal();
        return;
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

}

void ContactListener::EndContact(b2Contact* contact) {
    
    GoalSensor* goal;
    if ( this->getGoal(contact, goal) ) {
        //modelar termina el contacto
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