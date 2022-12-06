#include "Client.h"
#include "Lobby.h"
#include "ThreadLauncher.h"
#include "GameStatusMonitor.h"

Client::Client(char* ip, char* port) : conection(ip, port) { }

void Client::start() {
    Lobby lobby(conection);
    bool close_game = false;
    do {
        //aca creamos la connection
        //aca definimos el lobby
        close_game = lobby.start();
        
        if (close_game) {
            break;
        }
        GameStatusMonitor gameStatusMonitor;
        
        ThreadLauncher threadlauncher;
        threadlauncher.start(conection,gameStatusMonitor);


        close_game = true;

    } while (!close_game);

}