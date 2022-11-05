#ifndef GAME_H
#define GAME_H

#include <list>
#include <string>

#include "ClientConnection.h"

class Game {
private:
    std::string name;
    int maxClients;
    //std::list<ClientConnection> connections;
    bool started;
    //Gameloop gameLoop;

public:
    /*
    * Construye el juego
    * */
    Game();

    /*
    * Construye el juego
    * */
    Game(
        const std::string& name,
        int maxClients);

    /*
    * Construye el juego con la conexion del
    * primer cliente.
    * */
    Game(
        const std::string& name,
        int maxClients,
        ClientConnection& firstConnection);

    /*
    * Obtiene el nombre de la partida.
    * */
    std::string getName();

    /*
    * Intenta agregar un jugador.
    * */
    bool addPlayer(ClientConnection& clientConnection);

    /*
    * Obtiene el numero de clientes conectados.
    * */
    int getNumberOfConnectedClients();

    bool isFull();

    void start();

    /*
    * Libera los recursos.
    * */
    ~Game() = default;
};

#endif