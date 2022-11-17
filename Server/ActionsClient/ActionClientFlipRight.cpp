#include <string>
#include <sstream>

#include "ActionClientFlipRight.h"

ActionClientFlipRight::ActionClientFlipRight(int sktId) {
    this->socketId = sktId;
}

std::string ActionClientFlipRight::execute(
    Physics &physics) {
    physics.flipCarRight(socketId);
    return "";
}
