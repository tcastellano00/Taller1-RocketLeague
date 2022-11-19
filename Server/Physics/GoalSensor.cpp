#include "GoalSensor.h"

GoalSensor::GoalSensor(SideOfGoal side, b2Body* body) {
    body->SetUserData(this);
    this->side = side;
    this->goalBody = body;
    this->goals = 0;
}

GoalSensor::GoalSensor() {
}

SideOfGoal GoalSensor::getSideOfGoal() {
    return side;
}

b2Body* GoalSensor::getGoalBody() {
    return goalBody;
}

int GoalSensor::getGoals() {
    return goals;
}

void GoalSensor::scoreGoal() {
    goals++;
}