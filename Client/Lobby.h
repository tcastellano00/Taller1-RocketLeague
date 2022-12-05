#include "../Common/Socket.h"

class Lobby {
    Socket& clientSocket;

    bool initLobbyForms();

public:
    Lobby(Socket& clientSocket);
    bool start();
};
