/*  Encapsula logica del cliente
*/
class Client {
private:
    char* ip;
    char* port;

public:
    Client(char* ip, char* port);
    void start();
};
