#include "ThreadClientReceiver.h"


ThreadClientReceiver::ThreadClientReceiver(Socket& newSktConecction,Queue<Command>& newRecibingQueue)
    :sktConecction(newSktConecction),recibingQueue(newRecibingQueue), receiverProtocol(sktConecction){
}

void ThreadClientReceiver::run(){
    //protocolo.recibir() 
    //pushear a la cola.
}


ThreadClientReceiver::~ThreadClientReceiver(){
}