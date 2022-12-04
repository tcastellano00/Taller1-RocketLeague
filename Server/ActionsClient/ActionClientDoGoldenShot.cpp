#include <string>
#include <sstream>

#include "ActionClientDoGoldenShot.h"

ActionClientDoGoldenShot::ActionClientDoGoldenShot(int cltId) { 
    this->clientId = cltId;
}

std::string ActionClientDoGoldenShot::execute(
    Physics &physics) {
    physics.doGoldenShot(clientId);
    return "";
}