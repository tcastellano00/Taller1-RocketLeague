#include "ActionsClient.h"
#include "ActionClientJump.h"
#include "ActionClientLeft.h"
#include "ActionClientRight.h"
#include "ActionClientTurbo.h"




std::unique_ptr<ActionsClient> ActionsClient::get_command_ptr(
const std::string &name){
if (name == "left")
    return std::unique_ptr<ActionsClient>(
        new ActionClientLeft());
else if (name == "right")
    return std::unique_ptr<ActionsClient>(
        new ActionClientRight());
else if(name == "jump")
    return std::unique_ptr<ActionsClient>(
        new ActionClientJump());
else return std::unique_ptr<ActionsClient>(
        new ActionClientTurbo());
}