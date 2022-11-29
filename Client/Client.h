#include "../Common/Socket.h"

class Client {
private:
    Socket conection;
public:
    Client(char* ip, char* port);
    void start();
};
