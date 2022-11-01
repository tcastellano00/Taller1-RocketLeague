#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <list>
#include <memory>

#include "../Common/LibError.h"
#include "ThreadClient.h"

ThreadClient::ThreadClient(Socket& socket) 
    :   connection(std::move(socket)), 
        protocol(connection),
        deathClient(false), 
        talkWithClient(true) { 

        }

void ThreadClient::run() {
    while (this->talkWithClient) {
        try {
            std::string message = protocol.reciveMessage();

            if (protocol.isClosed())
                break;

            std::cout << message << std::endl;

            protocol.sendMessage(message);
        } catch(const LibError &e) {
            this->deathClient = true;
        }
    }

    this->deathClient = true;
}

void ThreadClient::stop() {
    this->deathClient = true;
    this->talkWithClient = false;
    
    this->protocol.close();
    this->join();
}

bool ThreadClient::isDeath() {
    return this->deathClient;
}

ThreadClient::~ThreadClient() {
    if (this->isDeath())
        return;

    this->stop();
}
