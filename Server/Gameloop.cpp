#include "Gameloop.h"
#include "ThreadClientBroadcaster.h"
#include "Physics/Physics.h"
#include "ActionsClient/ActionsClient.h"
#define LIMITOFCOMANDS 10  //puse un numero cualquiera
#include <chrono>
#include <unistd.h>
#define DELTA 5000
typedef std::chrono::high_resolution_clock Clock;


Gameloop::Gameloop() { }

void Gameloop::run() {
    std::cout << "Gameloop::run" << std::endl;

    //Inicia el mundo del game.
    Physics gamePhysics(this->connectionList.size());

    //Instancia las colas de envio y recepcion.
    Queue<std::shared_ptr<ActionsClient>> recibingQueue(false);
    Queue<Command> senderQueue(true);
    
    //Instanciamos los receivers.
    for (auto connection = connectionList.begin(); connection != connectionList.end(); ++connection) {
        
        clientThreadList.emplace_back((*connection).getSocketReference(),recibingQueue);
        clientThreadList.back().start();
    }

    //Instanciamos el broadcaster
    ThreadClientBroadcaster broadcasterThread(connectionList, senderQueue);
    broadcasterThread.start();


    std::cout << "Gameloop::while" << std::endl;

    //bool isRunning = true;
    int commandsCounter = 0;

    //Iniciamos el Gameloop donde procesa los comandos.
    while (true) {
        auto timeStart = Clock::now();
        while (!recibingQueue.empty() &&  commandsCounter > LIMITOFCOMANDS) {
            std::shared_ptr<ActionsClient> action = recibingQueue.pop();
            action->execute(gamePhysics);
            
            /*
            -- TODO: El juego se va a manejar con un temporizador.
            if (action->gameFinished()) {
                isRunning = false;
                break;
            }*/

            //pegarle al estado del juego (intenciones)

            commandsCounter += 1;
        }


        /*
        if (!isRunning) {
            break;
        }
        */

        gamePhysics.simulateTimeStep();
        // enviar estado actal (broadcaster)
        auto timeFinish = Clock::now();
        int elapsed = std::chrono::duration_cast<std::chrono::microseconds>(timeFinish - timeStart).count();
        if (DELTA - elapsed > 0) {
            //sleep(DELTA - elapsed);
        }
        
    }
}

void Gameloop::init(std::list <ClientConnection>& connectionList) {
    this->connectionList = std::move(connectionList);

    this->start();
}

// void Gameloop::init(ClientConnection& newConnection) {
//     std::cout << "GameLoop::init" << std::endl;

//     this->connection = std::move(newConnection);
//     std::cout << "GameLoop::stdmove" << std::endl;
//     this->start();
// }

Gameloop::~Gameloop() {
    this->join();
}