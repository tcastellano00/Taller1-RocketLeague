#include "ActionsClient.h"




std::unique_ptr<ActionsClient> ActionsClient::get_command_ptr(
const std::string &name){
if (name == "left")
    return std::unique_ptr<ActionsClient>(
        new ActionsClientLeft());
else if (name == "right")
    return std::unique_ptr<ActionsClient>(
        new ActionsClientRight());
else if (name == "jump")
    return std::unique_ptr<ActionsClient>(
        new ActionsClientJump());
}