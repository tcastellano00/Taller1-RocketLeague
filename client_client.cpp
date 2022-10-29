#include "client_client.h"
#include "client_lobby.h"
#include "client_threadlauncher.h"
#include "client_renderer.h"    

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

        ThreadLauncher threadlauncher;
        threadlauncher.start();
        Renderer renderer;
        renderer.render();

        close_game = true;

    } while (!close_game);

}