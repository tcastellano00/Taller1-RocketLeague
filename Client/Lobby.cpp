#include "Lobby.h"
#include <iostream>
#include "../Common/Protocol.h"
#include <string>


Lobby::Lobby(Socket& cnct): conection(cnct) {
}

bool Lobby::start() {
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
