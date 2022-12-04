#include <string>
#include <sstream>

#include "ActionsClient.h"
#include "ActionClientStopFlip.h"
#include <iostream>

ActionClientStopFlip::ActionClientStopFlip(int cltId) {
    this->clientId = cltId;
}

std::string ActionClientStopFlip::execute(
    Physics &physics) {
        physics.carStopFlip(clientId);
        return "";
}