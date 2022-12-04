#include <string>
#include <sstream>

#include "ActionClientDoPurpleShot.h"

ActionClientDoPurpleShot::ActionClientDoPurpleShot(int cltId) {
    this->clientId = cltId;
}

std::string ActionClientDoPurpleShot::execute(
    Physics &physics) {
    physics.doPurpleShot(clientId);
    return "";
}