#include <iostream>
#include <sstream>
#include <string>
#include <list>

#include "../Common/common_socket.h"
#include "../Common/common_protocol.h"

#include "Server.h"
#include "ThreadClientReciver.h"

Server::Server(
    const char *port) : socket(port) { }

void Server::reciveAndReturnMessage() {
    ThreadClientReciver clientReciver(this->socket);
    clientReciver.start();

    std::string key;

    while (std::cin >> key)
        if (key == "q")
            break;
}

Server::~Server() { }
