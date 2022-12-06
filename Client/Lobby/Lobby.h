#include "../../Common/Socket.h"

/*
Esta clase se encarga de lanzar el lobby en QT
*/
class Lobby {
    Socket& clientSocket;

    /* Devuelve true si el cliente se unio a un juego */
    bool initLobbyForms();

public:
    Lobby(Socket& clientSocket);

    /* Devuelve true si el cliente se unio a un juego */
    bool start();
};
