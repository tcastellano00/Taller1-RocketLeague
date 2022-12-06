#ifndef BALLPHYSICS_H
#define BALLPHYSICS_H

#include "../Box2D/Box2D.h"
#include "EntityCategory.h"
#include <string>
#include "../../Common/Config/ServerConfig.h"
#include "../../Common/Model/BallModel.h"
#include "Car.h"

//Tipo de tiro especial que la pelota va a registrar cuando
// el jugador la lleve a cabo.
enum SpecialShot {
    REDSHOT,
    GOLDSHOT,
    PURPLESHOT,  
    NONE,

};

//Clase que representa la pelota en Box2D y se le aplican 
//los tiros especiales que realice el jugador.
class BallPhysics {
private:
    b2Body* ballBody;
    void generateImpulse(float impulse);
    SpecialShot shotType;
    int specialShotTimer;
    bool contactWithBox;
    

    //Id del cliente
    CarPhysics* lastPLayerContact;
    CarPhysics* penultimatePlayerContact;
    // int lastPLayerContact;
    // int penultimatePlayerContact;



    float REDSHOTIMPULSE = ServerConfig::getRedShotImpulse();
    float GOLDSHOTIMPULSE = ServerConfig::getGoldShotImpulse();
    float PURPLESHOTIMPULSE = ServerConfig::getPurpleShotImpulse();
    float FIELDHALFWIDTH = ServerConfig::getFieldHalfWidth();
    float FIELDHEIGTH = ServerConfig::getFieldHeight();
    float CARFRICTION = ServerConfig::getCarFriction();
    float SPECIALSHOTTIME = ServerConfig::getSpecialShotTime();
    float BALLRADIUS = ServerConfig::getBallRadius();
    

public:
    explicit BallPhysics(b2World &world);
    BallPhysics();
    b2Body* getBody();

    b2Body* createBody(b2World& world);
    


    void redShot(int sideMultiplicator);
    void goldShot(int sideMultiplicator);
    void purpleShot(int sideMultiplicator);

    SpecialShot getShotType();
    void setShotType(SpecialShot type);

    void updateShotStatus();

    void updateLastPlayerContact(CarPhysics* newPlayer);

    void setContactWithBox(bool isTouching);

    CarPhysics* getLastPlayerContact();
    CarPhysics* getPenultimatePlayerContact();


    BallModel getModel();

};

#endif