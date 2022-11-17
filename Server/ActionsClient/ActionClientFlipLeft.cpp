#include <string>
#include <sstream>

#include "ActionClientFlipLeft.h"

ActionClientFlipLeft::ActionClientFlipLeft(int sktId) {
    this->socketId = sktId;
}

std::string ActionClientFlipLeft::execute(
    Physics &physics) {
    physics.flipCarLeft(socketId);
    return "";
}