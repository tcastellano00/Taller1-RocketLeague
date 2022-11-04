
#include "../Common/Socket.h"

/*  Encapsula logica del servidor
*/
class Server {
private:
    Socket socket;

public:
    /*
    * Construye el Server.
    * */
    explicit Server(const char *port);

    /*  Corre el hilo. Lanza el hilo aceptador.
    */
    void run();

    /*
    * Libera los recursos.
    * */
    ~Server();
};
