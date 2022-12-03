#include <string>
#include <sstream>

#include "ActionClientStartTurning.h"

ActionClientStartTurning::ActionClientStartTurning(int sktId) {
    this->socketId = sktId;
}

std::string ActionClientStartTurning::execute(
    Physics &physics) {

    physics.turnCar(socketId);

    return "OK";
}