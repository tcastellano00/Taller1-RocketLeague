#include <string>
#include <sstream>

#include "ActionsClient.h"
#include "ActionClientStopFlip.h"
#include <iostream>

ActionClientStopFlip::ActionClientStopFlip(int sktId) {
    this->socketId = sktId;
}

std::string ActionClientStopFlip::execute(
    Physics &physics) {
        physics.carStopFlip(socketId);
        return "";
}