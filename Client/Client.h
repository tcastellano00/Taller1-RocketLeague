#include "../Common/Socket.h"

class Client {
private:
    Socket conection;
public:

    // Usualmente un "host" (identificado con una IP) tiene varios "services" 
    // (identificados con puetos). Estos argumentos deberían ser host:service, o ip:port
    Client(char* service, char* port);
    void start();
};
