#include <string>
#include <sstream>

#include "ActionsClient.h"
#include "ActionClientTurbo.h"
#include <iostream>

ActionClientTurbo::ActionClientTurbo(int cltId) {
    this->clientId = cltId;
}

std::string ActionClientTurbo::execute(
    Physics &physics) {
        physics.startDoingTurbo(clientId);
        return "";
}
