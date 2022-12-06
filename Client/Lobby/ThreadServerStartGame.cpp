#include "ThreadServerStartGame.h"
#include "../../Common/Socket.h"
#include "../../Common/Protocol.h"

ThreadServerStartGame::ThreadServerStartGame(
    Socket &clientSocket, QObject *parent) 
    : QThread(parent), clientSocket(clientSocket) { }

void ThreadServerStartGame::run()
{
    Protocol protocol(this->clientSocket);
    std::string serverReponse("");

    while(true)
    {
        serverReponse = protocol.reciveMessage();

        if (serverReponse == "start!") {
            emit HaveStartedGame(true);
            break;
        }
    }
}