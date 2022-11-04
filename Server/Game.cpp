
#include "Game.h"

Game::Game(const std::string& name) {
    this->name = name;
}

Game::Game(
    const std::string& name,
    ClientConnection firstConnection) {
        this->name = name;
        this->connections.push_back(firstConnection);
    }

std::string Game::getName() {
    return this->name;
}