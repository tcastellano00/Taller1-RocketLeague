#include "Gameloop.h"
#include "ThreadClientBroadcaster.h"
#define LIMITOFCOMANDS 10  //puse un numero cualquiera


Gameloop::Gameloop() { }

void Gameloop::run() {
    std::cout << "Gameloop::run" << std::endl;

    Queue <Command> recibingQueue(false);
    Queue <Command> senderQueue(true);
    
    // for (auto connection = connectionList.begin(); connection != connectionList.end(); ++connection) {
        
    //     clientThreadList.emplace_back((*connection).getSocketReference(),recibingQueue);
    //     clientThreadList.back().start();
    // }

    ThreadClientReceiver clientThreadReceiver(connection.getSocketReference(),recibingQueue);
    clientThreadReceiver.start();

    Broadcaster broadcaster(connection, senderQueue);
    broadcaster.start();

    int commandsCounter = 0;


    std::cout << "Gameloop::while" << std::endl;
    while (!recibingQueue.empty() &&  commandsCounter > LIMITOFCOMANDS) {
        Command command = recibingQueue.pop();
        //     pegarle al estado del juego (intenciones)

        commandsCounter += 1;

    }
    // simularPasoDelTiempo (world.update())
    // enviar estado actal (broadcast)
    // sleep(delta - elapsed)
}

// void Gameloop::init(std::list <ClientConnection>& connectionList) {
//     this->connectionList = std::move(connectionList);

//     this->start();
// }

void Gameloop::init(ClientConnection& newConnection) {
    std::cout << "GameLoop::init" << std::endl;

    this->connection = std::move(newConnection);
    std::cout << "GameLoop::stdmove" << std::endl;
    this->start();
}

Gameloop::~Gameloop() {
    this->join();
}