#include <string>
#include <sstream>

#include "ActionsClient.h"
#include "ActionClientStopTurbo.h"
#include <iostream>

ActionClientStopTurbo::ActionClientStopTurbo(int sktId) {
    this->socketId = sktId;
}

std::string ActionClientStopTurbo::execute(
    Physics &physics) {
        physics.carStopTurbo(socketId);
        return "";
}