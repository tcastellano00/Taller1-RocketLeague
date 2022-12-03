#include <string>
#include <sstream>

#include "ActionClientDoGoldenShot.h"

ActionClientDoGoldenShot::ActionClientDoGoldenShot(int sktId) {
    this->socketId = sktId;
}

std::string ActionClientDoGoldenShot::execute(
    Physics &physics) {
    physics.doGoldenShot(socketId);
    return "";
}