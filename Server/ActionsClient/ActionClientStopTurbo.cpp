#include <string>
#include <sstream>

#include "ActionsClient.h"
#include "ActionClientStopTurbo.h"
#include <iostream>

ActionClientStopTurbo::ActionClientStopTurbo(int cltId) {
    this->clientId = cltId;
}

std::string ActionClientStopTurbo::execute(
    Physics &physics) {
        physics.carStopTurbo(clientId);
        return "";
}