#include <string>
#include <sstream>

#include "ActionsClient.h"
#include "ActionClientTurbo.h"

ActionClientTurbo::ActionClientTurbo(int sktId) {
    this->socketId = sktId;
}

std::string ActionClientTurbo::execute(
    Physics &physics) {
    
    return "";
}
