#include "GameMonitor.h"

GameMonitor::GameMonitor() {}

bool GameMonitor::createGame(
    const std::string& gameName,
    int maxClient,
    ClientConnection& clientConnection){
    
    std::lock_guard<std::mutex> lock(mutex);

    //Veo si ya hay una partida con ese nombre
    if (this->games.find(gameName) != this->games.end())
        return false;

    this->games.try_emplace(gameName,gameName,maxClient,clientConnection);

    clientConnection.setGameName(gameName);
    
    return true;
}

bool GameMonitor::addPlayerIfNotFull(
    const std::string& gameName, 
    ClientConnection& clientConnection) {
    std::lock_guard<std::mutex> lock(mutex);

    //Veo si la partida no existe
    if (this->games.find(gameName) == this->games.end())
        return false;

    //Esta llena?
    if (this->games.at(gameName).isFull())
        return false;

    this->games.at(gameName).addPlayer(clientConnection);

    clientConnection.setGameName(gameName);

    return true;
}

bool GameMonitor::startIfLastPlayer(
    const std::string& gameName) {
    std::lock_guard<std::mutex> lock(mutex);
    
    //Veo si la partida no existe
    if (this->games.find(gameName) == this->games.end())
        return false;

    //Esta llena?
    if (!this->games.at(gameName).isFull())
        return false;

    this->games.at(gameName).launch();

   return true;
}

std::string GameMonitor::listGames() {
    std::lock_guard<std::mutex> lock(mutex);

    std::string result = "";
    std::map<std::string, Game>::iterator it;

    for (auto &gameRow : this->games) {
        result += "\n"; //Break line.
        result += gameRow.second.getName() + " " + 
                     std::to_string(gameRow.second.getNumberOfConnectedClients()) + "/" +
                     std::to_string(gameRow.second.getMaxClients());
    }

    return result;
}

void GameMonitor::finishGame(
    const std::string& gameName) {
    std::lock_guard<std::mutex> lock(mutex);

    //Veo si la partida no existe
    if (this->games.find(gameName) == this->games.end())
        return;

    this->games.at(gameName).finish();
}

void GameMonitor::finishGames() {
    std::lock_guard<std::mutex> lock(mutex);
    std::map<std::string, Game>::iterator it;
    
    for (auto &gameRow : this->games)
        gameRow.second.finish();
}

GameMonitor::~GameMonitor() {
    this->finishGames();
}