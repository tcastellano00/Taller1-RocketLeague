#include <string>
#include <sstream>

#include "ActionsClient.h"
#include "ActionClientStartAcceleratingBackwards.h"

ActionClientStartAcceleratingBackwards::ActionClientStartAcceleratingBackwards(int sktId) {
    this->socketId = sktId;
}

std::string ActionClientStartAcceleratingBackwards::execute(
    Physics &physics) {
    
    physics.startAcceleratingCarBackwards(socketId);

    return "OK";
}
