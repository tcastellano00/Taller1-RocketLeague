#include "Lobby.h"
#include <iostream>
#include <string>


#include "../Common/Protocol.h"
#include "Lobby/LobbyForm.h"

#include <QApplication>


Lobby::Lobby(Socket& cnct): conection(cnct) {
}

bool Lobby::start() {

    int argc = 1;
    char w1[] = "";
    char *argv[] = { w1 };
    QApplication a(argc, argv);

    std::string clientName;

    LobbyForm w(clientName);
    w.show();

    a.exec();

    std::cout << "Im in the lobby" << std::endl;
    Protocol protocol(conection);
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

    return false;
}
