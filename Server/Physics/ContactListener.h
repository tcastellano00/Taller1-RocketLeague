#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include "../../libs/Box2D/Box2D.h"
#include "GoalSensor.h"


class ContactListener : public b2ContactListener  {

    void BeginContact(b2Contact* contact);

    void EndContact(b2Contact* contact);

    bool getGoal(b2Contact* contact, GoalSensor*& goal);
};

#endif