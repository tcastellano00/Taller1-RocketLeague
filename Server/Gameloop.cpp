#include "Gameloop.h"
#include "ThreadClientBroadcaster.h"
#define LIMITOFCOMANDS 10  //puse un numero cualquiera


Gameloop::Gameloop() { }

void Gameloop::run() {
    Queue <Command> recibingQueue(false);
    Queue <Command> senderQueue(true);
    
    for (auto connection = connectionList.begin(); connection != connectionList.end(); ++connection) {
        
        clientThreadList.emplace_back((*connection).getSocketReference(),recibingQueue);
        clientThreadList.back().start();
    }

    Broadcaster broadcaster(connectionList, senderQueue);
    broadcaster.start();

    int commandsCounter = 0;

    while (!recibingQueue.empty() &&  commandsCounter > LIMITOFCOMANDS) {
        Command command = recibingQueue.pop();
        //     pegarle al estado del juego (intenciones)

        commandsCounter += 1;

    }
    // simularPasoDelTiempo (world.update())
    // enviar estado actal (broadcast)
    // sleep(delta - elapsed)
}

void Gameloop::init(std::list <ClientConnection>& connectionList) {
    this->connectionList = std::move(connectionList);

    this->start();
}

Gameloop::~Gameloop() {
    this->join();
}