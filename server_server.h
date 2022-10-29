
#include "common_socket.h"

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

    /*  Comienza a recibir clientes.
    */
    void reciveAndReturnMessage();

    /*
    * Libera los recursos.
    * */
    ~Server();
};
