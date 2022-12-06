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

TEST(GameMonitorTest, addAPlayerToANonFullGame) {
     GameMonitor gameMonitor;
    const char* ip = "localhost";
    const char* port = "8080";

    Socket accepter(port);
    Socket client1(ip, port);
    Socket client2(ip, port);
    Socket server1 = accepter.accept();
    Socket server2 = accepter.accept();



    std::string gameName = "LaMegaPartida";
    int gameMaxPlayers = 2;
    ClientConnection clientConnection1(server1);
    clientConnection1.setName("Fernandinho");

    ClientConnection clientConnection2(server2);
    clientConnection2.setName("Marquinhos");


    gameMonitor.createGame(gameName, gameMaxPlayers, clientConnection1);
    
    bool playerAdded = gameMonitor.addPlayerIfNotFull(gameName, clientConnection2);

    EXPECT_TRUE (playerAdded);
}


TEST(GameMonitorTest, addPlayerToACompleteRoom) {
    GameMonitor gameMonitor;
    const char* ip = "localhost";
    const char* port = "8080";

    Socket accepter(port);
    Socket client(ip, port);
    Socket server = accepter.accept();

    std::string gameName = "Si perdemos el viernes se borra el repo";
    int gameMaxPlayers = 3;

    ClientConnection clientConnection1(server);
    clientConnection1.setName("Fernandinho");

    ClientConnection clientConnection2(server);
    clientConnection2.setName("Tomasinho");

    ClientConnection clientConnection3(server);
    clientConnection3.setName("Marquinhos");

    ClientConnection clientConnection4(server);
    clientConnection4.setName("AnuloMufa");
    
    gameMonitor.createGame(gameName, gameMaxPlayers, clientConnection1);

    bool playerAdded1 = gameMonitor.addPlayerIfNotFull(gameName, clientConnection2);
    bool playerAdded2 = gameMonitor.addPlayerIfNotFull(gameName, clientConnection3);
    bool playerAdded3 = gameMonitor.addPlayerIfNotFull(gameName, clientConnection4);

    EXPECT_TRUE (playerAdded1);
    EXPECT_TRUE (playerAdded2);
    EXPECT_FALSE (playerAdded3);
}


TEST(GameMonitorTest, startRoomIfIsComplete) {
    GameMonitor gameMonitor;
    const char* ip = "localhost";
    const char* port = "8080";

    Socket accepter(port);
    Socket client(ip, port);
    Socket server = accepter.accept();

    std::string gameName = "Si perdemos el viernes se borra el repo";
    int gameMaxPlayers = 3;


    ClientConnection clientConnection1(server);
    clientConnection1.setName("AnuloMufa");

    ClientConnection clientConnection2(server);
    clientConnection2.setName("Julian>Lautaro");

    ClientConnection clientConnection3(server);
    clientConnection3.setName("MEEEEESSI");
    
    gameMonitor.createGame(gameName, gameMaxPlayers, clientConnection1);

    gameMonitor.addPlayerIfNotFull(gameName, clientConnection2);
    gameMonitor.addPlayerIfNotFull(gameName, clientConnection3);


    bool startGame = gameMonitor.startIfLastPlayer(gameName);

    EXPECT_TRUE (startGame);

}