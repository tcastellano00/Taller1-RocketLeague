#include "ThreadClientLobby.h"
#include "../Common/Protocol.h"
#include <string>
#include <utility>
#include "Lobby/LobbyCommand.h"
#include "Lobby/LobbyParser.h"

ThreadClientLobby::ThreadClientLobby(ClientConnection& clt, GameMonitor& gameMtr): client(std::move(clt)), gameMonitor(gameMtr) {}

void ThreadClientLobby::stop() {}

void ThreadClientLobby::run(){
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



