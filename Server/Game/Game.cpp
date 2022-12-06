#include "iostream"
#include "Game.h"

Game::Game(
    const std::string& name,
    int maxClients,
    ClientConnection& firstConnection) {
        this->name = name;
        this->maxClients = maxClients;
        this->clients = 1;
        this->started = false;
        this->connections.emplace_back(std::move(firstConnection));
    }

bool Game::addPlayer(ClientConnection& clientConnection) {
    if (this->isFull())
        return false;

    try
    {
        this->clients += 1;
        this->connections.emplace_back(std::move(clientConnection));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

int Game::getNumberOfConnectedClients() {
    return this->clients;
}

int Game::getMaxClients() {
    return this->maxClients;
}

bool Game::isFull() {
    return (this->maxClients == this->getNumberOfConnectedClients());
}

std::string Game::getName() {
    return this->name;
}

void Game::launch() {
    if (this->started)
        return;

    this->started = true;
    this->gameloopRunner.init(this->connections);
}

void Game::finish() {
    if(this->started)
        this->gameloopRunner.stop();
}