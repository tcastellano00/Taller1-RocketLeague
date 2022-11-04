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
    /* Si el usuario hace algo como tratar de moverse
     * a si mismo simplemente no hacemos
     * nada.
     * */
    if (this == &other)
        return *this;

    this->socket = std::move(other.socket);
    this->clientName = other.getName();
}

Socket& ClientConnection::getSocketReference() {
    return this->socket;
}