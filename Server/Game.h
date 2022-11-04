#include <list>
#include <string>

#include "ClientConnection.h"

class Game {
private:
    std::string name;
    std::list<ClientConnection> connections;

public:
    /*
    * Construye el juego con la conexion del
    * primer client.
    * */
    Game(
        const std::string& name);

    /*
    * Construye el juego con la conexion del
    * primer cliente.
    * */
    Game(
        const std::string& name, 
        ClientConnection firstConnection);

    /*
    * Obtiene el nombre de la partida.
    * */
    std::string getName();

    /*
    * Libera los recursos.
    * */
    ~Game();
};