#include "ThreadClientSender.h"


ThreadClientSender::ThreadClientSender(Queue <Command>& newSenderQueue,Socket& newSocketSender)
    :senderQueue(newSenderQueue) , socketSender(newSocketSender){}

void ThreadClientSender::run(){
    while (!senderQueue.empty()){
        //pop estado del mundo
        //protocolo enviar(estado del mundo)
    }
}

ThreadClientSender::~ThreadClientSender(){}