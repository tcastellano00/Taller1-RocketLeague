#include <string>
#include <sstream>

#include "ActionClientRight.h"

ActionClientRight::ActionClientRight() {}

std::string ActionClientRight::execute(
    Physics &physics) {

    physics.moveCarRight();

    return "OK";
}
