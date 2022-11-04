#include <string>

#include "../Common/Socket.h"

class ClientConnection {
private:
    Socket socket;
    std::string clientName;

public:
    /*
    * Construye el ClientConnection.
    * */
    explicit ClientConnection(
        Socket& socket, 
        const std::string& clientName);

    /*
    * Obtiene el id del cliente.
    * */
    int getId();
    Socket& getSocketReference();

    /*
    * Obtiene el nombre del cliente.
    * */
    std::string getName();

    ClientConnection(const ClientConnection&) = delete;
    ClientConnection& operator=(const ClientConnection&) = delete;
    ClientConnection(ClientConnection&&);
    ClientConnection& operator=(ClientConnection&&);

    /*
    * Libera los recursos.
    * */
    ~ClientConnection() = default;
};