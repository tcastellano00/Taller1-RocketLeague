#include "ThreadClientBroadcaster.h"
#include "ThreadClientSender.h"


Broadcaster::Broadcaster(std::list<ClientConnection> newConnections, Queue<Command>& newSenderQueue)
    :senderQueue(newSenderQueue),connections(newConnections){

}

void Broadcaster::run(){
    for (auto connection = connections.begin(); connection != connections.end(); ++connection) {
        //creo la cola que va a tener el sender

        //no son comando, es un estado del mundo
        Queue <Command> senderQueue(true);
        ThreadClientSender sender(senderQueue,(*connection).getSocketReference());
        sender.start();
    }

    while (senderQueue.empty()){
        //pop comando
        //protocolo.send(comand)
    }
}

    