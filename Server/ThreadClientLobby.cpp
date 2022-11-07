#include <string>
#include <utility>
#include <iostream>

#include "../Common/Protocol.h"
#include "ThreadClientLobby.h"
#include "Lobby/LobbyCommand.h"
#include "Lobby/LobbyParser.h"

ThreadClientLobby::ThreadClientLobby(ClientConnection& clt, GameMonitor& gameMtr): 
    client(std::move(clt)), 
    gameMonitor(gameMtr) {}

void ThreadClientLobby::run(){
    std::cout << "ThreadClientLobby: cliente conectado" << std::endl;

    Protocol protocol(client.getSocketReference());
    bool inAGame = false;
    std::string finalGameName;
    while (!inAGame){
        std::string message = protocol.reciveMessage();
        std::unique_ptr<LobbyCommand> command = LobbyParser::getCommand(message);
        std::string response = command->execute(gameMonitor, client);
        protocol.sendMessage(response);
    }
}

void ThreadClientLobby::stop() {
}

ThreadClientLobby::~ThreadClientLobby() {
    this->join();
}



