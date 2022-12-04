#include <string>
#include <sstream>

#include "ActionClientFlipRight.h"

ActionClientFlipRight::ActionClientFlipRight(int cltId) {
    this->clientId = cltId;
}

std::string ActionClientFlipRight::execute(
    Physics &physics) {
    physics.flipCarRight(clientId);
    return "";
}
