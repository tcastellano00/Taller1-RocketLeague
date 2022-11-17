#include <string>
#include <sstream>

#include "ActionClientJump.h"

ActionClientJump::ActionClientJump(int sktId) {
    this->socketId = sktId;
}

std::string ActionClientJump::execute(
    Physics &physics) {
    physics.carJump(socketId);
    return "";
}
