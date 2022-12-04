#include <string>
#include <sstream>

#include "ActionClientDoRedShot.h"

ActionClientDoRedShot::ActionClientDoRedShot(int cltId) {
    this->clientId = cltId;
}

std::string ActionClientDoRedShot::execute(
    Physics &physics) {
    physics.doRedShot(clientId);
    return "";
}