#include <vector>
#include <utility>

#include "Protocol.h"

#define BUFF_SIZE 11
#define END_OF_MESSAGE "\n\n"

Protocol::Protocol(
    Socket &socket) : socket(std::move(socket)) {
        this->closedSocket = false;
     }

std::string Protocol::reciveMessage() {
    bool wasClosed = this->closedSocket;
    
    std::string message;
    while (message.find(END_OF_MESSAGE) == std::string::npos){
        char buf[BUFF_SIZE];
        int recived = this->socket.recvsome(
            &buf, 
            BUFF_SIZE, 
            &wasClosed);
             
        if (recived == 0)
            break;
        
        message.append(buf, recived);
    }

    this->closedSocket = wasClosed;

    return message.substr(0, message.find(END_OF_MESSAGE));
}

void Protocol::sendMessage(const std::string& message) {
    bool wasClosed = this->closedSocket;

    std::string message_protocol = message + END_OF_MESSAGE;
    std::vector<char> message_chars(
        message_protocol.begin(), 
        message_protocol.end());

    this->socket.sendall(
        &message_chars[0],
        message_protocol.length(),
        &wasClosed);

    this->closedSocket = wasClosed;
}

bool Protocol::isClosed() {
    return this->closedSocket;
}

void Protocol::close() {
    if (this->isClosed())
        return;

    this->closeSocket();
}

void Protocol::closeSocket() {
    this->socket.shutdown(2);
    this->socket.close();
    this->closedSocket = true;
}
