#include "ClientConnection.h"

ClientConnection::ClientConnection(
    Socket& socket, 
    const std::string& clientName) :
    socket(std::move(socket)) {
        this->clientName = clientName;
    }

int ClientConnection::getId() {
    return this->socket.getIdentifier();
}

std::string ClientConnection::getName() {
    return this->clientName;
}

ClientConnection::ClientConnection(ClientConnection&& other): 
    socket(std::move(other.socket)) {
    this->clientName = other.getName();
}

ClientConnection& ClientConnection::operator=(ClientConnection&& other) {
    if (this == &other)
        return *this;

    this->socket = std::move(other.socket);
    this->clientName = other.getName();

    return *this;
}

Socket& ClientConnection::getSocketReference() {
    return this->socket;
}