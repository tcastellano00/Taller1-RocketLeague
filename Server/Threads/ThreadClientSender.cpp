#include <string>

#include "ThreadClientSender.h"
#include "../../Common/LibError.h"
#include "../../Common/GameStatusSerializer.h"

ThreadClientSender::ThreadClientSender(Socket& socket)
    : queue(), protocol(socket), open(true) {}

void ThreadClientSender::run(){

    GameStatusSerializer gameStatusSerializer;

    //Avisa que tiene que arrancar.
    if (open)
        protocol.sendMessage("start!");

    try {
        while (open) {
            GameStatus gameStatus = queue.pop();

            if (gameStatus.isClosed()) {
                protocol.sendMessage("close");
                protocol.close();
                open = false;
                break;
            } 

            std::string message = gameStatusSerializer.serialize(gameStatus);
            
            protocol.sendMessage(message);

            this->open = (not protocol.isClosed());
        }
    } 
    catch(const LibError &e) {
        this->open = false;
    }
}

void ThreadClientSender::push(GameStatus gameStatus) {
    this->queue.push(gameStatus);
}

ThreadClientSender::~ThreadClientSender() {
    this->join();
}