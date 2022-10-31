#include "common_command.h"

Command::Command(const std::string &newType):
    type(newType){}


std::string Command::getType(){
    return type;
}
