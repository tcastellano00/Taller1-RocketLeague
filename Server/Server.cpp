#include <iostream>
#include <sstream>
#include <string>
#include <list>

#include "../Common/Socket.h"
#include "../Common/Protocol.h"

#include "Server.h"
#include "Threads/ThreadClientAcceptor.h"

Server::Server(
    const char *port) : socket(port) { }

void Server::run() {
    ThreadClientAcceptor clientAcceptor(this->socket);
    clientAcceptor.start();

    std::string key;

    while (std::cin >> key) {
        if (key == "q")
            break;
    }
}

Server::~Server() { }
