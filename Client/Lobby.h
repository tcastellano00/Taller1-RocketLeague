#include "../Common/Socket.h"

/*
Esta clase se encarga de lanzar el lobby en QT, una vez terminado esto
lanza el juego y cuando esta termina lanza otra venta de QT con las
estadisticas de del juego.
*/
class Lobby {
    Socket& clientSocket;

    bool initLobbyForms();

public:
    Lobby(Socket& clientSocket);
    bool start();
};
