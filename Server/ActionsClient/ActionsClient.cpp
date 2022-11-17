#include "ActionsClient.h"
#include "ActionClientJump.h"
#include "ActionClientLeft.h"
#include "ActionClientRight.h"
#include "ActionClientFlipRight.h"
#include "ActionClientFlipLeft.h"
#include "ActionClientTurbo.h"

std::shared_ptr<ActionsClient> ActionsClient::get_command_ptr(
const std::string &name, int sktId){
    if (name == "left")
        return std::shared_ptr<ActionsClient>(
            new ActionClientLeft(sktId));
    else if (name == "right")
        return std::shared_ptr<ActionsClient>(
            new ActionClientRight(sktId));
    else if(name == "jump")
        return std::shared_ptr<ActionsClient>(
            new ActionClientJump(sktId));
    else if(name == "flip right")
        return std::shared_ptr<ActionsClient>(
            new ActionClientFlipRight(sktId));
    else if(name == "flip left")
        return std::shared_ptr<ActionsClient>(
            new ActionClientFlipLeft(sktId));
    else return std::shared_ptr<ActionsClient>(
            new ActionClientTurbo(sktId));
}