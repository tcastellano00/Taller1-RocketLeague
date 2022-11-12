#include "ThreadClientSender.h"

ThreadClientSender::ThreadClientSender(Socket& socket)
    : queue(true), protocol(socket), open(true){}

void ThreadClientSender::run(){
    std::cout << "ThreadClientSender::run" << std::endl;

    //Avisa que tiene que arrancar.
    if (open)
        protocol.sendMessage("start!");

    while (open) {
        Command gameStatus = queue.pop();
        //senderProtocol.sendMessage(gameStatus.getMessage());
    }
}

void ThreadClientSender::push(Command command) {
    this->queue.push(command);
}

ThreadClientSender::~ThreadClientSender(){
    this->join();
}