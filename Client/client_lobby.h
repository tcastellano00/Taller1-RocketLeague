#include "../Common/common_socket.h"

class Lobby {
    Socket& conection;
public:
    Lobby(Socket& cnct);
    bool start();
};
