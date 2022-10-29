#include "common_socket.h"

class Client {
private:
    Socket conection;
public:
    Client(char* service, char* port);
    void start();
};
