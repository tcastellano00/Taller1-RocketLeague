#ifndef GOALSENSOR_H
#define GOALSENSOR_H

#include "../../libs/Box2D/Box2D.h"


enum SideOfGoal {
    LEFT,
    RIGHT,
};

class GoalSensor {
private:
    SideOfGoal side;
    b2Body* goalBody;
    int goals;
    bool goalScored;

public:
    GoalSensor(SideOfGoal side, b2Body* goalBody);
    GoalSensor();
    SideOfGoal getSideOfGoal();
    b2Body* getGoalBody();
    int getGoals();
    void scoreGoal();

    bool getGoalScored();
    void setGoalScored(bool set);

};

#endif