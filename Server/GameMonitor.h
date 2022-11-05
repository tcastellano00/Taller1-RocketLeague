#include <list>
#include <string>
#include <map>
#include <mutex>

#include "Game.h"
#include "ClientConnection.h"

class GameMonitor {
private:
    std::map<std::string, Game> games;
    std::mutex mutex;

public:
    /*
    * Construye el GameMonitor.
    * */
    explicit GameMonitor();

    /*
    * Crea una partida partida con la primer conexion.
    * */
    bool createGame(
        const std::string& gameName,
        int maxClients, 
        ClientConnection& clientConnection);

    /*
    * Agrego un nuevo jugador a la partida.
    * */
    bool addPlayerIfNotFull(
        const std::string& gameName, 
        ClientConnection& clientConnection);

    /*
    * Inicia la partida si ya esta llena.
    */
   bool startIfLastPlayer(
        const std::string gameName);
    
    std::string listGames();

    /*
    * Libera los recursos.
    * */
    ~GameMonitor() = default;
};
