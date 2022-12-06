#ifndef BOXPHYSICS_H
#define BOXPHYSICS_H
#include "../../libs/Box2D/Box2D.h"
#include "EntityCategory.h"
#include "../../Common/Config/ServerConfig.h"

//Representa "la cancha" del juego. En ella se imprimen
//las rampas, los arcos (con su sensor), paredes y techo.
class BoxPhysics{
    
    float FIELDHALFWIDTH = ServerConfig::getFieldHalfWidth();
    float FIELDHEIGHT = ServerConfig::getFieldHeight();
    float GRAVITY = ServerConfig::getGravity();
    float GAMETIME = ServerConfig::getGameTime();
    float EXTRATIME = ServerConfig::getExtraTime();
    float REPLAYTIME = ServerConfig::getReplayTime();
    float REDSHOTIMPULSE = ServerConfig::getRedShotImpulse();
    float GOLDSHOTIMPULSE = ServerConfig::getGoldShotImpulse();
    float PURPLESHOTIMPULSE = ServerConfig::getPurpleShotImpulse();
    float CARFRICTION = ServerConfig::getCarFriction();
    float SPECIALSHOTTIME = ServerConfig::getSpecialShotTime();
    float BALLRADIUS = ServerConfig::getBallRadius();
    float GROUNDFRICTION = ServerConfig::getGroundFriction();
    float WALLWIDTH = ServerConfig::getWallWidth();
    float GOALTOPHALFWIDTH = ServerConfig::getGoalTopHalfWidth();

public:
    BoxPhysics(b2World &world);

};

#endif
