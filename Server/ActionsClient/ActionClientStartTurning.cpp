#include <string>
#include <sstream>

#include "ActionClientStartTurning.h"

ActionClientStartTurning::ActionClientStartTurning(int cltId) {
    this->clientId = cltId;
}

std::string ActionClientStartTurning::execute(
    Physics &physics) {

    physics.turnCar(clientId);

    return "OK";
}