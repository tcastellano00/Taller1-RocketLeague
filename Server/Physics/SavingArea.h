#ifndef SAVINGAREA_H
#define SAVINGAREA_H

#include "../../libs/Box2D/Box2D.h"
#include "../../Common/Config/ServerConfig.h"


enum SavingAreaSide {
    LEFTAREA,
    RIGHTAREA,
};


/*
Sensor que representa el area en donde puedan 
existir las atajadas. Si un jugador se encuentra cerca de su arco
y la pelota llega con el ultimo toque proveniente de un jugador del
equipo contrario y realiza un cambio de direccion, se contabiliza como atajada.
*/
class SavingArea {
private:
    SavingAreaSide side;
    b2Body* goalBody;

    b2Body* createBody(b2World& world);

    float FIELDHALFWIDTH = ServerConfig::getFieldHalfWidth();
    float FIELDHEIGHT = ServerConfig::getFieldHeight();
    float GOALTOPHALFWIDTH = ServerConfig::getGoalTopHalfWidth();
    float GOALTOPHALFHEIGHT = ServerConfig::getGoalTopHalfHeight();
    float BALLRADIUS = ServerConfig::getBallRadius();

public:
    SavingArea(SavingAreaSide side, b2World& world);
    SavingArea();
    SavingAreaSide getSavingAreaSide();
    b2Body* getGoalBody();
};

#endif