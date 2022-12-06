#include "GameloopRunner.h"
#include "ThreadClientBroadcaster.h"
#include "../Physics/Physics.h"
#include "../ActionsClient/ActionsClient.h"
#include "../../Common/GameStatus.h"
#include "../Game/GameLoop.h"



GameloopRunner::GameloopRunner() 
    : senderQueue(), 
      recibingQueue(),
      isRunning(false),
      isThreadRunning(false) { }

void GameloopRunner::run() {

    //Inicia el mundo del game.
    Physics gamePhysics(this->connectionList);
    
    //Instanciamos los receivers.
    for (auto &connection : connectionList){
        clientThreadReceiver.emplace_back(connection.getId(), connection.getSocketReference(), recibingQueue);
        clientThreadReceiver.back().start();
    }

    //Instanciamos el broadcaster
    ThreadClientBroadcaster broadcasterThread(senderQueue, connectionList);
    broadcasterThread.start();



    //Iniciamos el Gameloop donde procesa los comandos.
    GameLoop gameLoop;
    gameLoop.run(this->isRunning, this->recibingQueue, gamePhysics, this->senderQueue);


}

void GameloopRunner::init(std::list <ClientConnection>& connectionList) {
    this->isRunning = true;
    this->isThreadRunning = true;
    this->connectionList = std::move(connectionList);

    this->start();
}

void GameloopRunner::stop() {
    /*
        Al cerrar el GameloopRunner, necesitamos pushear
        un nuevo estado del mundo, pero con un
        estado indicando que esta cerrado
    */
    GameStatus gameStatus;
    gameStatus.setClose();

    senderQueue.push(gameStatus);

    this->isRunning = false;
}


GameloopRunner::~GameloopRunner() {
    if (this->isThreadRunning) {
        this->join();
    }
}