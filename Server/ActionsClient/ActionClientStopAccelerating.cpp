#include <string>
#include <sstream>

#include "ActionsClient.h"
#include "ActionClientStopAccelerating.h"
#include <iostream>

ActionClientStopAccelerating::ActionClientStopAccelerating(int sktId) {
    this->socketId = sktId;
}

std::string ActionClientStopAccelerating::execute(
    Physics &physics) {
        physics.carStopAccelerating(socketId);
        return "";
}