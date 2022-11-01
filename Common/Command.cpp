#include "Command.h"

Command::Command(const std::string &newType):
    type(newType){}


std::string Command::getType(){
    return type;
}
