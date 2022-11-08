#include "iostream"
#include "Game.h"
#include "Gameloop.h"

/*
Game::Game() : connections() {
    this->name = "";
    this->maxClients = -1;
}

Game::Game(
    const std::string& name,
    int maxClients) : connections() {
    this->name = name;
    this->maxClients = maxClients;
}
*/

Game::Game(
    const std::string& name,
    int maxClients,
    ClientConnection& firstConnection) : connections(firstConnection) {
        this->name = name;
        this->maxClients = maxClients;
        this->clients = 1;
        this->started = false;
        //this->connections.push_back(firstConnection);
    }

bool Game::addPlayer(ClientConnection& clientConnection) {
    if (this->isFull())
        return false;

    try
    {
        this->clients += 1;
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
    return this->clients; // this->connections.size();
}

bool Game::isFull() {
    return (this->maxClients == this->getNumberOfConnectedClients());
}

std::string Game::getName() {
    return this->name;
}

void Game::start() {
    if (this->started)
        return;

    std::cout << "Game::start" << std::endl;

    this->gameLoop.init(this->connections);
    this->started = true;
}