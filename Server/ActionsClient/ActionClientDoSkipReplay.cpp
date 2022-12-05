#include <string>
#include <sstream>

#include "ActionClientDoSkipReplay.h"

ActionClientDoSkipReplay::ActionClientDoSkipReplay(int cltId) {
    this->clientId = cltId;
    skipReplay = true;
}

std::string ActionClientDoSkipReplay::execute(
    Physics &physics) {
    physics.playerSetSkipReplay(clientId);
    return "";
}