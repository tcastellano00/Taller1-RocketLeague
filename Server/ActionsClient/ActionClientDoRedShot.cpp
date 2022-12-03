#include <string>
#include <sstream>

#include "ActionClientDoRedShot.h"

ActionClientDoRedShot::ActionClientDoRedShot(int sktId) {
    this->socketId = sktId;
}

std::string ActionClientDoRedShot::execute(
    Physics &physics) {
    physics.doRedShot(socketId);
    return "";
}