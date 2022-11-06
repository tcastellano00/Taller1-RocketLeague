#include "ThreadClientSender.h"


ThreadClientSender::ThreadClientSender(Queue <Command>& newSenderQueue,Socket& newSocketSender)
    :senderQueue(newSenderQueue) , socketSender(newSocketSender), senderProtocol(socketSender){}

void ThreadClientSender::run(){
    while (!senderQueue.empty()){
        Command gameStatus = senderQueue.pop();
        //senderProtocol.sendMessage(gameStatus);
    }
}

ThreadClientSender::~ThreadClientSender(){}