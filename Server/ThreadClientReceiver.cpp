#include "ThreadClientReceiver.h"
#include "../Common/Queue.h"


ThreadClientReceiver::ThreadClientReceiver(Socket& newSktConecction,Queue<Command>& newRecibingQueue)
    :sktConecction(newSktConecction),recibingQueue(newRecibingQueue), receiverProtocol(sktConecction){
}

void ThreadClientReceiver::run(){
    std::cout << "ThreadClientReceiver::run" << std::endl;
    std::string message = receiverProtocol.reciveMessage();
    
    recibingQueue.push(message); //o el comando nuevo.

}


ThreadClientReceiver::~ThreadClientReceiver(){
}