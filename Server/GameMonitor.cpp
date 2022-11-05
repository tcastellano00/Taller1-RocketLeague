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

    Game game(gameName, maxClient, clientConnection);

    this->games[gameName] = game;
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
    if (this->games[gameName].isFull())
        return false;

    this->games[gameName].addPlayer(clientConnection);

    return true;
}

bool GameMonitor::startIfLastPlayer(
    const std::string gameName) {
    std::lock_guard<std::mutex> lock(mutex);
    
    //Esta llena?
    if (!this->games[gameName].isFull())
        return false;

    this->games[gameName].start();
    /*
        Aca creo que lo mejor seria hacer un
        this->games[gameName].start() y que ese
        metodo adentro haga "GameLoop.start(this.clientConnections)"
        para iniciar el gameLoop de esa partida.
    */

   return true;
}

std::string GameMonitor::listGames() {
    return "";
}