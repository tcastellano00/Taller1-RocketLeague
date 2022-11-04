#include "ThreadClientLobby.h"
#include "../Common/Protocol.h"
#include <string>

ThreadClientLobby::ThreadClientLobby(ClientConnection& clt, GameMonitor& gameMtr): client(std::move(clt)), gameMonitor(gameMtr) {}

void ThreadClientLobby::stop() {}

void ThreadClientLobby::run(){
    Protocol protocol(client.getSocketReference());
    bool inAGame = false;
    std::string finalGameName;
    while (!inAGame){
        /*LobbyCommand command(protocol.reciveMessage());
        std::string response = command.process(gameMonitor, &inAGame, &finalGameName, clt);
        protocol.sendMessage(response);*/
    }
    //gameMonitor.startIfLastPlayer(finalGameName);


}



