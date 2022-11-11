#include "ThreadClientSender.h"


ThreadClientSender::ThreadClientSender(Queue <Command>& newSenderQueue,Socket& newSocketSender)
    :senderQueue(newSenderQueue) , senderProtocol(newSocketSender),senderOpen(true){}

void ThreadClientSender::run(){
    std::cout << "ThreadClientSender::run" << std::endl;

    while(senderOpen){
        Command gameStatus = senderQueue.pop();
        //senderProtocol.sendMessage(gameStatus);
    }
}

ThreadClientSender::~ThreadClientSender(){
    this->join();
}