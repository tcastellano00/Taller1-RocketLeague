#include <string>
#include <sstream>

#include "ActionsClient.h"
#include "ActionClientLeft.h"

ActionClientLeft::ActionClientLeft(int sktId) {
    this->socketId = sktId;
}

std::string ActionClientLeft::execute(
    Physics &physics) {
    
    physics.moveCarLeft(socketId);

    return "OK";
}
