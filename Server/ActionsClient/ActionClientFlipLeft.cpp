#include <string>
#include <sstream>

#include "ActionClientFlipLeft.h"

ActionClientFlipLeft::ActionClientFlipLeft(int cltId) {
    this->clientId = cltId;
}

std::string ActionClientFlipLeft::execute(
    Physics &physics) {
    physics.flipCarLeft(clientId);
    return "";
}