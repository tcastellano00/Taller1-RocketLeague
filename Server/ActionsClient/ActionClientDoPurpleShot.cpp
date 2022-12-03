#include <string>
#include <sstream>

#include "ActionClientDoPurpleShot.h"

ActionClientDoPurpleShot::ActionClientDoPurpleShot(int sktId) {
    this->socketId = sktId;
}

std::string ActionClientDoPurpleShot::execute(
    Physics &physics) {
    physics.doPurpleShot(socketId);
    return "";
}