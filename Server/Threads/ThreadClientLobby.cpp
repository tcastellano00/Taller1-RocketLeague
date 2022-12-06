#include <string>
#include <utility>
#include <iostream>

#include "../../Common/Protocol.h"
#include "../../Common/LibError.h"

#include "../ActionsLobby/ActionsLobby.h"
#include "../ActionsLobby/ActionsLobbyParser.h"
#include "ThreadClientLobby.h"

ThreadClientLobby::ThreadClientLobby(ClientConnection& clt, GameMonitor& gameMtr): 
    client(std::move(clt)), 
    gameMonitor(gameMtr),
    protocol(client.getSocketReference()) {
        inLobby = true;
    }

void ThreadClientLobby::run(){
    std::cout << "ThreadClientLobby: cliente conectado" << std::endl;
    
    client.setGameName("");
    bool clientJoinedGame = false;
    
    try {
        while (!clientJoinedGame && not protocol.isClosed()){
            std::string message = protocol.reciveMessage();
            std::unique_ptr<ActionsLobby> command = ActionsLobbyParser::getCommand(message);

            std::string response;
            if (command != NULL)
                response = command->execute(gameMonitor, client);
                
            clientJoinedGame = client.getInAGame();

            /*
             Cuando el client se une al juego, la conexion
             pasa a estar en el juego y deja de estar en el
             lobby
            */
            if (clientJoinedGame) {
                std::string gameName = client.getGameName();
                gameMonitor.startIfLastPlayer(gameName);
            } else {
                protocol.sendMessage(response);
            }
        }
    } catch(const LibError &e) { 
        clientJoinedGame = false;
    }
    
    this->inLobby = false;
}

void ThreadClientLobby::stop() {
    if (this->inLobby)
        protocol.close();
}

ThreadClientLobby::~ThreadClientLobby() {
    this->join();
}



