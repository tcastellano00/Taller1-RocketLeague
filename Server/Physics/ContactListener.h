#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include "../../libs/Box2D/Box2D.h"
#include "GoalSensor.h"
#include "Car.h"
#include "BallPhysics.h"
#include "EntityCategory.h"

//Clase que implementa todos los contactos que Box2D registra.
//En cada tipo de contacto se implementa su logica correspondiente
//segun el caso.
class ContactListener : public b2ContactListener  {

    void BeginContact(b2Contact* contact);

    void EndContact(b2Contact* contact);

    bool getGoalContactWithBall(b2Contact* contact, GoalSensor*& goal, BallPhysics*& ball);

    bool getCarContactWithBox(b2Contact* contact, CarPhysics*& car);

    bool getCarSensorContactWithBall(b2Contact* contact, CarPhysics*& car, bool& isFrontSensor);

    bool getCarContactWithBall(b2Contact* contact, CarPhysics*& car, BallPhysics*& ball);

    bool getBallContactWithBox(b2Contact* contact, BallPhysics*& ball);

    bool getCarContactWithCorner(b2Contact* contact, CarPhysics*& car);
};

#endif