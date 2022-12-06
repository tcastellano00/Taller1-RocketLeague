#include "gtest/gtest.h"
#include "../Server/ClientConnection.h"
#include "../Server/Game/GameMonitor.h"

TEST(GameMonitorTest, createGame) {
    
    GameMonitor gameMonitor;
    const char* ip = "localhost";
    const char* port = "8080";

    Socket accepter(port);
    Socket client(ip, port);
    Socket server = accepter.accept();

    std::string gameName = "LaPartida";
    int gameMaxPlayers = 2;
    ClientConnection clientConnection(server);
    clientConnection.setName("Tomas");

    gameMonitor.createGame(gameName, gameMaxPlayers, clientConnection);

    std::string lstGames = gameMonitor.listGames();

    //assert
    EXPECT_TRUE (lstGames.find(gameName) > 0);
}