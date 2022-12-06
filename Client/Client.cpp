#include "Client.h"
#include "Lobby/Lobby.h"
#include "Lobby/GameStatistics.h"
#include "ThreadLauncher.h"
#include "GameStatusMonitor.h"
#include "../Common/Socket.h"

Client::Client(char* ip, char* port) : ip(ip), port(port) { }

void Client::start() {
    
    bool continueInApp = false;

    do {
        Socket clientConnection(ip, port);

        Lobby lobby(clientConnection);
        continueInApp = lobby.start();
        
        if (not continueInApp)
            break;
        
        GameStatusMonitor gameStatusMonitor;
        
        ThreadLauncher threadlauncher;
        threadlauncher.start(
            clientConnection,
            gameStatusMonitor
        );

        GameStatistics gameStatistics(gameStatusMonitor);
        continueInApp = gameStatistics.start();

    } while (continueInApp);
}