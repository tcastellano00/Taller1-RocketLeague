#include "Gameloop.h"
#include "ThreadClientReceiver.h"
#include "ThreadClientBroadcaster.h"


Gameloop::Gameloop(std::list <ClientConnection> newConnectionList) : connectionList(newConnectionList){
}


void Gameloop::run(){
    Queue <Command> recibingQueue(false);
    Queue <Command> senderQueue(true);
    
    for (auto connection = connectionList.begin(); connection != connectionList.end(); ++connection) {
        
        clientThreadList.emplace_back((*connection).getSocketReference(),recibingQueue);
        clientThreadList.back().start();
    }

    Broadcaster broadcaster(connectionList,senderQueue);
    broadcaster.start();


    // while (queue.notEmpty() && not limiteDeCmds) {
    //     queue.pop()
    //     pegarle al estado del juego (intenciones)
    // }
    // simularPasoDelTiempo (world.update())
    // enviar estado actal (broadcast)
    // sleep(delta - elapsed)
}