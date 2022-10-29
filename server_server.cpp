#include <iostream>
#include <sstream>
#include <string>
#include <list>

#include "common_socket.h"
#include "common_protocol.h"

#include "server_server.h"
#include "server_thread_client_reciver.h"

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
