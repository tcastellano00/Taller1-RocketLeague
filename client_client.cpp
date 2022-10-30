#include "client_client.h"
#include "client_lobby.h"
#include "client_threadlauncher.h"
#include "client_renderer.h"   
#include "client_gamestatusmonitor.h"

Client::Client(char* service, char* port): conection(service, port){

}

void Client::start() {
    Lobby lobby(conection);
    bool close_game = false;
    do {
        close_game = lobby.start();
        
        if (close_game) {
            break;
        }
        GameStatusMonitor gameStatusMonitor;

        ThreadLauncher threadlauncher;
        threadlauncher.start(conection,gameStatusMonitor);
        Renderer renderer;
        renderer.render(gameStatusMonitor);

        close_game = true;

    } while (!close_game);

}