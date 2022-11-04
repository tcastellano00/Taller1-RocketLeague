#include "Gameloop.h"



Gameloop::Gameloop(std::list <ClientConnection> newConnectionList) : connectionList(newConnectionList){
}


void Gameloop::run(){
    Queue <Command> recibingQueue(false);
    Queue <Command> senderQueue(true);
    
    for (auto clientThread = connectionList.begin(); clientThread != connectionList.end(); ++clientThread) {
        
        //crear thread con la conexion
        //run del thread
        
    }
}