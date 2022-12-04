#include <string>
#include <sstream>

#include "ActionsClient.h"
#include "ActionClientStopAccelerating.h"
#include <iostream>

ActionClientStopAccelerating::ActionClientStopAccelerating(int cltId) {
    this->clientId = cltId;
}

std::string ActionClientStopAccelerating::execute(
    Physics &physics) {
        physics.carStopAccelerating(clientId);
        return "";
}