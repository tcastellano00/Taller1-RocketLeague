#include <string>
#include <sstream>

#include "ActionClientStartAcceleratingForward.h"

ActionClientStartAcceleratingForward::ActionClientStartAcceleratingForward(int cltId) {
    this->clientId = cltId;
}

std::string ActionClientStartAcceleratingForward::execute(
    Physics &physics) {

    physics.startAcceleratingCarForward(clientId);

    return "OK";
}
