#include "../Common/Socket.h"

/*  Encapsula logica del cliente
*/
class Client {
private:
    Socket conection;
public:
    Client(char* ip, char* port);
    void start();
};
