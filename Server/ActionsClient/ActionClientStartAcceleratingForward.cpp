#include <string>
#include <sstream>

#include "ActionClientStartAcceleratingForward.h"

ActionClientStartAcceleratingForward::ActionClientStartAcceleratingForward(int sktId) {
    this->socketId = sktId;
}

std::string ActionClientStartAcceleratingForward::execute(
    Physics &physics) {

    physics.startAcceleratingCarForward(socketId);

    return "OK";
}
