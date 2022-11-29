#include <string>

#include "ThreadClientSender.h"
#include "../Common/LibError.h"
#include "../Common/GameStatusSerializer.h"

ThreadClientSender::ThreadClientSender(Socket& socket)
    : queue(true), protocol(socket), open(true){}

void ThreadClientSender::run(){
    std::cout << "ThreadClientSender::run" << std::endl;

    GameStatusSerializer gameStatusSerializer;

    //Avisa que tiene que arrancar.
    if (open) // puede ser false acá open?
        protocol.sendMessage("start!");

    try {
        // while (not protocol.isClosed()) y pueden volar el bool 
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