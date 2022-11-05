#include "iostream"
#include "Game.h"
#include "Gameloop.h"

Game::Game() {
    this->name = "";
    this->maxClients = -1;
}


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
        //this->connections.push_back(firstConnection);
    }

bool Game::addPlayer(ClientConnection& clientConnection) {
    if (this->isFull())
        return false;

    try
    {
        //this->connections.push_back(clientConnection);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

int Game::getNumberOfConnectedClients() {
    return 0; // this->connections.size();
}

bool Game::isFull() {
    return (this->maxClients == this->getNumberOfConnectedClients());
}

std::string Game::getName() {
    return this->name;
}

void Game::start() {
    //this->gameLoop.init(this->connections);
    this->started = true;
}