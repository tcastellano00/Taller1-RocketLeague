#ifndef GAME_MONITOR_H
#define GAME_MONITOR_H

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
    * Empieza la partida si se unio el ultimo jugador.
    * */
    bool startIfLastPlayer(
        const std::string& gameName);

    /*
    * Lista las partidas.
    * */
    std::string listGames();

    /*
    * Termina una partida.
    * */
    void finishGame(
        const std::string& gameName);

    /*
    * Termina todas las partidas.
    * */
    void finishGames();

    /*
    * Libera los recursos.
    * */
    ~GameMonitor();
};

#endif