#ifndef GAME_H
#define GAME_H

#include <list>
#include <string>

#include "../Threads/GameloopRunner.h"
#include "../ClientConnection.h"


/*
Partida del juego. Se encarga de almacenar las distintas conecciones de los clientes a
medida que los mismos se van sumando a la partida. Una vez que se llena, se inicia la partida y se
lanza el hilo GameLoopRunner.
*/
class Game {
private:
    std::string name;
    int maxClients;
    int clients;
    std::list<ClientConnection> connections;
    bool started;
    GameloopRunner gameloopRunner;

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