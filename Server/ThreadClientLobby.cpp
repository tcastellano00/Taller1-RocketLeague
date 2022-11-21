#include <string>
#include <utility>
#include <iostream>

#include "../Common/Protocol.h"
#include "../Common/LibError.h"

#include "ThreadClientLobby.h"
#include "Lobby/LobbyCommand.h"
#include "Lobby/LobbyParser.h"

ThreadClientLobby::ThreadClientLobby(ClientConnection& clt, GameMonitor& gameMtr): 
    client(std::move(clt)), 
    gameMonitor(gameMtr),
    protocol(client.getSocketReference()) {
        inLobby = true;
    }

void ThreadClientLobby::run(){
    std::cout << "ThreadClientLobby: cliente conectado" << std::endl;
    
    bool inAGame = false;
    
    try {
        while (!inAGame && not protocol.isClosed()){
            std::string message = protocol.reciveMessage();
            std::unique_ptr<LobbyCommand> command = LobbyParser::getCommand(message);

            std::string response;
            if (command != NULL)
                response = command->execute(gameMonitor, client);
                
            inAGame = client.getInAGame();
            
            if (inAGame) {
                std::string gameName = client.getGameName();
                gameMonitor.startIfLastPlayer(gameName);
            } else {
                protocol.sendMessage(response);
            }
        }
    } catch(const LibError &e) { }

    this->inLobby = false;
}

void ThreadClientLobby::stop() {
    if (this->inLobby)
        protocol.close();
}

ThreadClientLobby::~ThreadClientLobby() {
    this->join();
}



