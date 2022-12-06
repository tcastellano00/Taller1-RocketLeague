#ifndef GOALSENSOR_H
#define GOALSENSOR_H

#include "../../libs/Box2D/Box2D.h"
#include "../../Common/Config/ServerConfig.h"


enum SideOfGoal {
    LEFT,
    RIGHT,
};



//Sensor que representar al arco. En el momento donde se registra un contacto
//con la pelota es interpretada como un gol en donde se le suma +1 a una variable
//interna que representa la cantidad de goles del partido de un equipo.
class GoalSensor {
private:
    SideOfGoal side;
    b2Body* goalBody;
    int goals;
    bool goalScored;

    b2Body* createBody(b2World& world);

    float FIELDHALFWIDTH = ServerConfig::getFieldHalfWidth();
    float FIELDHEIGHT = ServerConfig::getFieldHeight();
    float GOALTOPHALFWIDTH = ServerConfig::getGoalTopHalfWidth();
    float BALLRADIUS = ServerConfig::getBallRadius();

public:
    GoalSensor(SideOfGoal side, b2World& world);
    GoalSensor();
    SideOfGoal getSideOfGoal();
    b2Body* getGoalBody();
    int getGoals();
    void scoreGoal();

    bool getGoalScored();
    void setGoalScored(bool set);

};

#endif