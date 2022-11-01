#include "../Common/Socket.h"

class Lobby {
    Socket& conection;
public:
    Lobby(Socket& cnct);
    bool start();
};
