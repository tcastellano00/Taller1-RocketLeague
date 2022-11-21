#include <string>

#include "ThreadClientSender.h"
#include "../Common/GameStatusSerializer.h"

ThreadClientSender::ThreadClientSender(Socket& socket)
    : queue(true), protocol(socket), open(true){}

void ThreadClientSender::run(){
    std::cout << "ThreadClientSender::run" << std::endl;

    GameStatusSerializer gameStatusSerializer;

    //Avisa que tiene que arrancar.
    if (open)
        protocol.sendMessage("start!");

    while (open) {
        GameStatus gameStatus = queue.pop();

        std::string message = gameStatusSerializer.serialize(gameStatus);
        
        protocol.sendMessage(message);

        this->open = (not protocol.isClosed());
    }
}

void ThreadClientSender::push(GameStatus gameStatus) {
    this->queue.push(gameStatus);
}

ThreadClientSender::~ThreadClientSender(){
    this->join();
}