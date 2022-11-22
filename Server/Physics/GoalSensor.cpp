#include "GoalSensor.h"

GoalSensor::GoalSensor(SideOfGoal side, b2Body* body) {
    body->SetUserData(this);
    this->side = side;
    this->goalBody = body;
    this->goals = 0;
    this->goalScored = false;
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
    goalScored = true;
    goals++;
}

bool GoalSensor::getGoalScored(){
    return this->goalScored;
}

void GoalSensor::setGoalScored(bool set) {
    this->goalScored = set;
}