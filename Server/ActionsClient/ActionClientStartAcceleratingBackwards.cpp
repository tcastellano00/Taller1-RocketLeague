#include <string>
#include <sstream>

#include "ActionsClient.h"
#include "ActionClientStartAcceleratingBackwards.h"

ActionClientStartAcceleratingBackwards::ActionClientStartAcceleratingBackwards(int cltId) {
    this->clientId = cltId;
}

std::string ActionClientStartAcceleratingBackwards::execute(
    Physics &physics) {
    
    physics.startAcceleratingCarBackwards(clientId);

    return "OK";
}
