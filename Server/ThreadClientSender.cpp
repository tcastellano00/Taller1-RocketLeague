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

        //std::cout << gameStatus.identificador << std::endl;

        //std::cout <<"ThreadClientSender: run" <<std::endl;

        // float xcord = gameStatus.getPlayer().getCoordX();
        // float ycord = gameStatus.getPlayer().getCoordX();

        //std::cout << "Sender x:" << std::to_string(gameStatus.getPlayer().getCoordX()) << std::endl;
        //std::cout << "Sender y:"  << std::to_string(gameStatus.getPlayer().getCoordY()) << std::endl;

        std::string message = gameStatusSerializer.serialize(gameStatus);

        //std::cout << message <<std::endl;
        //std::cout << "ThreadClientSender::enviar mensaje" << std::endl;
        //std::cout << message << std::endl;
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