#include "common_command.h"

Command::Command(const std::string &type_command):
    type_command(type_command){}


std::string Command::get_type_command(){
    return type_command;
}
