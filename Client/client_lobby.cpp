#include "client_lobby.h"
#include <iostream>

Lobby::Lobby(Socket& cnct): conection(cnct) {
}

bool Lobby::start() {
    std::cout << "Im in the lobby" << std::endl;
    return false;
}
