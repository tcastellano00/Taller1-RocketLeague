#include <string>
#include <sstream>

#include "ActionsClient.h"
#include "ActionClientLeft.h"

ActionClientLeft::ActionClientLeft() {}

std::string ActionClientLeft::execute(
    Physics &physics) {
    
    physics.moveCarLeft();

    return "OK";
}
