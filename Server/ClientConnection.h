#ifndef SERVER_CLIENT_CONNECTION_H
#define SERVER_CLIENT_CONNECTION_H

#include <string>

#include "../Common/Socket.h"

class ClientConnection {
private:
    Socket socket;
    std::string clientName;
    std::string gameName;
    bool inAGame;

public:
    /*
    * Construye el ClientConnection.
    * */
    ClientConnection();

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

    void setGameName(std::string newGameName);

    std::string getGameName();

    bool getInAGame();

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

#endif