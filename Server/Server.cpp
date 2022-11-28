#include <iostream>
#include <sstream>
#include <string>
#include <list>

#include "../Common/Socket.h"
#include "../Common/Protocol.h"

#include "Server.h"
#include "ThreadClientAcceptor.h"

Server::Server(
    const char *port) : socket(port), serverConfig() { }

void Server::run() {
    ThreadClientAcceptor clientAcceptor(this->socket);
    clientAcceptor.start();

    std::string key;

    std::cout << serverConfig.getGravity() << std::endl;

    while (std::cin >> key) {
        if (key == "q")
            break;
    }
}

Server::~Server() { }
