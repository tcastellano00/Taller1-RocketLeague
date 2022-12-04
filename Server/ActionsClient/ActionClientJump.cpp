#include <string>
#include <sstream>

#include "ActionClientJump.h"

ActionClientJump::ActionClientJump(int cltId) {
    this->clientId = cltId;
}

std::string ActionClientJump::execute(
    Physics &physics) {
    physics.carJump(clientId);
    return "";
}
