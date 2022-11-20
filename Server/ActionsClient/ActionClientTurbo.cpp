#include <string>
#include <sstream>

#include "ActionsClient.h"
#include "ActionClientTurbo.h"
#include <iostream>

ActionClientTurbo::ActionClientTurbo(int sktId) {
    this->socketId = sktId;
}

std::string ActionClientTurbo::execute(
    Physics &physics) {
        physics.carTurbo(socketId);
        return "";
}
