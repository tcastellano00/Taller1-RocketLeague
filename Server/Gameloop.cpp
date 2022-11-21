#include "Gameloop.h"
#include "ThreadClientBroadcaster.h"
#include "Physics/Physics.h"
#include "ActionsClient/ActionsClient.h"
#include "../Common/GameStatus.h"

#include <chrono>
#include <unistd.h>
#define LIMITOFCOMANDS 10  //puse un numero cualquiera
#define DELTA 1000000.0f/25.0f
typedef std::chrono::high_resolution_clock Clock;

Gameloop::Gameloop() { }

void Gameloop::run() {
    std::cout << "Gameloop::run" << std::endl;

    //Inicia el mundo del game.
    Physics gamePhysics(this->connectionList);

    //Instancia las colas de envio y recepcion.
    Queue<GameStatus> senderQueue(true);
    Queue<std::shared_ptr<ActionsClient>> recibingQueue(false);
    
    //Instanciamos los receivers.
    for (auto connection = connectionList.begin(); connection != connectionList.end(); ++connection) {
        clientThreadReceiver.emplace_back((*connection).getSocketReference(),recibingQueue);
        clientThreadReceiver.back().start();
    }

    //Instanciamos el broadcaster
    ThreadClientBroadcaster broadcasterThread(senderQueue, connectionList);
    broadcasterThread.start();

    int commandsCounter = 0;

    //Iniciamos el Gameloop donde procesa los comandos.
    std::cout << "Gameloop::while" << std::endl;
    while (true) {
        auto timeStart = Clock::now();

        while (!recibingQueue.empty() && commandsCounter < LIMITOFCOMANDS) {
            std::shared_ptr<ActionsClient> action = recibingQueue.pop();
            if (action != NULL) {
                action->execute(gamePhysics);
            }

            commandsCounter += 1;
        }

        GameStatus gameStatus = gamePhysics.getGameStatus();
        
        senderQueue.push(gameStatus);
        
        gamePhysics.simulateTimeStep();
        // enviar estado actal (broadcaster)
        auto timeFinish = Clock::now();
        int elapsed = std::chrono::duration_cast<std::chrono::microseconds>(timeFinish - timeStart).count();
        if (DELTA - elapsed > 0) {
            usleep(DELTA - elapsed);
        }

        commandsCounter = 0;
    }
}

void Gameloop::init(std::list <ClientConnection>& connectionList) {
    this->connectionList = std::move(connectionList);

    this->start();
}

Gameloop::~Gameloop() {
    this->join();
}