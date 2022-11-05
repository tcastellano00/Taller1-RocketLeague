#include "iostream"
#include "Game.h"

Game::Game(
    const std::string& name,
    int maxClients) {
    this->name = name;
    this->maxClients = maxClients;
}

Game::Game(
    const std::string& name,
    int maxClients,
    ClientConnection& firstConnection) {
        this->name = name;
        this->maxClients = maxClients;
        this->connections.emplace_back(firstConnection);
    }

bool Game::addPlayer(ClientConnection& clientConnection) {
    if (this->isFull())
        return false;

    try
    {
        this->connections.emplace_back(clientConnection);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

int Game::getNumberOfConnectedClients() {
    return this->connections.size();
}

bool Game::isFull() {
    return (this->maxClients == this->getNumberOfConnectedClients());
}

std::string Game::getName() {
    return this->name;
}