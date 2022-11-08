#include "ThreadClientBroadcaster.h"
#include "ThreadClientSender.h"


// Broadcaster::Broadcaster(std::list<ClientConnection>& newConnections, Queue<Command>& newSenderQueue)
//     :senderQueue(newSenderQueue),connections(newConnections){
// }


Broadcaster::Broadcaster(ClientConnection& newConnection, Queue<Command>& newSenderQueue)
    :senderQueue(newSenderQueue), connection(newConnection) , open(true){
}

void Broadcaster::run(){
    std::cout << "Broadcaster::run" << std::endl;
    // for (auto connection = connections.begin(); connection != connections.end(); ++connection) {
    //     //Queue<Command> newSenderQueue(true);
    //     listSenderQueues.emplace_back(true);

    //     //no son comandos, es un estado del mundo
    //     ThreadClientSender sender(listSenderQueues.back(), (*connection).getSocketReference());
    //     sender.start();
    // }

    // while (!senderQueue.empty()){
    //     Command command = senderQueue.pop();
    //     for (auto queue = listSenderQueues.begin(); queue != listSenderQueues.end(); ++queue) {
    //         (*queue).push(command); //tiene que ser estado del mundo
    //     }
    // }

    Queue<Command> newSenderQueue(true);
     
    ThreadClientSender sender(newSenderQueue, connection.getSocketReference());
    sender.start();

    while(open){
        Command command = senderQueue.pop();
        newSenderQueue.push(command);
    }


    // while (!senderQueue.empty()){
    //     Command command = senderQueue.pop();
    //     newSenderQueue.push(command);
    // }

}

Broadcaster::~Broadcaster() {
    this->join();
}
