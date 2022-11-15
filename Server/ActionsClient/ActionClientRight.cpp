#include <string>
#include <sstream>

#include "ActionClientRight.h"

ActionClientRight::ActionClientRight(int sktId) {
    this->socketId = sktId;
}

std::string ActionClientRight::execute(
    Physics &physics) {

    physics.moveCarRight();

    return "OK";
}
