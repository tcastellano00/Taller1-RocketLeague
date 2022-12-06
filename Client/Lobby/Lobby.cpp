#include "Lobby.h"
#include <iostream>
#include <string>

#include <QApplication>
#include "LobbyForm.h"


Lobby::Lobby(Socket& clientSocket): 
    clientSocket(clientSocket) { }

bool Lobby::start() {
    return this->initLobbyForms();
}

bool Lobby::initLobbyForms() {
    int argc = 1;
    char w1[] = "";
    char *argv[] = { w1 };
    QApplication qtApplication(argc, argv);

    std::string clientName = "";
    bool clientJoinedGame = false;

    LobbyForm lobbyForm(
        this->clientSocket, 
        clientName,
        clientJoinedGame
    );

    lobbyForm.show();

    qtApplication.exec();

    return clientJoinedGame;
}