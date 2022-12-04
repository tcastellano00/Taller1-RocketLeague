#include "ClientConnection.h"
#include "ClientIdGenerator.h"

ClientConnection::ClientConnection() :
    socket() {
        this->id = ClientIdGenerator::getId();
        this->gameName = "";
        this->clientName = "";
        this->inAGame = false;
    }

ClientConnection::ClientConnection(
    Socket& socket) :
    socket(std::move(socket)) {
        this->id = ClientIdGenerator::getId();
        this->gameName = "";
        this->clientName = "";
        this->clientName = clientName;
    }

int ClientConnection::getId() {
    return this->id;
}

std::string ClientConnection::getName() {
    return this->clientName;
}

void ClientConnection::setName(std::string name) {
    this->clientName = name;
}

Socket& ClientConnection::getSocketReference() {
    return this->socket;
}

void ClientConnection::setGameName(std::string newGameName) {
    this->gameName = newGameName;
    this->inAGame = true;
}

std::string ClientConnection::getGameName() {
    return this->gameName;
}

bool ClientConnection::getInAGame() {
    return this->inAGame;
}

ClientConnection::ClientConnection(ClientConnection&& other): 
    socket(std::move(other.socket)) {
    this->clientName = other.getName();
    this->gameName = other.getGameName();
    this->inAGame = other.getInAGame();
}

ClientConnection& ClientConnection::operator=(ClientConnection&& other) {
    if (this == &other)
        return *this;

    this->socket = std::move(other.socket);
    this->clientName = other.getName();
    this->gameName = other.getGameName();
    this->inAGame = other.getInAGame();

    return *this;
}