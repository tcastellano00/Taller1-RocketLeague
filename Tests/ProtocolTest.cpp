#include "gtest/gtest.h"
#include "../Common/Socket.h"
#include "../Common/Protocol.h"

TEST(ProtocoloTest, isClosed_shouldReturnFalseWhenTheProtocoloItsCreated) {
    const char* port = "8080";

    Socket socket(port);
    Protocol protocol(socket);
    
    //assert
    EXPECT_TRUE (not protocol.isClosed());
}

TEST(ProtocoloTest, close_shouldCloseProtocol) {
    const char* port = "8080";

    Socket socket(port);
    Protocol protocol(socket);

    protocol.close();
    
    //assert
    EXPECT_TRUE (protocol.isClosed());
}

TEST(ProtocoloTest, sendAndReciveMessage_ServerShouldReciveWhatClientSend) {
    const char* ip = "localhost";
    const char* port = "8080";

    Socket accepter(port);
    Socket client(ip, port);
    Socket server = accepter.accept();

    Protocol protocolClient(client);
    Protocol protocolServer(server);

    std::string sentMessage = "¿Sabes lo que es Bow pibe?";
    protocolClient.sendMessage(sentMessage);
    std::string recivedMessage = protocolServer.reciveMessage();

    protocolClient.close();
    protocolServer.close();

    //assert
    EXPECT_EQ (sentMessage, recivedMessage);
}

TEST(ProtocoloTest, sendAndReciveMessage_ClientShouldReciveWhatServerSend) {
    const char* ip = "localhost";
    const char* port = "8080";

    Socket accepter(port);
    Socket client(ip, port);
    Socket server = accepter.accept();

    Protocol protocolClient(client);
    Protocol protocolServer(server);

    std::string sentMessage = "Es arco pibe, arco.";
    protocolServer.sendMessage(sentMessage);
    std::string recivedMessage = protocolClient.reciveMessage();

    protocolClient.close();
    protocolServer.close();

    //assert
    EXPECT_EQ (sentMessage, recivedMessage);
}