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
        std::string reply = protocol.reciveMessage();
        std::cout << reply;
        break;  //CAMBIAR ESTO, por ahora probamos con 1 solo jugador por lo que ya sabemos que deberia salir.
    } while (keepReading);

    return false;
}
