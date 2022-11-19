#include "ContactListener.h"
#include "Physics.h"
#include <iostream>

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
        std::cout << "arco izq" << std::endl;
        goalEntity = static_cast<GoalSensor*>(fixtureA->GetBody()->GetUserData());
    } else {//fixtureB is the goal
    std::cout << "arco der" << std::endl;
        goalEntity = static_cast<GoalSensor*>(fixtureB->GetBody()->GetUserData());
    }

    goal = goalEntity;

    return true;
}

void ContactListener::BeginContact(b2Contact* contact) {
    GoalSensor* goal;
    if ( this->getGoal(contact, goal) ) {
        std::cout << "detecte contacto" << std::endl;
        goal->scoreGoal();
    }
}

void ContactListener::EndContact(b2Contact* contact) {
        GoalSensor* goal;
        if ( this->getGoal(contact, goal) ) {
            //modelar termina el contacto
        }
    }