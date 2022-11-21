#ifndef GAME_H
#define GAME_H

#include <list>
#include <string>

#include "Gameloop.h"
#include "ClientConnection.h"

class Game {
private:
    std::string name;
    int maxClients;
    int clients;
    std::list<ClientConnection> connections;
    bool started;
    Gameloop gameLoop;

public:

    /*
    * Construye el juego con la conexion del
    * primer cliente.
    * */
    explicit Game(
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

    int getMaxClients();

    bool isFull();

    void launch();

    void finish();

    /*
    * Libera los recursos.
    * */
    ~Game() = default;
};

#endif