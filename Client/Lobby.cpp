#include "Lobby.h"
#include <iostream>
#include <string>


#include "../Common/Protocol.h"
#include "Lobby/LobbyForm.h"

#include <QApplication>


Lobby::Lobby(Socket& clientSocket): clientSocket(clientSocket) {

}

bool Lobby::start() {

    bool result = this->initLobbyForms();

    std::cout << result << std::endl;

    return false;
    
    /*
    std::cout << "Im in the lobby" << std::endl;
    Protocol protocol(this->clientSocket);
    std::string input;
    bool keepReading;
    do {

        keepReading = (bool) getline(std::cin, input);
        if (!keepReading) {break;}
        if (input == "\n") {break;}
        protocol.sendMessage(input);
        
        if (protocol.isClosed())
            return true;
        
        std::string reply = protocol.reciveMessage();

        if (protocol.isClosed())
            return true;

        if (reply == "start!")
            keepReading = false;
        std::cout << reply;
    } while (keepReading);

    return false; */
}


bool Lobby::initLobbyForms() {
    int argc = 1;
    char w1[] = "";
    char *argv[] = { w1 };
    QApplication qtApplication(argc, argv);

    std::string clientName;

    LobbyForm lobbyForm(this->clientSocket, clientName);
    lobbyForm.show();

    //Devuelve 0 si salio con un quit();
    int result = qtApplication.exec();

    return (result == 0);
}